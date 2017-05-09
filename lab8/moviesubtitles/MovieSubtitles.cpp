//
// Created by Grove on 2017-05-07.
//

#include "MovieSubtitles.h"

namespace moviesubs {

    void MovieSubtitles::ShiftAllSubtitlesBy(int delay, int fps, istream *ins, ostream *outs) {

    }

    void SubRipSubtitles::ShiftAllSubtitlesBy(int delay, int fps, istream *ins, ostream *outs) {

    }


    void MicroDvdSubtitles::ShiftAllSubtitlesBy(int delay, int fps, istream *ins, ostream *outs) {

    }

    NegativeFrameAfterShift::NegativeFrameAfterShift(int line_number, const char *line) {

    }

    OutOfOrderFrames::OutOfOrderFrames(int line_number, const char *line) {

    }

    InvalidSubtitleLineFormat::InvalidSubtitleLineFormat(int line_number, const char *line) {

    }

    SubtitleEndBeforeStart::SubtitleEndBeforeStart(int line_number, const char *line) {

    }

    int SubtitleEndBeforeStart::LineAt(void) const {
        return 0;
    }

    MissingTimeSpecification::MissingTimeSpecification(int line_number, const char *line) {

    }


}