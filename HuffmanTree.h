#ifndef EX_4_HUFFMANTREE_H
#define EX_4_HUFFMANTREE_H
#include "HuffmanNode.h"

// Class for decode and encode using Huffman code
class HuffmanTree {
private:
    priority_queue<HuffmanNode*, vector<HuffmanNode*>,	CompareNode> pQueue;
    HuffmanNode* root;

    void inOrder(HuffmanNode* root);
    void FindTreeStructure(HuffmanNode current,string& s);
    HuffmanNode* FindPath(HuffmanNode* current,char c);
    string BuildStrForDecode(HuffmanNode* current,string str,string& s);
    priority_queue<HuffmanNode*, vector<HuffmanNode*>,	CompareNode> buildQ( priority_queue<HuffmanNode*, vector<HuffmanNode*>,	CompareNode>& pQ,string str);
    HuffmanNode* buildHuffmanTree(priority_queue<HuffmanNode*, vector<HuffmanNode*>,CompareNode> pQ);
    void BuildTreeFromStructure(string&, string&, HuffmanNode*);
    string FindNextLetter(string&, HuffmanNode*);
    void clear(HuffmanNode* current);
public:
    HuffmanTree();
    ~HuffmanTree();
    void encode(string str);
    void Decode();
};


#endif //EX_4_HUFFMANTREE_H
