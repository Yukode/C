#include <stdio.h>
#include <stdlib.h>

void main();
void insertChecker(int value);
void deleteChecker();
void display();

struct node {

    int data;
    struct node *link;

};

struct node *top = NULL;

void insertChecker(int value) {

    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr -> data = value;

    if(top == NULL) {
        top = ptr;
    } else {

        struct node *temp = top;
        while(temp -> link != NULL) {
            temp = temp -> link;
        }
        
        temp -> link = ptr;

    }
    ptr -> link = NULL;

}

void deleteChecker() {

    if(top == NULL) {
        printf("                 STACK IS EMPTY                \n");
        printf("-----------------------------------------------\n");
    } else {

        struct node *toDelete = top;
        top = top -> link;

        free(toDelete);
        printf("[] DELETED SUCCESSFULLY!\n");

    }

}

void display() {

    if(top == NULL) {
        printf("                 STACK IS EMPTY                \n");
        printf("-----------------------------------------------\n");
    } else {

        struct node *ptr = top;
        while(ptr != NULL) {
            printf("\t\t       %d\n", ptr -> data);
            ptr = ptr -> link;
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