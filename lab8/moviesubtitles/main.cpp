//
// Created by Grove on 2017-05-07.
//

#include <MovieSubtitles.h>
using std::cout;
int main(){
    auto subs = std::make_unique<moviesubs::SubRipSubtitles>();
    std::stringstream in {"1\n00:05:54,555 --> 00:05:56,722\nText\n\n2\n00:06:06,433 --> 00:06:07,801\nNEWLINE\n"};
cout << "DX";
    subs->ShiftAllSubtitlesBy(300, 24, &in, &cout);
    return 0;
}