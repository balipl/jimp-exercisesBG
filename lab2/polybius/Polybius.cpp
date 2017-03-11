//
// Created by ASUSTek on 2017-03-09.
//

#include "Polybius.h"

ifstream opened_file("file.txt");
ofstream saving_file ("file.txt", ios_base::in | ios_base::app);

if(!opened_file)
cout << "Nie można otworzyć pliku!" << endl;

if(!saving_file)
cout << "Nie można otworzyć pliku!" << endl;


string PolybiusCrypt(string message) {

    char line[1];
    while(!myfile.eof()){
        myfile.getline(line,1);
        cout << line;
    }


}
string PolybiusDecrypt(string crypted) {

}


    opened_file.close();
    saving_file.close();
    return 0;

}