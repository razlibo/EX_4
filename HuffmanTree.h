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


public:
    HuffmanTree();
    void encode(string str);
    void preOrder(HuffmanNode* current);//preorder
    void Decode(int numberOfLetters, string letters, string treeStructure, string encodedText);
    void BuildTreeFromStructure(string&, string&, HuffmanNode*);
    string FindNextLetter(string&, HuffmanNode*);
};


#endif //EX_4_HUFFMANTREE_H
