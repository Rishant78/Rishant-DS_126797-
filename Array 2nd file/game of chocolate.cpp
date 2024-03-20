#include <stdio.h>

// Function to calculate the minimum cost to complete the game
int minCost(int chocolates[], int n) {
    int cost = 0;
    
    // Iterate until only one chocolate left
    while (n > 1) {
        // Find the index of the cheaper chocolate among adjacent pairs
        int minIndex = 0;
        for (int i = 1; i < n; i++) {
            if (chocolates[i] < chocolates[minIndex]) {
                minIndex = i;
            }
        }
        
        // Pay for the cheaper chocolate and remove the expensive one
        cost += chocolates[minIndex];
        for (int i = minIndex; i < n - 1; i++) {
            chocolates[i] = chocolates[i + 1];
        }
        
        // Update the number of chocolates
        n--;
    }
    
    return cost;
}

int main() {
    int T;
    printf("Enter the number of games: ");
    scanf("%d", &T); // Input number of games
    
    while (T--) {
        int N;
        printf("Enter the number of chocolates for this game: ");
        scanf("%d", &N); // Input number of chocolates
        
        int chocolates[N];
        printf("Enter the cost of each chocolate: ");
        for (int i = 0; i < N; i++) {
            scanf("%d", &chocolates[i]); // Input cost of each chocolate
        }
        
        // Calculate and print the minimum cost for each game
        printf("Minimum cost for this game: %d\n", minCost(chocolates, N));
    }
    
    return 0;
}

