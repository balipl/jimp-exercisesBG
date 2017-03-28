//
// Created by bartek on 27.03.17.
//

#ifndef JIMP_EXERCISES_SIMPLEJSON_H
#define JIMP_EXERCISES_SIMPLEJSON_H

#include <experimental/optional>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <regex>


namespace nets {
//Używana struktura danych: JsonValue
    class JsonValue {
    public:
        JsonValue();
        JsonValue(int value_int);
        JsonValue(double value_double);
        JsonValue(std::string value_string);
        JsonValue(bool value_bool);
        JsonValue(std::vector<JsonValue> value_vector);
        JsonValue(std::map<std::string, JsonValue> value_map);
        ~JsonValue();


        //sygnatury metod w klasie View
        std::experimental::optional<JsonValue> ValueByName(const std::string &name) const;
        std::string ToString() const;
    private:
        int value_int_;
        double value_double_;
        std::string value_string_;
        bool value_bool_;
        std::vector<nets::JsonValue> value_vector_;
        std::map<std::string, nets::JsonValue> value_map_;
        int type_of_value_;
    };
}

#endif //JIMP_EXERCISES_SIMPLEJSON_H
