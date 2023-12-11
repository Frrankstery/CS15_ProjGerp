/*
 *  searchDir.h
 *  Cullen McCaleb & Frank Li
 *  12/07
 *
 *  CS 15 Project 4 Gerp
 *
 *  File Purpose:
 *  This file is the header file for the searchDir class, which will
 *  fascillatate the output in the gerp project, using the hashMap created
 *  in the wordHash class.
 *  There are no significant data structures in this class.
 *
 */

#include "wordHash.h"

class searchDir {
    public:
        searchDir();
        void runGerp(std::string filename);

    private:
        //wordHash gerpHash;
};