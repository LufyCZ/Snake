#ifndef snake_h
#define snake_h


#include <ncurses.h>
#include <vector>

#include "field.h"

extern field Field;

class snake {
    private:
    std::vector<int> previousPosition;
    
    int input;
    int direction = 100;

    public:
    
    int lenghtOfSnake = 1;
    
    std::vector<int> snakePosition;
    
    void getInput();
    void move();
    bool colission();


};

#endif
