#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "account.h"
#include "data.h"

void deposit() {
    int accNumber;
    float amount;
    int found = 0;

    printf("Enter account number: ");
    scanf("%d", &accNumber);

    printf("Enter deposit amount: ");
    scanf("%f", &amount);

    FILE *fp = fopen("accounts.dat", "rb+");
    if (!fp) {
        printf("Error opening file.\n");
        return;
    }

    Account acc;
    while (fread(&acc, sizeof(Account), 1, fp)) {
        if (acc.accountNumber == accNumber) {
            acc.balance += amount;
            fseek(fp, -sizeof(Account), SEEK_CUR);
            fwrite(&acc, sizeof(Account), 1, fp);
            printf("Deposit successful. New balance: %.2f\n", acc.balance);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Account not found.\n");

    fclose(fp);
}

void withdraw() {
    int accNumber;
    float amount;
    int found = 0;

    printf("Enter account number: ");
    scanf("%d", &accNumber);

    printf("Enter withdraw amount: ");
    scanf("%f", &amount);

    FILE *fp = fopen("accounts.dat", "rb+");
    if (!fp) {
        printf("Error opening file.\n");
        return;
    }

    Account acc;
    while (fread(&acc, sizeof(Account), 1, fp)) {
        if (acc.accountNumber == accNumber) {
            if (acc.balance >= amount) {
                acc.balance -= amount;
                fseek(fp, -sizeof(Account), SEEK_CUR);
                fwrite(&acc, sizeof(Account), 1, fp);
                printf("Withdrawal successful. New balance: %.2f\n", acc.balance);
            } else {
                printf("Insufficient balance.\n");
            }
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Account not found.\n");

    fclose(fp);
}

void view_balance() {
    int accNumber;
    int found = 0;

    printf("Enter account number: ");
    scanf("%d", &accNumber);

    FILE *fp = fopen("accounts.dat", "rb");
    if (!fp) {
        printf("Error opening file.\n");
        return;
    }

    Account acc;
    while (fread(&acc, sizeof(Account), 1, fp)) {
        if (acc.accountNumber == accNumber) {
            printf("Account Holder: %s\n", acc.name);
            printf("Balance: %.2f\n", acc.balance);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Account not found.\n");

    fclose(fp);
}
