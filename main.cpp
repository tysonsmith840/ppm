#include "PPM.h"

int main() {
    PPM myPPM = PPM();
    std::string filename = "paw.ppm";

    std::ifstream fin(filename, std::ios::binary);
    
    std::cout << myPPM.getWidth() << std::endl;
    return 0;
}
