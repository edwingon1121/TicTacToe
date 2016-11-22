// Edwin Gonzalez
// ITP 165, Spring 2016
// Homework 06
// edwingon@usc.edu

#include <iostream>
#include <string>

//Function: PrintBoard
//Purpose: to print the game board
//Parameters:three numbers in each row and a total of three rows
//Returns: Nothing since it is a void function.
void PrintBoard(char game[])
{
    int length=std::strlen(game);
    for (int i=0; i<length; i++)
         {
             if (i==3|| i==6)
             {
                 std::cout<<"-----------"<<std::endl;
                 std::cout<<game[i]<<" | ";
             }
             else if (i==2 || i==5 || i==8)
             {
                 std::cout<<game[i]<<std::endl;
             }
             else
             {
                 std::cout<<game[i]<< " | ";
             }
         }
}

//Function: IsValidMove
//Purpose: to validate if a player may make a move in the attempted spot on the game board
//Parameters: the charcter array storing the game board, the INDEX of the player's next and attempted move in character array
//Return: true if player may make a move in valid range and empty spot, false if spot is already taken or outside valid array index range

bool IsValidMove(char board[], int index)
{
    int value=0;
    if((index>=0 && index<=9) && (board[index]!='X' && board[index]!='O'))
    {
        value=1;
    }
        
    bool retVal=value;
        return retVal;
	
}

//Function: WinnerIfAny
//Purpose: to determine who is the current winner (if any)
//Parameters: the character array that contains the game's moves
//Return: a char symbolizing who is the current winner: either X or O to show a player has one, or N if no one has yet won the game
char WinnerIfAny(char move[], int moveCounter)
{
	unsigned int j = 0;
	for (unsigned int i = 0; i < 9; i += 3)
	{
		//Three in a row
		if (move[i] == move[i + 1] && move[i] == move[i + 2])
		{
			return move[i];
		}
		//three in a column
		else if (move[j] == move[j + 3] && move[j] == move[j + 6])
		{
			return move[j];
		}
		//three in first diagonal (top left to bottom right)
		else if (move[0] == move[4] && move[0] == move[8])
		{
			return move[0];
		}
		//three in second diagonal (top left to bottom left)
		else if (move[2] == move[4] && move[2] == move[6])
		{
			return move[2];
		}
		j++;
	}

	//winner wasn't found, board completely filled up - return Stalemate 'S'
	if (moveCounter > 8)
	{
		return 'S';
	}

	//otherwise there are no three-in-a-row anywhere on the board - return NoWinner 'N'
	return 'N';
}

int main()
{
	//intializes the array
    char array[]=
    {
        "123456789"
    };
    
    PrintBoard(array);
    
    //Creation of boolean for a loop
    bool loop=true;
    
    int index=0;
    int counter=0;
    
    while (loop)
    {
        //Player X's turn 
        std::cout<<"Player X. Pick a spot:";
        std::cin>>index;
        
        //In order to check whether if values are true or false.
        //std::cout<<IsValidMove(array,index-1)<<std::endl;
        
        if (IsValidMove(array,index-1)==1)
        {
            array[index-1]='X';
            PrintBoard(array);
            counter++;
        }
        else
        {
            ~loop;
        while (~loop)
               {
                std::cout<<"Invalid spot or range. Try Again."<<std::endl;
                std::cout<<"Player X. Pick a spot:";
                std::cin>>index;
                
                
                if (IsValidMove(array,index-1)==1)
                {
                    array[index-1]='X';
                    PrintBoard(array);
                    counter++;
                    break;
                }
               }
        }
        
        if (WinnerIfAny(array,counter)=='X')
        {
            std::cout<<"Player X is the winner!"<<std::endl;
            break;
        }
        
        else if (WinnerIfAny(array, counter)=='O')
        {
            std::cout<<"Player O is the winner!"<<std::endl;
            break;
        }
        else if (WinnerIfAny(array, counter)=='N')
        {
            std::cout<<"No one has won yet..."<<std::endl;
            
        }
        else if (WinnerIfAny(array, counter)=='S')
        {
            std::cout<<"There is a stalemate!"<<std::endl;
            break;
            
        }

        //Now it is Player O's turn.
        
        std::cout<<"Player O. Pick a spot:";
        std::cin>>index;
        
        //In order to check whether if values are true or false.
        //std::cout<<IsValidMove(array,index-1)<<std::endl;
        
        if (IsValidMove(array,index-1)==1)
        {
            array[index-1]='O';
            PrintBoard(array);
            counter++;
            
        }
        else
        {
            ~loop;
            while (~loop)
            {
                std::cout<<"Invalid spot or range. Try Again."<<std::endl;
                std::cout<<"Player O. Pick a spot:";
                std::cin>>index;
                //std::cout<<IsValidMove(array, index-1)<<std::endl;
            
                if (IsValidMove(array,index-1)==1)
                {
                    array[index-1]='O';
                    PrintBoard(array);
                    counter++;
                    break;
                }
            }
        }
    
            if (WinnerIfAny(array, counter)=='X')
            {
                std::cout<<"Player X is the winner!"<<std::endl;
                break;
            }
            
            else if (WinnerIfAny(array, counter)=='O')
            {
                std::cout<<"Player O is the winner!"<<std::endl;
                break;
            }
            else if (WinnerIfAny(array, counter)=='N')
            {
                std::cout<<"No one has won yet..."<<std::endl;

            }
            else if (WinnerIfAny(array, counter)=='S')
            {
                std::cout<<"There is a stalemate!"<<std::endl;
                break;

            }
        }

	return 0;
}