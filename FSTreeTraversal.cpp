#include <string>
#include "FSTree.h"
#include "DirNode.h"
#include <vector>
#include <iostream>

using namespace std;

void traverseTree(std::string directory);
void traverseTreeHelper(DirNode *node, std::vector<string>& path);

void traverseTree(std::string directory){
    FSTree myTree(directory);
    DirNode *root = myTree.getRoot();
    std::vector<string> path;
    traverseTreeHelper(root, path);
}

void traverseTreeHelper(DirNode *node, std::vector<string>& path){
    if (node->isEmpty()){
        return;
    }

    path.push_back(node->getName());

    if (node->hasFiles()) {
        for(int i = 0; i<node->numFiles(); i++){
            path.push_back(node->getFile(i));
            int pathSize = path.size();
            for (int j = 0; j < pathSize; j++) {
                std::cout << path[j];
                if (j != pathSize - 1){
                    std::cout << "/";
                }
            }
            path.pop_back();
            std::cout << std::endl;
        }
    }
        if(node->hasSubDir()){
            for(int i = 0; i<node->numSubDirs(); i++){
                traverseTreeHelper(node->getSubDir(i), path);
            }
        }

    path.pop_back();
}


int main(int argc, char *argv[]){
    if(argc == 2){
        traverseTree(argv[1]);
    }else{
        std::cerr << "Usage: ./treeTraversal inputDirectory" << endl;
    }
}
