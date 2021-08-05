// biblioteca cimg soporta differentes formatos de imagenes
// sudo apt install cimg-dev
// compilar: g++ -o rowmajor linearize.cpp -lm -lpthread -lX11

#include "CImg-2.9.8_pre052421/CImg.h"
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <fstream>

using namespace std;
using namespace cimg_library;

int main(int argc, char *argv[]){

    for(int i = 1; i < argc; i++){

        CImg<float> src(argv[i]);
        //CImg<float> img(256*256, 1, 1, 3, 0);

        ofstream file;
        string aux(argv[i]);
        aux = aux.substr(aux.find_last_of("/") + 1);
        string name = "r_lin_files/"; name += aux;
        name = name.substr(0, name.find_last_of("."));
        cout<<name<<endl;
        file.open(name.c_str(), ios::binary);

        //Row Major
        int r, g, b, x = 0;
        for(int i = 0; i < 256; i++){
            for(int j = 0; j < 256; j++){
                r = src(j, i, 0);
                g = src(j, i, 1);
                b = src(j, i, 2);
                file.write(reinterpret_cast<const char*>(&r), 1);
                file.write(reinterpret_cast<const char*>(&g), 1);
                file.write(reinterpret_cast<const char*>(&b), 1);
                x++;
            }
        }
        file.close();
 //   img.display();
    }

 //   row_major_image.save(name);

    return 0;
}
