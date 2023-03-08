/**
 * @file User.cpp
 * @author Leif Anders, Andrew Scott
 * @brief implementation file for User class of BidToBuy
 * @version 0.1
 * @date 2023-03-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "User.h"
unsigned long User::GetAccountBalance() const { return accountBalance_; }
void User::SetAccountBalance(unsigned long account_balance) {
  accountBalance_ = account_balance;
}
const std::string &User::GetName() const { return name_; }
void User::SetName(const std::string &name) { name_ = name; }
const std::string &User::GetPhoneNumber() const { return phoneNumber_; }
void User::SetPhoneNumber(const std::string &phone_number) {
  phoneNumber_ = phone_number;
}
const std::string &User::GetAddress() const { return address_; }
void User::SetAddress(const std::string &address) { address_ = address; }
const std::vector<User::message> &User::GetMessages() const { return messages_; }
void User::SetMessages(const std::vector<message> &messages) {;
}

User::User(const std::string &name,
     const std::string &phone_number, const std::string &address,
     const std::vector<message> &messages)
    : name_(name), phoneNumber_(phone_number), address_(address),
      messages_(messages) {
    std::hash<std::string> hashFn;
    this->UUID_=hashFn(name)^hashFn(phone_number);
}
User::User(unsigned long uuid, unsigned long account_balance,
           const std::string &name, const std::string &phone_number,
           const std::string &address, const std::vector<message> &messages)
    : UUID_(uuid), accountBalance_(account_balance), name_(name),
      phoneNumber_(phone_number), address_(address), messages_(messages) {}
void User::SendNewMessage(const User & to, const std::string body) {

}
