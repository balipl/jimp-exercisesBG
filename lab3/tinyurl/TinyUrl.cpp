//
// Created by bartek on 21.03.17.
//

#include "TinyUrl.h"


namespace tinyurl {
    using namespace std;

    std::unique_ptr<TinyUrlCodec> Init(){
        unique_ptr<TinyUrlCodec> p = make_unique<TinyUrlCodec>();
        return p;
    }

    void NextHash(std::array<char, 6> *state){
        string dict = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        string newurl;
        bool next_line = 1;
        for (int i = 5; i >=0 ; --i) {

            if ((*state)[i] == 'z' && next_line == 1)
            {(*state)[i] = '0'; }
            else if (next_line == 1)
            {(*state)[i] = dict[dict.find(((*state)[i])) + 1];
            next_line = 0;}

            newurl = (*state)[i] + newurl;
        }


    }
    std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec){
        string newurl;


        for (int i = 0; i < 6; ++i) {
            newurl += (*codec)->tab[i];
        }
        NextHash(&(*codec)->tab);

        (*codec)->mapa[newurl]=url;
        return newurl;
    }
    std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash){
        string url;
        url = codec->mapa[hash];
        return url;
    }


}