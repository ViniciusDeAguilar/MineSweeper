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
        printf("-----------------------------------------\n");

        for(int j = 0; j < size; j++){
//            printf("| %d ", matriz[i][j].bomb);
            if(matriz[i][j].bomb == 1 ){
                printf("| x ");
            }
            else{
                printf("| %d ", matriz[i][j].radar);
            }
        }
        printf("|\n");
    }

    printf("-----------------------------------------\n");
}

// Cell validation
int cellValidation(int x1 ,int y1){
    if((x1 < 0 || x1 >= size) || (y1 < 0 || y1 >= size)){
//        printf("Cell %d %d don't exists!\n", x1, y1);

        return 0;
    }
    return 1;
}

// Radar
void radar(){
    int radarPoints = 0;
    int xx = 0, xi = -1, xf = 2;
    int yy = 0, yi = -1 , yf = 2;

    for(x = 0; x < size; x++){
        for(y = 0; y < size; y++){

//            if(x + xx <= 0){
//                xi = 0;
//            }
//            else if(x + xx >= size){
//                xf = 1;
//            }
//
//            if(y + yy <= 0){
//                yi = 0;
//            }
//            else if(y + yy >= size){
//                yf = 1;
//            }

            for (xx = xi; xx < xf; xx++) {
                for (yy = yi; yy < yf; yy++) {

                   if(cellValidation(x + xx, y + yy) == 1){
                       if (matriz[x + xx][y + yy].bomb == 1) {
                           radarPoints++;
                       }
                   }

                }
            }

            matriz[x][y].radar = radarPoints;
            radarPoints = 0;
//
//            xi = -1;
//            xf = 2;
//
//            yi = -1;
//            yf = 2;
        }
    }

    matriz[x][y].radar = radarPoints;
    radarPoints = 0;
}

// Main
int main(){

    initialize();
    bombLocations(10);
    radar();
    draw();
    scanf("%d");
    return 0;
}

