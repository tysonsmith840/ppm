#include "PPM.h"
#include <cstdlib>
#include <iomanip>


PPM::PPM() { 
}
int PPM::getWidth( ) const {
    return mWidth;
}
int PPM::getHeight( ) const{
    return mHeight;
}
int PPM::getMaxColorValue( ) const {
    return mMaxColorValue;
}
int PPM::getChannel( const int& row, const int& column, const int& channel ) const{

}
void PPM::setWidth( int& width ) {
    mWidth=width;
}
void PPM::setHeight( int& height ) {
    mHeight=height;
}
void PPM::setMaxColorValue( int& max_color_value ) {
    mMaxColorValue=max_color_value;
}
void PPM::setChannel( const int& row, const int& column, const int& channel, const int& value ) {

}

std::ostream& operator<<(std::ostream& fout, PPM& myPPM) { //operator to send object to std::ostream
   /*char chan [totalChan];
   int i, j, k;
      for (i=0;i<myPPM.getHeight();i++) {
       for (j=0;j<myPPM.getWidth()*3;j++) {
        for (k=0;k<totalChan;k++) {
   	  chan[k]=myPPM.getChannel(i,j,k);
      }
     }
    } 
    fout << myPPM;*/
}
std::istream &operator>>(std::istream &fin, PPM& myPPM) { // operator to retrieve object from std::istream
    std::string allInput="";
    int numbers;
    std::vector< std::vector<char> > pixels;
    std::string x;
    unsigned char channel[3];
    char arr[3];
    int i,j,k;
    //P6
    fin >> x;
    //width
    fin >> allInput;
    numbers=std::stoi(allInput);
    myPPM.setWidth(numbers);
    //height
    fin >> allInput;
    numbers=std::stoi(allInput);
    myPPM.setHeight(numbers);
    //max_color_value
    fin >> allInput;
    numbers = std::stoi(allInput);
    myPPM.setMaxColorValue(numbers);
    //throw away newline char
    fin >> x;
    char chan;
    int size = myPPM.getWidth()*myPPM.getHeight()*3;
    //loop through binary
    
   
    /* for (i=0;i<myPPM.getHeight();i++) {
       for (j=0;j<myPPM.getWidth();i++) {
         fin.read(arr,size);
         for (k=0;k<3;k++) {
    	   myPPM.setChannel(i,j,k,channel[k]);
     }
     }
    }

      pixels.push_back(channel);*/
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



