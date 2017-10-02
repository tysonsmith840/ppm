#include "PPM.h"

int main() {
    PPM myPPM = PPM();
    std::string filename = "paw.ppm";

    std::ifstream fin(filename, std::ios::binary);
    fin >>  myPPM;
   
    std::ofstream fout("paws.ppm", std::ios::binary);
    fout << myPPM; 
    std::cout << myPPM.getWidth() << " " << myPPM.getHeight() << " " << myPPM.getMaxColorValue() << std::endl;
    return 0;
}
