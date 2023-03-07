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

};

class Technology: public Product{

};

class Automotive: public Product{

};

class Furniture : public Product{

};

class Recreation: public Product{

};

class Health: public Product{

};

enum class ProductCategory {Technology, Automotive, Furniture, Recreation, Health};

Product* ProductFactory(ProductCategory pc){
    // switch(pc){}
}
    

#endif // _PRODUCT_H_