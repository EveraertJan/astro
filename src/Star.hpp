//
//  Star.hpp
//  astro_forever_whatever
//
//  Created by Jan Everaert on 01/11/2019.
//

#ifndef Star_hpp
#define Star_hpp

#include <stdio.h>
#include "ofMain.h"

class Star {
public:
    void setup();
    void draw();
    
    float posX;
    float posY;
    
    float size;
};
#endif /* Star_hpp */
