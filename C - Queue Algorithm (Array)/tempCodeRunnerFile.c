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