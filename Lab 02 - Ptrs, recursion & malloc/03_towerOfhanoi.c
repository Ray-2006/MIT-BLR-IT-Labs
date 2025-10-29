// tower of hanoi using recursion
#include <stdio.h>
#include <stdlib.h>

void towerOfHanoi(int n, char source, char target, char auxiliary) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", source, target);
        return;
    }
    towerOfHanoi(n - 1, source, auxiliary, target);
    printf("Move disk %d from rod %c to rod %c\n", n, source, target);
    towerOfHanoi(n - 1, auxiliary, target, source);
}

int main() {
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);
    towerOfHanoi(n, 'A', 'C', 'B'); 
    return 0;
}