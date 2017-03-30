//
// Created by ASUSTek on 2017-03-14.
//
#include "Polybius.h"

using std::ifstream;
using std::cout;
using std::ios_base;
using std::ofstream;
using std::endl;

int main(int argc, char **argv) {

    char word[64];
    ifstream open_file(argv[1]);
    if (!open_file)
        cout << "Nie można otworzyć pliku!" << endl;


    ofstream save_file(argv[2], ios_base::in | ios_base::app);
    if (!save_file)
        cout << "Nie można otworzyć pliku!" << endl;


    if (argv[3] == "1") {
        while (open_file >> word) {
            save_file << PolybiusCrypt(word);
        }
    }

    if (argv[3]== "0") {
        while (open_file >> word) {
            save_file << PolybiusDecrypt(word);
        }
    }
        open_file.close();
        save_file.close();
        return 0;

    }
