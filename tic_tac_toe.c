#include<stdio.h>
void rules();
void play();
void printBoard(int mat[3][3]);

int main()
{
	printf("\n.............................................................................\n\n");
	printf("\t\t\t Welcome to TIC TAC TOE Game 🎰\n");
	int opt;
	do
	{

		printf("Select options below:\n1. Play 🎮\n2. Rules 📋\n3. Exit\n");
		printf("\n.............................................................................\n\n");
		
		scanf("%d",&opt);

		switch(opt)
		{
				case 1: play();
						break;
				case 2: rules();
						break;
				case 3: printf("Game is closing...\n");
						break;
						default: printf("Invalid input!");
		}

	} while (opt != 3);

}

void rules()
{
	printf("\n.............................................................................\n");
	printf("\t\t\t📃TIC TAC TOE game rules \n");
	printf("✦  Player 1 uses ❌\n");
	printf(" \n✦  Player 2 uses ⭕️\n");
	printf(" \n✦  The board is a 3️⃣   x 3️⃣  grid.\n");
	printf(" \n✦  A move is made by choosing a row and column\n");
	printf(" \n✦  A player cannot place a symbol in an already occupied cell.\n");
	printf(" \n✦  First player to get 3 in a row(horizontally,vertically\n   or diagonally wins the game🎉\n");
	printf(" \n✦  If all 9 cells are filled and no player has 3 in a row,\n   the game ends in a draw🤝\n");
	printf(".............................................................................\n\n");
	printf("\n");
}

void play()
{
		char player1[100];
		char player2[100];
		printf("Enter player1 name(X):\n");
		scanf(" %[^\n]",player1);

		printf("Enter player2 name(O):\n");
		scanf(" %[^\n]",player2);
		int mat[3][3];
		
		int count = 0;
		int r;
		int c;

		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
			{
				mat[i][j] = 0;
			}
		}

		printBoard(mat);
		do
		{
			
			if(count % 2 == 0)
			{
				printf("%s's turn ", player1);
				scanf("%d",&r);
				scanf("%d",&c);
				if(r < 0 || r > 2 || c < 0 || c > 2)
				{
					printf("Invalid position! Enter in the range of 0 - 2\n\n");
					continue;
				}
				if(mat[r][c] == 0)
				{
					mat[r][c] = 1;
					count++;
				}
				else
				{
					printf("\nChoose another position!\n"); 
				}
			}
			else if(count % 2 == 1)
			{
				printf("%s's turn ", player2);
				scanf("%d",&r);
				scanf("%d",&c);
				if(mat[r][c] == 0)
				{
					mat[r][c] = 2;
					count++;
				}
				else
				{
					printf("\nChoose another position!\n\n"); 
				}
			}
				printBoard(mat);
			/*
			for(int i = 0; i < 3; i++)
			{
				for(int j = 0; j < 3; j++)
				{
					if(mat[i][j] == 1)
					{
						printf("❌\t");
					}
					else if(mat[i][j] == 2)
					{
						printf("⭕️\t");
					}
					else
					{
						printf(" \t");
					}
				}
				printf("\n\n");
			}
				*/
			for(int i = 0; i < 3; i++)
			{
				//Rows and Column check 
				if((mat[i][0] == 1 && mat[i][1] == 1 && mat[i][2] == 1) || (mat[0][i] == 1 && mat[1][i] == 1 && mat[2][i] == 1))
				{
					printf("🎊Congragulations %s wins!\n\n",player1);
					return;
				}
				else if((mat[i][0] == 2 && mat[i][1] == 2 && mat[i][2] == 2) || (mat[0][i] == 2 && mat[1][i] == 2 && mat[2][i] == 2))
				{
					printf("🎊Congragulations %s wins!\n\n",player2);
					return;
				}
			}

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
				
			if(count == 9)
			{
				printf("Game is a draw!\n\n");
			}

		}while(count != 9);
}

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
