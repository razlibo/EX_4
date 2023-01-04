#include "HuffmanNode.h"

// empty constructor
HuffmanNode::HuffmanNode() {
    str = "";
    frequency = 0;
    left = nullptr;
    right = nullptr;
    parent = nullptr;
}

// constructor with values
HuffmanNode::HuffmanNode(string s, int f, HuffmanNode *l, HuffmanNode *r, HuffmanNode *p) {
    str = s;
    frequency = f;
    left = l;
    right = r;
    parent = p;
}


