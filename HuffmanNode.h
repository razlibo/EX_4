//
// Created by 97253 on 28/12/2022.
//

#ifndef EX_4_HUFFMANNODE_H
#define EX_4_HUFFMANNODE_H

#include <queue>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class HuffmanNode {
public:
    string str;
    int frequency;
    HuffmanNode *left, *right;
    friend class CompareNode;
};

class CompareNode {
public:
    bool operator()(HuffmanNode *const &n1, HuffmanNode *const &n2)
    {
        return n1->frequency > n2->frequency;
    }

};

#endif //EX_4_HUFFMANNODE_H
