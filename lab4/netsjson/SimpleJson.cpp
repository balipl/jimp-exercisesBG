//
// Created by bartek on 27.03.17.
//

#include "SimpleJson.h"

using std::vector;
using std::map;
using std::cout;
using std::endl;
using std::to_string;
using std::stringstream;
using std::string;
using nets::JsonValue;
using std::literals::operator""s;


namespace nets {

    JsonValue::JsonValue() {}

    JsonValue::JsonValue(int value_int) {
        value_int_ = value_int;
        type_of_value_ = 0;
    }

    JsonValue::JsonValue(double value_double) {
        value_double_ = value_double;
        type_of_value_ = 1;
    }

    JsonValue::JsonValue(string value_string) {
        value_string_ = value_string;
        type_of_value_ = 2;
    }

    JsonValue::JsonValue(bool value_bool) {
        value_bool_ = value_bool;
        type_of_value_ = 3;
    }

    JsonValue::JsonValue(vector<JsonValue> value_vector) {
        value_vector_ = value_vector;
        type_of_value_ = 4;
    }

    JsonValue::JsonValue(map<std::string, JsonValue> value_map) {
        value_map_ = value_map;
        type_of_value_ = 5;
    }

    JsonValue::~JsonValue() {}

    std::experimental::optional<JsonValue> JsonValue::ValueByName(const string &name) const {
        auto search = value_map_.find(name);
        if (search != value_map_.end()) {
            return search->second;
        }
    }

    string SuperString(string weak_string) {
        string exit_str = "\"";
        int i = 0;
        while (weak_string[i] != '\0') {
            if (weak_string[i] == '\\' or weak_string[i] == '\"') {
                exit_str += "\\";
            }
            exit_str += weak_string[i];
            i++;
        }
        exit_str += "\"";

        return exit_str;
    }

    string JsonValue::ToString() const {
        string exit_str;
        switch (type_of_value_) {
            case 0: {
                return to_string(value_int_);
            }
            case 1: {
                stringstream ss;
                ss << value_double_;
                string s = ss.str();
                return s;
            }
            case 2: {
                string exit_str = "\"";
                int i = 0;
                while (value_string_[i] != '\0') {
                    if (value_string_[i] == '\\' or value_string_[i] == '\"') {
                        exit_str += "\\";
                    }
                    exit_str += value_string_[i];
                    i++;

                }
                exit_str += "\"";
                return exit_str;
            }
            case 3: {
                if (value_bool_ == true) return "true";
                else return "false";
            }
            case 4: {
                string exit_str = "[";
                for (int i = 0; i < value_vector_.size() - 1; ++i) {
                    exit_str += value_vector_[i].ToString() + ", ";
                }
                exit_str += value_vector_[value_vector_.size() - 1].ToString() + "]";
                return exit_str;
            }
            case 5: {
                string exit_str = "{";
                for (auto n: value_map_) {
                    exit_str += SuperString(n.first);
                    exit_str += ": ";
                    exit_str += n.second.ToString();
                    exit_str += ", ";
                }
                exit_str.pop_back();
                exit_str.pop_back();
                exit_str += "}";

                return exit_str;
            }
            default: {
                return 0;
            }

        }

    }

}