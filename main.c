#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Cell structuration
typedef struct{
    int bomb;
    int open;
    int radar;
} Cell;

// Global variables
int x, y;
int size = 10;
Cell matriz[10][10];

// Menu


// Initializer
void initialize(){
    for(x = 0; x < size; x++){
        for(y = 0; y < size; y++){
            matriz[x][y].bomb = 0;
            matriz[x][y].open = 0;
            matriz[x][y].open = 0;
        }
    }
}

// Bomb random
void bombLocations(int number){
    srand(time(NULL));

    for(int i = 0; i < number; i++){
        x = rand() % 10;
        y = rand() % 10;

        if (matriz[x][y].bomb == 0){
            matriz[x][y].bomb = 1;
        }
        else{
            i--;
        }
    }
}

// Radar
int radar(){

}

// Main
int main(){
    initialize();
    bombLocations(10);

    return 0;
}

