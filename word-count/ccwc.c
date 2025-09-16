#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    char *command = argv[1];
    char *filename = argv[2];

    FILE *fptr = fopen(filename, "r");

    if (fptr == NULL) {
        printf("File not opened successfully!");
        return 1;
    } else {
        char ch;
        int count = 0;
        int inWord = 0;

        while ((ch = fgetc(fptr)) != EOF) {
            if (strcmp(command, "-c") == 0) {
                if (ch) {
                    count++;
                }
            }

            if (strcmp(command, "-l") == 0) {
                if (ch == '\n') {
                    count++;
                }
            } 

            if (strcmp(command, "-w") == 0) {
                if (isspace(ch)) {
                    inWord = 0;
                } else {
                    if (inWord == 0) {
                        inWord = 1;
                        count++;
                    }
                }
            }
        }
        printf("%d%s%s\n", count, " ", filename);
    }
    fclose(fptr);
    return 0;
}
