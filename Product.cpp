/**
 * @file Product.cpp
 * @author Leif Anders, Andrew Scott
 * @brief implementation file for Product class of BidToBuy
 * @version 0.1
 * @date 2023-03-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "Product.h"
const std::string &Product::GetProductName() const { return productName_; }
const std::vector<Product::Bid> &Product::GetListOfBids() const { return listOfBids_; }
double Product::GetBasePrice() const { return basePrice_; }
unsigned long Product::GetListingId() const { return listingID_; }
Quality Product::GetQuality() const { return quality_; }
bool Product::IsActive() const { return active_; }
void Product::SetActive(bool active) { active_ = active; }
Product::Product(const std::string &product_name,
                 const std::vector<Bid> &list_of_bids, double base_price,
                 unsigned long listing_id, Quality quality, bool active)
    : productName_(product_name), listOfBids_(list_of_bids),
      basePrice_(base_price), listingID_(listing_id), quality_(quality),
      active_(active) {}
Technology::Technology(const std::string &product_name,
                       const std::vector<Bid> &list_of_bids, double base_price,
                       unsigned long listing_id, Quality quality, bool active)
    : Product(product_name, list_of_bids, base_price, listing_id, quality,
              active) {}
Automotive::Automotive(const std::string &product_name,
                       const std::vector<Bid> &list_of_bids, double base_price,
                       unsigned long listing_id, Quality quality, bool active)
    : Product(product_name, list_of_bids, base_price, listing_id, quality,
              active) {}
Furniture::Furniture(const std::string &product_name,
                     const std::vector<Bid> &list_of_bids, double base_price,
                     unsigned long listing_id, Quality quality, bool active)
    : Product(product_name, list_of_bids, base_price, listing_id, quality,
              active) {}
Recreation::Recreation(const std::string &product_name,
                       const std::vector<Bid> &list_of_bids, double base_price,
                       unsigned long listing_id, Quality quality, bool active)
    : Product(product_name, list_of_bids, base_price, listing_id, quality,
              active) {}
Health::Health(const std::string &product_name,
               const std::vector<Bid> &list_of_bids, double base_price,
               unsigned long listing_id, Quality quality, bool active)
    : Product(product_name, list_of_bids, base_price, listing_id, quality,
              active) {}
