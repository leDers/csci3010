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
class User;

enum Quality {New, UsedVeryGood, UsedGood, UsedOkay};


class Product {
    public:
      struct Bid{
        double value;
        User *buyer;
        Product *p;
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
              unsigned long listing_id, Quality quality, bool active){
                this->productName_ = product_name;
                this->listOfBids_ = list_of_bids;
                this->basePrice_ = base_price;
                this->listingID_ = listing_id;
                this->active_ = active; 
              }

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
      // Technology(): 
      // Product("template_Tech", std::vector<Bid> {}, 0.0, Quality::New, false) {}

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

class ProductFactory{
  public: 
    static Product* CreateProduct(ProductCategory pc){
      switch(pc){
          case ProductCategory::Technology: return new Technology("basic_Tech", {}, 0.0, 0, Quality::New, false);
          case ProductCategory::Automotive: return new Automotive("basic_Auto", {}, 0.0, 0, Quality::New, false);
          case ProductCategory::Furniture: return new Furniture("basic_Furn", {}, 0.0, 0, Quality::New, false);
          case ProductCategory::Recreation: return new Recreation("basic_Rec", {}, 0.0, 0, Quality::New, false);
          case ProductCategory::Health: return new Health("basic_Heal", {}, 0.0, 0, Quality::New, false);
          default: return new Product("basic_Prod", {}, 0.0, 0, Quality::New, false);
    }
  }
};
    

#endif // _PRODUCT_H_