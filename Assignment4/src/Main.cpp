
// Ecem Cirakoglu b21821665

#include <fstream>
#include <iostream>
#include "Trie.h"

using namespace std;

//Reading line by line the input file
void readInput(string sourceName, Trie* trie){
    fstream sourceFile;
    sourceFile.open(sourceName, ios::in);
    if(!sourceFile.is_open()){
        cout << "File couldn't be opened!" << endl;
        return;
    }

    //If-else condition for operation
    //I created an string for to keep inputs element
    string input;
    while(getline(sourceFile, input)){
        string funcName = input.substr(0, input.find('('));
        if(funcName == "insert"){
            string key = input.substr(input.find('(') + 1, input.find(',') - input.find('(') - 1);
            string value = input.substr(input.find(',') + 1, input.find(')') - input.find(',') - 1);

            trie->insertKey(key,value);
        }else if(funcName == "search"){
            string key = input.substr(input.find('(') + 1, input.find(')') - input.find('(') - 1);

            trie->searchKey(key);
        }else if(funcName == "delete"){
            string key = input.substr(input.find('(') + 1, input.find(')') - input.find('(') - 1);

            trie->deleteKey(key);
        }else if(funcName == "list"){
            trie->list();
        }else{
            //If there is something different than defined operations code gives an error
            cout << "Unknown function detected -> " << funcName << endl;
            return;
        }
    }
    sourceFile.close();
}

int main(int argc, char **argv) {
    //Taking files from command-line as arguman
    string source = argv[1];
    string destination = argv[2];

    Trie* trie = new Trie();
    //Reading line by line
    readInput(source, trie);

    string result = trie->out.str();

    fstream destFile;
    //Opening the output file
    destFile.open(destination, ios::out);
    if(!destFile.is_open()){
        cout << "File couldn't be opened!" << endl;
        return -1;
    }

    destFile << result;
    //Deleting the temp trie
    delete trie;
    destFile.close();
    return 0;
}
