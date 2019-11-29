//
//  StarSky.hpp
//  astro_forever_whatever
//
//  Created by Jan Everaert on 01/11/2019.
//

#ifndef StarSky_hpp
#define StarSky_hpp

#include <stdio.h>
#include "ofMain.h"
#include "Star.hpp"

class StarSky {
public:
    void setup();
    void draw();
    
    vector<Star> stars;
};
#endif /* StarSky_hpp */
