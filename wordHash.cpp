#include "FSTree.h"
#include "DirNode.h"
#include "stringProcessing.cpp"
#include "wordHash.h"

#include <iostream>
#include <fstream>
#include <istream>

wordHash::wordHash(string dirName) {
    directory = dirName;
}

DirNode wordHash::createTree() const{
    FSTree tree(directory);
    return *tree.getRoot();
}

/* traverseTree()
* Purpose: Creates a tree from a given directory, and prints every path in 
           that tree, from the directory name to the file name
* Input: A string representing the directory name.
* Return: Nothing
*/
void wordHash::traverseTree(std::string directory){
    FSTree myTree(directory);
    DirNode *root = myTree.getRoot();
    std::vector<string> path;
    traverseTreeHelper(root, path);
}

/* traverseTreeHelper()
* Purpose: Helps traverseTree to print each root-leaf path in the FSTree.
           This is a recursive function.
* Input: A pointer to a dirNode, and a reference to a vector containing the 
         names of every file in the paths.
* Return: Nothing
*/
void wordHash::traverseTreeHelper(DirNode *node, std::vector<string>& path){
    if (node->isEmpty()){
        return;
    }

    path.push_back(node->getName());

    if (node->hasFiles()) {
        for(int i = 0; i<node->numFiles(); i++){
            path.push_back(node->getFile(i));
            int pathSize = path.size();
            for (int j = 0; j < pathSize; j++) {
                if(j == 0){
                    paths.push_back("");
                }
                paths.back() += path[j];
                if (j != pathSize - 1){
                    paths.back() += "/";
                }
            }
            path.pop_back();
        }
    }
        if(node->hasSubDir()){
            for(int i = 0; i<node->numSubDirs(); i++){
                traverseTreeHelper(node->getSubDir(i), path);
            }
        }

    path.pop_back();
}

//remember to return hash
void wordHash::insert(std::string filename) {
    ifstream myfile;
    
    myfile.open(filename);
    if(myfile.fail()) {
        cerr << "error opening file \n";
        return;
    }
    std::string word;
    std::string line;
    int lineNum = 0; // track lin num

    while (getline(myfile, line)) {
        lineNum++;
        line >> word;
        stripNonAlphaNum(word); //remove the non-letter characters from the word

    }

    
    



    
    




}

DirNode *findKey(std::string value) {

}
void readFile(std::string filename) {

}
