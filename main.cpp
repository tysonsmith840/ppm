#include "PPM.h"


void make_copy() {
    PPM myPPM = PPM();

    std::string input_file;
    std::string output_file; 
    std::cout << "Input Filename? ";
    std::cin >> input_file;

    std::cout << "Output Filename? ";
    std::cin >> output_file; 
    std::ifstream fin(input_file, std::ios::binary);
    fin >>  myPPM;
   
    std::ofstream fout(output_file, std::ios::binary);
    fout << myPPM; 
} 
void grayscale(bool r, bool g, bool b, bool l) {
    PPM myPPM = PPM();
    PPM newppm = PPM();
    std::string input_file;
    std::string output_file; 

    std::cout << "Input Filename? ";
    std::cin >> input_file;

    std::cout << "Output Filename? ";
    std::cin >> output_file; 

    std::ifstream fin(input_file, std::ios::binary);
    fin >>  myPPM;
    if (r) {
      newppm = myPPM.red();
    }else if (g) {
      newppm = myPPM.green();
    }else if (b) {
      newppm = myPPM.blue();
    }else if (l) {
      newppm = myPPM.linear();
    }
    std::ofstream fout(output_file, std::ios::binary);
    fout << newppm;
} 


void options() {
    char choice;
    bool r, g, b, l;

    std::cout << "C) copy directly" << std::endl;
    std::cout << "r) grayscale from red" << std::endl;
    std::cout << "g) grayscale from green" << std::endl;
    std::cout << "b) grayscale from blue" << std::endl;
    std::cout << "l) grayscale from linear colorimetric" << std::endl;
    std::cout << "choice: ";
    std::cin >> choice;

    if (choice == 'C') {
       make_copy();
     }else if (choice == 'r') {
	grayscale(r=true, g=false, b=false, l=false);
     } else if (choice == 'g') {
	grayscale(r=false, g=true, b=false, l=false);
     } else if (choice == 'b') {
	grayscale(r=false, g=false, b=true, l=false);
     } else if (choice == 'l') {  
	grayscale(r=false, g=false, b=false, l=true);
     }
/*	    }else if (choice == 'p') {
	      new_add_two()
	    }else if (choice == 'm') {
	      new_minus_two()
	    }*/
}

int main() {
    options();
    return 0;
}
    /*std::cout << "Input Filename? ";
    std::cin >> input_file;

    std::cout << "Input Filename? ";
    std::cin >> input_file2;

    std::cout << "Output Filename? ";
    std::cin >> output_file; 

    //std::string filename = "paw.ppm";
    //std::string filename1 = "mandrill.ppm";
    if (choice == 'C') {
    std::ifstream fin(input_file, std::ios::binary);
    //std::ifstream fin(filename, std::ios::binary);
    fin >>  myPPM;
   
    std::ofstream fout(output_file, std::ios::binary);
    fout << myPPM; 
    std::cout << myPPM.getWidth() << " " << myPPM.getHeight() << " " << myPPM.getMaxColorValue() << std::endl;
  */ 
  /*  }else if (choice == 'a') {
    std::ifstream fin(input_file, std::ios::binary);
    fin >>  myPPM;
    std::ifstream fine(input_file2, std::ios::binary);
    fine >> other;
    newppm = myPPM + other;
    std::ofstream fout(output_file, std::ios::binary);
    fout << newppm; 
    }else if (choice == 'm') {
    std::ifstream fin(input_file, std::ios::binary);
    fin >>  myPPM;
    std::ifstream fine(input_file2, std::ios::binary);
    fine >> other;
    newppm = myPPM - other;
    std::ofstream fout(output_file, std::ios::binary);
    fout << newppm; 
    }*/
