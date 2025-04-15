#include <iostream>

class HaffmanTree {
private:
    struct Node {
        char c;
        int p;
        Node *left, *right, *parent;
    };

    Node *trees[256], *symbols[256];
    int count;

    void makeTree(int col) {
        if (col > 1) {
            int min1 = 2000000000, min2 = 2000000000;
            int n1 = 0, n2 = 0;
            for (int i = 0; i < count; i++) {
                if (trees[i] != NULL && trees[i]->p < min1)
                    n1 = i; min1 = trees[i]->p;
            }
            for (int i = 0; i < count; i++) {
                if (trees[i] != NULL && trees[i]->p < min2 && i != n1)
                    n2 = i; min2 = trees[i]->p;
            }

            Node* tmp = new Node;
            tmp->left = trees[n1]; tmp->right = trees[n2];
            tmp->p = trees[n1]->p + trees[n2]->p;
            tmp->parent = NULL;
            trees[n1]->parent = tmp; trees[n2]->parent = tmp;
            trees[n1] = tmp; trees[n2] = NULL;

            makeTree(col - 1);
        }
    }

public:
    HaffmanTree(int col) {
        count = col;
    }

    void readInfo() {
        for (int i = 0; i < count; i++) {
            trees[i] = new Node;
            symbols[i] = trees[i];
            std::cout << "Enter symbol: "; std::cin >> trees[i]->c;
            std::cout << "Enter frequiency: "; std::cin >> trees[i]->p;
            trees[i]->left = NULL;
            trees[i]->right = NULL;
            trees[i]->parent = NULL;
        }
    }

    void show() {
        std::cout << count << std::endl;
        makeTree(count);
        if (count == 1) std::cout << symbols[0]->c << " - " << 0;
        else {
            for (int i = 0; i < count; i++) {
                std::string code = "";
                Node* tmp = symbols[i];
                while (tmp->parent != NULL) {
                    if (tmp == tmp->parent->left)
                        code = "0" + code;
                    else
                        code = "1" + code;
                    tmp = tmp->parent;
                }
                std::cout << symbols[i]->c << " - " << code << std::endl;
            }
        }
    }
};

int main() {
    HaffmanTree hf(5);
    hf.readInfo();
    hf.show();
    return 0;
}