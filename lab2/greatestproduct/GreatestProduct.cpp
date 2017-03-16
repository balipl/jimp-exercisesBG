//
// Created by ASUSTek on 2017-03-09.
//


#include "GreatestProduct.h"
using namespace std;

int GreatestProduct(const vector<int> &numbers, int k){
    vector<int> liczby = numbers;
    sort (liczby.begin(), liczby.end());
    int wynik = 1;
    int dodatnie = 1;
    int ujemne = 0;
    for (int i = 0; i < k/2 ; ++i) {
        if(liczby[liczby.size()-dodatnie]*liczby[liczby.size()-dodatnie-1]>liczby[ujemne]*liczby[ujemne+1] or (liczby[liczby.size()-dodatnie]<0 and k%2!=0)){
            wynik = wynik * liczby[liczby.size()-dodatnie]*liczby[liczby.size()-dodatnie-1];
            dodatnie+=2; } else{
            wynik = wynik * liczby[ujemne]*liczby[ujemne+1];
            ujemne +=2;
        }
    }
    if(k%2!=0){
        wynik = wynik*liczby[liczby.size()-dodatnie];
    }
    return wynik;





}

