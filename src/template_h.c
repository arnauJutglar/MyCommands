#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 1000

int check_exists(char *name);
int create(char *name);
int fill(char *name);
void p_error(void);

int main(int argc, char *argv[]) {
    int i, r=0;
    if (argc == 1) {
        r = fill("header");
    } else if (argc > 0) {
        for (i=1; i < argc; i++) {
            r += fill(argv[i]);
        }
    }

    return r;
}

int check_exists(char *name) {
    char cmd[MAX_BUFFER];
    strcpy(cmd, "test -f ");
    strcat(cmd, name);
    strcat(cmd, ".h");
    if (system(cmd) == 0) {
        return 1;
    }
    return 0;
}

int create(char *name) {
    if (check_exists(name) == 1) {
        return 1;
    }
    char cmd[MAX_BUFFER];
    strcpy(cmd, "touch ");
    strcat(cmd, name);
    strcat(cmd, ".h");

    return (system(cmd));
}

int fill(char *name) {
    FILE *fp;
    char p_name[MAX_BUFFER];
    int i;

    if (create(name) == 1) {
        p_error();
        return 1;
    }

    strcpy(p_name, name);
    strcat(p_name, ".h");

    fp = fopen(p_name, "w");

    fprintf(fp, "#ifndef %s_h\n", name);
    fprintf(fp, "#define %s_h\n", name);

    for (i=0; i < 17; i++) {
        fprintf(fp, "\n");
    }

    fprintf(fp, "#endif /* %s_h */", name);

    fclose(fp);

    return 0;
}

void p_error(void) {
    printf("An error occured during file creation.\n");
    return;
}