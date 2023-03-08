/**
 * @file Driver.h
 * @author Leif Anders, Andrew Scott
 * @brief header file for Driver class of BidToBuy
 * @version 0.1
 * @date 2023-03-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef _DRIVER_H_
#define _DRIVER_H_
#include "User.h"
#include "Product.h"


#include <iostream>
#include <map>

class Driver{
    public:
      Driver();
      const std::vector<Product::Bid> &GetBidList() const;
      void addBid(Product::Bid &b);
    private:
      std::vector<Product::Bid> bidList_;
};

#endif // _DRIVER_H_