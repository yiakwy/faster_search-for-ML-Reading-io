//
//  main.cpp
//  boyerMoore
//
//  Created by Wang Yi on 30/10/16.
//  Copyright (c) 2016 Wang Yi. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <string>
#include "boyerMoore.h"
//#include "wikipedia_algo.h"

int main(int argc, const char * argv[]) {
    std::stringstream split;
    std::string txt, pttn;
    std::getline(std::cin, txt);
    std::getline(std::cin, pttn);
    boyer_moore(txt.c_str(), txt.length(), pttn.c_str(), pttn.length());
    return 0;
}