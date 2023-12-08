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

// testCreateWordHash()
// Purpose: Tests if the wordHash class can be constructed
void testCreateWordHash(){
    wordHash myHash("proj-gerp-test-dirs/tinyData");
}