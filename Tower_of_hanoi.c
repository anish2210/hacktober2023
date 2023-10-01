#include <stdio.h>

void tower_of_hanoi(int n, char src, char dest, char aux) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", src, dest);
        return;
    }
    tower_of_hanoi(n - 1, src, aux, dest);
    printf("Move disk %d from %c to %c\n", n, src, dest);
    tower_of_hanoi(n - 1, aux, dest, src);
}

void main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d",&n);
    tower_of_hanoi(n,'A','C','B');
}