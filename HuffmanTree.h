//
// Created by 97253 on 28/12/2022.
//

#ifndef EX_4_HUFFMANTREE_H
#define EX_4_HUFFMANTREE_H
#include "HuffmanNode.h"
class HuffmanTree {
private:
    priority_queue<HuffmanNode*, vector<HuffmanNode*>,	CompareNode> pQueue;
    void process(string val) { cout << val << " "; }//print the value
    int numberOfLetters;
    string letters;
    string originalText;
    string treeStructure;
    string encodedText;

public:
    void encode(string str);
    void preOrder(HuffmanNode* current);//preorder
    HuffmanTree();
};


#endif //EX_4_HUFFMANTREE_H
