//
// Created by ASUSTek on 2017-03-09.
//

#include "Polybius.h"

using namespace std;

ifstream opened_file("file.txt");

ofstream saving_file ("file.txt", ios_base::in | ios_base::app);

if(!opened_file)
cout << "Nie można otworzyć pliku!" << endl;

if(!saving_file)
cout << "Nie można otworzyć pliku!" << endl;

if(!saving_file)
cout << "Nie można otworzyć pliku!" << endl;

string PolybiusCrypt(string message) {

    char line[256];
    while(!myfile.eof()){
        myfile.getline(line,256);
        cout << line;
    }


}
string PolybiusDecrypt(string crypted){

    opened_file.close();
    saving_file.close();
    return 0;

}