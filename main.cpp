#include <ncurses.h>
#include <vector>
#include <ctime>
#include <cstdlib>

#include "field.h"
#include "snake.h"

field Field;
snake Snake;

bool notDead = true;


void startGame() {
    srand(time(NULL));
    initscr();
    printw("To start the game press any key.");
    refresh();
    getch();
    clear();


    Snake.snakePosition.clear();
    Snake.snakePosition.resize(1, Field.numberOfAll/3);

    Field.fillField();
    Field.printField();
    Field.spawnFood();
    
    halfdelay(5);
}

void gameLoop() {
    while(notDead) {
        Snake.getInput();
        Snake.move();
        
        
        if(Snake.colission()) { notDead = false; }
    }
}

void gameEnd() {
    cbreak();
    printw("You lost! :(, your score is %d.", Snake.lenghtOfSnake);
    getch();
}

int main() {
    startGame();
    gameLoop();
    gameEnd();
    endwin();
}

