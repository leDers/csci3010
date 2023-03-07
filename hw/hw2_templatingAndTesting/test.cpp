/**
 * @file test.cpp
 * @author Leif Anders
 * @brief 
 * @version 0.1
 * @date 2023-02-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "Linear.h"
#include "Tree.h"
#include "HashMap.h"
#include "myCLass.h"

#include <chrono>
using namespace std::chrono;



// Linear --------------------------------------
TEST_CASE("Linear Template Tests"){
    // integer ----------------------------------------
        std::vector<int> int_vec = {};
        Linear<int> int_lin(int_vec);
        
        int_lin.insertValue(0);

        SECTION("insertValue"){
            REQUIRE(int_lin.getSizeOfList() == 1);
        }

        SECTION("getElementAt") {
            REQUIRE(int_lin.getElementAt(0) == 0);
        }

        SECTION("search") {
            REQUIRE(int_lin.search(1) == 0);
            REQUIRE(int_lin.search(0) == 1);
        }
        
        SECTION("deleteElement") {
            int_lin.deleteElement(0);
            REQUIRE(int_lin.search(0) == 0);
        }

    // user class ----------------------------------------
        std::vector<myClass> myClass_vec = {myClass(0), myClass(1), myClass(2), myClass(3)};
        Linear<myClass> myClass_lin(myClass_vec);
        
        myClass_lin.insertValue(myClass(4));

        SECTION("insertValue"){
            REQUIRE(myClass_lin.getSizeOfList() == 5);
        }

        SECTION("getElementAt") {
            REQUIRE(myClass_lin.getElementAt(0) == myClass(0));
        }

        SECTION("search") {
            REQUIRE(myClass_lin.search(myClass(5)) == 0);
            REQUIRE(myClass_lin.search(myClass(4)) == 1);
        }
        
        SECTION("deleteElement") {
            myClass_lin.deleteElement(myClass(1));
            REQUIRE(myClass_lin.search(myClass(1)) == 0);
        }
}

// Tree ----------------------------------------
TEST_CASE("Tree Template Tests"){
    // char
        char char_root = 'n';
        Tree<char> char_tree(char_root);
        
        SECTION("insertElement") {
            char_tree.insertElement('a');

            REQUIRE(char_tree.search('n')==1);
            REQUIRE(char_tree.search('a')==1);
        }

        SECTION("search") {
            REQUIRE(char_tree.search('n')==1); 
            REQUIRE(char_tree.search('b')==0);
        }
        
        SECTION("deleteElement") {
            char_tree.insertElement('a');
            REQUIRE(char_tree.search('a')==1);

            char_tree.deleteElement('n');
            REQUIRE(char_tree.search('a')==1);
            REQUIRE(char_tree.search('n')==0);
        }
    
    // user class
        myClass myClass_root = myClass(4);
        Tree<myClass> myClass_tree(myClass_root);

        SECTION("insertElement") {
            myClass_tree.insertElement(myClass(2));

            REQUIRE(myClass_tree.search(myClass(4))==1);
            REQUIRE(myClass_tree.search(myClass(2))==1);
        }

        SECTION("search") {
            REQUIRE(myClass_tree.search(myClass(4))==1); 
            REQUIRE(myClass_tree.search(myClass(6))==0);
        }
        
        SECTION("deleteElement") {
            myClass_tree.insertElement(myClass(2));
            REQUIRE(myClass_tree.search(myClass(2))==1);

            myClass_tree.deleteElement(myClass(4));
            REQUIRE(myClass_tree.search(myClass(2))==1);
            REQUIRE(myClass_tree.search(myClass(4))==0);
        }

}

// HashMap -------------------------------------
TEST_CASE("HashMap Template Cases"){
    // double
        std::vector<double> dbl_vect = {0.0, 1.1, 2.2, 3.3, 4.4};
        int dbl_size = 5;
        HashMap<double> dbl_hash(dbl_vect, dbl_size);

        SECTION("hashKey"){
            REQUIRE(dbl_hash.hashKey(0.0) == 0);
            REQUIRE(dbl_hash.hashKey(0.1) == 4);
            REQUIRE(dbl_hash.hashKey(1.0) == 4);
        }

        SECTION("insertElement"){
            dbl_hash.insertElement(5.5);
            REQUIRE(dbl_hash.search(5.5) == 1);
        }

        SECTION("search"){
            REQUIRE(dbl_hash.search(0.0) == 1);
            REQUIRE(dbl_hash.search(6.6) == 0);
        }

        SECTION("deleteElement"){
            dbl_hash.deleteElement(4.4);
            REQUIRE(dbl_hash.search(4.4) == 0);
        }

    // user class
        std::vector<myClass> myClass_vec = {myClass(0), myClass(1), myClass(2), myClass(3)};
        int myClass_size = 5;
        HashMap<myClass> myClass_hash(myClass_vec, myClass_size);

        SECTION("hashKey"){
            REQUIRE(myClass_hash.hashKey(myClass(0)) == 0);
            REQUIRE(myClass_hash.hashKey(myClass(1)) == 3);
            REQUIRE(myClass_hash.hashKey(myClass(7)) == 4);
        }

        SECTION("insertElement"){
            myClass_hash.insertElement(myClass(5));
            REQUIRE(myClass_hash.search(myClass(5)) == 1);
        }

        SECTION("search"){
            REQUIRE(myClass_hash.search(myClass(0)) == 1);
            REQUIRE(myClass_hash.search(myClass(6)) == 0);
        }

        SECTION("deleteElement"){
            myClass_hash.deleteElement(myClass(0));
            REQUIRE(myClass_hash.search(myClass(0)) == 0);
        }

}

// time complexity

TEST_CASE("Time complexity Linear"){
    // linear ----------------------------------------
    // helpers
        std::ifstream file("integers.csv");
        std::string str;

        std::vector<int> v_100;
        std::vector<int> v_10000;

        int counter;

        // 100 --- --- --- ---
        counter = 0;
        while (counter < 100){
            file >> str;
            v_100.push_back(stoi(str));
            counter++;
        }
        file.clear();
        file.seekg(0);

        // 10000  --- --- --- ---
        counter = 0;
        while (counter < 10000){
            file >> str;
            v_10000.push_back(stoi(str));
            counter++;
        }
        file.clear();
        file.seekg(0);

        // linear init
        Linear<int> int_lin_100(v_100);
        Linear<int> int_lin_10000(v_10000);         

    // 100 ----------------------------------------
        // 100 - first
        auto start_100first_lin = high_resolution_clock::now();
        int_lin_100.getFirst();
        auto stop_100first_lin = high_resolution_clock::now();
        auto duration_100first_lin = duration_cast<microseconds>(stop_100first_lin - start_100first_lin);
        // std::cout << "Time taken by function: "
        //     << duration_100first.count() << " microseconds" << std::endl;

        // 100 - last
        auto start_100last_lin = high_resolution_clock::now();
        int_lin_100.getLast();
        auto stop_100last_lin = high_resolution_clock::now();
        auto duration_100last_lin = duration_cast<microseconds>(stop_100last_lin - start_100last_lin);

        // 100 - rand
        auto start_100rand_lin = high_resolution_clock::now();
        int_lin_100.getRandom();
        auto stop_100rand_lin = high_resolution_clock::now();
        auto duration_100rand_lin = duration_cast<microseconds>(stop_100rand_lin - start_100rand_lin);

        // 10000 ----------------------------------------
        // 10000 - first
        auto start_10000first_lin = high_resolution_clock::now();
        int_lin_10000.getFirst();
        auto stop_10000first_lin = high_resolution_clock::now();
        auto duration_10000first_lin = duration_cast<microseconds>(stop_10000first_lin - start_10000first_lin);

        // 10000 - last
        auto start_10000last_lin = high_resolution_clock::now();
        int_lin_10000.getLast();
        auto stop_10000last_lin = high_resolution_clock::now();
        auto duration_10000last_lin = duration_cast<microseconds>(stop_10000last_lin - start_10000last_lin);

        // 10000 - rand
        auto start_10000rand_lin = high_resolution_clock::now();
        int_lin_10000.getRandom();
        auto stop_10000rand_lin = high_resolution_clock::now();
        auto duration_10000rand_lin = duration_cast<microseconds>(stop_10000rand_lin - start_10000rand_lin);
       
        REQUIRE(duration_100first_lin <= duration_10000first_lin);
        REQUIRE(duration_100last_lin <= duration_10000last_lin);
}

TEST_CASE("Time complexity Tree"){
    // time analysis ----------------------------------------
    // helpers
        std::ifstream file("strings.csv");
        std::string str;

        std::vector<std::string> v_100;
        std::vector<std::string> v_10000;

        int counter;

        // 100 --- --- --- ---
        counter = 0;
        while (counter < 100){
            file >> str;
            v_100.push_back(str);
            counter++;
        }
        file.clear();
        file.seekg(0);

        // 10000  --- --- --- ---
        counter = 0;
        while (counter < 10000){
            file >> str;
            v_10000.push_back(str);
            counter++;
        }
        file.clear();
        file.seekg(0);

        // tree init
        std::string root = "root";
        Tree<std::string> T_100 = Tree(root);
        Tree<std::string> T_10000 = Tree(root);

        for (auto i: v_100){
            T_100.insertElement(i);
        }

        for (auto i: v_10000){
            T_10000.insertElement(i);
        }


        // 100 ----------------------------------------
        // 100 - first
        auto start_100first_tree = high_resolution_clock::now();
        T_100.minValue(T_100.getRoot());
        auto stop_100first_tree = high_resolution_clock::now();
        auto duration_100first_tree = duration_cast<microseconds>(stop_100first_tree - start_100first_tree);
        // std::cout << "Time taken by function: "
        //     << duration_100first.count() << " microseconds" << std::endl;

        // 100 - last
        auto start_100last_tree = high_resolution_clock::now();
        T_100.maxValue(T_100.getRoot());
        auto stop_100last_tree = high_resolution_clock::now();
        auto duration_100last_tree = duration_cast<microseconds>(stop_100last_tree - start_100last_tree);

        // // 100 - rand
        // auto start_100rand_tree = high_resolution_clock::now();
        // T_100.getRandom();
        // auto stop_100rand_tree = high_resolution_clock::now();
        // auto duration_100rand_tree = duration_cast<microseconds>(stop_100rand_tree - start_100rand_tree);

        // 10000 ----------------------------------------
        // 10000 - first
        auto start_10000first_tree = high_resolution_clock::now();
        T_10000.minValue(T_10000.getRoot());
        auto stop_10000first_tree = high_resolution_clock::now();
        auto duration_10000first_tree = duration_cast<microseconds>(stop_10000first_tree - start_10000first_tree);

        // 10000 - last
        auto start_10000last_tree = high_resolution_clock::now();
        T_10000.maxValue(T_10000.getRoot());
        auto stop_10000last_tree = high_resolution_clock::now();
        auto duration_10000last_tree = duration_cast<microseconds>(stop_10000last_tree - start_10000last_tree);

        // // 10000 - rand
        // auto start_10000rand_tree = high_resolution_clock::now();
        // T_10000.getRandom();
        // auto stop_10000rand_tree = high_resolution_clock::now();
        // auto duration_10000rand_tree = duration_cast<microseconds>(stop_10000rand_tree - start_10000rand_tree);
       
        REQUIRE(duration_100first_tree <= duration_10000first_tree);
        REQUIRE(duration_100last_tree <= duration_10000last_tree);

        // we note that the 100 operations generally return faster than the 10k operations
        // but this is depeendent on the run itself
}

TEST_CASE("Time complexity Hashmap"){
    // time analysis ----------------------------------------
    
    // helpers
        std::ifstream file("decimals.csv");
        std::string str;

        std::vector<double> v_100;
        std::vector<double> v_10000;

        int counter;

        // 100 --- --- --- ---
        counter = 0;
        while (counter < 100){
            file >> str;
            v_100.push_back(stod(str));
            counter++;
        }
        file.clear();
        file.seekg(0);

        // 10000  --- --- --- ---
        counter = 0;
        while (counter < 10000){
            file >> str;
            v_10000.push_back(stod(str));
            counter++;
        }
        file.clear();
        file.seekg(0);

        // hash init
        int size = 20;
        HashMap<double> dbl_hash_100(v_100, size);
        HashMap<double> dbl_hash_10000(v_10000, size);         

        // 100 ----------------------------------------
        // 100 - first
        auto start_100first_hash = high_resolution_clock::now();
        dbl_hash_100.getFirst();
        auto stop_100first_hash = high_resolution_clock::now();
        auto duration_100first_hash = duration_cast<microseconds>(stop_100first_hash - start_100first_hash);
        // std::cout << "Time taken by function: "
        //     << duration_100first.count() << " microseconds" << std::endl;

        // 100 - last
        auto start_100last_hash = high_resolution_clock::now();
        dbl_hash_100.getLast();
        auto stop_100last_hash = high_resolution_clock::now();
        auto duration_100last_hash = duration_cast<microseconds>(stop_100last_hash - start_100last_hash);

        // 100 - rand
        auto start_100rand_hash = high_resolution_clock::now();
        dbl_hash_100.getRandom();
        auto stop_100rand_hash = high_resolution_clock::now();
        auto duration_100rand_hash = duration_cast<microseconds>(stop_100rand_hash - start_100rand_hash);

        // 10000 ----------------------------------------
        // 10000 - first
        auto start_10000first_hash = high_resolution_clock::now();
        dbl_hash_10000.getFirst();
        auto stop_10000first_hash = high_resolution_clock::now();
        auto duration_10000first_hash = duration_cast<microseconds>(stop_10000first_hash - start_10000first_hash);

        // 10000 - last
        auto start_10000last_hash = high_resolution_clock::now();
        dbl_hash_10000.getLast();
        auto stop_10000last_hash = high_resolution_clock::now();
        auto duration_10000last_hash = duration_cast<microseconds>(stop_10000last_hash - start_10000last_hash);

        // 10000 - rand
        auto start_10000rand_hash = high_resolution_clock::now();
        dbl_hash_10000.getRandom();
        auto stop_10000rand_hash = high_resolution_clock::now();
        auto duration_10000rand_hash = duration_cast<microseconds>(stop_10000rand_hash - start_10000rand_hash);
       
        REQUIRE(duration_100first_hash <= duration_10000first_hash);
        REQUIRE(duration_100last_hash <= duration_10000last_hash);

        // we note that the 100 operations generally return faster than the 10k operations
        // but this is depeendent on the run itself
}