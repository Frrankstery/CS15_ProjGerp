/*
 *  unit_test.h
 *  Cullen McCaleb & Frank Li
 *  12/07
 *
 *  CS 15 Project 4 Gerp
 *
 *  This file's purpose is to test various parts of our gerp project, a 
 *  program that can search for a given word in a given directory.
 *
 */

#include "HashMap.cpp"
#include "wordHash.h"
#include "DirNode.h"
#include "FSTree.h"
#include "stringProcessing.h"
#include <string>
#include <cassert>
#include <iostream>

// testStringProcessing()
// Purpose: Tests the stringProcessing class from part one, which we'll 
//          use in part 2.
void testStringProcessing(){
    assert(stripNonAlphaNum("$$#%@frank-cullen%^*") == "frank-cullen");
    assert(stripNonAlphaNum("$$#1234^*") == "1234");
    assert(stripNonAlphaNum("$$6-afraid-7*") == "6-afraid-7");
}

// testCreateHashMap()
// Purpose: Tests if the HashMap can be constructed
void testCreateHashMap(){
    HashMap<int, int> myHash;
}

// testHashInsertAndGet()
// Purpose: Tests the insert and get functions in the HashMap class.
void testHashInsertAndGet(){
    HashMap<int, int> map;
    map.insert(1, 5);
    assert(map.get(1) == 5);
}

// testDoubleHash()
// Purpose: Tests the HashMap class when created with a hash inside a hash.
void testDoubleHash(){
    HashMap<std::string, HashMap<std::string, int>> outmap;
    HashMap<std::string, int> inmap;
    inmap.insert("found", 5);
    outmap.insert("looking", inmap);
    assert(outmap.get("looking").get("found") == 5);
}

//testHashWStruct()
// Purpose: Tests the HashMap class by created a nested HashMap with a struct 
// as the value.
void testHashWStruct(){
    struct testStruct{
        int example;
        int test;
    };
    HashMap<std::string, HashMap<std::string, testStruct>> gerpHash;
    HashMap<std::string, testStruct> dummyHash;
    testStruct newInstance{1, 2};
    dummyHash.insert("test", newInstance);
    gerpHash.insert("test", dummyHash);
    assert(gerpHash.get("test").get("test").example == 1);
    assert(gerpHash.get("test").get("test").test == 2);
}

// testCreateWordHash()
// Purpose: Tests if the wordHash class can be constructed
void testCreateWordHash(){
    wordHash myHash("proj-gerp-test-dirs/tinyData");
}

// testPopulatePaths()
// Purpose: Tests if the treeTraversal function works to populate a paths 
//          vector.
void testPopulatePaths(){
    wordHash myHash("proj-gerp-test-dirs/tinyData");
    myHash.traverseTree();
    //test the paths vector against the results of FSTreeTraversal
    assert(myHash.paths[0] == "proj-gerp-test-dirs/tinyData/hello");
    assert(myHash.paths[2] == "proj-gerp-test-dirs/tinyData/a/found");
    assert(myHash.paths[5] == 
            "proj-gerp-test-dirs/tinyData/b/c/heyLookAtMe.txt");
}
