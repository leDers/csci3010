#ifndef CREATURE_H
#define CREATURE_H


class Creature {
public:
    Creature(int age): age_(age)
    {
        std::vector<Emotion *> tmp;
        this->emotions_ = tmp;
    }

    int get_age() const { return age_; };
    
    void age(int years) { age_ += years; };

    std::vector<Emotion *> get_emotions() const {return emotions_; }; 

    void Spread(Creature * c2);
    void AddEmotion(Emotion * d) { emotions_.push_back(d); };

    // 1) Create a virtual Creature * Clone() method.
    // When a creature is cloned, the clone starts at age 0
    // Emotions that are hereditary should be inherited.

    virtual Creature* Clone() {
        Creature* o = new Creature(0);
        
        for (unsigned long int i=0; i<this->emotions_.size(); i++){
            if (this->emotions_[i]->get_is_hereditary()){
                Emotion* e = this->emotions_[i];
                o->AddEmotion(e);
            }
        }
        return o;
    }

private:
    int age_;
    std::vector<Emotion *> emotions_;
};


// 2) Create 1 subclass of Creature. For this subclass,
// make its cloning behavior slightly different.
// For instance, some Cloned creatures might also inherit non-hereditary emotions.
// It's up to you!

// 3) In your main.cpp, instantiate your subclass. (the rest of the work for this
// part of the exercise will happen in main.)

#endif // CREATURE_H
