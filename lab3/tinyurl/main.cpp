//
// Created by bartek on 21.03.17.
//

#include "TinyUrl.h"

using std::cout;
using std::endl;
using std::string;

int main() {
    auto codec = tinyurl::Init();
    codec->hash_tab = {'0', '0', '0', '0', '0', '0'};
    cout << tinyurl::Encode("https://google.com", &codec) << endl;
    cout << tinyurl::Encode("https://google.com1", &codec) << endl;
    string cos12 = "000001";
    cout << tinyurl::Decode(&codec, cos12);
}