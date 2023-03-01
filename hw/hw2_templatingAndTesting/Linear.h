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
        Linear(std::vector<T> list) {this->list_ = list;}

        void insertValue (T val){
            this->list_.push_back(val);
        }

        T getElementAt(int index){
            return this->list_.at(index);
        }

        bool search(T val){
            for (auto i : this->list_){
                if (i == val) {return true;}
            }
            return false;
        }

        void deleteElement(T val){
            for (unsigned long int i=0; i<this->list_.size(); i++){
                if (this->list_.at(i) == val) {this->list_.erase(this->list_.begin()+i);}
            }
        }

        int getSizeOfList() {return this->list_.size(); }

        friend std::ostream& operator<<(std::ostream&os, const Linear<T> &l){
            for (unsigned long int i=0; i<l.list_.size(); i++){
                os << l.list_.at(i) << " ";
            }
            return os;
        }

};

#endif // _LINEAR_H_

