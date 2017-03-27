//
// Created by bartek on 27.03.17.
//

#ifndef JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
#define JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H

#include <string>
#include <unordered_map>

namespace nets {
    class View {
    private:
        std::string text_;
    public:
        View();

        View(std::string text);

        ~View();


        std::string Render(const std::unordered_map <std::string, std::string> &model) const;




    };

}
#endif //JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
