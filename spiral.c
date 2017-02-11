// Program34_A	: To Print the elements of the array in Spiral pattern

#include<stdio.h>
#include<process.h>

#define ROW 4
#define COL 4

enum DIR { RIGHT = 1, DOWN, LEFT, UP };


int main( void )
{
	
	/*
	int a[ROW][COL] =	{	
							{ 1, 2, 3, 4 ,5 }, 
							{ 6, 7, 8 ,9, 10 }, 
							{ 11, 12, 13, 14, 15 }, 
							{ 16, 17, 18, 19, 20 } , 
							{ 21, 22, 23, 24, 25 }
					};
	*/
	
	int a[ROW][COL] =	{	
							{ 1, 2, 3, 4 }, 
							{ 5, 6, 7, 8 }, 
							{ 9, 10, 11, 12 }, 
							{ 13, 14, 15, 16 } 
						};
	

	int i;
	int r = 0;
	int c = 0;
	int max = ROW-1;
	int min = 0;
	int dir;

	system("cls");

	
	printf("\n\n\t Output :: \n\n");
	printf("\n===========================================================================\n\n");
	
	dir = RIGHT;

	for( i = 0; i < 16 ; i++ )
	{
		printf("%4d",a[r][c]);

		switch( dir )
		{
			case RIGHT:
						if( c < max )
						{
							c++;
						}
						else
						{
							dir = DOWN;
							r++;
						}

						break;

			case DOWN:	
						if( r < max )
						{
							r++;
						}
						else
						{
							dir = LEFT;
							c--;
							max--;
						}
						
						break;


			case LEFT:	
						if( c > min )
							c--;
						else
						{
							dir = UP;
							r--;
						}

						break;


			case UP:	
						if( r > min+1 )
						{
							r--;
						}
						else
						{
							dir = RIGHT;
							c++;
							min++;
						}

						break;
		}//end of switch

	}//end of for loop
	
	printf("\n===========================================================================\n");
	printf("\n\n");

	return 0;
}