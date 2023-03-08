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

#ifndef PRODUCT_H_
#define PRODUCT_H_

#include <iostream>
#include <string>
#include "User.h"

enum Quality {New, UsedVeryGood, UsedGood, UsedOkay};


class Product {
    public:
      struct Bid{
        double value;
        User &buyer;
        Product &p;
      };
      const std::string &GetProductName() const;
      const std::vector<Product::Bid> &GetListOfBids() const;
      double GetBasePrice() const;
      unsigned long GetListingId() const;
      Quality GetQuality() const;
      bool IsActive() const;
      void AddBid(Product::Bid &b);
      void SetActive(bool active);
      Product(const std::string &product_name,
              const std::vector<Bid> &list_of_bids, double base_price,
              unsigned long listing_id, Quality quality, bool active);

    private:
      std::string productName_;
      std::vector<Bid> listOfBids_;
      double basePrice_;
      unsigned long listingID_;
      Quality quality_;
      bool active_;
};

class Technology: public Product{
    public:
      Technology(const std::string &product_name,
                 const std::vector<Bid> &list_of_bids, double base_price,
                 unsigned long listing_id, Quality quality, bool active);

    private:

};

class Automotive: public Product{
    public:
      Automotive(const std::string &product_name,
                 const std::vector<Bid> &list_of_bids, double base_price,
                 unsigned long listing_id, Quality quality, bool active);

    private:

};

class Furniture : public Product{
    public:
      Furniture(const std::string &product_name,
                const std::vector<Bid> &list_of_bids, double base_price,
                unsigned long listing_id, Quality quality, bool active);

    private:

};

class Recreation: public Product{
    public:
      Recreation(const std::string &product_name,
                 const std::vector<Bid> &list_of_bids, double base_price,
                 unsigned long listing_id, Quality quality, bool active);

    private:

};

class Health: public Product{
    public:
      Health(const std::string &product_name,
             const std::vector<Bid> &list_of_bids, double base_price,
             unsigned long listing_id, Quality quality, bool active);

    private:

};

enum class ProductCategory {Technology, Automotive, Furniture, Recreation, Health};

Product* ProductFactory(ProductCategory pc){
    // switch(pc){}
}
    

#endif // _PRODUCT_H_