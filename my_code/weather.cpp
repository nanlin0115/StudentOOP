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


using namespace std;




/*
 * A constructor for weather class.
 * */
Weather::Weather(std::string nm, GPS loc):
station_nm(nm), my_loc(loc) {
}

std::ostream& operator<<(ostream& os, const GPS& gps) {
    os<<gps.latitude<<gps.longitude<<endl;
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

ostream& operator<<(ostream& os, const Weather& w) {
    int r = w.get_rating();
    //w.set_rating(47);

    os <<"Station Name: "<< w.station_nm<<'\n'<<"Rating: "<<r<<'\n'<<"Location: "<<w.my_loc;
    return os;
}
