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

wordHash::wordHash(string dirName) {
    directory = dirName;
    FSTree tempTree(directory);
    //use of copy contructor
    tree = tempTree;
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
            insertWords(tempPath.back());
            std::cout << tempPath.back() << endl;
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


//remember to return hash
void wordHash::insertWords(std::string filename) {
    ifstream myfile;
    
    myfile.open(filename);
    if(myfile.fail()) {
        cerr << "error opening file \n";
        return;
    }
    std::string word;
    std::string line;
    int lineNum = 0; // track lin num

    /* TODO - IMPORTANT
        - use stringProcessing on the word
        - figure out how to keep track of pathNum
        - CHECK if word exists in the hash before adding it to the hash
        - remember to keep the outer hash key as lowercase, and the inner 
          hash key as case sensitive
    */
    while (getline(myfile, line)) {
        lineNum++;  
        std::istringstream lineStream(line);  
        while(lineStream >> word){
            
            stripNonAlphaNum(word); //remove the non-letter characters from the word

            //create a hashmap in order to insert it to the mainHash
            HashMap<std::string, wordInstance> wordHash;
            //create a word instance, not sure how we are going to keep track of pathNum
            //wordInstance newInstance{, lineNum};
            //insert the word into the first hash
            //wordHash.insert(word, newInstance);
            //insert the word and firsh hash into the main hash
            mainHash.insert(word, wordHash);
        }  

    }

}   

DirNode *findKey(std::string value) {

}
void readFile(std::string filename) {

}
