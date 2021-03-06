#include "PPM.h"
#include <cstdlib>
#include <iomanip>


PPM::PPM() {
   mWidth = 0;
   mHeight = 0;
   mMaxColorValue = 0;
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
int PPM::getSize( ) const {
    return mWidth*mHeight;
}
int PPM::getChannel( const int& row, const int& column, const int& channel ) const{
    if (row < mHeight && row >= 0 && column < mWidth && column >= 0 && channel <3 && channel >= 0) {
    int desChannel;
    desChannel = row*(getWidth()*3)+column*3+channel;
    if (desChannel < getWidth() * getHeight() * 3 && desChannel >=0) {
    return pixels[desChannel];

    }
   }
   return -1;
}
void PPM::setWidth(const int& width ) {
    if (width >=0)
    {
        mWidth=width;
        pixels.resize(mWidth*mHeight*3);
    }
}
void PPM::setHeight(const int& height ) {
    if (height >= 0) {
    mHeight=height;
    pixels.resize(mWidth*mHeight*3);
   }
}
void PPM::setMaxColorValue(const int& max_color_value ) {
    if (max_color_value >= 0 && max_color_value <= 255) {
    mMaxColorValue=max_color_value;
   }
}
void PPM::setChannel( const int& row, const int& column, const int& channel, const int& value ) {
    if (value >= 0 && value <= mMaxColorValue && row < mHeight && row >= 0 && column < mWidth && column >= 0 && channel <3 && channel >= 0) {
    int desChannel;
    desChannel = row*(mWidth*3)+column*3+channel;
    if (desChannel < mWidth * mHeight * 3 && desChannel >=0) {
       pixels[desChannel]=value;
    }
  }
}
std::istream &operator>>(std::istream &fin, PPM& myPPM) { // operator to retrieve object from std::istream
    std::string allInput="";
    int numbers;
    //char x;
    //std::string x;
    //std::vector<unsigned char> pixels;
    int i, j, k;
    //P6
    fin >> allInput;
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
    fin.get();

    unsigned char *chan = new unsigned char;
    //fin.read((char *)&chan, 1);
    //loop through binary
   for (i=0;i<myPPM.getHeight();i++) {
        for (j=0;j<myPPM.getWidth();j++) {
            for (k=0;k<3;k++)
            {
                fin.read((char *) &*chan, 1);
                myPPM.setChannel(i,j,k,*chan);
            }
        }
    }
    delete chan;
    return fin;
}
std::ostream& operator<<(std::ostream& fout, PPM& myPPM) { //operator to send object to std::ostream
   int i, j, k;
   //unsigned char chan[3];
   unsigned char *chan = new unsigned char;
   //fout.write((char *)&chan, 1);
   fout << "P6 " << myPPM.getWidth() << " " << myPPM.getHeight() << " " << myPPM.getMaxColorValue() << "\n";

   for (i=0;i<myPPM.getHeight();i++) {
      for (j=0;j<myPPM.getWidth();j++) {
        for (k=0;k<3;k++)
        {
         *chan = myPPM.getChannel(i,j,k);
         fout.write((char *) &*chan, 1);
         //*chan[k]=myPPM.getChannel(i,j,k);
         //myPPM.getChannel(i,j,k);
        }
     }
  }
  delete chan;
     return fout;
}
bool PPM::operator<(const PPM& ppm)const{
    return getSize()<ppm.getSize();
}
bool PPM::operator>(const PPM& ppm)const{
    return getSize()>ppm.getSize();
}
bool PPM::operator<=(const PPM& ppm)const{
    return getSize()<=ppm.getSize();
}
bool PPM::operator>=(const PPM& ppm)const{
    return getSize()>=ppm.getSize();
}
bool PPM::operator==(const PPM& ppm)const{
    return getSize()==ppm.getSize();
}
bool PPM::operator!=(const PPM& ppm)const{
    return getSize()!=ppm.getSize();
}
PPM& PPM::operator+=(const PPM& rhs) {
    int i,j,k;
    int value;
    for (i=0;i<getHeight();i++) {
        for (j=0;j<getWidth();j++) {
            for (k=0;k<3;k++)
            {
                value = getChannel(i,j,k)+rhs.getChannel(i,j,k);
                if (value > 255) {
                    value = 255;
                }
                setChannel(i,j,k,value);
            }
        }
    }
    return *this;
}
PPM& PPM::operator-=(const PPM& rhs) {
    int i,j,k;
    int value;
    for (i=0;i<getHeight();i++) {
        for (j=0;j<getWidth();j++) {
            for (k=0;k<3;k++)
            {
                value = getChannel(i,j,k)-rhs.getChannel(i,j,k);
                if (value < 0) {
                    value = 0;
                }
                setChannel(i,j,k,value);
            }
        }
    }
    return *this;
}
PPM PPM::operator+(const PPM& rhs)const {
    PPM newppm;
    newppm.setHeight(getHeight());
    newppm.setWidth(getWidth());
    newppm.setMaxColorValue(getMaxColorValue());
    int i,j,k;
    int value;
    for (i=0;i<getHeight();i++) {
        for (j=0;j<getWidth();j++) {
            for (k=0;k<3;k++)
            {
                value = getChannel(i,j,k)+rhs.getChannel(i,j,k);
                if (value > 255)
                {
                    value = 255;
                }
                newppm.setChannel(i,j,k,value);
            }
        }
    }
    return newppm;
}
PPM PPM::operator-(const PPM& rhs)const {
    PPM newppm;
    int i,j,k;
    int value;
    newppm.setHeight(getHeight());
    newppm.setWidth(getWidth());
    newppm.setMaxColorValue(getMaxColorValue());
    for (i=0;i<getHeight();i++) {
        for (j=0;j<getWidth();j++) {
            for (k=0;k<3;k++)
            {
                value = getChannel(i,j,k)-rhs.getChannel(i,j,k);
                if (value < 0) {
                    value = 0;
                }
                newppm.setChannel(i,j,k,value);
            }
        }
    }
    return newppm;
}
PPM& PPM::operator*=(double value) { //multiplies each channel by a double and then converts it back to an int. If any number is out of range then it should be set to the min or max value  *=
    size_t i;
    int pixel;
    for (i=0;i<pixels.size();i++) {
     pixel = (int)pixels[i] * value;
     pixels[i] = pixel;
     if (pixel > 255) {
      pixels[i] = 255;
     }else if (pixel < 0) {
       pixels[i] = 0;
     }else {
      pixels[i] = pixel;
   }
  }
  return *this;
}
PPM& PPM::operator/=(double value) {  //divide each channel by a double, convert back to an int and ensure that all channels are within bounds. /=
     size_t i;
     int pixel;
     for (i=0;i<pixels.size();i++) {
       pixel = (int)pixels[i] / value;
       pixels[i] = pixel;
     if (pixel > 255) {
       pixels[i] = 255;
     }else if (pixel < 0) {
       pixels[i] = 0;
     }else {
       pixels[i] = pixel;
   }
  }
  return *this;
}
PPM PPM::operator*(const double value)const {
    PPM newppm;
    int i,j,k;
    double newVal;
    newppm.setHeight(getHeight());
    newppm.setWidth(getWidth());
    newppm.setMaxColorValue(getMaxColorValue());
    for (i=0;i<getHeight();i++) {
        for (j=0;j<getWidth();j++) {
            for (k=0;k<3;k++)
            {
                newVal = value * getChannel(i,j,k);
                if (newVal < 0) {
                    newVal = 0;
                }
                else if (newVal > 255) {
                    newVal = 255;
                }
                newppm.setChannel(i,j,k,int(newVal));
            }
        }
    }
    return newppm;
}
PPM PPM::operator/(const double value)const {
    PPM newppm;
    int i,j,k;
    double newVal;
    newppm.setHeight(getHeight());
    newppm.setWidth(getWidth());
    newppm.setMaxColorValue(getMaxColorValue());
    for (i=0;i<getHeight();i++) {
        for (j=0;j<getWidth();j++) {
            for (k=0;k<3;k++)
            {
                newVal = getChannel(i,j,k) / value;
                if (newVal < 0) {
                    newVal = 0;
                }
                else if (newVal > 255) {
                    newVal = 255;
                }
                newppm.setChannel(i,j,k,int(newVal));
            }
        }
    }
    return newppm;
}
PPM PPM::red()const {
    PPM redppm;
    int i,j,k;
    int redVal;
    redppm.setWidth(getWidth());
    redppm.setHeight(getHeight());
    redppm.setMaxColorValue(getMaxColorValue());
    for (i=0;i<getHeight();i++) {
        for (j=0;j<getWidth();j++) {
            for (k=0;k<3;k++)
            {
                redVal = getChannel(i,j,0);
                redppm.setChannel(i,j,k,redVal);
            }
        }
    }
    return redppm;
}
PPM PPM::green()const {
    PPM greenppm;
    int i,j,k;
    int greenVal;
    greenppm.setWidth(getWidth());
    greenppm.setHeight(getHeight());
    greenppm.setMaxColorValue(getMaxColorValue());
    for (i=0;i<getHeight();i++) {
        for (j=0;j<getWidth();j++) {
            for (k=0;k<3;k++)
            {
                greenVal = getChannel(i,j,1);
                greenppm.setChannel(i,j,k,greenVal);
            }
        }
    }
    return greenppm;
}
PPM PPM::blue()const {
    PPM blueppm;
    int i,j,k;
    int blueVal;
    blueppm.setWidth(getWidth());
    blueppm.setHeight(getHeight());
    blueppm.setMaxColorValue(getMaxColorValue());
    for (i=0;i<getHeight();i++) {
        for (j=0;j<getWidth();j++) {
            for (k=0;k<3;k++)
            {
                blueVal = getChannel(i,j,2);
                blueppm.setChannel(i,j,k,blueVal);
            }
        }
    }
    return blueppm;
}
PPM PPM::linear()const {
    PPM linearppm;
    int i,j,k;
    double linearVal=0;
    linearppm.setWidth(getWidth());
    linearppm.setHeight(getHeight());
    linearppm.setMaxColorValue(getMaxColorValue());
    for (i=0;i<getHeight();i++) {
        for (j=0;j<getWidth();j++) {
            for (k=0;k<3;k++)
            {
		linearVal = (0.2126*getChannel(i,j,0))+(0.7152*getChannel(i,j,1))+(0.0722*getChannel(i,j,2));
                linearppm.setChannel(i,j,k,(int)linearVal);
            }
        }
    }
    return linearppm;
}   
