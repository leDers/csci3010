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

// Design a class, Deck.  Write down the fields and methods that this class should have.  
// Don’t implement them!

class Deck {
    public:
        Deck();

        void shuffle();
        void draw();

    private:
        std::vector<Card> cards_;
};

#endif // _SUIT_H_
