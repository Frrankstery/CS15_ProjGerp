#include <iostream>
#include <string>
#include "DirNode.h"
#include "FSTree.h"
#include "wordHash.h"
#include "searchDir.h"
#include "HashMap.cpp"

int main(int argc, char *argv[]){
    //check that the correct number of arguments are given
    if(argc != 2){
        std::cerr << "Usage: ./gerp inputDirectory outputFile" << endl;
        return EXIT_FAILURE;
    }
    searchDir gerp;
    gerp.runGerp(argv[1]);
    
    return 0;
}