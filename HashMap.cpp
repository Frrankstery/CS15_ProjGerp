/*
 *  HashMap.cpp
 *  Cullen McCaleb & Frank Li
 *  12/06
 *
 *  CS 15 Project 4 Gerp
 *
 *  File Purpose:
 *  This file contains the definitions and implementation for a HashMap class.
 *  This HashMap class creates a hash map data structure for use in the gerp
 *  project. This class offers an insert function, and get function, to
 *  interact with the hash map.
 * 
 *  HashMap is in one file, and not split into a .h and .cpp file, since it 
 *  requires the use of a template.
 *
 */

#include <iostream>
#include <vector>
#include <list>
#include <functional>

//use a template for the HashMap class
template <typename K, typename V>
class HashMap {
public:
    // Constructor to set the initial table size of 1
    HashMap(){
        table.resize(1);
    } 

    // Insert key-value pair into the map
    void insert(const K& key, const V& value) {
        //create hash index for the key
        int index = hash(key);
        //create the new node
        Node newWord{key, value};

        //go through the value vector for the given key's index
        for (size_t i = 0; i<table[index].size(); i++) {
            //if the key already exists, update its value
            if (table[index][i].key == key) {
                table[index][i].value = value;
                return;
            }
        }

        // Add the new node to the hashMap
        table[index].push_back(newWord);
    }
    
    // Get value associated with a given key
    V get(const K& key) const {
        //create hash index for the key
        int index = hash(key);
        //go through the value vector for the given key's index
        for (size_t i = 0; i<table[index].size(); i++) {
            //if the key already exists, return its value
            if (table[index][i].key == key) {
                return table[index][i].value;
            }
        }
        // Key not found, return a null V
        return V();
    }
    

private:
    //n to contain key-value pairs
    struct Node {
        K key;
        V value;
    };

    //vector of a vector of values (the scond vector is for chaining)
    std::vector<std::vector<Node>> table;

    //hash function for the keys
    std::hash<K> hasher;

    //hash function to get an index for the key
    int hash(const K& key) const {
        return hasher(key) % table.size();
    }

};
