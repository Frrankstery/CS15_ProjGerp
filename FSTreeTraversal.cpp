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
        std::cout << "Path: ";
        for(int i = 0; i<node->numFiles(); i++){
            path.push_back(node->getFile(i));
        }
        int pathSize = path.size();
        for (int i = 0; i < pathSize; i++) {
            std::cout << path[i];
            if (i != pathSize - 1){
                std::cout << " -> ";
            }
        }
        for(int i = 0; i<node->numFiles(); i++){
            path.pop_back();
        }
        std::cout << std::endl;
    } else {
        if(node->hasSubDir()){
            for(int i = 0; i<node->numSubDirs(); i++){
                traverseTreeHelper(node->getSubDir(i), path);
            }
        }
    }

    path.pop_back();
}
