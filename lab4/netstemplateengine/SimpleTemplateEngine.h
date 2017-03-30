//
// Created by bartek on 27.03.17.
//

#ifndef JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
#define JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H

#include <string>
#include <unordered_map>
#include <iostream>
#include <map>

namespace nets {
    class View {
    public:
        View();

        View(std::string text);

        ~View();

        std::string Render(const std::unordered_map<std::string, std::string> &model) const;

    private:
        std::string text_;
    };
}
#endif //JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H