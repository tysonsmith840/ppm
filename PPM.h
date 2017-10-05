#ifndef _PPM_H_
#define _PPM_H_
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class PPM{
    public:
     PPM();
     int getWidth( ) const;
     int getHeight( ) const;
     int getMaxColorValue( ) const;
     int getChannel( const int& row, const int& column, const int& channel ) const;
     int getSize( ) const;
     void setWidth(const int& width );
     void setHeight(const int& height );
     void setMaxColorValue(const int& max_color_value );
     void setChannel( const int& row, const int& column, const int& channel, const int& value );
     bool operator<(const PPM& name)const;
     bool operator>(const PPM& name)const;
     bool operator<=(const PPM& name)const;
     bool operator>=(const PPM& name)const;
     bool operator==(const PPM& name)const;
     bool operator!=(const PPM& name)const;
     PPM& operator+=(const PPM& ppm);
     PPM& operator-=(const PPM& ppm);
     PPM operator+(const PPM& ppm)const; //adds two PPM objects together creating a new object
     PPM operator-(const PPM& ppm)const; //subtracts two PPM objects together creating a new object
     PPM& operator*=(double value); //multiplies each channel by a double and then converts it back to an int. If any number is out of range then it should be set to the min or max value  *=
     PPM& operator/=(double value);  //divide each channel by a double, convert back to an int and ensure that all channels are within bounds. /=
     PPM operator*(const double value)const; //multiply each channel by a double and create a new PPM object ex. PPM3=PPM1*.67
     PPM operator/(const double value)const; //divide each channel by a double and create a new PPM object ex. PPM3=PPM1/.33
     private:
      std::vector<unsigned char> pixels;
      int mWidth;
      int mHeight;
      int mMaxColorValue;
};
     std::ostream &operator<<(std::ostream &fout, PPM &myPPM); //operator to send object to std::ostream cout << PPMIns;
     std::istream &operator>>(std::istream &fin, PPM &myPPM); // operator to retrieve object from std::istream
#endif /* PPM_H_ */

