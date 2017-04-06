//
// Created by ASUSTek on 2017-04-02.
//

#include "TextPool.h"

namespace pool{


TextPool::TextPool() {}

TextPool::~TextPool() {
    pool_.clear();
}

//konstruktor przenoszacy
    TextPool::TextPool(TextPool &&textpool): pool_{nullptr} {
std::swap(pool_, textpool.pool_);
    }
//operator przypisania
    TextPool &TextPool::operator=(TextPool &&textpool) {
        if(this == &textpool)
            return *this;

        pool_.clear();
        std::swap(pool_, textpool.pool_);
    }

    TextPool::TextPool(const std::initializer_list<std::experimental::string_view> pool): pool_(pool){}

std::experimental::string_view TextPool::Intern(const std::string &str) {
    for (auto i = pool_.begin(); i != pool_.end() ; ++i) {
        if(str == *i) return *i;
    }

    pool_.insert(std::experimental::string_view(str));

    for(auto i = pool_.begin() ; i!= pool_.end(); i++){
        if(str==*i) return *i;
    }
}

size_t pool::TextPool::StoredStringCount() const {
    size_t size = 0;

    for(auto m : pool_){
        size++;
        if(m=="\0") size--;
    }

    return size;
}





}