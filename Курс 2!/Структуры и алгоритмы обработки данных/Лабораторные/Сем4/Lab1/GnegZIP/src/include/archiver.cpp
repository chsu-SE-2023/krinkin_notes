#pragma once
#include <string>
#include <fstream>
#include <array>
#include "huffman.h"
#include "archiver.h"

void Archiver::updateProgress() {
	progress = ((float)processed / (float)fsize) * 100;
}

int Archiver::getProgress() {
	return progress;
}

/*
* Метод сжатия файла
*/
void Archiver::compress(std::string fileName, std::string outName) {
	HuffmanTree hf_tree;
	std::ifstream file(fileName, std::ios::binary);

	if (file.is_open()) {

		// Подсчёт размера файла для вычисления прогресса
		file.seekg(0, std::ios::end);
		fsize = file.tellg();
		file.seekg(0, std::ios::beg);

		// Создание дерева Хаффмана из байт
		unsigned char byte;
		while (file.read(reinterpret_cast<char*>(&byte), sizeof(byte)))
			hf_tree.addByte(byte);
		hf_tree.makeTree();
		file.close();

		std::ofstream out(outName, std::ios::binary);
		// Запись типа файла
		out.write(new char[4] {'G', 'N', 'E', 'G'}, 4);
		std::array<int, BYTE_MAX> freq = hf_tree.getFreq();
		for (int i = 0; i < freq.size(); i++)
			out.write(reinterpret_cast<const char*>(&freq[i]), sizeof(freq[i]));

		// Запись сжатых данных
		file.open(fileName, std::ios::binary);
		std::string buffer = "";
		while (file.read(reinterpret_cast<char*>(&byte), sizeof(byte))) {
			buffer += hf_tree.getCode(byte);
			while (buffer.size() >= 8) {
				unsigned char compByte = 0;
				for (int i = 0; i < 8; ++i)
					if (buffer[i] == '1')
						compByte += static_cast<unsigned char>(pow(2, 7 - i));
				out.write(reinterpret_cast<char*>(&compByte), sizeof(compByte));
				buffer = buffer.substr(8);
			}
			processed++;
			updateProgress();
		}
		file.close();
		out.close();
	}
	// Сброс прогресса по завершению
	processed = 0;
	updateProgress();
}

/*
* Метод разжатия файла
*/
void Archiver::decompress(std::string fileName, std::string outName) {
	HuffmanTree hf_tree;
	std::ifstream file(fileName, std::ios::binary);
	if (file.is_open()) {
		unsigned char byte;

		// Подсчёт размера файла для вычисления прогресса
		file.seekg(0, std::ios::end);
		fsize = file.tellg();
		file.seekg(0, std::ios::beg);

		// Проверка типа файла архива
		std::string type = "";
		for (int i = 0; i < 4; i++) {
			file.read(reinterpret_cast<char*>(&byte), sizeof(byte));
			type += byte;
		}
		if (type != "GNEG") {
			file.close();
			return;
		}

		std::array<int, BYTE_MAX> freq = {};
		// Построение дерева
		for (int i = 0; i < freq.size(); i++) {
			file.read(reinterpret_cast<char*>(&freq[i]), sizeof(freq[i]));
			hf_tree.addByte(i, freq[i]); // i - байт, byte - частота
		}
		hf_tree.makeTree();

		// Создание изначального файла
		std::ofstream out(outName, std::ios::binary);
		HuffmanTree::Node* node = hf_tree.getRoot();
		while (!file.eof() && file.read(reinterpret_cast<char*>(&byte), sizeof(byte))) {
			for (int i = 0; i < 8; ++i) {
				if (byte & (1 << (7 - i))) node = node->right;
				else node = node->left;
				if (!node->left && !node->right) {
					out.write(reinterpret_cast<char*>(&node->c), sizeof(node->c));
					node = hf_tree.getRoot();
				}
			}
			processed++;
			updateProgress();
		}

		file.close();
	}
	// Сброс прогресса по завершению
	processed = 0;
	updateProgress();
}
