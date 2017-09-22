#include "PPM.h"
#include <cstdlib>
#include <iomanip>

PPM::PPM() { 
}

std::ostream& operator<<(const std::ostream& fout, const PPM& myPPM) { //operator to send object to std::ostream
   fout << myPPM;
}
std::istream &operator>>(const std::istream &fin, const PPM& myPPM) { // operator to retrieve object from std::istream
    fin >> myPPM;
}
bool PPM::operator<(const PPM& name)const{

}
bool PPM::operator>(const PPM& name)const{

}
bool PPM::operator<=(const PPM& name)const{

}
bool PPM::operator>=(const PPM& name)const{

}
bool PPM::operator==(const PPM& name)const{

}
bool PPM::operator!=(const PPM& name)const{

}
PPM& PPM::operator+(PPM& name) { //adds red green and blue channels, if any channels is over 255 it should be set to 255

}
PPM& PPM::operator-(PPM& name) { //subtracts red green and blue channels, if any channel is less than 0 it should be set to 0

}
PPM PPM::operator+(const PPM& name)const { //adds two PPM objects together creating a new object  

}
PPM PPM::operator-(const PPM& name)const { //subtracts two PPM objects together creating a new object

}
PPM& PPM::operator*(double value) { //multiplies each channel by a double and then converts it back to an int. If any number is out of range then it should be set to the min or max value  *=

}
PPM& PPM::operator/(double value) {  //divide each channel by a double, convert back to an int and ensure that all channels are within bounds. /=

}
PPM PPM::operator*(const double value)const { //multiply each channel by a double and create a new PPM object ex. PPM3=PPM1*.67

}
PPM PPM::operator/(const double value)const { //divide each channel by a double and create a new PPM object ex. PPM3=PPM1/.33

}



