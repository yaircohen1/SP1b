#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 5
#define BAG_WEIGHT 20

// arrays declaration
char items[N];
int values[N];
int weights[N];

// b) program that gets a list of 5 items from the user,
// and gives a weight and values for each one
void getItemsFromUser() {
  for (int i = 0; i < N; i++) {
    printf("Please enter %d's item value: ", i);
    scanf("%d", &values[i]);

    printf("Please enter %d's item weight: ", i);
    scanf("%d", &weights[i]);
  }
}

// b) a function that decides which items include in the bag, such that the
// weight will be <= 20 kg. return the maximal value of items in the bag

int whichItemsInclude(int weights[], int values[], int selected_bool[]) {
  // initialize zero
  memset(selected_bool, 0, N * sizeof(int));

  // create a DP table
  int dp[N + 1][BAG_WEIGHT + 1]; // +1 for 0-th row and column

  // initializing the DP table
  for (int i = 0; i <= N; i++) {
    for (int w = 0; w <= BAG_WEIGHT; w++) {
      if (i == 0 || w == 0)
        dp[i][w] = 0;
      else if (weights[i - 1] <= w)
        dp[i][w] = findMax(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
      else
        dp[i][w] = dp[i - 1][w];
    }
  }

  int j = N;
  int w = BAG_WEIGHT;

  // calculate which items are included in the bag
  while (j > 0 && w > 0) {
    if (dp[j][w] != dp[j - 1][w]) {
      selected_bool[j - 1] = 1;
      w = w - weights[j - 1];
    }
    j--;
  }

  // calculate the maximum profit
  int maximum_profit = dp[N][BAG_WEIGHT];
  return maximum_profit;
}

// Assumption: in class we learn that a call of function on array is saving
// the changes that have been done so, we will pass the array selected_bool
char* knapSack(int weight[], int values[], int selected_bool[]) {
  int maximim_profit = whichItemsInclude(weight, values, selected_bool);

  char temp_result[N] = {'A', 'B', 'C', 'D', 'E'};
  int counter = 0;

  // create a result array, in the size of the number of items that have been
  // added to the bag
  char* result = (char*)malloc(N * sizeof(char));

  for (int i = 0; i < N; i++) {
    if (selected_bool[i] != 1) { // the item is not in the bag
      temp_result[i] = '\0';     // Null-terminate the string
      counter++;
    }
  }

  int M = N - counter;
  int result_index = 0;

  for (int i = 0; i < N; i++) {
    if (temp_result[i] != '\0') { // the item is not in the bag
      result[result_index] = temp_result[i];
      result_index++;
    }
  }

  return result;
}

int findMax(int x,int y)
{
    if(x>y) return x;
    else return y;
}
