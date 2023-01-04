//
// Created by 97253 on 28/12/2022.
//

#include "HuffmanNode.h"


HuffmanNode::HuffmanNode() {
    str = "";
    frequency = 0;
    left = nullptr;
    right = nullptr;
    parent = nullptr;
}


HuffmanNode::HuffmanNode(string s, int f, HuffmanNode *l, HuffmanNode *r, HuffmanNode *p) {
    str = s;
    frequency = f;
    left = l;
    right = r;
    parent = p;
}


