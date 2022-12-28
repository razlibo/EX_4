//
// Created by 97253 on 28/12/2022.
//

#ifndef EX_4_COMPARENODE_H
#define EX_4_COMPARENODE_H

#include "queue"
#include "HuffmanNode.h"

class compareNode{
private:
    priority_queue<HuffmanNode*, vector<HuffmanNode*>,	compareNode> pQueue;
public:
    bool operator()(HuffmanNode* const & n1, HuffmanNode* const & n2)
    {
        return n1->frequency > n2->frequency;
    }


};



#endif //EX_4_COMPARENODE_H
