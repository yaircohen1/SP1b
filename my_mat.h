#ifndef MY_MAT_H
#define MY_MAT_H
#define N 10

void FloydWarshallAlgorithm(int mat[N][N]);
void createMat(int mat[N][N]);
int hasPath(int i, int j, int mat[N][N]);
int shortestPath(int i, int j, int mat[N][N]);
int findMin(int x,int y);
void getItemsFromUser();
int whichItemsInclude(int weights[], int values[], int selected_bool[]);
char* knapSack(int weight[], int values[], int selected_bool[]);
int findMax(int x,int y);


#endif