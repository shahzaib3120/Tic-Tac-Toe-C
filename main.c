#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int check();                                    // implements rules
void print_grid();                              // prints grid using loops
void play();                                    // run by default
void modify_grid();                             // updates position array
void init_array();                              // initializes array
char pos[9];                                    // array of box numbers
int player = 0;                                 // player 1 if even , player 2 if odd
int choice = 0;                                 // choice of box number made by user
int grid_size = 3;
int history = 0;                                // 0 for off 1 for on (LOGS)
int moves = 0;                                  // used for max moves

int main()
{
    init_array();
    print_grid(grid_size);
	play();
	return 0;
}

void init_array(){
    int ascii = 49;
    for(int i=0; i<grid_size*grid_size;i++){
        pos[i] = ascii;
        ascii += 1;
    }
}

void print_grid(int i){
	for (int z = 0; z<i*i; z++){                 // repeats the patters vertically
		if (z != 0){                             // does not print first horizontal line
			for (int x = 0; x< i * 8; x++){      // prints horizontal lines
				printf("-");
			}
		}
		for (int y = 0; y<i; y++){
			printf("\n");
			for (int m = 0; m<i; m++){
				if (y == 1 && m == i - 1){
					printf("   %c   ", pos[z + m]);
				}
				if (y == 1 && m < i - 1){
					printf("   %c   |", pos[z + m]);
				}
				if (y != 1 && m == i - 1){
					printf(" ");
				}
				if (y != 1 && m <i - 1){
					printf("       |");
				}
			}
		}
		printf("\n");
		z = z + i - 1;
	}
}

void modify_grid(int number, int player){

	printf("\nPlayer %d chose box %d ", (player % 2 == 1) ? (2) : (1), number);
	while (pos[number - 1] == 'O' || pos[number - 1] == 'X'){
		printf("\n ***Already Taken***\n");
		if (player % 2 == 0){
			printf("\n\n");
			printf("PLAYER 1 ( X ): Choose your box : ");
			scanf(" %d", &choice);
			modify_grid(choice, player);
		}
		if (player % 2 == 1){
			printf("\n\n");
			printf("PLAYER 2 ( 0 ): Choose your box : ");
			scanf(" %d", &choice);
			modify_grid(choice, player);
		}
		if (pos[choice - 1] == 'O' || pos[choice - 1] == 'X'){
			break;
		}

	}

	pos[choice - 1] = (player % 2 == 1) ? ('O') : ('X'); // replaces box numbers with X or O
}

int check(void){
    if (history == 0){
        system("cls");
    }
    print_grid(grid_size);
    
        if (pos[0] == 'X' && pos[3] == 'X' && pos[6] == 'X'){
            printf("\nPlayer ONE WINS \n");
            return 1;
        }
        if (pos[1] == 'X' && pos[4] == 'X' && pos[7] == 'X'){
            printf("\nPlayer ONE WINS \n");
            return 1;
        }
        if (pos[2] == 'X' && pos[5] == 'X' && pos[8] == 'X'){
            printf("\nPlayer ONE WINS \n");
            return 1;
        }
        if (pos[0] == 'X' && pos[1] == 'X' && pos[2] == 'X'){
            printf("\nPlayer ONE WINS \n");
            return 1;
        }
        if (pos[3] == 'X' && pos[4] == 'X' && pos[5] == 'X'){
            printf("\nPlayer ONE WINS \n");
            return 1;
        }
        if (pos[6] == 'X' && pos[7] == 'X' && pos[7] == 'X'){
            printf("\nPlayer ONE WINS \n");
            return 1;
        }
        if (pos[0] == 'X' && pos[4] == 'X' && pos[8] == 'X'){
            printf("\nPlayer ONE WINS \n");
            return 1;
        }
        if (pos[2] == 'X' && pos[4] == 'X' && pos[6] == 'X'){
            printf("\nPlayer ONE WINS \n");
            return 1;
        }

        // check for PLAYER 2 START HERE

        if (pos[0] == 'O' && pos[3] == 'O' && pos[6] == 'O'){
            printf("\nPlayer TWO WINS \n");
            return 1;
        }
        if (pos[1] == 'O' && pos[4] == 'O' && pos[7] == 'O'){
            printf("\nPlayer TWO WINS \n");
            return 1;
        }
        if (pos[2] == 'O' && pos[5] == 'O' && pos[8] == 'O'){
            printf("\nPlayer TWO WINS \n");
            return 1;
        }
        if (pos[0] == 'O' && pos[1] == 'O' && pos[2] == 'O'){
            printf("\nPlayer TWO WINS \n");
            return 1;
        }
        if (pos[3] == 'O' && pos[4] == 'O' && pos[5] == 'O'){
            printf("\nPlayer TWO WINS \n");
            return 1;
        }
        if (pos[6] == 'O' && pos[7] == 'O' && pos[7] == 'O'){
            printf("\nPlayer TWO WINS \n");
            return 1;
        }
        if (pos[0] == 'O' && pos[4] == 'O' && pos[8] == 'O'){
            printf("\nPlayer TWO WINS \n");
            return 1;
        }
        if (pos[2] == 'O' && pos[4] == 'O' && pos[6] == 'O'){
            printf("\nPlayer TWO WINS \n");
            return 1;
        }
        else{
            if (moves < 9){
            play();
            return 0;
            }
            else{
            system("cls");
            print_grid(grid_size);
            printf("!!! DRAW !!! \n\n");

    }
        }
    
    
}

void play(){

    if (player % 2 == 0){
        printf("\n\n");
        printf("PLAYER 1 ( X ): Choose your box : ");
        scanf(" %d", &choice);
        moves += 1;
        modify_grid(choice, player);
    }
    if (player % 2 == 1){
        printf("\n\n");
        printf("PLAYER 2 ( 0 ): Choose your box : ");
        scanf(" %d", &choice);
        moves += 1;
        modify_grid(choice, player);
    }
    player = player + 1;
    check();
}




