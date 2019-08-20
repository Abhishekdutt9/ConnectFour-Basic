# new
Here are the list of function that I used to make the connect four program:

checkHorizontalWin- this function basically checks whether the game is over horizontally by checking for 4 consecutive X or O

checkVerticalWin- this function checks whether the game is over vertically by checking for 4 consecutive X or O

checkDiagonalWinDown2Up- this function checks whether there are 4 consecutive X or O in a diagonal going from the bottom to top

checkDiagonalWinUp2Down-this function checks whether there are 4 consecutive X or O in a diagonal going from the bottom to top

AIRandoms- this function creates a random integer where the Ai enters the X

toss- this function asks the user if he wants to go first or not 

findColNotFull- finds a column that is not full and returns the column number

playerTurn-this is the function which converts the char entry to an int 

isColFull- this functions checks whether the given column is full, returns boolean

makeBoard- this is the function used to initialize all of the board to .

isFull- this functions returns a boolean value of the board being completely full and the
 main then uses this function to say that the game ended in a draw if the board is full without no result

aiVertical- this is the complicated AI algorithm, it checks if there are 3 consecutive X or O vertically and if there is a place to enter the X or O to either win the game for the Ai or to block the move for the player

aiDiagonal- this is the AI algorithm which checks if the game can be won or not be lost by placing an X in a column which either makes the computer win or blocks the move of the player. It checks left and right of the particular column in the particular row

aiHorizontal- this is the Ai algorithm which checks for the game being won or not being lost if there is a chance to place the X in the column that makes it 4 X's diagonally or it saves the games for the computer by blocking the move of the user.

The program runs from the main, the main checks whether the board is full or not, I have used a Boolean function which I used to alternate chances between the player and the AI. I also called the Ai functions to determine which is the best column to place for the Ai.
It also takes the user input and calls a function that converts it into inter value.

The link to the youtube video demonstrating the execution of the program:
https://www.youtube.com/watch?v=6fajSmM-ZFA

Thank you.
