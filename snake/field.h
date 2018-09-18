#ifndef field_h
#define field_h

#include <ncurses.h>
#include <vector>
#include <cstdlib>


class field {
    
    public:
    
    void fillField();
    void printField();
    void spawnFood();

    std::vector<char> PlayingField;
    
    const int height = 50;
    const int width = 60;
    
    const int numberOfAll = height * width;
    
};

#endif
