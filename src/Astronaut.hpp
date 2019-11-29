//
//  Astronaut.hpp
//  astro_forever_whatever
//
//  Created by Jan Everaert on 01/11/2019.
//

#ifndef Astronaut_hpp
#define Astronaut_hpp

#include <stdio.h>
#include "ofMain.h"

class Astronaut {
public:
    void setup(string file);
    void update();
    void draw();
    
    int width = 80;
    int height = 80;
    
    
    ofTexture in;
    ofImage mask;
    ofImage overlay;
    ofFbo astroboy;
    
    float posX;
    float posY;
    float rot;
    float fX;
    float fY;
    float fR;
    
    int timeToLive;
    
};
#endif /* Astronaut_hpp */
