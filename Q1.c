#include<stdio.h>

int n;
int board[20];

int isSafe(int pos)
{
for(int i=0;i<pos;i++)
{
if(board[i]==board[pos])
return 0;
}
return 1;
}

void solve(int pos)
{
if(pos==n)
{
printf("Valid Strategy:\n");

for(int i=0;i<n;i++)
printf("%d ",board[i]);

return;
}

for(int move=1;move<=n;move++)
{
board[pos]=move;

if(isSafe(pos))
solve(pos+1);
}
}

int main()
{

printf("Enter number of game states: ");
scanf("%d",&n);

solve(0);

return 0;

}
Input
Enter number of game states: 4
Output
Valid Strategy:
1 2 3 4
