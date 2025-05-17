#include <stdio.h>
#include <string.h>

int login() {
    char user[20], pass[20];
    printf("Username: ");
    scanf("%s", user);
    printf("Password: ");
    scanf("%s", pass);

    if (strcmp(user, "admin") == 0 && strcmp(pass, "admin123") == 0) {
        return 1;
    }
    return 0;
}
