#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define FALSE 0
#define TRUE 1

int x[20];  // You can adjust this size or make it dynamic based on 'n'

// Function to check if a queen can be placed at position (k, i)
int place(int k, int i) {
    int j;
    for (j = 1; j < k; j++) {
        // Check if queens are in the same column or diagonal
        if ((x[j] == i) || (abs(x[j] - i) == abs(j - k)))
            return FALSE;
    }
    return TRUE;
}

// Function to solve N-Queens using backtracking
void nqueens(int k, int n) {
    int i, a;
    for (i = 1; i <= n; i++) {
        if (place(k, i)) {
            x[k] = i;  // Place queen at (k, i)
            if (k == n) {
                // Solution found, print it
                for (a = 1; a <= n; a++) {
                    printf("%d\t", x[a]);
                }
                printf("\n");
            } else {
                nqueens(k + 1, n);  // Try to place the next queen
            }
        }
    }
}

int main() {
    int n;

    // Input for the number of queens
    printf("Enter the number of queens: ");
    scanf("%d", &n);

    // Input validation
    if (n <= 0) {
        printf("Number of queens must be greater than 0.\n");
        return 1;  // Exit the program with an error
    }

    printf("\nThe solutions to the N-Queens problem are:\n");

    // Solve the N-Queens problem starting from the first queen
    nqueens(1, n);

    return 0;  // Return success
}