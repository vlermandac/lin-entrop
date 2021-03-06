// lee y despliega una imagen .tif

// sudo apt install cimg-dev
// compilar: g++ -o zorder linearize_z_order.cpp -lm -lpthread -lX11

#include "CImg-2.9.8_pre052421/CImg.h"
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <fstream>

using namespace std;
using namespace cimg_library;

CImg<float> src;
//CImg<float> img;

uint32_t zorder(uint16_t xPos, uint16_t yPos)
{
    static const uint32_t MASKS[] = {0x55555555, 0x33333333, 0x0F0F0F0F, 0x00FF00FF};
    static const uint32_t SHIFTS[] = {1, 2, 4, 8};

    uint32_t x = xPos;
    uint32_t y = yPos;

    x = (x | (x << SHIFTS[3])) & MASKS[3];
    x = (x | (x << SHIFTS[2])) & MASKS[2];
    x = (x | (x << SHIFTS[1])) & MASKS[1];
    x = (x | (x << SHIFTS[0])) & MASKS[0];

    y = (y | (y << SHIFTS[3])) & MASKS[3];
    y = (y | (y << SHIFTS[2])) & MASKS[2];
    y = (y | (y << SHIFTS[1])) & MASKS[1];
    y = (y | (y << SHIFTS[0])) & MASKS[0];

    const uint32_t result = x | (y << 1);
    return result;
}

int main(int argc, char *argv[]){

    for(int i = 1; i < argc; i++){

        src.clear();
        src.assign(argv[i]);
        //img.assign(256*256, 1, 1, 3, 0);

        ofstream file;
        string aux(argv[i]);
        aux = aux.substr(aux.find_last_of("/") + 1);
        string name = "z_lin_files/"; name += aux;
        name = name.substr(0, name.find_last_of("."));
        cout<<name<<endl;
        file.open(name.c_str(), ios::binary);

        //Z order
        //int z_order_array[256*256+5];
        int rm[256*256+5];
        int gm[256*256+5];
        int bm[256*256+5];
        int r, g, b;
        for(int i = 0; i < 256; ++i){
            for(int j = 0; j < 256; ++j){
                r = src(j, i, 0);
                g = src(j, i, 1);
                b = src(j, i, 2);
                rm[zorder(i, j)] = r;
                gm[zorder(i, j)] = g;
                bm[zorder(i, j)] = b;
            }
        }

        for(int i = 0; i < 256*256; ++i){
            file.write(reinterpret_cast<const char*>(&rm[i]), 1);
            file.write(reinterpret_cast<const char*>(&gm[i]), 1);
            file.write(reinterpret_cast<const char*>(&bm[i]), 1);
            //img(i, 0, 0) = rm[i];
            //img(i, 0, 1) = gm[i];
            //img(i, 0, 2) = bm[i];
        }

        file.close();

        //z_order_image.save(name);
        //img.display();
    }

    return 0;
}
