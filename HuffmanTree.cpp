//
// Created by 97253 on 28/12/2022.
//
#include <algorithm>
#include "HuffmanTree.h"

void HuffmanTree::preOrder(HuffmanNode current,string& s) {

    if(current.left)
    {
        s += '0';
         preOrder(*current.left,s);
    }
    if(!current.left && ! current.right)
    {
        s += '1';
    }
    if(current.right)
    {
       preOrder(*current.right,s);
    }

}

HuffmanTree::HuffmanTree()  {
    pQueue = *new priority_queue<HuffmanNode*, vector<HuffmanNode*>,CompareNode>;
}

HuffmanNode* findPath(HuffmanNode* current,char c)
{
    if(current != nullptr) {
        if (current->str.front() == c)
            return current;
        else {
            auto p = findPath(current->right,c);
            if(p == nullptr)
                p = findPath(current->left, c);
            return p;
        }
    }
    else
        return nullptr;

}

string build(HuffmanNode* current,string str,string& s)
{
    for(int i = 0; i < str.size(); i++)
    {
        auto p = findPath(current,str[i]);
        string temp = "";
        while (p != current)
        {
            auto q = p->parent;

            if(q->right == p)
            {
                temp.push_back('1');
            }

            else
            {
                temp.push_back('0');
            }
            p = q;
        }
        while (!temp.empty())
        {
            s.push_back(temp.back());
            temp.pop_back();
        }
    }
    return s;
}
priority_queue<HuffmanNode*, vector<HuffmanNode*>,	CompareNode> buildQ( priority_queue<HuffmanNode*, vector<HuffmanNode*>,	CompareNode>& pQ,string str)
{
    while (!str.empty())
    {
        string word(1,str.back());
        str.pop_back();
        priority_queue<HuffmanNode*, vector<HuffmanNode*>,	CompareNode>  tempQ;
        bool flag = false;
        while (!pQ.empty())
        {
            if(pQ.top()->str == word)
            {
                pQ.top()->frequency += 1;
                flag = true;
                break;
            }
            else
            {
                tempQ.push(pQ.top());
                pQ.pop();
            }
        }
        if(!flag) {
            pQ.push(new HuffmanNode(word, 1, nullptr, nullptr, nullptr));
        }
        while (!tempQ.empty())
        {
            pQ.push(tempQ.top());
            tempQ.pop();
        }

    }
    return pQ;
}
HuffmanNode buildHuffmanTree(priority_queue<HuffmanNode*, vector<HuffmanNode*>,	CompareNode> pQ)
{
    int size = pQ.size();
    for(int i = 0; i < size-1 ; i++)
    {
        auto p1 = pQ.top();
        if(!p1->str.empty())
            cout<<p1->str;
        pQ.pop();
        auto p2 = pQ.top();
        if(!p2->str.empty())
            cout<<p2->str;
        pQ.pop();
        pQ.push(new HuffmanNode("", p1->frequency + p2->frequency, p1, p2, nullptr));
        p1->parent = pQ.top();
        p2->parent = pQ.top();
    }
    return *pQ.top();
}
void HuffmanTree::encode(string str) {
    if(str.empty())
        return;
   pQueue = buildQ(pQueue,str);

    int size = pQueue.size();
    cout<<"The encoded string is:"<<endl<<size<<endl;

    auto root = buildHuffmanTree(pQueue);

    cout<<endl;
    string treeStructure = "";
    preOrder(root,treeStructure);
    cout<<treeStructure<<endl;
    string strForDecode = "";
     //strForDecode = build(*(&root),str,strForDecode);
    cout<<strForDecode<<endl;
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
    while(!node->str.empty()){
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


