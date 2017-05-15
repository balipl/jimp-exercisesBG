//
// Created by Grove on 2017-05-11.
//

#include <set>
#include <map>
#include <vector>
#include <string>
#include "Algo.h"

#include "Algo.h"

namespace algo{



    void CopyInto(const std::vector<int> &v, int n_elements, std::vector<int> *out) {
std::copy_n(v.begin(),n_elements,std::back_inserter(*out));
    }

    std::set<std::string> Keys(const std::map<std::string, int> &m) {
        std::set<std::string> os;

        std::transform(m.begin(),m.end(),std::inserter(os, os.begin()), [](const auto &v){return v.first;});
        return os;
    }

    std::vector<int> Values(const std::map<std::string, int> &m) {
        std::vector<int> v;
        std::transform(m.begin(),m.end(),std::back_inserter(v), [](const auto &mp){return mp.second;});
        return v;
    }

    bool Contains(const std::vector<int> &v, int element) {
        return false;
    }

    bool ContainsKey(const std::map<std::string, int> &v, const std::string &key) {
        auto search = std::find_if(v.begin(),v.end(),[&key](auto v){return v == key;});
        return search != v.end();
    }

    bool ContainsValue(const std::map<std::string, int> &v, int value) {
        return false;
    }

}