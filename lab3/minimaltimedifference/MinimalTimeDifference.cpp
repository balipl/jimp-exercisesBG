//
// Created by bartek on 16.03.17.
//x

#include "MinimalTimeDifference.h"

namespace minimaltimedifference {
    using std::string;
    using std::regex;
    using std::smatch;
    using std::stoi;
    using std::vector;

    unsigned int ToMinutes(string time_HH_MM) {
        unsigned int minutes;

        regex pattern{R"((\d{1,2})+:+(\d{2}))"};
        smatch matches;
        regex_match(time_HH_MM, matches, pattern);
        minutes = stoi(matches[1]) * 60 + stoi(matches[2]);

        return minutes;
    }

    unsigned int MinimalTimeDifference(vector<string> times) {
        vector<int> t_minutes = {};
        unsigned int min = 1441;

        for (int i = 0; i < times.size(); ++i) {
            t_minutes.push_back(ToMinutes(times[i]));
        }
        sort(t_minutes.begin(), t_minutes.end());

        for (int j = 0; j < t_minutes.size() - 1; ++j) {
            if (t_minutes[j + 1] - t_minutes[j] < min) {
                min = t_minutes[j + 1] - t_minutes[j];
            }
        }

        if (t_minutes[0] + 1440 - t_minutes[t_minutes.size() - 1] < min) {
            min = t_minutes[0] + 1440 - t_minutes[t_minutes.size() - 1];
        }

        return min;
    }
}