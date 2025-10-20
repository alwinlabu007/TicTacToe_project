#include<stdio.h>

// Function declarations
void rules();
void play();
void printBoard(int mat[3][3]);

// Main function
int main()
{
	printf("\n.............................................................................\n\n");
	printf("\t\t\t Welcome to TIC TAC TOE Game 🎰\n");
	int opt;

	// Main game menu loop
	do
	{
		printf("Select options below:\n1. Play 🎮\n2. Rules 📋\n3. Exit\n");
		printf("\n.............................................................................\n\n");
		
		scanf("%d",&opt);

		switch(opt)
		{
				case 1: play();					// Start the game
						break;
				case 2: rules();				// Display rules
						break;
				case 3: printf("Game is closing...\n");
						break;
						default: printf("Invalid input!");
		}
	} while (opt != 3);							// Exit loop when user selects 3
}

void rules()									//function to display rules
{
	printf("\n.............................................................................\n");
	printf("\t\t\t📃TIC TAC TOE game rules \n");
	printf("✦  Player 1 uses x\n");
	printf(" \n✦  Player 2 uses o\n");
	printf(" \n✦  The board is a 3️⃣   x 3️⃣  grid.\n");
	printf(" \n✦  A move is made by choosing a row and column\n");
	printf(" \n✦  A player cannot place a symbol in an already occupied cell.\n");
	printf(" \n✦  First player to get 3 in a row(horizontally,vertically\n   or diagonally wins the game🎉\n");
	printf(" \n✦  If all 9 cells are filled and no player has 3 in a row,\n   the game ends in a draw🤝\n");
	printf(".............................................................................\n\n");
	printf("\n");
}

void play()										//function to play the game
{
		// Get player names

		char player1[100];
		char player2[100];
		printf("Enter player1 name(X):\n");
		scanf(" %[^\n]",player1);

		printf("Enter player2 name(O):\n");
		scanf(" %[^\n]",player2);
		int mat[3][3];							// 3x3 board
		
		int count = 0;							//count variable to check the game round
		int r;
		int c;

		for(int i = 0; i < 3; i++)				// Initialize the board with zeros (empty)
		{
			for(int j = 0; j < 3; j++)
			{
				mat[i][j] = 0;
			}
		}

		printBoard(mat);						// Print initial empty board
		do
		{
			
			if(count % 2 == 0)					//if count is even,player 1's turn
			{
				printf("%s's turn ", player1);
				scanf("%d",&r);					//player enters the [row][col]
				scanf("%d",&c);
				
				if(r < 0 || r > 2 || c < 0 || c > 2)	// Input validation
				{
					printf("Invalid position! Enter in the range of 0 - 2\n\n");
					continue;
				}
				if(mat[r][c] == 0)				//if the array value is 0, user input is taken and array is modified as 1
				{
					mat[r][c] = 1;				
					count++;					//count is incremented 
				}
				else							// Check if position is free
				{
					printf("\nChoose another position!\n"); 
				}
			}
			else if(count % 2 == 1)				//if count is even,player 2's turn
			{
				printf("%s's turn ", player2);
				scanf("%d",&r);					//player enters the [row][col]
				scanf("%d",&c);
				if(mat[r][c] == 0)
				{
					mat[r][c] = 2;				//if the array value is 0, user input is taken and array is modified as 2
					count++;
				}
				else							// Check if position is free
				{
					printf("\nChoose another position!\n\n"); 
				}
			}
				printBoard(mat);				// Print updated board
			
			// Check win conditions (rows, columns, diagonals)
			for(int i = 0; i < 3; i++)
			{
				// Row and Column check for Player 1
				if((mat[i][0] == 1 && mat[i][1] == 1 && mat[i][2] == 1) || (mat[0][i] == 1 && mat[1][i] == 1 && mat[2][i] == 1))
				{
					printf("🎊Congragulations %s wins!\n\n",player1);
					return;
				}
				// Row and Column check for Player 1
				else if((mat[i][0] == 2 && mat[i][1] == 2 && mat[i][2] == 2) || (mat[0][i] == 2 && mat[1][i] == 2 && mat[2][i] == 2))
				{
					printf("🎊Congragulations %s wins!\n\n",player2);
					return;
				}
			}

			// Diagonal checks
			if ((mat[0][0] == 1 && mat[1][1] == 1 && mat[2][2] == 1) ||
           	 	(mat[0][2] == 1 && mat[1][1] == 1 && mat[2][0] == 1))

				{
					printf("\n🎊Congratulations %s wins!\n", player1);
					return;
				}

       		if ((mat[0][0] == 2 && mat[1][1] == 2 && mat[2][2] == 2) ||
            	(mat[0][2] == 2 && mat[1][1] == 2 && mat[2][0] == 2))
				{
					printf("\n🎊Congratulations %s wins!\n", player2);
					return;
				}
			// Check for draw	
			if(count == 9)
			{
				printf("Game is a draw!\n\n");
			}

		}while(count != 9);
}

// Function to display the Tic Tac Toe board
void printBoard(int mat[3][3])
{
    printf("\n\t     0   1   2\n");  // Column headers for easier play
    printf("\t   ┌───┬───┬───┐\n");

    for (int i = 0; i < 3; i++)
    {
        printf("\t %d │", i);  // Row label
        for (int j = 0; j < 3; j++)
        {
            if (mat[i][j] == 1)
                printf(" x │");
            else if (mat[i][j] == 2)
                printf(" o │");
            else
                printf("   │");
        }
        printf("\n");

        if (i < 2)
            printf("\t   ├───┼───┼───┤\n");
        else
            printf("\t   └───┴───┴───┘\n");
    }

    printf("\n");
}
