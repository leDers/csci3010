/**
 * @file User.h
 * @author Leif Anders, Andrew Scott
 * @brief head file of User class for BidToBuy
 * @version 0.1
 * @date 2023-03-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef USER_H_
#define USER_H_


#include <string>
#include <vector>
#include <iostream>

#include "Product.h"
class Product;

class User{
  public:
    struct message{
      std::string body;
      User &sender;
      User &recipient;
    };

    User(const std::string &name,
      const std::string &phone_number, const std::string &address,
      const std::vector<message> &messages);

    User(unsigned long uuid, unsigned long account_balance,
          const std::string &name, const std::string &phone_number,
          const std::string &address, const std::vector<message> &messages);

    unsigned long GetAccountBalance() const;
    void SetAccountBalance(unsigned long account_balance);

    const std::string &GetName() const;
    void SetName(const std::string &name);

    const std::string &GetPhoneNumber() const;
    void SetPhoneNumber(const std::string &phone_number);

    const std::string &GetAddress() const;
    void SetAddress(const std::string &address);

    const std::vector<message> &GetMessages() const;
    void SetMessages(const std::vector<message> &messages);
    void SendNewMessage(const User &to, const std::string body);

  private:
  unsigned long UUID_;
  unsigned long accountBalance_;

  std::string name_;
  std::string phoneNumber_;
  std::string address_;
  std::vector<message> messages_;

};

class Seller: public User{
    public:
      Seller(const std::string &name,
             const std::string &phone_number, const std::string &address,
             const std::vector<message> &messages)
          : User(name, phone_number, address, messages){
      }

      void PostProduct(Product &p);
      std::vector<Product> GetOverview() const;
      void EditBids(Product &p);

    private:
      std::vector<Product> saleList_;
};

class Buyer: public User{
    public:
      Buyer(const std::string &name,
             const std::string &phone_number, const std::string &address,
             const std::vector<message> &messages)
          : User(name, phone_number, address, messages){
      }
      int PlaceBid(Product &p);
      std::vector<Product> GetOverview() const;
      std::vector<Product> viewHistory() const;

    private:
      std::vector<Product::Bid> bidList_;
      std::vector<Product> purchased_;

};


#endif // _USER_H_