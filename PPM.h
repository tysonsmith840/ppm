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
     PPM operator+(const PPM& ppm)const; 
     PPM operator-(const PPM& ppm)const; 
     
     PPM& operator*=(double value); 
     PPM& operator/=(double value);  
     PPM operator*(const double value)const; 
     PPM operator/(const double value)const; 
     
     PPM red()const;
     PPM green()const;
     PPM blue()const;
     PPM linear()const;
     
    private:
      std::vector<unsigned char> pixels;
      int mWidth;
      int mHeight;
      int mMaxColorValue;
};
     std::ostream &operator<<(std::ostream &fout, PPM &myPPM); //operator to send object to std::ostream cout << PPMIns;
     std::istream &operator>>(std::istream &fin, PPM &myPPM); // operator to retrieve object from std::istream
#endif /* PPM_H_ */

