#include<stdio.h>

int grid[9][9];


int isSafe(int row,int col,int num)
{

for(int i=0;i<9;i++)
{
if(grid[row][i]==num)
return 0;

if(grid[i][col]==num)
return 0;
}


int startRow=row-row%3;
int startCol=col-col%3;


for(int i=0;i<3;i++)
{
for(int j=0;j<3;j++)
{
if(grid[i+startRow][j+startCol]==num)
return 0;
}
}

return 1;

}


int solve()
{

int row,col;


for(row=0;row<9;row++)
{
for(col=0;col<9;col++)
{

if(grid[row][col]==0)
{

for(int num=1;num<=9;num++)
{

if(isSafe(row,col,num))
{

grid[row][col]=num;


if(solve())
return 1;


grid[row][col]=0;

}

}

return 0;

}

}

}

return 1;

}



void display()
{

for(int i=0;i<9;i++)
{
for(int j=0;j<9;j++)
printf("%d ",grid[i][j]);

printf("\n");
}

}



int main()
{

printf("Enter Sudoku grid (0 for empty):\n");


for(int i=0;i<9;i++)
{
for(int j=0;j<9;j++)
scanf("%d",&grid[i][j]);
}


if(solve())
{
printf("\nSolved Sudoku:\n");
display();
}
else
{
printf("No solution exists");
}


return 0;

}
Input
Enter Sudoku grid (0 for empty):

5 3 0 0 7 0 0 0 0
6 0 0 1 9 5 0 0 0
0 9 8 0 0 0 0 6 0
8 0 0 0 6 0 0 0 3
4 0 0 8 0 3 0 0 1
7 0 0 0 2 0 0 0 6
0 6 0 0 0 0 2 8 0
0 0 0 4 1 9 0 0 5
0 0 0 0 8 0 0 7 9
Output
Solved Sudoku:

5 3 4 6 7 8 9 1 2
6 7 2 1 9 5 3 4 8
1 9 8 3 4 2 5 6 7
8 5 9 7 6 1 4 2 3
4 2 6 8 5 3 7 9 1
7 1 3 9 2 4 8 5 6
9 6 1 5 3 7 2 8 4
2 8 7 4 1 9 6 3 5
3 4 5 2 8 6 1 7 9
