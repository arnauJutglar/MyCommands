#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 1000

int check_exists(char *name);
int create(char *name);
void p_error(void);

int main(int argc, char *argv[]) {
    int i, r=0;
    if (argc == 1) {
        r = create("p");
    } else if (argc > 0) {
        for (i=1; i < argc; i++) {
            r += create(argv[i]);
        }
    }

    return r;
}

int check_exists(char *name) {
    char cmd[MAX_BUFFER];
    strcpy(cmd, "test -f ");
    strcat(cmd, name);
    strcat(cmd, ".cpp");
    if (system(cmd) == 0) {
        return 1;
    }
    return 0;
}

int create(char *name) {
    if (check_exists(name) == 1) {
        p_error();
        return 1;
    }
    char cmd[MAX_BUFFER];
    strcpy(cmd, "cp ~/MyCommands/resources/tempCpp.cpp ");
    strcat(cmd, name);
    strcat(cmd, ".cpp");

    return system(cmd);
}

void p_error(void) {
    printf("An error occured during file creation.\n");
    return;
}