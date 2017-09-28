#include "PPM.h"

int main() {
    PPM myPPM = PPM();
    std::string filename = "paw.ppm";

    std::ifstream fin(filename, std::ios::binary);
    fin >>  myPPM;
    
    std::cout << myPPM.getWidth() << std::endl;
    return 0;
}
