/**
 * @file Product.h
 * @author Leif Anders, Andrew Scott
 * @brief header file for Product class for BidToBuy
 * @version 0.1
 * @date 2023-03-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef _PRODUCT_H_
#define _PRODUCT_H_

#include <iostream>

#include "User.h"
class User;

class Product {
    public:
      struct Bid{
        double value;
        User &buyer;
        Product &p;
      };

    private:

};

class Technology: public Product{
    public:
    
    private:

};

class Automotive: public Product{
    public:
    
    private:

};

class Furniture : public Product{
    public:
    
    private:

};

class Recreation: public Product{
    public:
    
    private:

};

class Health: public Product{
    public:
    
    private:

};

enum class ProductCategory {Technology, Automotive, Furniture, Recreation, Health};

Product* ProductFactory(ProductCategory pc){
    switch(pc){
        case ProductCategory::Technology: return new Technology();
        case ProductCategory::Automotive: return new Automotive();
        case ProductCategory::Furniture: return new Furniture();
        case ProductCategory::Recreation: return new Recreation();
        case ProductCategory::Health: return new Health();
        default: return new Product();
    }
}
    

#endif // _PRODUCT_H_