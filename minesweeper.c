#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 30
//game board
typedef struct{
    int table[MAX][MAX];
    int gamemode;
    } TABLE;

void tableInitializer(int game_mode, TABLE* game){
    //refreshing pseudo-random numbers seed
    srand(time(NULL));

    //easy mode
    if(game_mode == 0){
        int bomb = 0;
        for(int line = 0; line < 8; line++){
            for(int column = 0; column < 10; column++){
                game->table[line][column] = 0;
            }
        }
        while(bomb < 10){
            int line = rand() % 8;
            int column = rand() % 10;
            if(game->table[line][column] == 0){
                    game->table[line][column] = 1;
                    bomb++;
            }else continue;
        }

    //medium mode
    }else if(game_mode == 1){
        int bomb = 0;
        for(int line = 0; line < 14; line++){
            for(int column = 0; column < 18; column++){
                game->table[line][column] = 0;
            }
        }
        while(bomb < 40){
            int line = rand() % 14;
            int column = rand() % 18;
            if(game->table[line][column] == 0){
                game->table[line][column] = 1;
                bomb++;
            }else continue;
        }

        //hard mode
        }else{
        int bomb = 0;
        for(int line = 0; line < 20; line++){
            for(int column = 0; column < 24; column++){
                game->table[line][column] = 0;
            }
        }
        while(bomb < 99){
            int line = rand() % 20;
            int column = rand() % 24;
            if(game->table[line][column] == 0){
                game->table[line][column] = 1;
                bomb++;
            }else continue;
        }
        }
}

void printTable(TABLE game){
    system("cls");
    int line, column;
    if(game.gamemode == 0) line = 8, column = 10;
    else if(game.gamemode == 1) line = 14, column = 18;
    else line = 20, column = 24;
    for(int i = 0; i < line; i++){
        for(int j = 0; j < column; j++){
            printf("[] ");
        }

        printf("\n");
    }
}

bool checkMove(TABLE game, int linha, int coluna){
    if(game.table[linha][coluna] == 0) return true;
    else return false;
}

void makeMove(TABLE* game, int linha, int coluna){
    game->table[linha][coluna] = 2;
}

int main() {
    TABLE game;
    printf("Choose gamemode:\n(0)Easy    (1)Medium    (2)Hard\n");
    scanf("%d", &game.gamemode);
    fflush(stdin);
    tableInitializer(game.gamemode, &game);
    int i = 0;
    while (i < MAX){
        printTable(game);
        printf("Choose a position by following Aij like a matrix:\n");
        int line_move, column_move;
        printf("Line: ");
        scanf("%d", &line_move);
        fflush(stdin);
        printf("Column: ");
        scanf("%d", &column_move);
        fflush(stdin);
        if(checkMove(game, line_move, column_move)== true) makeMove(&game, line_move, column_move);
        else break;
    }
    printf("You Loose!");
    return 1;
}
