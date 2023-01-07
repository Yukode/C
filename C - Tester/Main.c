#include <stdio.h>
#include <string.h>

void main() {
    char haha[9999];

    scanf("%s", haha);

    int length = strlen(haha);
    int a = 0;
    int total = 0;

    printf("%d\n", length);
    for(a = 0; a < length; a++) {
        total += haha[a];
    }
    printf("%d\n", total);
}