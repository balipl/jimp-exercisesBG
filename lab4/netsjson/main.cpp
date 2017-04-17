#include "SimpleJson.h"

using std::vector;
using std::map;
using std::cout;
using std::endl;
using std::string;
using nets::JsonValue;
using std::literals::operator""s;

int main() {

    map<string, JsonValue> object{{"name", {"Maciej"s}}, {"age", {44}}, {"account_balance", {-107.89}}};
    JsonValue simple_object_value{object};
    string obj_str = simple_object_value.ToString();
    std::cout << obj_str;
}