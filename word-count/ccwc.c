#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count_char(int ch, int count) {
    if (ch) {
        count++;
    }
    return count;
}

int line_count(int ch, int count) {
    if (ch == '\n') {
        count++;
    }
    return count;
}

int word_count(int ch, int count, int *in_word) {
    if (isspace(ch)) {
        *in_word = 0;
    } else {
        if (*in_word == 0) {
            *in_word = 1;
            count++;
        }
    }
    return count;
}

int m_count(int ch, int count) {
    if ((ch & 0xC0) != 0x80) {
        count++;
    }
    return count;
}


int main(int argc, char *argv[]) {
    char *command = argv[1];
    char *filename = argv[2];

    if (filename == NULL) {
        filename = argv[1]
    }

    FILE *fptr = fopen(filename, "r");

    if (fptr == NULL) {
        printf("File not opened successfully!");
        return 1;
    } else {
        char ch;
        int count = 0;
        int in_word = 0;

        while ((ch = fgetc(fptr)) != EOF) {
            if (strcmp(command, "-c") == 0) {
                count_char(ch, count);
            }

            if (strcmp(command, "-l") == 0) {
                line_count(ch, count);
            } 

            if (strcmp(command, "-w") == 0) {
                count = word_count(ch, count, &in_word);
            }
            
            if (strcmp(command, "-m") == 0) {
                count = m_count(ch, count);
            } 

            if (command == NULL) {
                
            }
        }
        printf("%d%s%s\n", count, " ", filename);
    }
    fclose(fptr);
    return 0;
}
