#ifndef TREE_H
#define TREE_H

class Tree {
    public:
        static int no_trees;
        Tree() {
            no_trees++;
        }

        
        virtual void Seed() { number_seeds_ += 1; };
        int get_number_seeds() { return number_seeds_; }

    // private:
    protected:
        static int number_seeds_;
};

class subTree: protected Tree{
    public:
        subTree() {no_trees++;}
        void Seed()override{ number_seeds_ +=2; }
        int get_number_seeds() { return number_seeds_; }

};

#endif // TREE_H
