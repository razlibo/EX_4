//
// Created by 97253 on 28/12/2022.
//

#include "HuffmanTree.h"

void HuffmanTree::preOrder(HuffmanNode *current) {
    // visit Node, left child, right child
    if (current)
    {   // process current Node
        process(current->str);
        // then visit children
        preOrder(current->right);
        preOrder(current->left);
    }

}

HuffmanTree::HuffmanTree()  {
    pQueue = *new priority_queue<HuffmanNode*, vector<HuffmanNode*>,CompareNode>;
}

void HuffmanTree::encode(string str) {

}

void HuffmanTree::Decode(int numberOfLetters, string letters, string treeStructure, string encodedText) {
    auto* root = new HuffmanNode();
    BuildTreeFromStructure(treeStructure, letters, root);
    string decodedText;
    while (!encodedText.empty()){
        decodedText += FindNextLetter(encodedText, root);
    }
    cout << decodedText;

}

void HuffmanTree::BuildTreeFromStructure(string &treeStructure, string &letters, HuffmanNode* node) {
    if(treeStructure.empty()) return;
    if(treeStructure[0] == '1') {
        node->str = letters[0];
        letters.erase(0,1);
        treeStructure.erase(0,1);
        return;
    }
    node->left = new HuffmanNode();
    node->right = new HuffmanNode();
    treeStructure.erase(0,1);
    BuildTreeFromStructure(treeStructure, letters, node->left);
    BuildTreeFromStructure(treeStructure, letters, node->right);
}

string HuffmanTree::FindNextLetter(string& encodedText,HuffmanNode *node) {
    while(node->str.empty()){
        if(encodedText[0] == '0'){
            node = node->left;
            encodedText.erase(0,1);
        }else{
            node = node->right;
            encodedText.erase(0,1);
        }
    }
    return node->str;
}


