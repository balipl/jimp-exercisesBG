//
// Created by bartek on 21.03.17.
//

#include "TinyUrl.h"


namespace tinyurl {
    using std::unique_ptr;
    using std::make_unique;

    std::unique_ptr<TinyUrlCodec> Init() {
        unique_ptr<TinyUrlCodec> p = make_unique<TinyUrlCodec>();
        return p;
    }

    void NextHash(std::array<char, 6> *state) {
        string symbols = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        string new_url;
        bool next_line = 1;
        for (int i = 5; i >= 0; --i) {
            if ((*state)[i] == 'z' && next_line == 1) {
                (*state)[i] = '0';
            } else if (next_line == 1) {
                (*state)[i] = symbols[symbols.find(((*state)[i])) + 1];
                next_line = 0;
            }
            new_url = (*state)[i] + new_url;
        }
    }

    std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec) {
        string new_url;
        for (int i = 0; i < 6; ++i) {
            new_url += (*codec)->hash_tab[i];
        }
        NextHash(&(*codec)->hash_tab);

        (*codec)->mapa[new_url] = url;
        return new_url;
    }

    std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash) {
        string url;
        url = codec->mapa[hash];
        return url;
    }
}