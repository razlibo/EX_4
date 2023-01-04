/*
 * Yonatan Klein 322961764
 * Raz Leibovich 209521863
 * Data Structure EX. 4
*/
#include <iostream>
#include <string>
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
                break;
            case 2:
                try {
                    t->Decode();
                } catch (...) {
                    cout << "ERROR" << endl;
                }
                break;
        }

    } while (choice != 3);
    return 0;
}