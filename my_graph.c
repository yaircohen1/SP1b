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
            createMat(mat[N][N]);
        
        if (ch=="B")
        {
            if (scanf("%d%d", &i, &j)!=EOF) 
            {
                if (hasPath(i, j, mat)!=1)
                    printf("True\n");
                else
                    printf("False\n");

            }
        }

        if(ch=='C')
        {
            if (scanf("%d%d", &i, &j)!=EOF) 
            {
                int num=shortestPath(i, j, mat);
                printf("%d\n",&num);
            }
        }
        scanf("%c",&ch);
    }
    return 0;
}