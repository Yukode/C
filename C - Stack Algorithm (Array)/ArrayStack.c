#include <stdio.h>
#define arrayMax 5

void main();
void insertChecker(int value);
void deleteChecker();
void display();

int array[arrayMax];
int top = -1;

void insertChecker(int value) {

    if(top == (arrayMax - 1)) {
        printf("-----------------------------------------------\n");
        printf("                 STACK IS FULL                 \n");
        printf("-----------------------------------------------\n");
    } else {

        top += 1;
        printf("%d\n", top);
        array[top] = value;

    }

}

void deleteChecker() {

    if(top == -1) {
        printf("                 STACK IS EMPTY                \n");
        printf("-----------------------------------------------\n");
    } else {

        int temp;
        int a = 0;
        for(a = 0; a < (top + 1); a++) {
            temp = array[a + 1];
            array[a] = temp;
        }

        top -= 1;
        printf("[] DELETED SUCCESSFULLY!\n");

    }

}

void display() {

    if(top == -1) {
        printf("                 STACK IS EMPTY                \n");
        printf("-----------------------------------------------\n");
    } else {

        int a = 0;
        for(a = 0; a < top + 1; a++) {
            printf("\t\t       %d\n", array[a]);
        }

    }

}

void main() {

    int choice = 0;

    printf("-----------------------------------------------\n");
    printf("                 ARRAY - STACK                 \n");
    printf("-----------------------------------------------\n");

    do {

        printf("[1] Insert\n");
        printf("[2] Delete\n");
        printf("[3] Display\n");
        printf("[4] Exit\n");

        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        while ((getchar()) != '\n');

        switch(choice) {
            case (1):

                printf("-----------------------------------------------\n");
                printf("                     INSERT                    \n");
                printf("-----------------------------------------------\n");

                int value;

                printf("Enter Value: ");
                scanf("%d", &value);

                while ((getchar()) != '\n');
                insertChecker(value);

                break;
            case (2):

                printf("-----------------------------------------------\n");
                printf("                     DELETE                    \n");
                printf("-----------------------------------------------\n");
                deleteChecker();

                break;
            case (3):
                printf("-----------------------------------------------\n");
                printf("                     DISPLAY                   \n");
                printf("-----------------------------------------------\n");
                display();
                break;
            case (4):
                break;
        }

    } while(choice != 4);

}