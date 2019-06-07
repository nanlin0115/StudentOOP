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

/*
 *Date Class:
 * */
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
    os <<wr.date<<": \nTemperature:"<< wr.temperature <<";  Humidity.:" << wr.humidity<<"； Windspeed:" << wr.windspeed;
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

ostream& operator<<(ostream& os, const Weather& w) {
    int r = w.get_rating();
    //w.set_rating(47);
    
    os <<"Station Name: "<< w.station_nm<<'\n'<<"Rating: "<<r<<'\n'<< "Location: " << w.my_loc << endl;
    for (WReading wr: w.wreadings) {
        os <<wr<<endl;
    }
    return os;
}
