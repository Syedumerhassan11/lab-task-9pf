#include <stdio.h>

void mainarrow(int N) {
    int rows = 2 * N + 1;
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < rows; j++) {
            if (i <= N) {
                if (j < N - i) {
                    printf(". ");
                } else if (j >= N - i && j <= N + i) {
                    printf("o");
                } else {
                    break;
                }
            }
            else {
                if (j < i - N) {
                    printf(". ");
                } else if (j >= i - N && j < rows - (i - N)) {
                    printf("o");
                } else {
                    break;
                }
            }
        }
        printf("\n");
    }
}

int main() {
    int number;
    printf("Number of Rows: ");
    scanf("%d", &number);
    mainarrow(number);
    return 0;
}




