
// Ecem Cirakoglu b21821665

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

//Looks for and defined prefixtree
#ifndef PREFIXTREE
#define PREFIXTREE

class Node{
public:
    //I created the fixed size as 26
    Node* pointers[26];
    string value;
    Node();
    ~Node();
    bool hasAnyChild();
    //I created a counter for to count the children and print them belong to count
    int childCount();
};


class Trie {
public:
    Trie();
    void insertKey(string key, string value);
    void searchKey(string key);
    void deleteKey(string key);
    void list();
    ~Trie();
    ostringstream out;
private:
    Node* root;
    int indexOfLetter(char c);
    char letterOfIndex(int i);
    //For to delete h
    void deleteHelper(string key);
    string listRecursive(Node* curr, int tabCount, string currentWord);
    //For output.txt tabs
    string createTabs(int tabCount);
};
#endif
