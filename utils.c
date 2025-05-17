#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "utils.h"

void clear_input() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void get_string(char *prompt, char *buffer, int size) {
    printf("%s", prompt);
    if (fgets(buffer, size, stdin)) {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0'; // remove newline
        } else {
            clear_input(); // flush remaining input
        }
    }
}

int get_int(char *prompt) {
    char buffer[20];
    get_string(prompt, buffer, sizeof(buffer));
    return atoi(buffer);
}

float get_float(char *prompt) {
    char buffer[20];
    get_string(prompt, buffer, sizeof(buffer));
    return atof(buffer);
}

int is_numeric(const char *str) {
    while (*str) {
        if (!isdigit(*str)) return 0;
        str++;
    }
    return 1;
}
