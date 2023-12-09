#include "FSTree.h"
#include "DirNode.h"
#include "stringProcessing.h"
#include "wordHash.h"

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
