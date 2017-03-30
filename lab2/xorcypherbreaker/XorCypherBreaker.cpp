//
// Created by bartek on 16.03.17.
//x

#include "XorCypherBreaker.h"

using namespace std;

string XorCypherBreaker(const vector<char> &cryptogram,
                        int key_length,
                        const vector<string> &dictionary) {

    int count_words = 0;
    char cipher_1;
    char cipher_2;
    char cipher_3;
    string a, b, c;
    string whole_cipher;
    string decrypted;

    for (int i = 0; i < 26; i = i + 1) {
        cipher_1 = 'a' + i;
        for (int j = 0; j < 26; j = j + 1) {
            cipher_2 = 'a' + j;
            for (int k = 0; k < 26; k = k + 1) {
                cipher_3 = 'a' + k;

                whole_cipher = cipher_1;
                whole_cipher += cipher_2;
                whole_cipher += cipher_3;

                decrypted = "";
                for (int l = 0; l < cryptogram.size() - 3; l = l + 3) {

                    a = cryptogram[l] ^ whole_cipher[0];
                    b = cryptogram[l + 1] ^ whole_cipher[1];
                    c = cryptogram[l + 2] ^ whole_cipher[2];
                    decrypted += a;
                    decrypted += b;
                    decrypted += c;
                }
                for (int m = 0; m < decrypted.size() - 3; ++m) {
                    char x, y, z;
                    x = decrypted[m];
                    y = decrypted[m + 1];
                    z = decrypted[m + 2];
                    for (int v = 0; v < 40; v++) {
                        if (x == dictionary[v][0] and y == dictionary[v][1] and z == dictionary[v][2])
                            count_words++;
                    }
                }

                if (count_words > cryptogram.size() / 25) {
                    return whole_cipher;
                }
                count_words = 0;
                decrypted = "";

            }
        }
    }
}



