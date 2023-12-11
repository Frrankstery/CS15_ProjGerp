/*
 *  searchDir.cpp
 *  Cullen McCaleb & Frank Li
 *  12/07
 *
 *  CS 15 Project 4 Gerp
 *
 *  File Purpose:
 *  This file contains the implementation of the searchDirr class, which will
 *  fascillatate the output in the gerp project, using the hashMap created
 *  in the wordHash class.
 *
 */

#include "searchDir.h"

//constructor
searchDir::searchDir(){

}

void searchDir::runGerp(std::string filename){
    wordHash makeHash(filename);
    makeHash.traverseTree();
    std::string command;
    std::cout << "Query? ";
    while((cin >> command)){
        if((command == "@q") or (command == "@quit")){
            std::cerr << "Goodbye! Thank you and have a nice day." << endl;
            return;
        }else if((command == "@i") or (command == "@insensitive")){
            std::cout << "case insensitive search" << endl;
            //cin >> command
            //search for command in hash
        }else if((command == "@f")){
            std::cout << "close cur output, open new output file" << endl;
            //not sure, we'll figure it out
        }else{
            //search for command in the hash
            std::string word = makeHash.toLower(command);
            if(makeHash.mainHash.inHash(word)){
                for(size_t i = 0; i<makeHash.mainHash.get(word).get(command).size(); i++){
                    //get the path and line number
                    std::cout << makeHash.paths
                    [makeHash.mainHash.get(word).get(command)[i].pathIndex]
                    << ":" << makeHash.mainHash.get(word).get(command)
                    [i].lineNum << ": ";
                    //get the line
                    std::cout << makeHash.lines
                    [makeHash.mainHash.get(word).get(command)[i].pathIndex]
                    [makeHash.mainHash.get(word).get(command)[i].lineNum-1] 
                    << endl;
                }
            }else{
                std::cout << word << " Not Found. Try with @insensitive or @i." << endl;
            }

        }
        std::cout << "Query? ";
    }
}
