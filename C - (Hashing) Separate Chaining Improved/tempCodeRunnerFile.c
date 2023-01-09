
            if(finder -> link == NULL && strcmp(finder -> name, removeName) == 0) {
                indexFound = a;
                doExist = 1;
                goto jumpToThisPart;
            }
