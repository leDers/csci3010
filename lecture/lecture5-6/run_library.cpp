#include <iostream>
#include <vector>
#include "Library.h"

// Name(s):
// Leif Anders

// Complete numbered coding tasks.
// Answer the questions with "Answer: " in the comments by writing your answer in the comments.
// some experiments might result in non-running/non-compiling code. Leave these experiments in, but
// comment them out.
// Turn in run_library.cpp, Library.h, and Library.cpp on Canvas before the end of class.
// make sure to leave a comment here and on canvas with your name and the name(s) of your partners.

int main() {
    // 1) Instantiate a couple Books. Set their fields equal to some values.
    // Print out the values of the books' fields.
    Book b1 = {"Braiding Sweetgrass", "Robin Wall Kimmerer"};
    Book b2 = {"Howl's Moving Castle", "Diana Wynne Jones"};

    std::cout << "\nPrinting book1, book2..." << std::endl;
    std::cout << b1.title << " by " << b1.author << std::endl;
    std::cout << b2.title << " by " << b2.author << std::endl;

    // 2) Instantiate a Library.

    Library lib1;

    // 3) Add a void Donate(Book b) method to your Library class.
    // Your Library should store the new book at the end of its shelf.


    // 4) Donate one of the Books that you instantiated to your Library.
    std::cout << "\nDonating to lib1..." << std::endl;
    lib1.Donate(b1);

    // 5) Print out the books in the Library (use the given PrintBooks method)
    std::cout << "\nPrinting lib1..." << std::endl;
    lib1.PrintBooks();

    // 6) Change the title and/or author of the book that you donated to
    // something different.
    // Print out the new book information, then print out the books in your
    // Library. Did changing the Book information change it in your Library?
    //
    // Answer (and your hypothesis for why/why not):
    std::cout << "\nChanging book1... \nPrinting book1..." << std::endl;
    b1.title = "Life 3.0";
    b1.author = "Max Tegmark";
    std::cout << b1.title << " by " << b1.author << std::endl;

    std::cout << "\nPrinting lib1..." << std::endl;
    lib1.PrintBooks();

    std::cout << "\nNote: nothing has changed because we are passing by value in Donate()" << std::endl;


    // 7) Create two Books that are separate structs (not pointers or references)
    // but that have the same information.
    // use the == operator to test if they are equal. What happens?
    // if it succeeds, are these equal?
    //
    // Answer:
    Book b3 = {"Title_X", "Author_Y"};
    Book b4 = {"Title_X", "Author_Y"};
    /*
        the '==' operator does not accept Book objects as operands
        we cannot compare these two object with the compilers use of '=='
        however we can compare the members of the objects
    */
   std::cout << "\ndirect compare of book obj..." << std::endl;
    if ((b3.title == b4.title) && (b3.author == b4.author)) {
        std::cout << "true" << std::endl;
    }
    else {
        std::cout << "false" << std:: endl;
    }  


    // 8) Create two Book references to your Books from # 7.
    // use the == operator to test if they are equal. What happens?
    // if it succeeds, are these equal?
    //
    // Answer:
    Book &b5 = b3;
    Book &b6 = b4;
    /* 
        we still cannot compare these two directly with the '==' operator
        we have to dip into the object members to make use of '=='
    */
    std::cout << "\nreference compare of book obj..." << std::endl;
    if ((b5.title == b6.title) && (b5.author == b6.author)) {
        std::cout << "true" << std::endl;
    }
    else {
        std::cout << "false" << std:: endl;
    } 

    // 9) Create two Book pointers to your Books from # 7.
    // use the == operator to test if they are equal. What happens?
    // if it succeeds, are these equal?
    //
    // Answer:
    Book *b7 = &b3;
    Book *b8 = &b4;
    /*
        now we CAN compare, bceause '==' operator 
        compares memory addresses fo pointers
        DOES NOT compare the actual values
    */
    std::cout << "\npointer compare of book obj..." << std::endl;
    if ((b7 == b8)) {
        std::cout << "true" << std::endl;
    }
    else {
        std::cout << "false" << std:: endl;
    }


    // 10) Add a void Donate(Book b, int num_copies) method to your Library class.
    // your Library should add num_copies of Book b to its shelf.
    std::cout << "\nDontaing 3 copies of book2 to lib1..." << std:: endl;
    int n = 3;
    lib1.Donate(b2, n);
    lib1.PrintBooks();

    // 11) Finally, if you reach this far, work on finding a solution to making it so
    // that you would be able to do any of the comparisons from # 7, 8, and 9
}
