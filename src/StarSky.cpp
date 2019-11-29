//
//  StarSky.cpp
//  astro_forever_whatever
//
//  Created by Jan Everaert on 01/11/2019.
//

#include "StarSky.hpp"


void StarSky::setup() {
    for(int i = 0; i < 2000; i++) {
        Star s;
        s.setup();
        stars.push_back(s);
    }
}

void StarSky::draw() {
    for(int i = 0; i<stars.size(); i++) {
        stars.at(i).draw();
    }
}
