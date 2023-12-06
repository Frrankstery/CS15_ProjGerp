

#ifndef _WORD_HASH_
#define _WORD_HASH_

#include "FSTree.h"
#include "DirNode.h"
#include "stringProcessing.h"


class wordHash {
public:
wordHash(string dirName);



private:
std::string directory;
DirNode *createTree(string dirName);

}

#endif