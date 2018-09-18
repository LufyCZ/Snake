#include "field.h"

void field::fillField() {
    
    PlayingField.clear();
    PlayingField.resize(numberOfAll, ' ');
    
    for(int x = 0; x < numberOfAll; x++) {
        if (x < width || (x%width) == 0 || x > (numberOfAll-width) || (x%width) == (width-1)) { PlayingField.at(x) = 'x'; } 
    }
    
}

void field::printField() {
    
    clear();

    for(int x = 0; x < numberOfAll; x++) {
        printw("%c", PlayingField.at(x));
        printw(" ");
        if ((x+1)%width == 0) { printw("\n"); }
    }
    
    refresh();
}

void field::spawnFood() {
    
    int random;
    bool suitable = false;
    
    while(!suitable) {
        random = rand()%numberOfAll;
        if (PlayingField.at(random) != ' ') { suitable = false; }
        else { suitable = true; }
    }
    
    PlayingField.at(random) = '*';
}