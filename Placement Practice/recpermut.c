# include <stdio.h>
/* Function to swap values at two pointers */
 void swap (char *x, char *y)
 {
     char temp;
     temp = *x;
     *x = *y;
     *y = temp;
     }
     /* Function to print permutations of string This function takes three parameters:
     1. String
     2. Starting index of the string 3
     . Ending index of the string. */
     void permute(char *a, int i, int n)
      {
          int j;
          if(i == n)
            printf("%s\n", a);
          else {
              for (j = i; j <= n; j++)
              {
                    printf("bef---  %s  i=%d, j =%d \n", a,i,j);
                    swap((a+i), (a+j));
                     permute(a, i+1, n);
                       printf("mid---  %s i=%d, j =%d \n", a,i,j);
                     swap((a+i), (a+j)); //backtrack
                        printf("aft---  %s i=%d, j =%d \n", a,i,j);
                }
            }
        } /* Driver program to test above functions */
    int main()
     {
          char a[] = "ABC";
        permute(a, 0, 2);
        getchar();
        return 0;
        }
