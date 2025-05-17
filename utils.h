#ifndef UTILS_H
#define UTILS_H

// Function prototypes
void clear_input();
void get_string(char *prompt, char *buffer, int size);
int get_int(char *prompt);
float get_float(char *prompt);
int is_numeric(const char *str);

#endif
