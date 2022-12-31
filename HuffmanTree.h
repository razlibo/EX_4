//
// Created by 97253 on 28/12/2022.
//

#ifndef EX_4_HUFFMANTREE_H
#define EX_4_HUFFMANTREE_H
#include "HuffmanNode.h"
class HuffmanTree {
private:
    priority_queue<HuffmanNode*, vector<HuffmanNode*>,	CompareNode> pQueue;

    string process(string str,char c){str.push_back(c);return str;};
    HuffmanNode buildHuffmanTree( priority_queue<HuffmanNode*, vector<HuffmanNode*>,	CompareNode> &pQueue);
public:
    HuffmanTree();
    void encode(string str);
    void preOrder(HuffmanNode current,string& s);//preorder
    void Decode(int numberOfLetters, string letters, string treeStructure, string encodedText);
    void BuildTreeFromStructure(string&, string&, HuffmanNode*);
    string FindNextLetter(string&, HuffmanNode*);
};


#endif //EX_4_HUFFMANTREE_H
