#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    // change title
    printf("\033]0;Bulldog Bucks Manager\007");
    printf("* * * * * * * * * * * * *\n"
           "* Bulldog Bucks Manager *\n"
           "* * * * * * * * * * * * *\n");

    // open file
    FILE *fptr;
    fptr = fopen("userdata.json", "r+w");

    printf("Welcome to the Bulldog Bucks Manager!\nType \"help\" for commands\n");
    while(1) {
        printf(">");
        char com[10];
        char acc[10];
        bool is_id;
        float fcom;
        float bal;
        int id;
        char version[] = "0.0.2alpha\n";
        // use 3 tabs to seperate command and desc, delete extra chars
        char help[] = "help            Shows commands\n\n"

                      "balance         Modifies balances (balance [id]/[name] add/minus/set [value]) or (balance [id]/[name] check)\n\n"

                      "account         Modifies accounts (account create [name]) or (account delete [id]/[name])\n\n"

                      "credits         Credits authors\n"
                      "version         Shows version\n\n"
                      
                      "exit            Closes program\n"
                      "quit            Closes program\n"
                      "break           Closes program\n";
        scanf("%s", &com);
        // if "help" is typed prints commands
        if (strcmp(com, "help") == 0) {
            printf("%s", help);
        }
        // display authors
        else if (strcmp(com, "credits") == 0) {
            printf("All programming was done by Ryan Norceide\n");
        }
        // display version
        else if (strcmp(com, "version") == 0) {
            printf("%s", version);
        }
        // balance operations
        else if (strcmp(com, "balance") == 0) {
            // get next phrase
            scanf("%s", &com);
            // distinguish names from ids
            if (atoi(com)) {
                id = atoi(com);
                is_id = true;
            }
            else {
                strcpy(acc, com);
                is_id = false;
            }
            if (strcmp(acc, "set") == 0 || strcmp(acc, "add") == 0 || strcmp(acc, "minus") == 0 || strcmp(acc, "check") == 0) {
                printf("invalid command: [id]/[name] expected\n");
            }
            else{
                // get next phrase
                scanf("%s", &com);
                // set (implement once storage works)
                if (strcmp(com, "set") == 0) {
                    scanf("%s", &com);
                    bal = atof(com);
                    if (is_id) {
                        // find user with given id

                        // set balance to bal

                    }
                    else {
                        // find user with given name

                        // set balance to bal

                    }
                    printf("balance set to %.2f\n", fcom);
                }
                // add (implement once storage works)
                else if (strcmp(com, "add") == 0) {
                    scanf("%s", &com);
                    fcom = atof(com);
                    if (is_id) {
                        // find user with given id and get balance

                        // add to balance
                        bal += fcom;
                        // send to file

                        // print success
                        printf("added %.2f to %d\n", fcom, id);
                    }
                    else {
                        // find user with given name and get balance

                        // add to balance
                        bal += fcom;
                        // send to file

                        // print success
                        printf("added %.2f to %s\n", fcom, acc);
                    }
                }
                // subtract (implement once storage works)
                else if (strcmp(com, "minus") == 0) {
                    scanf("%s", &com);
                    fcom = atof(com);
                    if (is_id) {
                        // find user with given id and get balance

                        // subtract from balance
                        bal -= fcom;
                        // send to file

                        // print success
                        printf("took %.2f from %d\n", fcom, id);
                    }
                    else {
                        // find user with given name and get balance

                        // subtract from balance
                        bal -= fcom;
                        // send to file

                        // print success
                        printf("took %.2f from %s\n", fcom, acc);
                    }
                }
                // check balance (implement once storage works)
                else if (strcmp(com, "check") == 0) {
                    if (is_id) {
                        // find user with given id and get balance to "bal" variable

                        // print success
                        printf("%d's balance is %.2f\n", id, bal);
                    }
                    else {
                        // find user with given name and set balance to "bal" variable

                        // print balance
                        printf("%s's balance is %.2f\n", acc, bal);
                    }
                }
            }
        }
        // account operations
        else if (strcmp(com, "account") == 0) {
            // get next phrase
            scanf("%s", &com);
            // create new user
            if (strcmp(com, "create") == 0) {
                // get name
                scanf("%s", &acc);
                // assign id

                // add to file

                // print success
                printf("account %s created with id %d\n", acc, id);
            }
            // delete user
            else if (strcmp(com, "delete") == 0) {
                // get name/id
                scanf("%s", com);
                // distinguish name from id
                if (atoi(com)) {
                    id = atoi(com);
                    is_id = true;
                }
                else {
                    strcpy(acc, com);
                    is_id = false;
                }
                if (is_id) {
                // find user amd delete from file
                
                // print success
                printf("account %d deleted\n", id);
                }
                else {
                // find user amd delete from file
                
                // print success
                printf("account %s deleted\n", acc);
                }
            }
        }
        // if "quit", "exit", or "break" are typed program closes
        else if (strcmp(com, "quit") == 0 || strcmp(com, "exit") == 0 || strcmp(com, "break") == 0) {
            break;
        }
        // if field is empty give error
        else if (strcmp(com, "") == 0) {
            printf("Error: no command typed\nsee \"help\" for commands\n");
        }
        // invalid command, this should be last
        else {
            printf("invalid command: %s\n", com);
        }
    }
    // close file
    fclose(fptr);
    // end program
    return 0;
}