#include "snake.h"
#include "field.h"

void snake::getInput() {
    halfdelay(5);
    input = getch();
}




void snake::move() {
    
    
    previousPosition.resize(lenghtOfSnake, 0);
    for(int x = 0; x < lenghtOfSnake; x++) { Field.PlayingField.at(snakePosition.at(x)) = ' '; }
    
    if(input == -1) {
        switch(direction) {
            case 115 : //down
                previousPosition.at(0) = snakePosition.at(0);
                snakePosition.at(0) += Field.width;
                break;
                
            case 119 : //up
                previousPosition.at(0) = snakePosition.at(0);
                snakePosition.at(0) -= Field.width;
                break;
            
            case 100 : //right
                previousPosition.at(0) = snakePosition.at(0);
                snakePosition.at(0) += 1;
                break;
                
            case 97 : //left
                previousPosition.at(0) = snakePosition.at(0);
                snakePosition.at(0) -= 1;
                break;
                
        }
    }
    
    else {
        switch(input) {
            case 115 :
                previousPosition.at(0) = snakePosition.at(0);
                snakePosition.at(0) += Field.width;
                direction = input;
                break;
                
            case 119 :
                previousPosition.at(0) = snakePosition.at(0);
                snakePosition.at(0) -= Field.width;
                direction = input;
                break;
                
            case 100 :
                previousPosition.at(0) = snakePosition.at(0);
                snakePosition.at(0) += 1;
                direction = input;
                break;
                
            case 97 :
                previousPosition.at(0) = snakePosition.at(0);
                snakePosition.at(0) -= 1;
                direction = input;
                break;
                
        }
    }
    
    for(int x = 1; x < lenghtOfSnake; x++) {
        previousPosition.at(x) = snakePosition.at(x);
        snakePosition.at(x) = previousPosition.at(x-1);
    }
    
    if (Field.PlayingField.at(snakePosition.at(0)) == '*')  { 
        lenghtOfSnake++;
        snakePosition.push_back(previousPosition.at(snakePosition.size()-1));
        Field.spawnFood();
        
        
    }
    
    for(int x = 0; x < lenghtOfSnake; x++) { Field.PlayingField.at(snakePosition.at(x)) = 'O'; }
    
    Field.printField();
}



bool snake::colission() {
    if (snakePosition.at(0) < Field.width || (snakePosition.at(0)%Field.width) == 0 || snakePosition.at(0) > (Field.numberOfAll-Field.width) || (snakePosition.at(0)%Field.width) == (Field.width-1)) { return true; }
    return false;
}

