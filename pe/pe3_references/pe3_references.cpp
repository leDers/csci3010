#include <iostream>

// Name: Leif Anders
//

// Write any functions you need here!
// function from #9
void foo1(int* i){
    (*i)++;
    std::cout << "Inside foo1() value: " << (*i) << std::endl;
    return; 
};

// function from #11
void foo2(int &i){
    i++;
    std::cout << "Inside foo2() value: " << i << std::endl;
    return;  
};

void foo3(const int &i, int* x){
    (*x) = i+1;
    std::cout << "Inside foo3() value: " << (*x) << std::endl;
}

class myClass{
    public:
        myClass(int x) { this->x_ = x; }
        int getX() {return this->x_; }
        void setX(int x) { this->x_ = x; }

        friend bool operator==(const myClass& lhs, const myClass& rhs){
            return (lhs.x_ == rhs.x_);
        }

        friend int operator+(const myClass& lhs, const myClass& rhs){
            return (lhs.x_ + rhs.x_);
        }

    private:
        int x_;
};

int my_main() {
    // Add as many prints to cout as you need to answer the questions.
    // Leave them in your code when you turn it in.
    // If you have lines of code that cause errors that test the questions,
    // leave this code in your file but comment it out.
    
    // 1) Declare an int
    int x = 1;
    std::cout << "\nValue of x:\t\t" << x << std::endl;

    // 2) Declare a pointer to that int
    int *p_int = &x;

    // 3) Increment the int via the pointer
    (*p_int)++;
    std::cout << "\nIncrement Pointer\nValue of x_pointer:\t" << x << std::endl;

    // 4) Declare a reference to your int
    int &r_int = x;
    // 5) Increment the int via the reference
    r_int++;
    std::cout << "\nIncrement refernce\nValue of x_reference:\t" << x << std::endl;

    // 6) When you increment the int via the variable declared in #1, which
    // variables will be modified to see the changes? (the pointer , reference or both?)
    // Answer: 
    //          all variables will reflect the change: original, pointer, and reference
    x++;
    std::cout << "\nIncrement original var\nValue of x:\t\t" << x << std::endl;
    std::cout << "Value of x_pointer:\t" << x << std::endl;
    std::cout << "Value of x_reference:\t" << x << std::endl;

    // 7) When you increment the int via the pointer declared in #2, which
    // variables will be modified to see the changes?
    // Answer:
    //          all variables will reflect the change: original, pointer, and reference
    (*p_int)++;
    std::cout << "\nIncrement pointer\nValue of x:\t\t" << x << std::endl;
    std::cout << "Value of x_pointer:\t" << x << std::endl;
    std::cout << "Value of x_reference:\t" << x << std::endl;

    // 8) When you increment the int via the reference declared in #4, which
    // variables will be modified to see the changes?
    // Answer: 
    //          all variables will reflect the change: original, pointer, and reference
    r_int++;
    std::cout << "\nIncrement reference\nValue of x:\t\t" << x << std::endl;
    std::cout << "Value of x_pointer:\t" << x << std::endl;
    std::cout << "Value of x_reference:\t" << x << std::endl;

    // 9) Write a function that takes an int * parameter. How would you pass the 
    // variable from #1 into this function? 
    // Modify the parameter within the function using any operation of your choice.(write the function definition and call below)
    // Does it update the value you originally passed to the function?
    std::cout << "\nFunction 1 Call 1" << std::endl;
    foo1(p_int);
    std::cout << "Value of x:\t\t" << x << std::endl;
    std::cout << "Value of x_pointer:\t" << x << std::endl;
    std::cout << "Value of x_reference:\t" << x << std::endl;
    std::cout << "Note: passing the reference retains value change" << std::endl;

    // 10) Can you pass your reference from #4 to the function from #9 without accessing its address?
    // Answer:
    //          We can only pass the reference from #4 to the function from #9 if we prefix it with '&'
    std::cout << "\nFunction 1 Call 2" << std::endl;
    foo1(&r_int);
    std::cout << "Value of x:\t\t" << x << std::endl;
    std::cout << "Value of x_pointer:\t" << x << std::endl;
    std::cout << "Value of x_reference:\t" << x << std::endl;

    // 11) Write a function that takes an int & parameter. How would you pass the 
    // variable from #1 into this function? 
    // Modify the parameter using any operation of your choice.(write the function definition and call below)
    // Does it update the value you originally passed to the function?
    std::cout << "\nFunction 2 Call" << std::endl;
    // we can pass the variable from #1 into the function from #11 by simply passing it in
    foo2(x);
    std::cout << "Value of x:\t\t" << x << std::endl;
    std::cout << "Value of x_pointer:\t" << x << std::endl;
    std::cout << "Value of x_reference:\t" << x << std::endl;
    std::cout << "Note: passing the delcared variable retains value change" << std::endl;

    // 12) Can you pass your pointer from #2 to the function from #11 without dereferencing it?
    // Answer:
    //          we can not pass the pointer from #2 into the fucntion from #11 wihtough dereferencing it
    std::cout << "\nFunction 2 Call -- dereferenced pointer" << std::endl;
    foo2(*p_int); 
    std::cout << "Value of x:\t\t" << x << std::endl;
    std::cout << "Value of x_pointer:\t" << x << std::endl;
    std::cout << "Value of x_reference:\t" << x << std::endl;
    std::cout << "Note: passing the de referenced pointer retains value change" << std::endl;

    // 13) Can you pass your reference from #4 to the function from #11?
    // Answer:
    //          yes , we can pass the reference from #4 to the function from #11
    std::cout << "\nFunction 2 Call -- referenced variable" << std::endl;
    foo2(r_int);
    std::cout << "Value of x:\t\t" << x << std::endl;
    std::cout << "Value of x_pointer:\t" << x << std::endl;
    std::cout << "Value of x_reference:\t" << x << std::endl;
    std::cout << "Note: passing the reference retains value change" << std::endl;

    // 14) Write a function that takes one const reference input parameter and one pointer
    // output parameter. The function should fill in the value of the output parameter based
    // on the value of the input parameter. (what it does exactly is up to you).
    // Call your function 3 times below. Be sure to include output as necessary to be sure
    // your function works as described.
    std::cout << "\nFunction 3 Call -- 3 times" << std::endl;
    foo3(r_int, p_int);
    foo3(r_int, p_int);
    foo3(r_int, p_int);
    std::cout << "Value of x:\t\t" << *p_int << std::endl;
    std::cout << "Value of x_pointer:\t" << *p_int << std::endl;
    std::cout << "Value of x_reference:\t" << *p_int << std::endl;

    // 15) What is/are the difference(s) between output parameters and return values?
    // Answer:
        // Out-parameters are variables that are used to pass information from the callee to the caller, they are part of the parameter list
        // A return is a value that a function returns to the calling script or function when it completes its task

    // 16) Create a custom class with at least one private field/class attribute. Overload the == and + operator for this class
    // such that == can be used to compare the objects of the class and + can be used to add
    // 2 objects of the class together. Implement an appropriate constructor for your class.
    // When you overload these operators, the resulting return value should make sense.
    // Instantiate at least 2 objects of this class and perform the == and + operations on them.
    // hint: for operator+, the function signature when implemented as a member function of the Object class is:
    // Object operator+(const Object &other)
    // Answer:

    myClass a = myClass(2);
    myClass b = myClass(4);

    std::cout << "\nClass Overloads" << std::endl;
    std::cout << "a + b\t= " << (a+b) << std::endl;
    std::cout << "(a == b)= " << (a==b) << std::endl;
    
    return 0;
}

