/**
 * @file Linear.h
 * @author Leif Anders
 * @brief   The header and implementation for the linear templated class
 * @version 0.1
 * @date 2023-02-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef _LINEAR_H_
#define _LINEAR_H_

#include <iostream>
#include <vector>

template <typename T>
class Linear {
    private:
        std::vector<T> list_;

    public:
        // constructors
        Linear() { this->list_; }
        Linear(std::vector<T> list) {this->list_ = list;}

        /**
         * @brief inserts value into linear list
         * 
         * @param val value to be inserted
         */
        void insertValue (T val){
            this->list_.push_back(val);
        }

        /**
         * @brief Get the Element At index of linear list
         * 
         * @param index index of list
         * @return T value returned from linear list
         */
        T getElementAt(int index){
            return this->list_.at(index);
        }

        /**
         * @brief searches for a value in linear list
         * 
         * @param val value to be found
         * @return true -- iff found
         * @return false -- iff not found
         */
        bool search(T val){
            for (auto i : this->list_){
                if (i == val) {return true;}
            }
            return false;
        }

        /**
         * @brief delete element from linear list
         * 
         * @param val value to be deleted
         */
        void deleteElement(T val){
            for (unsigned long int i=0; i<this->list_.size(); i++){
                if (this->list_.at(i) == val) {this->list_.erase(this->list_.begin()+i);}
            }
        }

        // returns size of list
        int getSizeOfList() {return this->list_.size(); }

        // helpers
        T getFirst() {return this->list_.at(0);}
        T getLast() {return this->list_.back();}
        T getRandom() {return this->list_.at(rand()%this->getSizeOfList());}

        // << overload
        friend std::ostream& operator<<(std::ostream&os, const Linear<T> &l){
            for (unsigned long int i=0; i<l.list_.size(); i++){
                os << l.list_.at(i) << " ";
            }
            return os;
        }

};

#endif // _LINEAR_H_

