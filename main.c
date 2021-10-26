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
            matriz[x][y].radar = 0;
        }
    }
}

// Bomb random
void bombLocations(int number){
    srand(time(NULL));

    for(int i = 0; i < number; i++){
        x = rand() % size;
        y = rand() % size;

        if (matriz[x][y].bomb == 0){
            matriz[x][y].bomb = 1;
        }
        else{
            i--;
        }
    }
}

//Draw
void draw(){
    for(int i = 0; i < size; i++){
        printf("--------------------------------------------\n");

        for(int j = 0; j < size; j++){
            printf("| %d ", matriz[i][j].bomb);
        }
//            if(matriz[i][j].bomb == 1){
//                printf("| x ");
//            }
//            else{
//                printf("| %d ", matriz[i][j].radar);
//            }
//        }

        printf("|\n");
    }

    printf("--------------------------------------------\n");
}

// Cell validation
// Radar
void radar(){
    int radarPoints = 0;
    int xx = 0;
    int yy = 0;

    for(x = 0; x < 10; x++){
        for(y = 0; y < 10; y++){

            if(x == 0){
                if (y == 0) {
                    for(xx = 0; xx < 2; xx++){
                        for(yy = 0; yy < 2; yy++){
                            if(matriz[x + xx][y + yy].bomb == 1){
                                radarPoints++;
                            }
                        }
                    }
                }
                if (y == size - 1) {
                    for(xx = 0; xx < 2; xx++) {
                        for(yy = -1; yy < 1; yy++) {
                            if(matriz[x + xx][y + yy].bomb == 1){
                                radarPoints++;
                            }
                        }
                    }
                }
            }
            else if(y == 0){ // x-- y++
                if(x == size - 1){
                    for(xx = 0; xx < 2; xx++){
                        for(yy = -1; yy < 1; yy++){
                            if(matriz[x + xx][y + yy].bomb == 1){
                                radarPoints++;
                            }
                        }
                    }
                }
            } else if (y == size - 1) { // x-- y--
                if (x == size - 1) {
                    for(xx = -1; xx < 1; xx++){
                        for(yy = -1; y < 1; yy++){
                            if(matriz[x + xx][y + yy].bomb == 1){
                                radarPoints++;
                            }
                        }
                    }
                }
            }
            else {
                for (xx = -1; xx < 2; xx++) {
                    for (yy = -1; yy < 2; yy++) {

                        if (matriz[x + xx][y + yy].bomb == 1) {
                            radarPoints++;
                        }
                    }
                }
            }

            matriz[x][y].radar = radarPoints;
            radarPoints = 0;
        }
    }

}

// Main
int main(){

    initialize();
    bombLocations(10);
    radar();
    draw();

    return 0;
}

