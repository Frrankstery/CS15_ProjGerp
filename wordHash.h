

#ifndef _WORD_HASH_
#define _WORD_HASH_

#include "FSTree.h"
#include "DirNode.h"
#include "stringProcessing.h"
#include "HashMap.cpp"
#include <vector>


class wordHash {
    public:
        //constructors
        wordHash(string dirName);
        wordHash();
        wordHash(const wordHash &other);
        wordHash &operator=(const wordHash &other);

        //functions
        void traverseTree();
        void traverseTreeHelper(DirNode *node, std::vector<string>& path);

        //variables
        std::string directory;
        vector<std::string> paths;

        struct wordInstance{
            int pathIndex;
            int lineNum;
        };

        FSTree tree;

        void insertWords(std::string dirName);
        void addToHash(std::string lower, std::string word, int lineNum);

        //has to be public because we need wordInstance in it
        HashMap<std::string, HashMap<std::string, vector<wordInstance>>> mainHash;

    private:
    std::string toLower(std::string &word);
    /*
        //variables
        std::string directory;
        vector<string> paths;

        struct wordInstance{
            int pathIndex;
            int lineNum;
        };

        HashMap<std::string, HashMap<std::string, wordInstance>> mainHash;

    */

};

#endif
