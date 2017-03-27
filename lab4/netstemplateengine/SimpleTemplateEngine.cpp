//
// Created by bartek on 27.03.17.
//

#include "SimpleTemplateEngine.h"

namespace nets{

    View::View() : text_(""){

    }

    View::View(std::string text) {
    text_ = text;
    }

    View::~View() {
    }

    std::string View::Render(const std::unordered_map<std::string, std::string> &model) const {
        std::string exit_text;
        std::string word;
        int i = -1;
        while(text_[i+1]!='\0'){
            i+=1;
            if(text_[i]=='{' && text_[i+1] == '{'){
                i+=2;
                word = "";
                while(text_[i]!='}' && text_[i+1]!='}') {
                    word += text_[i];
                    i+=1;
                }
                auto finded = model.find(word);
                exit_text += finded->second;
            }
            exit_text += text_[i];


        }

        return exit_text;
    }


}