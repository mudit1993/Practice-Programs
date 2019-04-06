#define N 4
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
char a[10][10],cpy[10][10];
    int n,m,cnt;

/* A utility function to print solution */
void printSolution()
{
    int i;
    for (i = 0; i < n; i++)
    {
        int j;
        for ( j = 0; j < m; j++)
        cout<<cpy[i][j]<<" ";
        cout<<"\n";
    }
}

/* A utility function to check if a queen can be placed on board[row][col]
   Note that this function is called when "col" queens are already placeed
   in columns from 0 to col -1. So we need to check only left side for
   attacking queens */
bool isSafe(int row, int col)
{
    int i, j;

    /* Check upper diagonal on left side */
    for (i = row, j = col; i >= 0 && j >= 0 && cpy[i][j]!='*'; i--, j--)
    {
        if (cpy[i][j]=='B')
            return false;
    }

    /* Check lower diagonal on left side */
    for (i = row, j = col; j >= 0 && i < n && cpy[i][j]!='*'; i++, j--)
    {
        if (cpy[i][j]=='B')
            return false;
    }
    for (i = row, j = col; j < m && i >=0 && cpy[i][j]!='*'; i--, j++)
    {
        if (cpy[i][j]=='B')
            return false;
    }

    for (i = row, j = col; j < m && i <n && cpy[i][j]!='*'; i++, j++)
    {
        if (cpy[i][j]=='B')
            return false;
    }
    return true;
}

/* A recursive utility function to solve N Queen problem */
bool solveNBUtil(int col)
{
    /* base case: If all queens are placed then return true */
    if (col > m)
        return true;

    /* Consider this column and try placing this queen in all rows
       one by one */
    for (int i = 0; i < m; i++)
    {
        /* Check if queen can be placed on board[i][col] */
        if ( isSafe(i, col) )
        {
            /* Place this queen in board[i][col] */
            cpy[i][col] = 'B';

            /* recur to place rest of the queens */
            if ( solveNBUtil(col+1) == true )
                return true;

            /* If placing queen in board[i][col] doesn't lead to a solution
               then remove queen from board[i][col] */
            cpy[i][col] = '.'; // BACKTRACK
        }
    }

     /* If queen can not be place in any row in this colum col
        then return false */
    return false;
}

/* This function solves the N Queen problem using Backtracking.  It mainly uses
solveNQUtil() to solve the problem. It returns false if queens cannot be placed,
otherwise return true and prints placement of queens in the form of 1s. Please
note that there may be more than one solutions, this function prints one of the
feasible solutions.*/
bool solveNB()
{
    for(int i=0;i<m;i++){
            for(int k=0;k<n;k++)
            {
                for(int l=0;l<m;l++)
                    cpy[k][l]=a[k][l];
            }
            cpy[0][i]='B';
    if ( solveNBUtil(1) == false )
    {
        printSolution();
      cout<<"Solution does not exist";
      return false;
    }
    else cnt++;
    printSolution();
    }
    return true;
}

// driver program to test above function
int main()
{
    cin>>n>>m;
    cnt=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {cin>>a[i][j];
            cpy[i][j]=a[i][j];
        }
    solveNB();

    getchar();
    return 0;
}
