#include <algorithm>
#include "HuffmanTree.h"
#include <map>

//The Function get str and encode the str using Huffman code
void HuffmanTree::encode(string str) {
    if(str.empty())//check if the str not empty
        return;
    pQueue = buildQ(pQueue,str);//build priority queue

    int size = pQueue.size();
    cout<<"The encoded string is"<<endl<<size<<endl;//print the size of the queue

    root = buildHuffmanTree(pQueue);//build the Huffman Tree
    inOrder(root);//print the word in the tree in order
    cout<<endl;
    string treeStructure = "";
    FindTreeStructure(*root,treeStructure);//get the tree structure
    cout<<treeStructure<<endl;
    string strForDecode = "";
    strForDecode = BuildStrForDecode(*(&root),str,strForDecode);//get the str for decode
    cout<<strForDecode<<endl;//print it
}

//The function moving on the tree in order and print the word
void HuffmanTree::inOrder(HuffmanNode *current) {
    if (current)
    {
        inOrder(current->left);
        cout << current->str;
        inOrder(current->right);
    }
}

//The function find the tree structure
void HuffmanTree::FindTreeStructure(HuffmanNode current, string &s) {
    if(!current.left && ! current.right)//if we got to leaf
    {
        s += '1';
    } else{//if the current node is in suction
        s += '0';
        FindTreeStructure(*current.left,s);
        FindTreeStructure(*current.right,s);
    }
}

//constructor for Huffman tree
HuffmanTree::HuffmanTree()  {
    root = new HuffmanNode();
    pQueue = *new priority_queue<HuffmanNode*, vector<HuffmanNode*>,CompareNode>;
}

//the Function get the current node and return pointer to the word c in the tree
HuffmanNode *HuffmanTree::FindPath(HuffmanNode *current, char c) {

    if(current != nullptr) {//check if the current str equal the word we got
        if (current->str.front() == c)
            return current;
        else {//if not find the word in the current node go right and then go left
            auto p = FindPath(current->right,c);
            if(p == nullptr)
                p = FindPath(current->left, c);
            return p;
        }
    }
    else//if we didn't found the word in the tree
        return nullptr;
}

//The function build the str for decode get the current node and the str and add 1 if we go left if we go right ass to s 0
string HuffmanTree::BuildStrForDecode(HuffmanNode *current, string str, string &s) {
    for(int i = 0; i < str.size(); i++)//run all the words in the str
    {
        auto p = FindPath(current,str[i]);//get pointer to the word
        string temp = "";
        while (p != current)//while we didn't get to root
        {
            auto q = p->parent;

            if(q->right == p)//check if the word is in the right of q add 1
            {
                temp.push_back('1');
            }

            else//check if the word is in the left of q add 0
            {
                temp.push_back('0');
            }
            p = q;
        }
        while (!temp.empty())//get the str for decode
        {
            s.push_back(temp.back());
            temp.pop_back();
        }
    }
    return s;
}

//The function return priority queue by count the frequency of the words in the string
priority_queue<HuffmanNode *, vector<HuffmanNode *>, CompareNode>
HuffmanTree::buildQ(priority_queue<HuffmanNode *, vector<HuffmanNode *>, CompareNode> &pQ, string str) {
    map<char,int> map;//using dictionary
    while (!str.empty())
    {
        char word = str.back();//get the word
        str.pop_back();
        map[word]++;//raise the frequency by 1
    }
    for(auto x:map)//enter to the priority queue
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

//The function get the priority queue and build the Huffman tree
HuffmanNode *HuffmanTree::buildHuffmanTree(priority_queue<HuffmanNode *, vector<HuffmanNode *>, CompareNode> pQ) {
    int size = pQ.size();
    for(int i = 0; i < size-1; i++)//run and the queue
    {
        auto p1 = pQ.top();
        pQ.pop();
        auto p2 = pQ.top();
        pQ.pop();
        HuffmanNode* temp = new HuffmanNode("", p1->frequency + p2->frequency, p1, p2, nullptr);
        p1->parent = temp;
        p2->parent = temp;
        pQ.push(temp);//push the new node white the frequency of the two nodes
    }
    auto p = pQ.top();
    pQ.pop();
    return p;//return the root
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













