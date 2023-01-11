#include <stdio.h>
#include <stdlib.h>
#define arrayMax 5

int array[arrayMax];
int front = -1;
int end = -1;

void insertChecker(int value) {

    if(front == -1 && end == -1) {
        front = end = 0;
    }

    if(front == arrayMax) {
        printf("-----------------------------------------------\n");
        printf("                 QUEUE IS FULL                 \n");
        printf("-----------------------------------------------\n");
    } else {

        array[front] = value;
        front += 1;

    }

}

void deleteChecker() {

    if(front == -1) {
        printf("                 QUEUE IS EMPTY                \n");
        printf("-----------------------------------------------\n");
    } else {

        int a = 0;
        for(a = end; a < front; a++) {
            array[a] = array[a + 1];
        }

        front -= 1;

        if(front == 0) {
            end = front = -1;
        }

        printf("[] Deleted Sucessfully!\n");
        printf("-----------------------------------------------\n");

    }

}

void display() {

    if(front == -1) {
        printf("                 QUEUE IS EMPTY                \n");
        printf("-----------------------------------------------\n");
    } else {
        int a = front;
        for(a = end; a < front; a++) {
            printf("%d ", array[a]);
        }
        printf("\n");
    }

}

void main() {

    int choice = 0;

    printf("-----------------------------------------------\n");
    printf("                 ARRAY - QUEUE                 \n");
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