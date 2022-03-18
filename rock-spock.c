/**
 * @file rock-spock.c
 * @author Stephen Jurgensen
 * @date 2022 Feb 12
 * @brief Play Rock-paper-scissors-lizard-Spock against the machine
 */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


#define COMPUTER 8088
#define PLAYER 1000

#define CHOICES 5

#define ROCK 'R'
#define PAPER 'P'
#define SCISSORS 'S'
#define LIZARD 'L'
#define SPOCK 'V'

void move(int who, int move);
int winner(int computer, int player);
void print_winner(int winner, int comp_move, int player_move);
int nrand(int range);
void seed();


int main(void)
{
	int computer;
	int player;
        int tmp;
	int the_winner;
	char x = '0';



	seed();
	
	while(x != ('q')){

        printf("Enter a move:\n");
	printf("R for ROCK\n");
	printf("P for PAPER\n");
	printf("S for SCISSORS\n");
	printf("L for LIZARD\n");
	printf("V for SPOCK\n");
	printf("Q to have SPOCK eat a ROCK while chasing a LIZARD and quit\n");
	printf("Move: ");
	while ((tmp = getchar()) != '\n')
                player = tmp;
	
	printf("\n");
	switch (player){
	case 'R':
	case 'r':
		player = 'R';
		printf("You picked:	 	ROCK\n");
		break;
	case 'P':
	case 'p':
		player = 'P';
		printf("You picked:	 	PAPER\n");
		break;
	case 'S':
	case 's':
		player = 'S';
		printf("You picked:	 	SCISSORS\n");
		break;
	case 'L':
	case 'l':
		player = 'L';
		printf("You picked:	 	LIZARD\n");
		break;
	case 'V':
	case 'v':
		player = 'V';
		printf("You picked:	 	SPOCK\n");
		break;
	case 'Q':
	case 'q':
		player = 'Q';
		printf("\n\nYou quit. Goodbye.\n");
		x = 'q';
		break;
	default:
		printf("\n !!!!  Invaild input. Try again !!!!\n");
		break;
	}

	if(((player == 'R') | (player == 'S')| (player == 'P') | (player == 'V') | (player == 'L')| (player == 'r') | (player == 's')| (player == 'p') | (player == 'v') | (player == 'l'))){
		switch(nrand(CHOICES)) {
		case 0:
			computer = ROCK;
			printf("Computer picked: 	ROCK\n");
			break;
		case 1:
			computer = PAPER;
			printf("Computer picked: 	PAPER\n");
			break;
		case 2:
			computer = SCISSORS;
			printf("Computer picked: 	SCISSORS\n");
			break;
		case 3:
			computer = LIZARD;
			printf("Computer picked: 	LIZARD\n");

			break;
		case 4:
			computer = SPOCK;
			printf("Computer picked: 	SPOCK\n");
			break;
		}
	}	

	printf("\n");
	the_winner = winner(computer, player);
	printf("\n");
	print_winner(the_winner, computer, player);
	printf("\n\n");

	}
	return 0;
}

/**
 * determines the winner either COMPUTER or PLAYER
 * @param computer the computer's move
 * @param player the player's move
 * @return the winner of the game
 */
int winner(int computer, int player)
{
	switch (player){
	case ROCK:			//Player Rock vs.
		switch (computer){
		case PAPER: 		//Paper covers rock
			return 1;
			break;
		case SCISSORS: 		//Rock crushes scissors
			return 0;
			break;
		case SPOCK: 		//Spock vaporizes rock
			return 1;
			break;
		case LIZARD: 		//Rock crushes lizard
			return 0;
			break;
		case ROCK: 		//Draw
			return 2;
			break;
		}
		break;
	case PAPER:			//Player Paper vs
		switch (computer){
		case PAPER: 		//Draw
			return 2;
			break;
		case SCISSORS:		//Scissors cuts paper
			return 1;
			break;
		case SPOCK: 		//Paper disproves Spock
			return 0;
			break;
		case LIZARD: 		//Lizard eats paper
			return 1;
			break;
		case ROCK: 		//Paper covers rock
			return 0;
			break;
		}
		break;
	case SCISSORS:			//Player Scissors vs.
		switch (computer){
		case PAPER: 		//Scissors cut paper
			return 0;
			break;
		case SCISSORS:		//Draw
			return 2;
			break;
		case SPOCK: 		//Spock smashes scissors
			return 1;
			break;
		case LIZARD: 		//Scissors decapitates lizard
			return 0;
			break;
		case ROCK: 		//Rock smashes scissors
			return 1;
			break;
		}
		break;
	case SPOCK:
		switch (computer){
		case PAPER: 		//Paper disproves Spock
			return 1;
			break;
		case SCISSORS:		//Spock smashes scissors
			return 0;
			break;
		case SPOCK: 		//Draw
			return 2;
			break;
		case LIZARD: 		//Lizard poisons Spock
			return 1;
			break;
		case ROCK: 		//Spock vaporizes rock
			return 0;
			break;
		}
		break;
	case LIZARD:			//Player Scissors vs.
		switch (computer){
		case PAPER: 		//Lizard eats paper
			return 0;
			break;
		case SCISSORS:		//Scissors decapitates lizard 
			return 1;
			break;
		case SPOCK: 		//Lizard poisons spock
			return 0;
			break;
		case LIZARD: 		//Draw
			return 2;
			break;
		case ROCK: 		//Rock smashes lizard
			return 1;
			break;
		default:
			break;
		}
		break;
	default:
		return 4;
		break;
	}
	return 1;
}

/**
 * prints the winner of the game to stdin
 * @param winner who won the computer or player
 * @param comp_move what move did the computer make
 * @param play_move what move did the player make
 * @return void
 */
void print_winner(int winner, int comp_move, int player_move)
{
	switch (winner) {
	case 1:
		printf("Computer wins!\n");
		switch (comp_move){
		case ROCK:
			switch (player_move){
			case SCISSORS: 		
				printf("Rock crushes scissors.\n");
				break;
			case LIZARD: 		
				printf("Rock crushes lizard.\n");
				break;
			}
			break;
		case PAPER:			
			switch (player_move){
			case SPOCK: 		
				printf("Paper disproves Spock.\n");
				break;
			case ROCK: 		
				printf("Paper covers rock.\n");
				break;
			}
			break;
		case SCISSORS:			
			switch (player_move){
			case PAPER: 		
				printf("Scissors cut paper.\n");
				break;
			case LIZARD: 		
				printf("Scissors decapitates lizard.\n");
				break;
			}
			break;
		case SPOCK:
			switch (player_move){
			case SCISSORS:		
				printf("Spock smashes scissors.\n");
				break;
			case ROCK: 		
				printf("Spock vaporizes rock.\n");
				break;
			}
			break;
		case LIZARD:			
			switch (player_move){
			case PAPER: 		
				printf("Lizard eats paper.\n");
				break;
			case SPOCK: 		
				printf("Lizard poisons Spock.\n");
				break;
			}
			break;
		default:
			break;
		}
		break;
	case 0:
		printf("Player wins!\n");
		switch (player_move){
		case ROCK:
			switch (comp_move){
			case SCISSORS: 		
				printf("Rock crushes scissors.\n");
				break;
			case LIZARD: 		
				printf("Rock crushes lizard.\n");
				break;
			}
			break;
		case PAPER:			
			switch (comp_move){
			case SPOCK: 		
				printf("Paper disproves Spock.\n");
				break;
			case ROCK: 		
				printf("Paper covers rock.\n");
				break;
			}
			break;
		case SCISSORS:			
			switch (comp_move){
			case PAPER: 		
				printf("Scissors cut paper.\n");
				break;
			case LIZARD: 		
				printf("Scissors decapitates lizard.\n");
				break;
			}
			break;
		case SPOCK:
			switch (comp_move){
			case SCISSORS:		
				printf("Spock smashes scissors.\n");
				break;
			case ROCK: 		
				printf("Spock vaporizes rock.\n");
				break;
			}
			break;
		case LIZARD:			
			switch (comp_move){
			case PAPER: 		
				printf("Lizard eats paper.\n");
				break;
			case SPOCK: 		
				printf("Lizard poisons Spock.\n");
				break;
			}
			break;
		}
		break;
	case 2:
		switch (player_move){
		case ROCK:
			switch (comp_move){
			case ROCK: 		
				printf("It's a draw. Play again!\n");
				break;
			}
			break;
		case PAPER:			
			switch (comp_move){
			case PAPER: 		
				printf("It's a draw. Play again!\n");
				break;
			}
			break;
		case SCISSORS:			
			switch (comp_move){
			case SCISSORS: 		
				printf("It's a draw. Play again!\n");
				break;
			}
			break;
		case SPOCK:
			switch (comp_move){
			case SPOCK:		
				printf("It's a draw. Play again!\n");
				break;
			}
			break;
		case LIZARD:			
			switch (comp_move){
			case LIZARD: 		
				printf("It's a draw. Play again!\n");
				break;
			}
			break;
		break;
		}
	break;
	}
}

/**
 * returns a uniform random integer n, between 0 <= n < range
 * @param range defines the range of the random number [0,range)
 * @return the generated random number
 */
int nrand(int range)
{
	return rand() % range;
}

/**
 * call this to seed the random number generator rand()
 * uses a simple seed -- the number of seconds since the epoch
 * call once before using nrand and similar functions that call rand()
 */
void seed(void)
{
  	srand((unsigned int)time(NULL));
}
