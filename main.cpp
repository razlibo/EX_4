#include <iostream>
#include <queue>
#include <list>
#include <string>
#include <cmath>
#include "HuffmanTree.h"

using namespace std;

int main() {
    int choice;
    string word;
    HuffmanTree *t;
    cout << "enter 1 to encode a text\n";
    cout << "enter 2 to decode a text\n";
    cout << "enter 3 to exit\n";

    do {
        t = new HuffmanTree();
        cin >> choice;
        switch (choice) {
            case 1:

                cout << "enter the original text" << endl;
                cin >> word;
                t->encode(word);
                //Build Huffman tree given the data inside "word".
                //Then find the code of each letter.
                //Then print the output - number of leaves, order of letters, tree structure and the encoded text - according to the explanation in the exercise.

                break;
            case 2:
                try {
                    t->Decode();
                } catch (...) {
                    cout << "ERROR" << endl;
                }
                break;
                //input the number of leaves, the  order of letters, tree structure and the encoded text.
                //build the Huffman Tree according to the tree strcture. put the letters in the leaves according to the given order.
                //Given the Huffman Tree and the encoded text, find the original text, and print it.
        }

    } while (choice != 3);
    return 0;
}