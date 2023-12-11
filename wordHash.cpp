/*
 *  wordHash.cpp
 *  Cullen McCaleb & Frank Li
 *  12/06
 *
 *  CS 15 Project 4 Gerp
 *
 *  File Purpose:
 *  This file contains the implementation of the wordHash class, which creates
 *  and fills a hashMap according to the data in agiven directory.
 *
 */

#include "FSTree.h"
#include "DirNode.h"
#include "stringProcessing.h"
#include "wordHash.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <istream>

//empty constructor
wordHash::wordHash() {

}

//constructor
wordHash::wordHash(string dirName) {
    directory = dirName;
    FSTree tempTree(directory);
    //use of copy contructor
    tree = tempTree;
}

//assignment operator
wordHash &wordHash::operator=(const wordHash &other){

    //check if both objects are the exact same
    if(this == &other){
        return *this;
    }

    tree = other.tree;
    directory = other.directory;
    
    return *this;
}

//copy constructor
wordHash::wordHash(const wordHash &other){
    tree = other.tree;
    directory = other.directory;
}

/* traverseTree()
* Purpose: Creates a tree from a given directory, and prints every path in 
           that tree, from the directory name to the file name
* Input: A string representing the directory name.
* Return: Nothing
*/
void wordHash::traverseTree(){
    int fileCounter = 0;
    std::vector<string> tempPath;
    traverseTreeHelper(tree.getRoot(), tempPath);
    for(size_t i = 0; i<paths.size(); i++){
        insertWords(paths[i]);
    }
}

/* traverseTreeHelper()
* Purpose: Helps traverseTree to print each root-leaf path in the FSTree.
           This is a recursive function.
* Input: A pointer to a dirNode, and a reference to a vector containing the 
         names of every file in the paths.
* Return: Nothing
*/
void wordHash::traverseTreeHelper(DirNode *node, std::vector<string>& tempPath){

    if (node->isEmpty()){
        return;
    }

    tempPath.push_back(node->getName());

    if (node->hasFiles()) {
        for(int i = 0; i<node->numFiles(); i++){
            tempPath.push_back(node->getFile(i));
            int pathSize = tempPath.size();
            for (int j = 0; j < pathSize; j++) {
                if(j == 0){
                    paths.push_back("");
                }
                paths.back() += tempPath[j];
                if (j != pathSize - 1){
                    paths.back() += "/";
                }
            }
            //call insert command here, with tempPath.back() as directory name
            //insertWords(tempPath.back());
            //std::cout << tempPath.back() << endl;
            tempPath.pop_back();
            
        }
    }
        if(node->hasSubDir()){
            for(int i = 0; i<node->numSubDirs(); i++){
                traverseTreeHelper(node->getSubDir(i), tempPath);
            }
        }

    tempPath.pop_back();
}  

 /* TODO - IMPORTANT
        - use stringProcessing on the word
        - figure out how to keep track of pathNum
        - CHECK if word exists in the hash before adding it to the hash
        - remember to keep the outer hash key as lowercase, and the inner 
          hash key as case sensitive
    */
void wordHash::insertWords(std::string filename) {
    std::ifstream myfile;
    myfile.open(filename);
    //check if the file is open
    if(myfile.fail()) {
        std::cerr << "error opening file \n";
        return;
    }else{
        std::cout << "opened the file" << endl;
    }
    //variables
    std::string word;
    std::string line;
    int lineNum = 0; // track line num
    //read lines
    while (std::getline(myfile, line)) {
        lineNum++;
        //copy the line into istream
        std::istringstream s(line); 
        //read words from line
        while(getline(s, word, ' ')) {
            //change word to lowercase
            std::string lower = toLower(word);
            //remove the non-letters/numbers
            word = stripNonAlphaNum(word);

            //check for collisions
            //if(mainHash.get(lower).get(word).lineNum == lineNum) {
            //    std::cerr << "collision with " << word << std::endl;
            //}

            //insert word into hash
            //create a vector of word instances
            
            addToHash(lower, word, lineNum);
        }
    }
}

std::string wordHash::toLower(std::string &word) {
   std::string lowercase = word;
    for (char& c : lowercase) {
        if (c >= 'A' && c <= 'Z') {
            c = c + ('a' - 'A');
        }
    }
    return lowercase;
}

void wordHash::addToHash(std::string lower, std::string word, int lineNum) {
    if(!mainHash.inHash(lower)){
        HashMap<std::string, vector<wordInstance>> minHash;
        vector<wordInstance> wordInstances;
        //create a wordInstance with lineNum and 0 for pathNum
        wordInstance instance{0, lineNum};
        wordInstances.push_back(instance);
        minHash.insert(word, wordInstances);
        mainHash.insert(lower, minHash);
        std::cout << "successfully added" << word << endl;
    }else{
        //check if the case sensitive word is in the second hash
        if(mainHash.get(lower).inHash(word)){
            //create a word instance of the new word
            wordInstance instance{0, lineNum};
            mainHash.get(lower).get(word).push_back(instance);
            std::cout << "successfully added" << word << endl;
        }else{
            //else, the case sensitive word does not exist yet
            vector<wordInstance> wordInstances;
            wordInstance instance{0, lineNum};
            wordInstances.push_back(instance);
            mainHash.get(lower).insert(word, wordInstances);
            std::cout << "successfully added" << word << endl;
        }
    }
}
