// FRONT IS ONLY THE POINTER

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

struct node *front = NULL;

void insertChecker(int value) {

    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr -> data = value;

    if(front == NULL) {
        front = ptr;
    } else {

        struct node *temp = front;
        while(temp -> link != NULL) {
            temp = temp -> link;
        }

        temp -> link = ptr;

    }

    ptr -> link = NULL;

}

void deleteChecker() {

    if(front == NULL) {
        printf("                 QUEUE IS EMPTY                \n");
        printf("-----------------------------------------------\n");
    } else {

        struct node *toDelete = front;
        front = front -> link;
        free(toDelete);

        printf("[] DELETED SUCCESSFULLY!\n");
        
    }

}

void display() {

    if(front == NULL) {
        printf("                 QUEUE IS EMPTY                \n");
        printf("-----------------------------------------------\n");
    } else {

        struct node *show = front;
        while(show != NULL) {

            printf("%d ", show -> data);

            show = show -> link;
        }
        printf("\n");
            
    }

}

void main() {

    int choice = 0;

    printf("-----------------------------------------------\n");
    printf("               LINKEDLIST - QUEUE              \n");
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

// FRONT AND END IS THE POINTER

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

struct node *front = NULL;
struct node *end = NULL;

void insertChecker(int value) {

    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr -> data = value;

    if(front == NULL) {
        front = end = ptr;
        ptr -> link = NULL;
    } else {

        ptr -> link = end;
        end = ptr;

    }

}

void deleteChecker() {

    if(front == NULL) {
        printf("                 QUEUE IS EMPTY                \n");
        printf("-----------------------------------------------\n");
    } else {

        struct node *toDelete;
        struct node *connector = end;

        if(end -> link == NULL) {
            toDelete = front;
            front = end = NULL;
        } else {

            toDelete = front;
            while(connector -> link -> link != NULL) {  // 2000
                connector = connector -> link;
            }
            connector -> link = NULL;

        }

        free(toDelete);

        printf("[] DELETED SUCCESSFULLY!\n");
        
    }

}

void display() {

    if(front == NULL) {
        printf("                 QUEUE IS EMPTY                \n");
        printf("-----------------------------------------------\n");
    } else {

        struct node *show = end;
        while(show != NULL) {

            printf("%d ", show -> data);
            show = show -> link;
             
        }
        printf("\n");
            
    }

}

void main() {

    int choice = 0;

    printf("-----------------------------------------------\n");
    printf("               LINKEDLIST - QUEUE              \n");
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