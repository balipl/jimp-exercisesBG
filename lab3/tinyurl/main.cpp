//
// Created by bartek on 21.03.17.
//

#include "TinyUrl.h"

using namespace std;
int main(){
    auto codec = tinyurl::Init();
    codec->tab= {'0','0','0','0','0','0'};

    cout << "Nic";

    cout << tinyurl::Encode("https://google.com", &codec)<<endl;
    cout << tinyurl::Encode("https://google.com1", &codec)<<endl;
    string cos12 = "000001";
    cout << tinyurl::Decode(&codec, cos12);
    //tinyurl::NextHash(&tab1);

}