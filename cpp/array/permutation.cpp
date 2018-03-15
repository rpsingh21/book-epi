// problem
// Find all permutation of given array
#include <stdio.h>
#include <string.h>

/* Function to swap values at two pointers */
void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void permute(char *a, int l, int r)
{
   int i;
   if (l == r)
     printf("%s\n", a);
   else
   {
       for (i = l; i <= r; i++)
       {
          swap((a+l), (a+i));
          permute(a, l+1, r);
          swap((a+l), (a+i)); //backtrack
       }
   }
}

int main()
{
    char str[] = "ABCD";
    int n = strlen(str);
    permute(str, 0, n-1);
    return 0;
}

// Time complexity = O(n*n!) where n is number of ements
