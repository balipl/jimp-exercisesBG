//
// Created by ASUSTek on 2017-04-02.
//

#ifndef JIMP_EXERCISES_TEXTPOOL_H
#define JIMP_EXERCISES_TEXTPOOL_H

#include <initializer_list>
#include <string>
#include <experimental/string_view>
#include <set>
#include <iostream>
#include <vector>



namespace pool{

class TextPool {
public:
    TextPool();
    ~TextPool();

    TextPool(TextPool &&textpool); // konstruktor przenoszacy

    TextPool &operator=(TextPool &&textpool); //operator kopiujacy

    //konstruktor z listą initializacyjna
    TextPool(const std::initializer_list<std::experimental::string_view> pool);

    std::experimental::string_view Intern(const std::string &str);

    size_t StoredStringCount() const;

private:
    std::set<std::experimental::string_view> pool_;
};

}

#endif //JIMP_EXERCISES_TEXTPOOL_H
