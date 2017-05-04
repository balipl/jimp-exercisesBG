//
// Created by Grove on 2017-05-03.
//

#ifndef JIMP_EXERCISES_MOVIESUBTITLES_H
#define JIMP_EXERCISES_MOVIESUBTITLES_H

#include <sstream>
#include <iostream>
#include <stdexcept>
#include <string>

using std::istream;

namespace moviesubs {


    class MovieSubtitles {
    public:
        virtual void ShiftAllSubtitlesBy(int delay, int fps, istream *ins, istream *outs);
    };

    class MicroDvdSubtitles : public MovieSubtitles {
    public:
        virtual void ShiftAllSubtitlesBy(int delay, int fps, istream *ins, istream *outs) override;


    };

    class SubRipSubtitles : public MovieSubtitles {
        virtual void ShiftAllSubtitlesBy(int delay, int fps, istream *ins, istream *outs) override;



    };

    class MovieSubtitlesException : public std::invalid_argument {
    public:
        MovieSubtitlesException(std::string errmessage) : std::invalid_argument{errmessage} {};
    protected:
        int line_number_;
        std::string line_;

    };

    class NegativeFrameAfterShift : public MovieSubtitlesException {
    public:
        NegativeFrameAfterShift(int line_number, const char *line);
    };

    class SubtitleEndBeforeStart {
    public:
        SubtitleEndBeforeStart(int line_number, const char *line);
    };

    class InvalidSubtitleLineFormat {
    public:
        InvalidSubtitleLineFormat(int line_number, const char *line);
    };

    class MissingTimeSpecification {
    public:
        MissingTimeSpecification(int line_number, const char *line);
    };

    class OutOfOrderFrames {
    public:
        OutOfOrderFrames(int line_number, const char *line);
    };
}
#endif //JIMP_EXERCISES_MOVIESUBTITLES_H
