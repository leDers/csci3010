/**
 * @file main.cpp
 * @author Leif Anders
 * @brief   main file for testing outside of unit tests
 * @version 0.1
 * @date 2023-02-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
using namespace std::chrono;

#include "Linear.h"
#include "Tree.h"
#include "HashMap.h"
#include "myClass.h"

int main(){
    // helpers
    std::ifstream file("integers.csv");
    std::string str;

    std::vector<int> v_100;
    std::vector<int> v_1000;
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

    // ----------------------------------------
    Linear<int> int_lin_100(v_100);
    Linear<int> int_lin_10000(v_10000);

    // 100 ----------------------------------------
    std::cout <<"Size 100: first, last, random" << std::endl;
    // 100 - first
    auto start_100first = high_resolution_clock::now();
    int_lin_100.getFirst();
    auto stop_100first = high_resolution_clock::now();
    auto duration_100first = duration_cast<microseconds>(stop_100first - start_100first);
    std::cout << "Time taken by function: "
         << duration_100first.count() << " microseconds" << std::endl;

    // 100 - last
    auto start_100last = high_resolution_clock::now();
    int_lin_100.getLast();
    auto stop_100last = high_resolution_clock::now();
    auto duration_100last = duration_cast<microseconds>(stop_100last - start_100last);
    std::cout << "Time taken by function: "
         << duration_100last.count() << " microseconds" << std::endl;

    // 100 - rand
    auto start_100rand = high_resolution_clock::now();
    int_lin_100.getRandom();
    auto stop_100rand = high_resolution_clock::now();
    auto duration_100rand = duration_cast<microseconds>(stop_100rand - start_100rand);
    std::cout << "Time taken by function: "
         << duration_100rand.count() << " microseconds" << std::endl;


    // 10000 ----------------------------------------
    std::cout <<"Size 10000: first, last, random" << std::endl;
    // 10000 - first
    auto start_10000first = high_resolution_clock::now();
    int_lin_10000.getFirst();
    auto stop_10000first = high_resolution_clock::now();
    auto duration_10000first = duration_cast<microseconds>(stop_10000first - start_10000first);
    std::cout << "Time taken by function: "
         << duration_10000first.count() << " microseconds" << std::endl;

    // 10000 - last
    auto start_10000last = high_resolution_clock::now();
    int_lin_10000.getLast();
    auto stop_10000last = high_resolution_clock::now();
    auto duration_10000last = duration_cast<microseconds>(stop_10000last - start_10000last);
    std::cout << "Time taken by function: "
         << duration_10000last.count() << " microseconds" << std::endl;

    // 10000 - rand
    auto start_10000rand = high_resolution_clock::now();
    int_lin_10000.getRandom();
    auto stop_10000rand = high_resolution_clock::now();
    auto duration_10000rand = duration_cast<microseconds>(stop_10000rand - start_10000rand);
    std::cout << "Time taken by function: "
         << duration_10000rand.count() << " microseconds" << std::endl;

    return 0;
}