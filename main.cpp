#include "PPM.h"

int main() {
    PPM myPPM = PPM();
    //std::string filename = "paw.ppm";
    std::string filename1 = "mandrill.ppm";

    std::ifstream fin(filename1, std::ios::binary);
    //std::ifstream fin(filename, std::ios::binary);
    fin >>  myPPM;
   
    std::ofstream fout("monkey.ppm", std::ios::binary);
    fout << myPPM; 
    std::cout << myPPM.getWidth() << " " << myPPM.getHeight() << " " << myPPM.getMaxColorValue() << std::endl;
    return 0;
}
