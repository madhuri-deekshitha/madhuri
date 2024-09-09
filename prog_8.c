#include <stdio.h>
#include <string.h>

#define MAX 500

int t[MAX];

void shifttable(char p[]) {
    int i, j, m;
    m = strlen(p);
    
    for (i = 0; i < MAX; i++) {
        t[i] = m; // Initialize all table entries to the length of the pattern
    }

    // Fill the shift table based on the pattern
    for (j = 0; j < m - 1; j++) {
        t[p[j]] = m - 1 - j;
    }
}

int horspool(char src[], char p[]) {
    int i, j, k, m, n;
    n = strlen(src); // Length of the text
    m = strlen(p);   // Length of the pattern

    printf("\nLength of text = %d", n);
    printf("\nLength of pattern = %d", m);

    i = m - 1; // Start from the end of the pattern

    while (i < n) {
        k = 0;
        while ((k < m) && (p[m - 1 - k] == src[i - k])) {
            k++;
        }
        if (k == m) {
            return (i - m + 1); // Pattern found
        } else {
            i += t[src[i]]; // Shift using the table
        }
    }

    return -1; // Pattern not found
}

int main() {
    char src[100], p[100];
    int pos;

    // Input for text
    printf("Enter the text in which the pattern is to be searched: ");
    scanf("%s", src);

    // Input for pattern
    printf("Enter the pattern to be searched: ");
    scanf("%s", p);

    // Build the shift table
    shifttable(p);
    
    // Search for the pattern
    pos = horspool(src, p);

    if (pos >= 0) {
        printf("\nThe desired pattern was found starting from position %d\n", pos + 1);
    } else {
        printf("\nThe pattern was not found in the given text.\n");
    }

    return 0;
}