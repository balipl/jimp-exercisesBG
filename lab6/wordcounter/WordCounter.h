//
// Created by Grove on 2017-04-19.
//

#ifndef JIMP_EXERCISES_WORDCOUNTER_H
#define JIMP_EXERCISES_WORDCOUNTER_H

#include <set>
#include <initializer_list>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <istream>

namespace datastructures {

    class Word {
    private:
        std::string word_;
    public:
        Word();

        Word(std::string);

        ~Word();

        void SetWord(std::string word) { word_ = word; };

        std::string GetWord() const { return word_; };
    };

    class Counts {
    private:
        int counter_;
    public:
        Counts();

        Counts(int);

        ~Counts();

        int GetCounts() const { return counter_; };

        void PlusCounts() { ++counter_; };
    };

    class WordCounter {
    private:
        std::map<Word, Counts> dictionary_;

    public:
        WordCounter();//konstruktor inicjalizujacy pusty slownik

        WordCounter(const std::initializer_list<Word> words);  //konstruktor z listą inicjalizacyjną pozwalający zliczyć podane słowa

        ~WordCounter();

        int DistinctWords();

        int TotalWords();

        std::set<Word> Words();

        WordCounter FromInputStream(std::istream *input);

        int operator[](std::string index) {
            Word index1 = Word(index);
            return dictionary_.find(index1) != dictionary_.end() ? dictionary_[index1].GetCounts() : 0 ;
        }
    };

    inline bool operator<(const Word word1, const Word word2) {
        return word1.GetWord()[0] < word2.GetWord()[0] ? true : false;
    }

    inline bool operator==(const Word word1, const Word word2) {
        return word1.GetWord()[0] == word2.GetWord()[0] ?true : false;
    }

    inline bool operator==(const Counts count1, const Counts count2) {
        return count1.GetCounts() == count2.GetCounts()?true : false;
    }
}
#endif //JIMP_EXERCISES_WORDCOUNTER_H
