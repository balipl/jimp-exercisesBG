//
// Created by Grove on 2017-04-27.
//

#ifndef JIMP_EXERCISES_PESEL_H
#define JIMP_EXERCISES_PESEL_H

#include <string>

namespace academia {
    class AcademiaDataValidationError {
    public:
        AcademiaDataValidationError(std::string error_str);

    private:
        std::string error_str_;

    };


    class InvalidPeselChecksum : public AcademiaDataValidationError {
    public:
        InvalidPeselChecksum(std::string pesel) : AcademiaDataValidationError("EROR1") , pesel_(pesel){}
    private:
        std::string pesel_;
    };
    class InvalidPeselLength : public AcademiaDataValidationError {

    };
    class InvalidPeselCharacter :public AcademiaDataValidationError{

    };

    class Pesel {
    public:
        Pesel();

        Pesel(std::string pesel);

        ~Pesel();

        void ValidatePESEL(std::string);
    };

}
#endif //JIMP_EXERCISES_PESEL_H
