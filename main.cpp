#include "PPM.h"
  
void options() {
    char choice;
    bool C, r, g, b, l;

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
	grayscale(bool r=true, bool g=false, bool b=false);
     } else if (choice == 'g') {
	grayscale(bool r=false, bool g=true, bool b=false);
     } else if (choice == 'b') {
	grayscale(bool r=false, bool g=false, bool b=true);
     } else if (choice == 'l') {  

     }
/*	    }else if (choice == 'p') {
	      new_add_two()
	    }else if (choice == 'm') {
	      new_minus_two()
	    }*/
    }
}
void grayscale(bool r, bool g, bool b) {
    PPM myPPM = PPM();
    PPM other = PPM();
    PPM newppm = PPM();
    std::string input_file;
    std::string input_file2;
    std::string output_file; 

    std::cout << "Input Filename? ";
    std::cin >> input_file;

    std::cout << "Input Filename? ";
    std::cin >> input_file2;

    std::cout << "Output Filename? ";
    std::cin >> output_file; 

} 
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
    std::cout << myPPM.getWidth() << " " << myPPM.getHeight() << " " << myPPM.getMaxColorValue() << std::endl;
    
}


int main() {
    std::cout << "Input Filename? ";
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
    }else if (choice == 'r') {
    std::ifstream fin(input_file, std::ios::binary);
    fin >>  myPPM;
    PPM redPPM = myPPM.red();
    std::ofstream fout(output_file, std::ios::binary);
    fout << redPPM; 
    }else if (choice == 'g') {
    std::ifstream fin(input_file, std::ios::binary);
    fin >>  myPPM;
    PPM greenPPM = myPPM.green();
    std::ofstream fout(output_file, std::ios::binary);
    fout << greenPPM; 
    }else if (choice == 'b') {
    std::ifstream fin(input_file, std::ios::binary);
    fin >>  myPPM;
    PPM bluePPM = myPPM.blue();
    std::ofstream fout(output_file, std::ios::binary);
    fout << bluePPM; 
    }else if (choice == 'a') {
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
    }


    return 0;
}
