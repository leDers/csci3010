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
#include <list>

template <typename T>
class HashMap {
    private:
        std::list<T> *map_;
        int size_;

    public:
        HashMap(std::vector<T> vals, int size){
            this->size_ = size;

            this->map_ = new list<T>[this->size_]; 
            this->map_.assign(vals.begin(), vals.end());   
        }

        int hashKey(T val){
            
        }

        void insertElement(T val){

        }

        bool search(T val){

        }

        void deleteElement(T val){
            
        }

        std::ostream&operator<<(std::ostream&os, const HashMap<T>&m);

};

#endif // _HASHMAP_H_