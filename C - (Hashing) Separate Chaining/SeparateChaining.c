#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define nameMax 9999
#define arrayMax 5

void main();

struct node {

    int key;
    char name[nameMax];
    struct node *link;

};

struct node *array[arrayMax];

void goInsert(char inputName[nameMax], int inputKey) {

    int nameLength = strlen(inputName);
    int nameASCII = 0;
    int a = 0;

    for(a = 0; a < nameLength; a++) {

        nameASCII += inputName[a];

    }

    int keyIndex = nameASCII % arrayMax;

    // Check if already exists.
    struct node *checker = array[keyIndex];
    int alreadyExists = 0;  // 0 = false, 1 = true

    while(checker != NULL) {

        if(strcmp(inputName, checker -> name) == 0) {
            alreadyExists = 1;
            goto jumpToThisArea;
        }

        checker = checker -> link;
    }

    jumpToThisArea:
    if(alreadyExists == 1) {

        strcpy(checker -> name, inputName);
        checker -> key = inputKey;        

    } else {

        struct node *ptr = (struct node *)malloc(sizeof(struct node));
    
        ptr -> key = inputKey;
        strcpy(ptr -> name, inputName);

        if(array[keyIndex] == NULL) {
            array[keyIndex] = ptr;
        } else {

            struct node *temp = array[keyIndex];
            while(temp -> link != NULL) {
                temp = temp -> link;
            }
            temp -> link = ptr;
            ptr -> link = NULL;

        }

    }
    
    printf("[] ADD SUCCESSFUL!\n");

}

void goDisplay() {

    int a = 0;
    for(a = 0; a < arrayMax; a++) {

        struct node *displayer = array[a];
        printf("[ARRAY %d] = ", a);
        while(displayer != NULL) {

            printf("[%d] %s", displayer -> key, displayer -> name);
            if(displayer -> link != NULL) {
                printf(", ");
            }

            displayer = displayer -> link;

        }
        printf("\n");

    }

}

void goRemove(char removeName[nameMax]) {

    struct node *before;
    struct node *connector;
    struct node *finder;
    int a = 0;

    int indexFound;
    int removeExists = 0;   // 0 = false, 1 = true

    for(a = 0; a < arrayMax; a++) {
        
        connector = array[a];
        finder = array[a];

        while(finder != NULL) {         // 1000, 2000

            before = finder;            // 1000, 2000
            finder = finder -> link;    // 2000, 3000

            if(strcmp(before -> name, removeName) == 0) {
                indexFound = a;
                removeExists = 1;
                goto jumpToThisPart;
            }

            connector = before;         // 1000

        }        

    }

    jumpToThisPart: 
    if(removeExists == 1) {

        printf("RUS! - 1\n");

        if(array[indexFound] -> link == NULL && strcmp(array[indexFound] -> name, removeName) == 0) {   // First node (to be removed/deleted).
            array[indexFound] = NULL;
        } else if(array[indexFound] -> link != NULL && strcmp(array[indexFound] -> name, removeName) == 0) {
            array[indexFound] = array[indexFound] -> link;
        } else if(before -> link != NULL) {
            connector -> link = before -> link;
        } else if(before -> link == NULL) {
            connector -> link = NULL;
        }
        printf("RUS! - 5\n");
        free(before);

        printf("[] WORD SUCCESSFULLY REMOVED!\n");

    } else {
        printf("[] WORD TO REMOVE NOT FOUND!\n");
    }

}

void main() {

    int choice = 0;

    do {

        printf("---------------------------------------------------\n");
        printf("                SEPARATE CHAINING                  \n");
        printf("---------------------------------------------------\n");
        printf("[1] Add\n");
        printf("[2] Remove\n");
        printf("[3] Search\n");
        printf("[4] Display\n");
        printf("[5] Exit\n");
        
        printf("\nEnter Choice: ");
        scanf("%d", &choice);

        while ((getchar()) != '\n');

        switch(choice) {
            case (1):

                printf("---------------------------------------------------\n");
                printf("                        ADD                        \n");
                printf("---------------------------------------------------\n");

                char inputName[nameMax];
                int inputKey;
                
                printf("Enter Name: ");
                fgets(inputName, nameMax, stdin);
                inputName[strcspn(inputName, "\n")] = '\0';

                printf("Enter Key: ");
                scanf("%d", &inputKey);
                while ((getchar()) != '\n');

                goInsert(inputName, inputKey);

                break;
            case (2):

                printf("---------------------------------------------------\n");
                printf("                       REMOVE                      \n");
                printf("---------------------------------------------------\n");

                char removeName[nameMax];
                
                printf("Enter Name: ");
                fgets(removeName, nameMax, stdin);
                removeName[strcspn(removeName, "\n")] = '\0';

                goRemove(removeName);

                break;
            case (3):
                break;
            case (4):

                printf("---------------------------------------------------\n");
                printf("                      DISPLAY                      \n");
                printf("---------------------------------------------------\n");

                goDisplay();

                break;
            case (5):
                break;
        }

    } while(choice != 5);
    

}

/*
    inputName[strcspn(inputName, "\n")] = '\0';
    while ((getchar()) != '\n');
*/