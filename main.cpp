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

/*
enter 1 to encode a text
enter 2 to decode a text
enter 3 to exit
1
enter the original text
avffafffs
The encoded string is
4
asvf
0010111
000111100111010
2
enter n
4
enter the letters
asvf
enter the encoded structure
0010111
enter the encoded text
000111100111010
The decoded string is
avffafffs
3

 */