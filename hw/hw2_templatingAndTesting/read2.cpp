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

#include "Linear.h"
#include "Tree.h"
#include "HashMap.h"
#include "myClass.h"

int main(){
    std::ifstream file("integers.csv");
    std::string str;

    std::vector<int> v_100;
    std::vector<int> v_1000;
    std::vector<int> v_10000;
    std::vector<int> v_20000;
    // std::vector<int> v_100;
    std::vector< std::vector<int> > v_list = {&v_100, &v_1000, &v_10000, &v_20000};
    // std::vector< std::vector<int>* > v_list = {&v_100};


    int counter;
    std::vector<int> v_size = {100, 1000, 10000, 20000} ;
    // int v_size[1] = {100} ;


    for (auto i: v_list){
        counter = 0;

        for (auto j: v_size){
            while (counter < j){
                file >> str;
                i.push_back(stoi(str));
                counter++;
            }

            file.clear();
            file.seekg(0);
        }
    }

    int x = 0;
    for (auto k: v_100){
        std::cout << x << " : " << k << std::endl;
        x++;
    }

    // // 100
    // while (counter < 100){
    //     file >> str;
    //     v_100.push_back(stoi(str));
    //     counter++;
    // }
    // counter = 0;
    // file.clear();
    // file.seekg(0);

    // for (auto i: v_100){
    //     std::cout << i << std::endl;
    // }

    // // 1000
    // while (counter < 1000){
    //     file >> str;
    //     v_1000.push_back(stoi(str));
    //     counter++;
    // }
    // counter = 0;
    // file.clear();
    // file.seekg(0);


    // // 10000
    // while (counter < 10000){
    //     file >> str;
    //     v_10000.push_back(stoi(str));
    //     counter++;
    // }
    // counter = 0;
    // file.clear();
    // file.seekg(0);


    // //20000
    // while (counter < 200000){
    //     file >> str;
    //     v_100.push_back(stoi(str));
    //     counter++;
    // }
    // counter = 0;
    // file.clear();
    // file.seekg(0);

    return 0;
}