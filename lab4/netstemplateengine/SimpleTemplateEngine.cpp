//
// Created by bartek on 27.03.17.
//

#include "SimpleTemplateEngine.h"

using std::string;
namespace nets {

    View::View() : text_("") {
    }

    View::View(string text) {
        text_ = text;
    }

    View::~View() {}

    string View::Render(const std::unordered_map<string, string> &model) const {
        string exit_text;
        string word;
        int i = 0;

        while (text_[i] != '\0') {
            if (text_[i] == '{' and text_[i + 1] == '{' and text_[i + 2] != '{') {
                word = "";
                i += 2; //omijam 2 klamry początkowe
                while (text_[i] != '}') {
                    word += text_[i];
                    i += 1;
                }
                if (text_[i + 1] != '}') //sprawdzam czy na koncu sa 2 klamry zamykajace
                {
                    exit_text += "{{" + word;  //jesli nie, to wracam do poczatkowej wersji
                } else {
                    auto finded = model.find(word);
                    if (finded != model.end()) //sprawdzam czy szukana fraza znajduje sie w mapie
                    {
                        exit_text += finded->second;
                    }
                    i += 2;
                }
            }
            if (i < text_.size()) {
                exit_text += text_[i];
            }
            i += 1;
        }
        if (exit_text[exit_text.size() - 1] == '\0') {
            exit_text.pop_back();
        }
        
        return exit_text;
    }
}