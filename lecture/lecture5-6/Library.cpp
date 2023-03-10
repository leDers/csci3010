#include <iostream>
#include <string>
#include <vector>

#include "Library.h"

/**
  Zero argument constructor initializes a library with a shelf but no books.
*/
Library::Library() {
  std::vector<Book> tmp;
  shelf_ = tmp;  // initialize my shelf
}

/**
  Prints out each book in the library, one per line to cout
*/
void Library::PrintBooks() {
  // for (Book b : shelf_) {
  //   std::cout << b.title << " by " << b.author << std::endl;
  // }

   for (Book b : shelf_) {
    std::cout << b;
  }

}

/*
store the new book at the end of its shelf
*/
void Library::Donate(Book b) {
  shelf_.push_back(b);
}

void Library::Donate(Book b, int num_copies) {
  shelf_.insert(shelf_.end(), num_copies, b);
}