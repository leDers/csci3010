/**
 * @file Driver.cpp
 * @author Leif Anders, Andrew Scott
 * @brief implemntation file for the driver class of BidToBuy 
 * @version 0.1
 * @date 2023-03-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>

#include "Driver.h"
Driver::Driver() {}

const std::vector<Product::Bid> &Driver::GetBidList() const { return bidList_; }
void Driver::addBid(Product::Bid &b) {
  this->bidList_.push_back(b);
}
