#include <stdio.h>
#include "my_mat.h"
#define N 10

void createMat(int mat[N][N]) 
{
    int temp;
    for (int i=0; i<N;i++){
        for(int j=0; j<N; j++){
            scanf("%d", &temp);
            mat[i][j]=temp;
        }
    }
    FloydWarshallAlgorithm(mat);
}

void FloydWarshallAlgorithm(int mat[N][N])
{
    for(int k=0; k<N; k++)
    {
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                if(i!=j && mat[i][k] != 0 && mat[k][j] != 0) // make sure that i!=j so its not the same vertice && check if all the cells on k row & k column has values  
                {

                        if (mat[i][j] == 0) // if theres no path between two vertices
                        {
                            mat[i][j] = mat[i][k] + mat[k][j];
                         }

                        else 
                        {
                            mat[i][j] = findMin(mat[i][j], mat[i][k]+mat[k][j]);
                         }
                    
                }
            }
        }
    }
}

int hasPath(int i, int j, int mat[N][N])
{
    if(mat[i][j]!=0)
        return 1;
    return 0;
}

int shortestPath(int i, int j, int mat[N][N])
{
    if(mat[i][j] != 0)
        return mat[i][j];
    return -1;
}


int findMin(int x,int y)
{
    if(x<y) return x;
    else return y;
}


