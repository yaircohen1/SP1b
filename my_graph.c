#include "my_mat.h"
#include <stdio.h>
#define N 10

int main(){
    int mat[N][N];
    char ch=0;
    int i=0;
    int j=0;
    while (scanf("%c", &ch)!= EOF && ch!='D')
    {
        if (ch=='A')
            createMat(mat);
        
        if (ch=='B')
        {
            if (scanf("%d%d", &i, &j)!=EOF) 
            {
                if (hasPath(i, j, mat)!=1)
                    printf("False\n");
                else
                    printf("True\n");

            }
        }

        if(ch=='C')
        {
            if (scanf("%d%d", &i, &j)!=EOF) 
            {
                printf("%d\n",shortestPath(i, j, mat));
            }
        }
        scanf("%c",&ch);
    }
    return 0;
}