#ifndef EMOTION_H
#define EMOTION_H


class Emotion {
public:
    Emotion(std::string name,
            bool is_communicable,
            bool is_hereditary,
            double affects_young_rate, // between 0 (no chance) and 1 (always)
            double affects_old_rate,   // between 0 (no chance) and 1 (always)
            double affects_middle_aged_rate // between 0 (no chance) and 1 (always)
            ) :
    name_(name),
    is_communicable_(is_communicable),
    is_hereditary_(is_hereditary),
    affects_young_rate_(affects_young_rate),
    affects_old_rate_(affects_old_rate),
    affects_middle_aged_rate_(affects_middle_aged_rate)
    { counter_+=1; }

    std::string get_name() const { return name_; };
    bool get_is_communicable() const { return is_communicable_;};
    bool get_is_hereditary() const { return is_hereditary_;};
    double get_affects_young_rate() const { return affects_young_rate_; };
    double get_affects_old_rate() const { return affects_old_rate_; };
    double get_affects_middle_aged_rate() const { return affects_middle_aged_rate_; };

    int get_count() {return counter_; }

    friend std::ostream& operator<<(std::ostream &os, const Emotion &d);

private:
    std::string name_;
    bool is_communicable_;
    bool is_hereditary_;
    double affects_young_rate_;
    double affects_old_rate_;
    double affects_middle_aged_rate_;

    // 0) Add a static int field counter_, then modify Emotion.cpp to
    // initialize the field properly. Then, modify the Emotion constructor
    // so that every time a Emotion is instantiated, counter_ is increased
    // by one.

    static int counter_;

    // Then, add a static get_count function to the Emotion class.
};


class EmotionFactory {
public:
// we use the factory to make all the objects below, without instatiating an actual emotion factory

// 1) Implement a static method Emotion * GetHappy() that takes no parameters and returns
// a Emotion pointer to a happy object. Happiness is communicable, it is not hereditary, and affects all age groups similarly.
// Go ahead and make up answers for the other traits.
    static Emotion* GetHappy(){
        Emotion* o = new Emotion("Happy", true, false, 1.0, 1.0, 1.0);
        return o;
    }

// 2) Implement a static method Emotion * GetAngry() that takes no parameters and returns a
// Emotion pointer to a angry object. Let's assume Anger affects middle-aged and older people more than younger people 
// and is not (readily/easily) communicable. Use what you know and your imagination to fill in the other fields.
    static Emotion* GetAngry(){
        Emotion* o = new Emotion("Angry", false, false, 0.5, 1.0, 1.0);
        return o;
    }

// 3) Implement a static method that returns a pointer to a Emotion object of your choice (can be a real emotion,
// can be something that you've made up).
    static Emotion* GetSad(){
        Emotion* o = new Emotion("Sad", true, true, 0.5, 0.5, 1.0);
        return o;
    }

};


// 4) in main.cpp, get pointers to your emotions and Infect some Creature objects (how many of each is up to you)
// (the rest of the work for this part will take place in main.cpp)

#endif // EMOTION_H
