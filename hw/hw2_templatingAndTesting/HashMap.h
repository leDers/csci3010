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
        std::list<T> *map_;
        int size_;

    public:
        HashMap(std::vector<T> vals, int size){
            this->size_ = size;

            map_ = new std::list<T>[this->size_]; 

            for (auto i : vals){
                this->insertElement(i);
            }
        }

        int hashKey(T val){
            std::hash<T> hash_val;
            return hash_val(val)%this->size_;
        }

        void insertElement(T val){
            int i = hashKey(val);
            map_[i].push_back(val);
        }

        bool search(T val){
            for (int i=0; i<this->size_; i++){
                for ( auto j : map_[i]){
                    if (j == val) {return true;}
                }
            }
            return false;
        }

        void deleteElement(T val){
            int i = hashKey(val);

            typename std::list<T> :: iterator j;

            for ( j=map_[i].begin(); j!= map_[i].end(); j++){
                if ( *j == val ) { break; }
            }

            if ( j != map_[i].end()) { map_[i].erase(j); }
        }

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