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

#ifdef _PRODUCT_H_
#define _PRODUCT_H_

#include <iostream>

class Product {
    public:
    
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
    // switch(pc){}
}
    

#endif // _PRODUCT_H_