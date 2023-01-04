#ifndef EX_4_HUFFMANNODE_H
#define EX_4_HUFFMANNODE_H

#include <queue>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

// Class to represent node in the Huffman tree
class HuffmanNode {
public:
    string str;
    int frequency;
    HuffmanNode *left, *right, *parent;
    friend class CompareNode;
    HuffmanNode(string s, int f, HuffmanNode* l, HuffmanNode* r,HuffmanNode* p);
    HuffmanNode();
};

// class for comparing the frequency of the nodes for the priority queue
class CompareNode {
public:
    bool operator()(HuffmanNode *const &n1, HuffmanNode *const &n2)
    {
        return n1->frequency > n2->frequency;
    }

};

#endif //EX_4_HUFFMANNODE_H
