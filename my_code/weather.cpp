//
//  weather.cpp
//  hwandlab
//
//  Created by Nan Lin on 6/6/19.
//  Copyright © 2019 Nan Lin. All rights reserved.
//

#include "weather.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const double C_TO_F = (9/5);
//const double F_TO_C = 5/9;



Image::Image(int w, int h, std::string flnm)
:width(w),height(h){
    filename = flnm;
    image_buf = new char[image_sz()];
}
// copy constructor:
Image::Image(const Image& img2){
    height = img2.height;
    width = img2.width;
    filename = img2.filename;
    image_buf = new char[image_sz()];
    for (int i = 0; i < 1000;i++){
        image_buf[i] = img2.image_buf[i];
    }
}
Image::~Image(){
    if (image_buf != nullptr) delete image_buf;
}
Image& Image::operator=(const Image& img2){
    if (&img2 != this){
        if (image_buf != nullptr) delete image_buf;
        height = img2.height;
        width = img2.width;
        filename = img2.filename;
        image_buf = new char[image_sz()];
        for (int i = 0; i<1000;i++){
            image_buf[i] = img2.image_buf[i];
        }
    }
    return *this;
}

int Image::image_sz(){
    return width*height;
}

/*
 * Setting `display() = 0` here makes this an abstract
 * class that can't be implemented.
 * */
void Image::display(){
    cout<< "Displaying Image"<<endl;
}
void Gif::display(){
    cout << "Displaying Gif"<<endl;
}
void Jpeg::display(){
    cout << "Displaying Jpeg"<<endl;
}
void Png::display(){
    cout << "Displaying Png" << endl;
}

double WReading::get_tempF(){
    return((temperature * C_TO_F) + 32);
}

/*
 *Date Class:
 * *
 **/

Date :: Date(int d, int m, int y){
    if ((d < 1) || (d > 31)) throw d;
    if ((m < 1) || (m > 12)) throw m;
    if ((y < 1800) || (y > 2200)) throw y;
    
    day = d;
    month = m;
    year = y;
}
ostream& operator<<(ostream& os, const Date& date){
    os << date.month <<"/" << date.day <<"/"<<date.year;
    return os;
}



/*
 * WReading class: weather readings
 **/

ostream& operator<<(ostream& os, const WReading& wr){
    os <<wr.date<<": \nTemperature: "<< wr.temperature <<";  Humidity: " << wr.humidity<<"； Windspeed: " << wr.windspeed<<endl;
    return os;
}

/*
 * A constructor for weather class.
 * */
Weather::Weather(string nm, GPS loc):
station_nm(nm), my_loc(loc) {
}

std::ostream& operator<<(ostream& os, const GPS& gps) {
    os<<"Latitude: "<<gps.latitude<<" Longitude: "<<gps.longitude<<endl;
    return os;
};


string Weather::get_name() const{
    return station_nm;
}
int Weather:: get_rating() const{
    return rating;
    
}
void Weather::set_rating(int new_rating){
    rating = new_rating;
}
void Weather::add_reading(WReading wr){
    wreadings.push_back(wr);
}
void WReading::display_image(){
    if (img) img->display();
    else cout<<"No image"<<endl;
}
void Weather::display_images(){
    for (WReading wr:wreadings){
        wr.display_image();
    }
}


ostream& operator<<(ostream& os, const Weather& w) {
    int r = w.get_rating();
    //w.set_rating(47);
    
    os <<"Station Name: "<< w.station_nm<<'\n'<<"Rating: "<<r<<'\n'<< "Location: " << w.my_loc << endl;
    for (WReading wr: w.wreadings) {
        os <<wr<<endl;
    }
    return os;
}
