/**
 * @file myClass.h
 * @author Leif Anders
 * @brief 
 * @version 0.1
 * @date 2023-03-02
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef _MYCLASS_H_
#define _MYCLASS_H_

#include <iostream>


struct myClass{
    private:
        int x_;

    public:
        myClass() {this->x_= 0; }
        myClass(int x) {this->x_ = x;}

        int get_x() const {return this->x_; }

        friend std::ostream& operator<<(std::ostream& os, const myClass& m){
            os << m.x_;
            return os;
        }

        friend bool operator== ( const myClass& lhs, const myClass& rhs){
            return (lhs.x_ == rhs.x_);
        } 

        friend bool operator< ( const myClass& lhs, const myClass& rhs){
            return (lhs.x_ < rhs.x_);
        }

        friend bool operator> ( const myClass& lhs, const myClass& rhs){
            return (lhs.x_ > rhs.x_);
        }
        
        friend bool operator<= ( const myClass& lhs, const myClass& rhs){
            return (lhs.x_ <= rhs.x_);
        }

        friend bool operator>= ( const myClass& lhs, const myClass& rhs){
            return (lhs.x_ >= rhs.x_);
        }
};

template<>
struct std::hash<myClass>
{
    std::size_t operator()(myClass const& m) const noexcept
    {
        std::size_t h1 = std::hash<int>{}(m.get_x());
        return h1 ^ (h1 << 1); // or use boost::hash_combine
    }
};

#endif // _MYCLASS_H_