#ifndef _SUIT_H_ // this is the header guard
#define _SUIT_H_

// Create an enum class, Suit to represent the suit in a deck of cards
enum class suit {clubs, diamonds, hearts, spades};

// Create a struct, Card, to represent a card in a deck of cards.  You must
// use your Suit enum.  You may use any other values that you choose.
struct Card{
    suit s; // suit
    int v;  // value

    // Override operator== in your Card struct.
    const inline bool operator==(const Card& other){
        return (s == other.s) && (v == other.v);
    }
};

// ex init card c
    // Card c;
    // c.s = suit::clubs;
    // c.v = 7;


// Design a class, Deck.  Write down the fields and methods that this class should have.  
// Don’t implement them!

class Deck {
    public:
        Deck();

        void shuffle();
        void draw();

    private:
        std::vector<Card> cards_;
        const int size_ = 52; 
};

#endif // _SUIT_H_


/*
OOPS - Increase reusability without compromising security

- Abstraction -- privacy setting; public / private
- Encapsulation -- classes
- Polymorphism  -- ability to behave in differnt ways
    - compile time
        - overloading
            - function overload
                - change: number of parameters/ types of parameters
                - keep: the functionality
            - operator overloading
                - '==' knows to expect two operands; 
                    we can exapnd they types of operands it expects
                - lhs == rhs (left hand side == right hand side)
                    bool operator==(const Type &lhs, const T &rhs) {
                        return ((lhs.a == rhs.a) && (lhs.b == rhs.b) && ... ) ; 
                    }

                    bool operator==(const T &rhs) {
                        return ((this->a == hrs.a) && (this->b == rhs.b) && ... ) ; 
                    }

                    T t1, t2;   // assume init
                    t1 == t2;
                    t1.operator==(t2);

                - friend talk
                    friend bool operator==(const T &t1, const T &t2);
                    bool T::operator==(T &t1, T &t2){
                        return ((t1.a == t2.a) && (t1.b == t2.b) && ... ) ;
                    } 

                    operator==(t1,t2);

    - run time
- Inheritence -- introducing hierarchy between classes

*/