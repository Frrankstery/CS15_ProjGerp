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
 *  project. This class offers an insert function and two get function, to
 *  interact with the hash map. 
 * 
 * NOTE: There are two get functions, one for constant values and the other 
 *       for non-constant values.
 * 
 *  HashMap is in one file, and not split into a .h and .cpp file, since it 
 *  requires the use of a template.
 *
 */

#ifndef _HASH_MAP_
#define _HASH_MAP_

#include <iostream>
#include <vector>
#include <list>
#include <functional>

//use a template for the HashMap class
template <typename K, typename V>
class HashMap {
public:
    /* HashMap()
    * Purpose: Constructor for HashMap to make the size of the map 1.
    * Input: Nothing
    * Return: Nothing
    */
    HashMap(){
        map.resize(1);
    } 

    /* insert()
    * Purpose: Insert key-value pair into the map.
    * Input: a const reference to a key, and a const reference to a value
    * Return: Nothing
    */
    void insert(const K& key, const V& value) {
        //create hash index for the key
        int index = hash(key);
        //create the new node
        Node newWord{key, value};

        //go through the value vector for the given key's index
        for (size_t i = 0; i<map[index].size(); i++) {
            //if the key already exists, update its value
            if (map[index][i].key == key) {
                map[index][i].value = value;
                return;
            }
        }

        // Add the new node to the hashMap
        map[index].push_back(newWord);
    }
    
    /* get()
    * Purpose: Get a non-constant value from a given key.
    * Input: A constant reference to a key.
    * Return: A reference to the value.
    */
    V& get(const K& key) {
        //default-initialized value for V
        static V default_value = V{};

        //create hash index for the key
        int index = hash(key);

        //go through the value vector for the given key's index
        for (size_t i = 0; i<map[index].size(); i++) {
            //if the key already exists, return its value
            if (map[index][i].key == key) {
                return map[index][i].value;
            }
        }
        //key not found, return a null V
        return default_value;
    }

    /* get()
    * Purpose: Get a constant value from a given key.
    * Input: A constant reference to a key.
    * Return: A reference to the value.
    */
    const V& get(const K& key) const {
        //default-initialized value for V
        static V default_value = V{};

        //create hash index for the key
        int index = hash(key);

        //go through the value vector for the given key's index
        for (size_t i = 0; i<map[index].size(); i++) {
            //if the key already exists, return its value
            if (map[index][i].key == key) {
                return map[index][i].value;
            }
        }
        //key not found, return a null V
        return default_value;
    }

    /* inHash()
    * Purpose: Find out if the value is in the hashmap or not.
    * Input: A constant reference to a key
    * Return: A boolean representing if the key is in the hashmap.
    */
    bool inHash(const K& key) const{
        //create hash index for the key
        int index = hash(key);
        //go through the value vector for the given key's index
        for (size_t i = 0; i<map[index].size(); i++) {
            //if the key already exists, return its value
            if (map[index][i].key == key) {
                return true;
            }
        }
        // Key not found, return a null V
        return false;
    }

    /* inHash()
    * Purpose: Returns the size of the hashmap
    * Input: Nothing
    * Return: Nothing
    */
    int size(){
        return map.size();
    }

private:
    //node to contain key-value pairs
    struct Node {
        K key;
        V value;
    };

    //vector of a vector of values (the scond vector is for chaining)
    std::vector<std::vector<Node>> map;

    //hash function for the keys
    std::hash<K> hasher;

    //hash function to get an index for the key
    int hash(const K& key) const {
        return hasher(key) % map.size();
    }
};

#endif
