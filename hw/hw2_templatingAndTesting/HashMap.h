/**
 * @file HashMap.h
 * @author Leif Anders
 * @brief   Header and implementation of hashmap
 * @version 0.1
 * @date 2023-02-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef _HASHMAP_H_
#define _HASHMAP_H_

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <list>

template <typename T>
class HashMap {
    private:
        std::list<T> *map_;     // list for pairing key -> value
        int size_;              // buckets

    public:
        // defualt consturctor
        HashMap() {
            this->size_=1;
            map_ = new std::list<T>[this->size_]; 
        }
        
        // constructor
        HashMap(std::vector<T> vals, int size){
            this->size_ = size;

            map_ = new std::list<T>[this->size_]; 

            for (auto i : vals){
                this->insertElement(i);
            }
        }

        /**
         * @brief performs the hash function on the value given
         * 
         * @param val value to be hashed
         * @return int the hash value
         */
        int hashKey(T val){
            std::hash<T> hash_val;
            return hash_val(val)%this->size_;
        }

        /**
         * @brief inserts element into the hashmap
         * 
         * @param val value to be inserted
         */
        void insertElement(T val){
            int i = hashKey(val);
            map_[i].push_back(val);
        }

        /**
         * @brief searched for a value in the hashmap
         * 
         * @param val value to be searched for
         * @return true -- iff found
         * @return false -- iff not found
         */
        bool search(T val){
            int i = hashKey(val);
            for ( auto j : map_[i]){
                if (j == val) {return true;}
            }
            
            return false;
        }

        /**
         * @brief deletes element from hashtable
         * 
         * @param val value to be deleted
         */
        void deleteElement(T val){
            int i = hashKey(val);   // hash key
            typename std::list<T> :: iterator j;    // iterator

            //iterate through map's keys
            for ( j=map_[i].begin(); j!= map_[i].end(); j++){
                if ( *j == val ) { break; }
            }
            
            // if j is not the end of the mpa at this key, erase j
            if ( j != map_[i].end()) { map_[i].erase(j); }
        }

        // helpers
        T getFirst() {return this->map_->front(); }
        T getLast() {return this->map_->back(); }
        T getRandom() {return this->search(rand());}

        // << overload
        friend std::ostream&operator<<(std::ostream&os, const HashMap<T>&m){
            for (int i=0; i<m.size_; i++){
                os << i;
                for ( auto j : m.map_[i] ){
                    os << " -> " << j;
                }
                os << std::endl;
            }

            return os;
        }

};

#endif // _HASHMAP_H_