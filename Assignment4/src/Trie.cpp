
// Ecem Cirakoglu b21821665

#include "Trie.h"

Trie::Trie() {
    root = new Node();
}

void Trie::insertKey(string key, string value) {
    Node* current = root;
    for(int i = 0; i < key.length(); i++){
        if(current->pointers[indexOfLetter(key[i])] == nullptr){
            current->pointers[indexOfLetter(key[i])] = new Node();
        }

        if(i == key.length() - 1){
            if(current->pointers[indexOfLetter(key[i])]->value == value)
                //The given dothraki is already in trie
                out << '\"' << key << '\"' << " already exist" << endl;
            else if(current->pointers[indexOfLetter(key[i])]->value != "")
                out << '\"' << key << '\"' << " was updated" << endl;
            else
                out << '\"' << key << '\"' << " was added" << endl;

            current->pointers[indexOfLetter(key[i])]->value = value;
        }

        current = current->pointers[indexOfLetter(key[i])];
    }
}

void Trie::searchKey(string key) {
    Node *current = root;

    for (int i = 0; i < key.length(); i++) {
        if (current->pointers[indexOfLetter(key[i])] == nullptr) {
            if(i == 0)
                //first n char of the k is not referenced by the root node
                out << "\"no record\"" << endl;
            else
                // first n char of the k exist on the tree, but the reminder is not
                out << "\"incorrect Dothraki word\"" << endl;
            return;
        }

        if (i == key.length() - 1) {
            if(current->pointers[indexOfLetter(key[i])]->value == "")
                //if all chars of the k exist on the tree but the last char has
                // no English equivalent
                out << "\"not enough Dothraki word\"" << endl;
            else
                out << "\"The English equivalent is " + current->pointers[indexOfLetter(key[i])]->value + '\"' << endl;
            return;
        }
        //I assigned in every loop the currents pointers element to current
        current = current->pointers[indexOfLetter(key[i])];
    }
}

void Trie::deleteKey(string key) {
    Node *current = root;
    for (int i = 0; i < key.length(); i++) {
        if (current->pointers[indexOfLetter(key[i])] == nullptr) {
            if(i == 0)
                //first char of k is not referenced by the root node
                out << "\"no record\"" << endl;
            else
                //if the first n char of k exist on the tree but the remainder is not
                out << "\"incorrect Dothraki word\"" << endl;
            return;
        }

        if (i == key.length() - 1) {
            if(current->pointers[indexOfLetter(key[i])]->value == "")
                out << "\"not enough Dothraki word\"" << endl;
            else {
                if(current->pointers[indexOfLetter(key[i])]->hasAnyChild()){ // Node toBeDeleted have child
                    current->pointers[indexOfLetter(key[i])]->value = "";
                }else{ // Node toBeDeleted don't have child
                    current->pointers[indexOfLetter(key[i])]->value = "";
                    deleteHelper(key);
                }
                out << "\"" << key << "\" deletion is successful" << endl;
            }
            return;
        }
        current = current->pointers[indexOfLetter(key[i])];
    }
}
//Recursive method for to delete in an easy way the pointers element
void Trie::deleteHelper(string key) {
    Node *current = root;
    for (int i = 0; i < key.length(); i++) {
        if (i == key.length() - 1) {
            if(current->pointers[indexOfLetter(key[i])]->value == "" && !current->pointers[indexOfLetter(key[i])]->hasAnyChild()){
                delete(current->pointers[indexOfLetter(key[i])]);
                current->pointers[indexOfLetter(key[i])] = nullptr;

                deleteHelper(key.substr(0, key.length() - 1));
            }
        }
        current = current->pointers[indexOfLetter(key[i])];
    }
}
//Displaying the dict.
//Listing by words' preorder traversal
void Trie::list() {
    Node *current = root;
    int tabCount = 0;
    for(int i = 0; i < 26; i++){
        if(root->pointers[i] != nullptr){
            string currentWord;
            currentWord.push_back(letterOfIndex(i));
            listRecursive(root->pointers[i], tabCount, currentWord);
        }
    }
}
//If a brach have different values code display with one tab
//If no brach just one tab
//
string Trie::listRecursive(Node *curr, int tabCount, string currentWord) {
    string result = "";

    if(curr->childCount() > 1){
        out << createTabs(tabCount) << '-' << currentWord;
        tabCount++;
        if(curr->value != "")
            out << '(' << curr->value << ')';
        out << endl;
    }else if(curr->value != ""){
        out << createTabs(tabCount) << '-' << currentWord;
        if(curr->value != "")
            out << '(' << curr->value << ')';
        out << endl;
    }

    for(int i = 0; i < 26; i++){
        if(curr->pointers[i] != nullptr){
            string newWord = currentWord;
            newWord.push_back(letterOfIndex(i));
            listRecursive(curr->pointers[i], tabCount, newWord);
        }
    }

    return result;
}
//Output.txt tabs
//If there is no branch no need a new tab

string Trie::createTabs(int tabCount){
    string result;
    for(int i = 0; i < tabCount; i++)
        result.push_back('\t');
    return result;
}

//Looks for index of letter
int Trie::indexOfLetter(char c) {
    return c - 97;
}

Trie::~Trie() {
    delete root;
}
//It searchs indexes' letter
char Trie::letterOfIndex(int i) {
    char c = i + 97;
    return c;
}
//Constructor and destructor
Node::Node() {
    value = "";
    for(int i = 0; i < 26; i++)
        pointers[i] = nullptr;
}
Node::~Node() {
    for(int i = 0; i < 26; i++){
        if(pointers[i] != nullptr)
            delete pointers[i];
    }
}
//This method looks for the node has any child or not
bool Node::hasAnyChild() {
    for(int i = 0; i < 26; i++){
        if(pointers[i] != nullptr)
            return true;
    }
    return false;
}
//It calculates child count
int Node::childCount() {
    int result = 0;
    for(int i = 0; i < 26; i++){
        if(pointers[i] != nullptr)
            result++;
    }
    return result;
}
