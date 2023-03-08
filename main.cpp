/**
 * @file main.cpp
 * @author Leif Anders, Andrew Scott
 * @brief main file for BidToBuy
 * @version 0.1
 * @date 2023-03-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "User.h"
#include "Driver.h"

int main(){
  Product::Bid bid1= {.value=100.00,.buyer=NULL,.p=NULL};
  Driver d=Driver();
    d.addBid(bid1);
    return 0;
}