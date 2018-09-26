#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

///cambiar path y el inicio del rango de imagenes
///Ejemplo para las de bohemia
const string MY_PATH = "C:\\Users\\mimit\\OneDrive\\5 semestre\\semana_i\\Bohemia pilsner botella 355ml";
const int INICIO = 1381;
const int FIN = 1470;


int main() {
	string filename, num, line, newFile, newPath;
	ifstream archivo;
	ofstream salida;
	char buffer[32];
    newFile = "";

	for(int i=INICIO;i<FIN + 1; i++) {
        num = string(itoa(i, buffer, 10));
        filename = "IMG_" + num + ".xml";
        cout << filename << endl;
        archivo.open(filename.c_str());
        newFile = "";
        while(!archivo.eof()) {
            getline(archivo, line);
            if(line.find("<path>") != -1) {
                newPath = "      <path>" + MY_PATH + "\\IMG_" + num + ".JPG</path>";
                printf("Can open the file path:\n %d", i);
                cout << line << endl;
                cout << newPath << endl;
                newFile = newFile + newPath + "\n";
            } else {
                newFile = newFile + line + "\n";
            }
        }
        archivo.close();
        salida.open(filename.c_str());
        salida << newFile;
        salida.close();
	}
	system("pause");
	return 0;
}
