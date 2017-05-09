//
// Created by Grove on 2017-05-03.
//

#ifndef JIMP_EXERCISES_MOVIESUBTITLES_H
#define JIMP_EXERCISES_MOVIESUBTITLES_H

#include <sstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <iomanip>
#include <regex>

using std::istream;
using std::ostream;
using std::string;
using std::regex;
using std::setw;
using std::setfill;
using std::cout;
using std::stoi;
using std::regex_match;
using std::to_string;
using std::endl;
namespace moviesubs {


    class MovieSubtitles {
    public:
        virtual void ShiftAllSubtitlesBy(int delay, int fps, istream *ins, ostream *outs);
    };

    class MicroDvdSubtitles : public MovieSubtitles {
    public:
        virtual void ShiftAllSubtitlesBy(int delay, int fps, istream *ins, ostream *outs) override;


    };

    class SubRipSubtitles : public MovieSubtitles {
    public:
        virtual void ShiftAllSubtitlesBy(int delay, int fps, istream *ins, ostream *outs) override;
    };





    class MovieSubtitlesException : public std::invalid_argument {
    public:
        MovieSubtitlesException(std::string err_message) : std::invalid_argument{err_message} {};
    protected:
        int line_number_;
        std::string line_text_;

    };

    class NegativeFrameAfterShift : public MovieSubtitlesException {
    public:
        NegativeFrameAfterShift(int line_number, const char *line);
    };

    class SubtitleEndBeforeStart : public MovieSubtitlesException {
    public:
        SubtitleEndBeforeStart(int line_number, const char *line);
        int LineAt(void) const;
    };

    class InvalidSubtitleLineFormat : public MovieSubtitlesException {
    public:
        InvalidSubtitleLineFormat(int line_number, const char *line);
    };

    class MissingTimeSpecification : public MovieSubtitlesException {
    public:
        MissingTimeSpecification(int line_number, const char *line);
    };

    class OutOfOrderFrames : public MovieSubtitlesException {
    public:
        OutOfOrderFrames(int line_number, const char *line);
    };
}
#endif //JIMP_EXERCISES_MOVIESUBTITLES_H
