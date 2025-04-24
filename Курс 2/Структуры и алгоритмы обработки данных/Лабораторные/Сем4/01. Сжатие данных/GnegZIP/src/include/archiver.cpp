#pragma once
#include <string>
#include <fstream>
#include <array>
#include "huffman.h"
#include "archiver.h"

void Archiver::updateProgress() {
	progress = ((float)processed / (float)fsize) * 100;
}

void Archiver::clearProgress() {
	progress = 0;
	processed = 0;
	fsize = 1;
}

int Archiver::getProgress() {
	return progress;
}

/*
* Метод сжатия файла
*/
void Archiver::compress(std::string fileName, std::string outName) {
	clearProgress();
	HuffmanTree hf_tree;
	std::ifstream file(fileName, std::ios::binary);
	file.exceptions(std::ios::badbit);

	if (file.is_open()) {

		// Подсчёт размера файла для вычисления прогресса
		file.seekg(0, std::ios::end);
		fsize = file.tellg();
		file.seekg(0, std::ios::beg);

		// Создание дерева Хаффмана из байт
		unsigned char byte;
		while (file.read((char*)(&byte), sizeof(byte)))
			hf_tree.addByte(byte);
		hf_tree.makeTree();
		file.close();

		std::ofstream out(outName, std::ios::binary);
		// Запись типа файла
		out.write(new char[4] {'G', 'N', 'E', 'G'}, 4);
		std::array<int, BYTE_MAX> freq = hf_tree.getFreq();
		for (int i = 0; i < freq.size(); i++)
			out.write((char*)(&freq[i]), sizeof(freq[i]));

		// Запись сжатых данных
		file.open(fileName, std::ios::binary);
		unsigned char compByte = 0;
		std::string buffer = "";
		while (file.read((char*)(&byte), sizeof(byte))) {
			buffer += hf_tree.getCode(byte);
			while (buffer.size() >= 8) {
				compByte = 0;
				for (int i = 0; i < 8; ++i)
					if (buffer[i] == '1')
						compByte += (unsigned char)(pow(2, 7 - i));
				out.write((char*)(&compByte), sizeof(compByte));
				buffer = buffer.substr(8);
			}
			processed++;
			updateProgress();
		}
		compByte = 0;
		for (int i = 0; i < buffer.size(); ++i)
			if (buffer[i] == '1')
				compByte += (unsigned char)(pow(2, 7 - i));
		out.write((char*)(&compByte), sizeof(compByte));
		file.close();
		out.close();
	}
	// Сброс прогресса по завершению
	clearProgress();
}

/*
* Метод разжатия файла
*/
void Archiver::decompress(std::string fileName, std::string outName) {
	clearProgress();
	HuffmanTree hf_tree;
	std::ifstream file(fileName, std::ios::binary);
	file.exceptions(std::ios::badbit);

	if (file.is_open()) {
		unsigned char byte;

		// Подсчёт размера файла для вычисления прогресса
		file.seekg(0, std::ios::end);
		fsize = file.tellg();
		file.seekg(0, std::ios::beg);

		// Проверка типа файла архива
		std::string type = "";
		for (int i = 0; i < 4; i++) {
			file.read((char*)(&byte), sizeof(byte));
			type += byte;
		}
		if (type != "GNEG") {
			file.close();
			return;
		}

		std::array<int, BYTE_MAX> freq = {};
		// Построение дерева
		for (int i = 0; i < freq.size(); i++) {
			file.read((char*)(&freq[i]), sizeof(freq[i]));
			hf_tree.addByte(i, freq[i]); // i - байт, byte - частота
		}
		hf_tree.makeTree();

		// Создание изначального файла
		std::ofstream out(outName, std::ios::binary);
		HuffmanTree::Node* node = hf_tree.getRoot();
		while (!file.eof() && file.read((char*)(&byte), sizeof(byte))) {
			for (int i = 0; i < 8; ++i) {
				if (byte & (1 << (7 - i))) node = node->right;
				else node = node->left;
				if (!node->left && !node->right) {
					out.write((char*)(&node->c), sizeof(node->c));
					node = hf_tree.getRoot();
				}
			}
			processed++;
			updateProgress();
		}

		file.close();
	}
	// Сброс прогресса по завершению
	clearProgress();
}
