//
// Created by Grove on 2017-05-07.
//

#include "MovieSubtitles.h"

namespace moviesubs {

    void MovieSubtitles::ShiftAllSubtitlesBy(int delay, int fps, istream *ins, ostream *outs) {}

    void MicroDvdSubtitles::ShiftAllSubtitlesBy(int delay, int fps, istream *ins, ostream *outs) {
        int one_frame_lenght = 1000 / fps;
        int one_frame_delay = delay / one_frame_lenght;
        int line_number = 1;
        string line_text;
        regex pattern{"^\\{(\\d{1,})\\}\\{(\\d{1,})\\}(.*)$"};

        if (fps < 0) {
            throw std::invalid_argument("FPS error");
        } else {

            while (getline(*ins, line_text)) {
                std::smatch result;
                string out_text = "";

                if (regex_match(line_text, result, pattern)) {
                    if (stoi(result[1]) > stoi(result[2])) {
                        throw (SubtitleEndBeforeStart(line_number, line_text.c_str()));
                    }
                    int new_start = stoi(result[1]) + one_frame_delay;
                    if (new_start < 0) {
                        throw (NegativeFrameAfterShift(line_number, line_text.c_str()));
                    }

                    int new_end = stoi(result[2]) + one_frame_delay;

                    out_text = "{" + to_string(new_start) + "}{" + to_string(new_end) + "}" + result[3].str();

                    *outs << out_text << endl;
                    line_number++;

                } else {
                    throw InvalidSubtitleLineFormat(line_number, line_text.c_str());
                }
            }
        }
    }


    void SubRipSubtitles::ShiftAllSubtitlesBy(int delay, int fps, istream *ins, ostream *outs) {
        int line_number;
        string line_text;

        regex number_pattern{"^(\\d+)$"};
        regex pattern{"^(\\d{2}):(\\d{2}):(\\d{2}),(\\d{3}) --> (\\d{2}):(\\d{2}):(\\d{2}),(\\d{3})$"};
        regex empty_pattern{"^$"};
        bool previous_line_empty = 1;
        bool previous_line_number = 0;
        bool previous_line_time = 0;
        int previous_number = 0;

        if (fps < 0) {
            throw std::invalid_argument("FPS error");
        } else {

            while (getline(*ins, line_text)) {
                std::smatch result;
                if (previous_line_empty) {
                    if (regex_match(line_text, result, number_pattern)) {
                        if (stoi(result[1]) != previous_number + 1) {
                            throw OutOfOrderFrames(line_number, line_text.c_str());
                        } else {
                            previous_line_empty = 0;
                            previous_line_number = 1;
                            previous_line_time = 0;

                            previous_number++;

                            *outs << line_text << endl;
                        }
                    } else {
                        throw InvalidSubtitleLineFormat(line_number, line_text.c_str());
                    }

                } else if (previous_line_number) {
                    if (regex_match(line_text, result, pattern)) {
                        string exit_text = "";
                        int start_time = (((stoi(result[1])) * 60 + stoi(result[2])) * 60 + stoi(result[3])) * 1000 +
                                         stoi(result[4]);
                        int end_time = (((stoi(result[5])) * 60 + stoi(result[6])) * 60 + stoi(result[7])) * 1000 +
                                       stoi(result[8]);

                        if (start_time > end_time) {
                            throw SubtitleEndBeforeStart(previous_number, line_text.c_str());
                        }

                        start_time += delay;

                        if (start_time < 0) {
                            throw NegativeFrameAfterShift(line_number, line_text.c_str());
                        }

                        end_time += delay;

                        string s1 = miliseconds_to_string(start_time);
                        string s2 = miliseconds_to_string(end_time);

                        *outs << s1 << " --> " << s2 << endl;
                        line_number++;

                        previous_line_empty = 0;
                        previous_line_number = 0;
                        previous_line_time = 1;

                    } else {
                        throw InvalidSubtitleLineFormat(line_number, line_text.c_str());
                    }
                } else if (previous_line_time) {
                    if (regex_match(line_text, result, empty_pattern)) {
                        previous_line_empty = 1;
                        previous_line_number = 0;
                        previous_line_time = 0;
                        *outs << line_text << endl;
                    } else {
                        *outs << line_text << endl;
                    }
                }
            }


        }
    }

    string SubRipSubtitles::miliseconds_to_string(int time) const {
        int time_p4 = time % 1000;
        time /= 1000;
        int time_p3 = time % 60;
        time /= 60;
        int time_p2 = time % 60;
        int time_p1 = time / 60;

        std::ostringstream ss;
        ss << setw(2) << setfill('0') << time_p1 << ":";
        ss << setw(2) << setfill('0') << time_p2 << ":";
        ss << setw(2) << setfill('0') << time_p3 << ",";
        ss << setw(3) << setfill('0') << time_p4;
        string s1(ss.str());

        return s1;
    }


    NegativeFrameAfterShift::NegativeFrameAfterShift(int line_number, const char *line) : MovieSubtitlesException(
            "At line " + std::to_string(line_number) + ": " + line) {
        this->line_number_ = line_number;
        this->line_text_ = line;
    }

    OutOfOrderFrames::OutOfOrderFrames(int line_number, const char *line) : MovieSubtitlesException(
            "At line " + std::to_string(line_number) + ": " + line) {
        this->line_number_ = line_number;
        this->line_text_ = line;

    }

    InvalidSubtitleLineFormat::InvalidSubtitleLineFormat(int line_number, const char *line) : MovieSubtitlesException(
            "At line " + std::to_string(line_number) + ": " + line) {
        this->line_number_ = line_number;
        this->line_text_ = line;

    }

    SubtitleEndBeforeStart::SubtitleEndBeforeStart(int line_number, const char *line) : MovieSubtitlesException(
            "At line " + std::to_string(line_number) + ": " + line) {
        this->line_number_ = line_number;
        this->line_text_ = line;

    }

    MissingTimeSpecification::MissingTimeSpecification(int line_number, const char *line) : MovieSubtitlesException(
            "At line " + std::to_string(line_number) + ": " + line) {
        this->line_number_ = line_number;
        this->line_text_ = line;

    }

    int SubtitleEndBeforeStart::LineAt(void) const {
        return line_number_;
    }


}