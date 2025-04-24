#pragma once
#include <fstream>
#include <array>
#include <map>

#define BYTE_MAX 256

class HuffmanTree {
public:
    struct Node {
        size_t p = 0;
        unsigned char c = 0;
        Node* left = nullptr,
            * right = nullptr,
            * parent = nullptr;
        ~Node() {
            if (left) delete left;
            if (right) delete right;
            if (parent) delete parent;
        }
    };
private:
    Node* trees[BYTE_MAX];
    std::map<unsigned char, std::string> codes;
    std::array<int, BYTE_MAX> freq;
    Node* root;

    void makeTree(int&);
    void buildCodes(Node*, const std::string&);

public:
    HuffmanTree();
    ~HuffmanTree();
    void addByte(unsigned char, int = 1);
    void makeTree();
    std::string getCode(unsigned char);
    std::array<int, BYTE_MAX> HuffmanTree::getFreq() const;
    Node* getRoot();
};
