/**
 * @file Compare.h
 * @author Leif Anders
 * @brief  Header and Implementation for template class
 * @version 0.1
 * @date 2023-02-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef _COMPARE_H_
#define _COMPARE_H_

#include <iostream>
#include <vector>

template <typename T> 
class Compare {
    private:
        std::vector<T> val_;

    public:
        Compare(std::vector<T> value) {this->val_ = value;}

        //returns all matches that are less than val
        std::vector<T> getLessThan(T val){
            std::vector<T> o;
            for (unsigned long int i=0; i<this->val_.size(); i++){
                if ( this->val_[i] < val ) { o.push_back(this->val_[i]); }
            }
            return o;
        }

        //returns all matches that are greater than val
        std::vector<T> getGreaterThan(T val){
            std::vector<T> o;
            for (unsigned long int i=0; i<this->val_.size(); i++){
                if ( this->val_[i] > val ) { o.push_back(this->val_[i]); }
            }
            return o;
        }

        //if there are exact matches, then it returns the number of matches
        int matches(T val){
            int c = 0;
            for (unsigned long int i=0; i<this->val_.size(); i++){
                if ( this->val_[i] == val ) { c++; }
            }
            return c;
        }
};

#endif // _COMPARE_H_