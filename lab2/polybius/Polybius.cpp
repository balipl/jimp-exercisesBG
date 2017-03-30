//
// Created by ASUSTek on 2017-03-14.
//

#include "Polybius.h"

using std::map;
using std::to_string;
using std::string;

string PolybiusCrypt(string message) {
    map<char, int> szyfr = {{'a', 11},
                            {'b', 12},
                            {'c', 13},
                            {'d', 14},
                            {'e', 15},
                            {'f', 21},
                            {'g', 22},
                            {'h', 23},
                            {'i', 24},
                            {'j', 24},
                            {'k', 25},
                            {'l', 31},
                            {'m', 32},
                            {'n', 33},
                            {'o', 34},
                            {'p', 35},
                            {'q', 41},
                            {'r', 42},
                            {'s', 43},
                            {'t', 44},
                            {'u', 45},
                            {'v', 51},
                            {'w', 52},
                            {'x', 53},
                            {'y', 54},
                            {'z', 55}};
    string crypted_message = "";

    for (int i = 0; i < message.length(); ++i) {
        if (message[i] != 32)
            crypted_message += to_string(szyfr[tolower(message[i])]);
    }
    return crypted_message;
}

string PolybiusDecrypt(string crypted) {
    map<int, char> deszyfr = {{11, 'a'},
                              {12, 'b'},
                              {13, 'c'},
                              {14, 'd'},
                              {15, 'e'},
                              {21, 'f'},
                              {22, 'g'},
                              {23, 'h'},
                              {24, 'i'},
                              {25, 'k'},
                              {31, 'l'},
                              {32, 'm'},
                              {33, 'n'},
                              {34, 'o'},
                              {35, 'p'},
                              {41, 'q'},
                              {42, 'r'},
                              {43, 's'},
                              {44, 't'},
                              {45, 'u'},
                              {51, 'v'},
                              {52, 'w'},
                              {53, 'x'},
                              {54, 'y'},
                              {55, 'z'}};
    string encrypted_message = "";
    int i_number;
    string s_number;
    for (int i = 0; i + 1 < crypted.length(); i = i + 2) {
        s_number = "";
        s_number = s_number + crypted[i];
        s_number = s_number + crypted[i + 1];
        i_number = atoi(s_number.c_str());
        encrypted_message += deszyfr[i_number];
    }
    return encrypted_message;
}