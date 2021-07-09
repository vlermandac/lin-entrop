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

        ofstream file;
        string name = "new/";
        name+=argv[i];
        name.pop_back();name.pop_back();name.pop_back();name.pop_back();
        cout<<name<<endl;
        file.open(name.c_str(), ios::binary);

        //Row Major
        int aux, r, g, b;
        for(int i = 0; i < 256; i++){
            for(int j = 0; j < 256; j++){
                aux = 0;
                r = src(j, i, 0);// r = r << 16;
                //g = src(j, i, 1); g = g << 8;
                //b = src(j, i, 2);
                //aux |= r; aux |= g; aux |= b;
                file.write(reinterpret_cast<const char*>(&r), sizeof r);
            }
        }
        file.close();
    }

 //   row_major_image.save(name);
 //   row_major_image.display();

    return 0;
}
