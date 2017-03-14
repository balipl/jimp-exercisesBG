//
// Created by ASUSTek on 2017-03-14.
//
#include "Polybius.h"

using namespace std;

int main(int argc, char** argv) {
    int test1 = 0;

    ifstream open_file(argv[1]);
    char word[64];

    if(!open_file)
        cout << "Nie można otworzyć pliku!" << endl;

    ofstream save_file (argv[2], ios_base::in | ios_base::app);

    if(!save_file)
        cout << "Nie można otworzyć pliku!" << endl;


    if(atoi(argv[2])==1)
        { while(open_file >> word) {
                save_file << PolybiusCrypt(word);
            }
        }

    if(atoi(argv[2])==0){
        while(open_file >> word) {
            cout << PolybiusDecrypt(word);
            save_file << PolybiusDecrypt(word);

    }


        open_file.close();
        save_file.close();
    return 0;

}}