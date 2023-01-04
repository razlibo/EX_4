#include <algorithm>
#include "HuffmanTree.h"
#include <map>


void HuffmanTree::encode(string str) {
    if(str.empty())
        return;
    pQueue = buildQ(pQueue,str);

    int size = pQueue.size();
    cout<<"The encoded string is"<<endl<<size<<endl;

    root = buildHuffmanTree(pQueue);
    inOrder(root);
    cout<<endl;
    string treeStructure = "";
    FindTreeStructure(*root,treeStructure);
    cout<<treeStructure<<endl;
    string strForDecode = "";
    strForDecode = BuildStrForDecode(*(&root),str,strForDecode);
    cout<<strForDecode<<endl;
}

void HuffmanTree::inOrder(HuffmanNode *current) {
    if (current)
    {
        inOrder(current->left);
        cout << current->str;
        inOrder(current->right);
    }
}

void HuffmanTree::FindTreeStructure(HuffmanNode current, string &s) {
    if(!current.left && ! current.right)
    {
        s += '1';
    } else{
        s += '0';
        FindTreeStructure(*current.left,s);
        FindTreeStructure(*current.right,s);
    }
}

HuffmanTree::HuffmanTree()  {
    root = new HuffmanNode();
    pQueue = *new priority_queue<HuffmanNode*, vector<HuffmanNode*>,CompareNode>;
}

HuffmanNode *HuffmanTree::FindPath(HuffmanNode *current, char c) {

    if(current != nullptr) {
        if (current->str.front() == c)
            return current;
        else {
            auto p = FindPath(current->right,c);
            if(p == nullptr)
                p = FindPath(current->left, c);
            return p;
        }
    }
    else
        return nullptr;
}

string HuffmanTree::BuildStrForDecode(HuffmanNode *current, string str, string &s) {
    for(int i = 0; i < str.size(); i++)
    {
        auto p = FindPath(current,str[i]);
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

priority_queue<HuffmanNode *, vector<HuffmanNode *>, CompareNode>
HuffmanTree::buildQ(priority_queue<HuffmanNode *, vector<HuffmanNode *>, CompareNode> &pQ, string str) {
    map<char,int> map;
    while (!str.empty())
    {
        char word = str.back();
        str.pop_back();
        map[word]++;
    }
    for(auto x:map)
    {
        if(x.second > 0)
        {
            string word(1,x.first);
            auto* temp = new HuffmanNode(word,x.second, nullptr, nullptr, nullptr);
            pQ.push(temp);
        }
    }
    return pQ;
}

HuffmanNode *HuffmanTree::buildHuffmanTree(priority_queue<HuffmanNode *, vector<HuffmanNode *>, CompareNode> pQ) {
    int size = pQ.size();
    for(int i = 0; i < size-1; i++)
    {
        auto p1 = pQ.top();
        pQ.pop();
        auto p2 = pQ.top();
        pQ.pop();
        HuffmanNode* temp = new HuffmanNode("", p1->frequency + p2->frequency, p1, p2, nullptr);
        p1->parent = temp;
        p2->parent = temp;
        pQ.push(temp);
    }
    auto p = pQ.top();
    pQ.pop();
    return p;
}

// Function to decode given encoded string
void HuffmanTree::Decode() {
    int numberOfLetters;
    string letters, treeStructure, encodedText;
    cout << "enter n" << endl;
    cin >> numberOfLetters;
    cout << "enter the letters" << endl;
    cin >> letters;
    cout << "enter the encoded structure" << endl;
    cin >> treeStructure;

    // if the structure don't fit to number of letters
    int count = count_if(treeStructure.begin(), treeStructure.end(),[](char a){return a == '1';});
    if(count != numberOfLetters)
        throw "ERROR";
    cout << "enter the encoded text" << endl;
    cin >> encodedText;
    cout << "The decoded string is" << endl;

    // call to build the tree
    BuildTreeFromStructure(treeStructure, letters, root);
    string decodedText;

    //decoding
    while (!encodedText.empty()){
        decodedText += FindNextLetter(encodedText, root);
    }
    cout << decodedText<<endl;

}
// Recursive function to build the huffman tree
void HuffmanTree::BuildTreeFromStructure(string &treeStructure, string &letters, HuffmanNode* node) {
    if(treeStructure.empty()) return; // if we're done
    if(treeStructure[0] == '1') { // if the node is a leaf
        node->str = letters[0];
        letters.erase(0,1);
        treeStructure.erase(0,1);
        return;
    }else if(treeStructure[0] == '0') { // if the node isn't a leaf
        node->left = new HuffmanNode();
        node->right = new HuffmanNode();
        treeStructure.erase(0, 1);
        // calling the function for the children
        BuildTreeFromStructure(treeStructure, letters, node->left);
        BuildTreeFromStructure(treeStructure, letters, node->right);
    }else{ // if the tree structure string include symbols other than 0 or 1
        throw "ERROR";
    }
}

// Find the next letter in the string by the given tree
string HuffmanTree::FindNextLetter(string& encodedText,HuffmanNode *node) {
    while(node->str.empty()){ // if the node isn't a leaf
        if(encodedText[0] == '0'){
            node = node->left;
            encodedText.erase(0,1);
        }else if (encodedText[0] == '1'){
            node = node->right;
            encodedText.erase(0,1);
        } else{// if the encoded string include symbols other than 0 or 1
            throw "ERROR";
        }
    }
    return node->str;
}

HuffmanTree::~HuffmanTree() {
    if (root != nullptr)
        clear(root);
    root = nullptr;
}

void HuffmanTree::clear(HuffmanNode *current) {
    if (current)
    {    // Release memory associated with children
        if (current->left)
            clear(current->left);
        if (current->right)
            clear(current->right);
        delete current;
    }
}













