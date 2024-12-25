#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
        float fcom;
        char acc[10];
        char version[] = "0.0.2\n";
        // use 3 tabs to seperate command and desc, delete extra chars
        char help[] = "help            Shows commands\n\n"

                      "balance         Modifies balances (balance [id] add/minus/set [value])\n\n"

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
            // copy account to acc
            strcpy(acc, com);
            if (strcmp(acc, "set") == 0 || strcmp(acc, "add") == 0 || strcmp(acc, "minus") == 0 || strcmp(acc, "check") == 0) {
                printf("invalid command: [id] expected\n");
            }
            else{
                // get next phrase
                scanf("%s", &com);
                // choose operation
                // set (implement once storage works)
                if (strcmp(com, "set") == 0) {
                    scanf("%s", &com);
                    fcom = atof(com);
                    printf("balance set to %.2f\n", fcom);
                }
                // add (implement once storage works)
                else if (strcmp(com, "add") == 0) {
                    scanf("%s", &com);
                    fcom = atof(com);
                    printf("added %.2f\n", fcom);
                }
                // subtract (implement once storage works)
                else if (strcmp(com, "minus") == 0) {
                    scanf("%s", &com);
                    fcom = atof(com);
                    printf("took %.2f\n", fcom);
                }
                // // check balance (implement once storage works)
                // else if (strcmp(com, "check") == 0) {
                //     printf("balance is %.2f\n");
                // }
            }
        }

        // if "quit", "exit", or "break" are typed program closes
        else if (strcmp(com, "quit") == 0 || strcmp(com, "exit") == 0 || strcmp(com, "break") == 0) {
            break;
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