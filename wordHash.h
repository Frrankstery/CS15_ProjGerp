#ifndef _WORD_HASH_
#define _WORD_HASH_

#include "FSTree.h"
#include "DirNode.h"
#include "stringProcessing.h"
#include "HashMap.cpp"
#include <vector>


class wordHash {
    public:
        wordHash(string dirName);

        //functions
        DirNode createTree() const;
        void traverseTree(std::string directory);
        void traverseTreeHelper(DirNode *node, std::vector<string>& path);

        //variables
        std::string directory;
        vector<std::string> paths;

        struct wordInstance{
            int pathIndex;
            int lineNum;
        };

        //has to be public because we need wordInstance in it
        HashMap<std::string, HashMap<std::string, wordInstance>> gerpHash;


        void insertWord(std::string dirName);
        DirNode *findKey(std::string value);
        void readFile(std::string filename);

    private:
    /*
        //variables
        std::string directory;
        vector<string> paths;

        struct wordInstance{
            int pathIndex;
            int lineNum;
        };

        HashMap<std::string, HashMap<std::string, wordInstance>> gerpHash;

    */

};

#endif
