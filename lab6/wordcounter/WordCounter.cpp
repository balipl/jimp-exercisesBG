//
// Created by Grove on 2017-04-19.
//

#include "WordCounter.h"

namespace datastructures{
    int WordCounter::DistinctWords() {
        int distinctwords = 0;

        for(auto word : slownik_){
            distinctwords+=1;
        }
        return distinctwords;
    }

    int WordCounter::TotalWords() {
        int totalwords = 0;
        for(auto word : slownik_){
            totalwords+= word.second.GetCounts();
        }
        return totalwords;
    }

    std::set<Word> WordCounter::Words() {
        std::set<Word> wyjscie;

        for(auto v : slownik_){
            wyjscie.insert(v.first);
        }
        return wyjscie;
    }

    WordCounter::WordCounter(const std::initializer_list<Word> words) {

        for(auto v : words){
            if (slownik_.find(v) == slownik_.end())
            {slownik_.emplace(v,1);}
            else
            {
                slownik_[v].PlusCounts();
            }
        }
    }

    WordCounter::WordCounter() {} //konstruktor bezparametryczny

    WordCounter::~WordCounter() {} //dekonstruktor

    Word::Word() {} //konstruktor bezparametryczny

    Word::Word(std::string word) {
        word_ = word;
    }

    Word::~Word() {}

    Counts::Counts() {}

    Counts::Counts(int counter) {
        counter_ = counter;
    }

    Counts::~Counts() {}
}