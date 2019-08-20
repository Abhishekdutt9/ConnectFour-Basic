#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
bool checkHorizontalWin(char board[6][7]){//check whether the game has been won horizontally
  int cx=0;
  int co=0;
  for(int i=5;i>=0;i--){//iterating through the board columnvise
    for(int j=0;j<7;j++){//column iteration
        if(board[i][j]=='.'){//checks if the char is .
          cx=0;
          co=0;
          continue;
        }
        else if(board[i][j]=='X'){//check whether char is X and increases the x counter
          cx++;
          co=0;
          if(cx>3){
          printf("%dAi wins Horizontally",cx);//if the counter exceeds 3 it declares win
          return true;
        }
        }
        else if(board[i][j]=='O'){//checks whether the char is o and increases the o counter
          cx=0;
          co++;
          if(co>3){
          printf("%dYou win! Congrats ",co);//if the counter exceeds 3 it declares win
          return true;
          } 
        }
    }
  }
return false;
}
bool checkVerticalWin(char board[6][7]){
  for(int j=0;j<7;j++){ //iterating through the board rowvise
  int cx=0;
  int co=0;
    for(int i=5;i>=0;i--){
      if(cx<=3&&co<=3){
        if(board[i][j]=='.'){
          cx=0;
          co=0;
          break;
        }
        else if(board[i][j]=='X'){
          cx++;
          co=0;
        }
        else if(board[i][j]=='O'){
          co++;
          cx=0;
        }
      }
      else if(cx>3||co>3){
        if(cx>3){//if the counter exceeds 3 it declares win
          printf("AI wins");
        }
        else
        printf("you win");//if the counter exceeds 3 it declares win
        return true;
      }
    }
  }
  return false;
}
bool checkDiagonalWinDown2Up(char board[6][7]){
  int x;
  int y;
  int co=0;
  int cx=0;
  
  for(int i=3;i<=5;i++){
    for(int j=0;j<=3;j++){
      if(board[i][j]=='.'){
      continue;
      }
      else if(board[i][j]=='X'){
        cx=0;
        for(x=i-1,y=j+1;y<=j+3;x--,y++){
          
          if(board[x][y]=='X'){
            cx++;
          }
          else{
            continue;
          }
        }
        if(cx>=3){//if the counter exceeds 3 it declares win
        printf("AI wins Diagonally");
        return true;
        }
      }
      else if(board[i][j]=='O'){
        co=0;
        for(x=i-1,y=j+1;y<=j+3;x--,y++){
          if(board[x][y]=='O'){
            co++;
          }
          else{
            continue;
          }
        }
        if(co>=3){//if the counter exceeds 3 it declares win
        printf("You win! Congrats");
        return true;
        }
      }
    }
  }
return false;
}
bool checkDiagonalWinUp2Down(char board[6][7]){
  int x;
  int y;
  int co=0;
  int cx=0;
  
  for(int i=0;i<=2;i++){
    for(int j=0;j<=3;j++){
      if(board[i][j]=='.'){
      continue;
      }
      else if(board[i][j]=='X'){
        cx=0;
        for(x=i+1,y=j+1;y<=j+3;x++,y++){
          
          if(board[x][y]=='X'){
            cx++;
          }
          else{
            continue;
          }
        }
        if(cx>=3){//if the counter exceeds 3 it declares win
        printf("AI wins diagonally");
        return true;
        }
      }
      else if(board[i][j]=='O'){
        co=0;
        
        for(x=i+1,y=j+1;y<=j+3;x++,y++){
        
          if(board[x][y]=='O'){
            co++;
          }
          else{
            continue;
          }
        }
        if(co>=3){//if the counter exceeds 3 it declares win
        printf("You Win! Congrats dia 2");
        return true;
        }
      }
    }
  }
  return false;
}
int AIRandoms(int lower, int upper)//generates a random number
{
//copied this from https://www.geeksforgeeks.org/generating-random-number-range-c/
return (rand() % (upper - lower + 1)) + lower;
}
void printBoard(char board[6][7])//function to print the board
{
printf("   A  B  C  D  E  F  G  \n");

for(int i = 6, index = 0; index < 6; i--, index++)
{
printf("%i  ", i);
for(int j = 0; j < 7; j++)
{
 printf("%c  ", board[index][j]);
}
printf("\n");
}
}
bool toss(){
  char var;
  printf("Do you want to play first?(enter y/n)\n");//asks user if he wants to go first
  scanf("%c",&var);
  if(var=='y')
  return true;
  return false;
  
}
int findColNotFull(char board[6][7]){//finds a column that is not full
  for(int i=0;i<7;i++){
    if(board[0][i]=='.')//if . is found the column is not full
    return i;
  }
  return 0;
}
int playerTurn(char col){//converts the char entry to equivalent int
  
  int coln = -1;
  while(coln==-1){
    if(col=='A')
      coln=0;
    else if(col=='B')
      coln=1;
    else if(col=='C')
      coln=2;
    else if(col=='D')
      coln=3;
    else if(col=='E')
      coln=4;
    else if(col=='F')
      coln=5;
    else if(col=='G')
      coln=6;
    else{
      coln =-1;
      printf("Please enter a valid column from A-G\n");
      scanf("%c",&col);
      playerTurn(col);
    }
    }
  
 return coln;
}
bool isColFull(char board[6][7], int coln){
  if(board[0][coln]!='.'){//checking if the top most row has an empty slot
    return true;
  }
  return false;
}
bool add(char board[6][7],int coln, char ch){//adds either X or O in the desired column
  int i;
  if(isColFull(board,coln)){//checks whether the column is full or not 
      if(ch=='X'){
        int z=findColNotFull(board);
        add(board,z,'X');
      }
      
    return false;
  }
  else {
    i = 5; //bottom row
    while(board[i][coln]!='.')
    i--;
  }
  board[i][coln]=ch;//storing the character in the right spot of the 2-d array
  printBoard(board);
  return true;
}
void makeBoard(char board[6][7]){//initialises the board of connect 4
  for(int i = 0 ; i < 6; i++)
{
for(int j = 0 ; j < 7; j++)
{
 board[i][j]= '.' ;
}
}
}
bool isFull(char board[6][7]){//boolean function that returns true if the board is full
  int row=0;
  int column=0;
  for(;column<=6;column++){
    if(board[row][column]=='.'){
      return false;
    }
  }
  printf("the game is a draw");
  return true;
}
int aiVertical(char board[6][7]){//Ai function that recogonises whether the game could be won vertically
  int co=0;//counters
  int cx=0;
  int col = 7;
  for(int j=0;j<col;j++){
    co=0;
    cx=0;
    for(int i=5;i>=1;i--){
        if(board[i][j]=='.'){//breaks if the column is empty
          break;
        }
        if(board[i][j]=='X'&&board[i-1][j]=='.'){
          cx++;//increases the value of x counter
          co=0;
          if(cx==3)
          return j;
          continue;
        }
        if(board[i][j]=='O'){
          co++;// increases the value of o counter
          cx=0;//makes x counter 0
          if(co==3&&board[i-1][j]=='.')
          return j;
          continue;
        }
    }
  }
  return -1;
}
int aiDiagonal(char board[6][7]){//Ai function that recogonises whether the game could be won diagonally
  int rowArr[7]={-1,-1,-1,-1,-1,-1,-1};
  for(int i=0;i<7;i++){//finding the possible places on the board where the player can place the X or O
    if(isColFull(board,i)){
      continue;
    }
    else{
      for(int j=5;j>=0;j--){
        if(board[j][i]=='.'){
        rowArr[i]=j;//saves the row where the possible moves could be playes in column i 
        break;
        }
        else
        continue;
      }
    }
  }
  for(int i=0;i<7;i++){
    int leftx1=0;//all the counters that are used
    int rightx1=0;
    int lefto1=0;
    int righto1=0;
    int leftx2=0;
    int rightx2=0;
    int lefto2=0;
    int righto2=0;
    int z;
    int x;
    if(rowArr[i]!=-1){
      for(z=i-1,x=rowArr[i]-1;z>=0||x>=0;z--,x--){//goes left and up
        if(board[x][z]=='X'){
          leftx1++;//counter increment
          if(leftx1+rightx1==3)
          return i;//returns the value of column
          }
          else if(board[x][z]!='X')
          break; 
        }
      for(int z=i+1,x=rowArr[i]+1;z<=6||x>=0;z++,x++){//goes right and down
        if(board[x][z]=='X'){
          rightx1++;
          if(leftx1+rightx1>=3)
            return i;//returns the value of column
        }
        else if(board[x][z]!='O')
          break;
      }
      for(z=i-1,x=rowArr[i]-1;z>=0||x>=0;z--,x--){//goes left and up
        if(board[x][z]=='O'){
          lefto1++;
          if(lefto1+righto1==3)
          return i;//returns the value of column
        }
        else if(board[x][z]!='O')
        break; 
      }
      for(int z=i+1,x=rowArr[i]+1;z<=6||x>=0;z++,x++){//goes right and down 4
        if(board[x][z]=='O'){
          righto1++;
          if(lefto1+righto1>=3)
            return i;//returns the value of column
        }
        else if(board[x][z]!='O')
          break;
      }
      for(z=i-1,x=rowArr[i]+1;z>=0||x<=5;z--,x++){//goes left and down
        if(board[x][z]=='X'){
          leftx2++;
          if(leftx2+rightx2==3)
          return i;//returns the value of column
          }
          else if(board[x][z]!='X')
          break; 
        }
      for(int z=i+1,x=rowArr[i]-1;z<=6||x>=0;z++,x--){//goes right and up
        if(board[x][z]=='X'){
          rightx2++;
          if(leftx2+rightx2>=3)
            return i;//returns the value of column
        }
        else if(board[x][z]!='O')
          break;
      }
      for(z=i-1,x=rowArr[i]+1;z>=0||x<=5;z--,x++){//goes left and down
        if(board[x][z]=='O'){
          lefto2++;
          if(lefto2+righto2==3)
          return i;//returns the value of column
        }
        else if(board[x][z]!='O')
        break; 
      }
      for(int z=i+1,x=rowArr[i]-1;z<=6||x>=0;z++,x--){//goes right and up
        if(board[x][z]=='O'){
          righto2++;
          if(lefto2+righto2>=3)
            return i;//returns the value of column
        }
        else if(board[x][z]!='O')
          break;
      }
    }
  }
  return -1;
}

int aiHorizontal(char board[6][7]){
  int leftx=0;
  int rightx=0;
  int lefto=0;
  int righto=0;
  int rowArr[7]={-1,-1,-1,-1,-1,-1,-1};
  for(int i=0;i<7;i++){//finding the possible places on the board where the player can place the X or O
    if(isColFull(board,i)){
      continue;
    }
    else{
      for(int j=5;j>=0;j--){
        if(board[j][i]=='.'){
        rowArr[i]=j;//saves the row which has . in the column i
        break;
        }
        else
        continue;
      }
    }
  }
  for(int i=0;i<7;i++){
    leftx=0;
    rightx=0;
    lefto=0;
    righto=0;
    if(rowArr[i]!=-1){
      for(int z=i-1;z>=0;z--){//goes left
        if(board[rowArr[i]][z]=='X'){
          leftx++;
          lefto=0;
          if(leftx+rightx==3)
            return i;//returns the value of column
        }
        else if(board[rowArr[i]][z]!='X')
          break; 
      }
      for(int z=i+1;z<=6;z++){//goes right and checks for X
        if(board[rowArr[i]][z]=='X'){
          rightx++;
          righto=0;
          if(leftx+rightx==3)
            return i;//returns the value of column
        }
        else if(board[rowArr[i]][z]!='X')
          break;
      }
                
      for(int z=i-1;z>=0;z--){//goes left and checks for X
        if(board[rowArr[i]][z]=='O'){
          lefto++;
          leftx=0;
          if(lefto+righto==3)
            return i;//returns the value of column and checks for O
        }
        else if(board[rowArr[i]][z]!='O')
          break;
        }
      for(int z=i+1;z<=6;z++){//goes right and checks for O
        if(board[rowArr[i]][z]=='O'){
          righto++;
          rightx=0;
          if(righto+lefto==3)
            return i;//returns the value of column
        }
        else if(board[rowArr[i]][z]!='O')
          break;
        }        
    }
  }
return -1;
}

int main(int arg, char *argv[]){
char col;
char board[6][7];
makeBoard(board);
printBoard(board);
bool t=toss();
bool chance;//alternates between player and AI
if(t){//player turn
    printf("Enter the collumn where you want to place from A-G\n");//asking user for input
    scanf("%c ",&col);
    int coln=playerTurn(col);
    add(board,coln,'O');
    chance=false;
}
else if(!t){//AI turn
  printf("AI's turn\n"); 
  int aiMove = AIRandoms(0, 7);
  add(board, aiMove, 'X');
  chance=true;
}
while(!isFull(board)&&!checkVerticalWin(board)&&!checkDiagonalWinUp2Down(board)&&!checkDiagonalWinDown2Up(board)&&!checkHorizontalWin(board)){//add win function here
if(chance){
  printf("Enter the column where you want to place from A-G\n");//asking user for input
    scanf("%c ",&col);
    int coln=playerTurn(col);
    if(isColFull(board,coln)){
      printf("Column Full\nEnter another column");//asking user for input
      scanf("%c ",&col);
      int coln=playerTurn(col);
    }
    add(board,coln,'O');
    chance=false;
}
else{
  printf("AI's turn\n"); 
  int aiMove;
  int x=aiDiagonal(board);
  int x1=aiHorizontal(board);
  int x2=aiVertical(board);
  if(x!=-1&&x1!=-1&&x2!=-1)
  aiMove = AIRandoms(0, 7);
  else if(x!=-1){
    aiMove=x;
  }
  else if(x1!=-1){
    aiMove=x1;
  }
  else if(x2!=-1){
    aiMove=x2;
  }
  if(add(board, aiMove, 'X'));
  chance=true;
}
}
}


