//
// Created by bartek on 16.03.17.
//x

#ifndef JIMP_EXERCISES_XORCYPHERBREAKER_H
#define JIMP_EXERCISES_XORCYPHERBREAKER_H

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

std::string XorCypherBreaker(const std::vector<char> &cryptogram,
                             int key_length,
                             const std::vector<std::string> &dictionary);


#endif //JIMP_EXERCISES_XORCYPHERBREAKER_H
