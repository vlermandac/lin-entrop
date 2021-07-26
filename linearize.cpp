// lee y despliega una imagen .tif
// biblioteca cimg soporta differentes formatos de imagenes
// sudo apt install cimg-dev
// compilar: g++ -o tifexample linearize.cpp -lm -lpthread -lX11

#include "../CImg-2.9.8_pre052421/CImg.h"
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <fstream>

using namespace std;
using namespace cimg_library;

int main(int argc, char *argv[]){

    for(int i = 1; i < argc; i++){

        CImg<float> src(argv[i]);
        CImg<float> img(256*256, 1, 1, 3, 0);

        ofstream file;
        string name = "new/";
        name+=argv[i];
        name.pop_back();name.pop_back();name.pop_back();name.pop_back();
        cout<<name<<endl;
        file.open(name.c_str());//, ios::binary);

        //Row Major
        int aux, r, g, b, x = 0;
        for(int i = 0; i < 256; i++){
            for(int j = 0; j < 256; j++){
                aux = 0;
                r = src(j, i, 0);img(x, 0, 0) = r;// r = r << 16;
                g = src(j, i, 1);img(x, 0, 1) = g;// g = g << 8;
                b = src(j, i, 2);img(x, 0, 2) = b;
                aux |= r; aux |= g; aux |= b;
                //file.write(reinterpret_cast<const char*>(&aux), sizeof aux);
                file<<aux;
                x++;
            }
        }
        file.close();
 //   img.display();
    }

 //   row_major_image.save(name);

    return 0;
}
