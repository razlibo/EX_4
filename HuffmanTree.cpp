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
