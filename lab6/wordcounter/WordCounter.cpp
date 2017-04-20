//
// Created by Grove on 2017-04-19.
//

#include "WordCounter.h"

namespace datastructures {
    int WordCounter::DistinctWords() {
        int distinctwords = 0;

        for (auto word : dictionary_) {
            distinctwords += 1;
        }
        return distinctwords;
    }

    int WordCounter::TotalWords() {
        int totalwords = 0;
        for (auto word : dictionary_) {
            totalwords += word.second.GetCounts();
        }
        return totalwords;
    }

    std::set<Word> WordCounter::Words() {
        std::set<Word> exit_set;

        for (auto v : dictionary_) {
            exit_set.insert(v.first);
        }
        return exit_set;
    }

    WordCounter::WordCounter(const std::initializer_list<Word> words) {

        for (auto v : words) {
            if (dictionary_.find(v) == dictionary_.end()) {
                dictionary_.emplace(v, 1);
            } else {
                dictionary_[v].PlusCounts();
            }
        }
    }

    WordCounter WordCounter::FromInputStream(std::istream *input) {
        WordCounter exit_word;
        std::string word;
        while (*input >> word) {
            std::string checked_word = "";

            for (int i = 0; i <word.length(); ++i) {
                if((word[i]>= 65 and word[i]<=90) or (word[i]>=97 and word[i]<=122))
                {
                    checked_word += word[i];
                }

                Word new_word = Word(checked_word);
                if (dictionary_.find(new_word) == dictionary_.end()) {
                    dictionary_.emplace(new_word, 1);
                } else {
                    dictionary_[new_word].PlusCounts();
                }
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