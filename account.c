
#include <stdio.h>
#include <string.h>
#include "account.h"

void add_account() {
    Account newAccount;

    printf("Enter account number: ");
    scanf("%d", &newAccount.accountNumber);

    printf("Enter name: ");
    getchar(); 
    fgets(newAccount.name, sizeof(newAccount.name), stdin);
    newAccount.name[strcspn(newAccount.name, "\n")] = 0;  // remove trailing newline

    printf("Enter user ID: ");
    fgets(newAccount.user_id, sizeof(newAccount.user_id), stdin);
    newAccount.user_id[strcspn(newAccount.user_id, "\n")] = 0;

    printf("Enter address: ");
    fgets(newAccount.address, sizeof(newAccount.address), stdin);
    newAccount.address[strcspn(newAccount.address, "\n")] = 0;

    printf("Enter phone: ");
    fgets(newAccount.phone, sizeof(newAccount.phone), stdin);
    newAccount.phone[strcspn(newAccount.phone, "\n")] = 0;

    printf("Enter email: ");
    fgets(newAccount.email, sizeof(newAccount.email), stdin);
    newAccount.email[strcspn(newAccount.email, "\n")] = 0;

    printf("Enter date of birth (YYYY-MM-DD): ");
    fgets(newAccount.dob, sizeof(newAccount.dob), stdin);
    newAccount.dob[strcspn(newAccount.dob, "\n")] = 0;

    printf("Enter initial balance: ");
    scanf("%f", &newAccount.balance);

    FILE *f = fopen("accounts.dat", "ab");
    if (f == NULL) {
        perror("Error opening file");
        return;
    }

    fwrite(&newAccount, sizeof(Account), 1, f);
    fclose(f);

    printf("Account added successfully!\n");
}

void view_accounts() {
    FILE *f = fopen("accounts.dat", "rb");
    if (f == NULL) {
        perror("Error opening file");
        return;
    }

    Account acc;
    printf("List of accounts:\n");
    printf("---------------------------------------------------------\n");

    while (fread(&acc, sizeof(Account), 1, f)) {
        printf("Account Number: %d\n", acc.accountNumber);
        printf("Name: %s\n", acc.name);
        printf("User ID: %s\n", acc.user_id);
        printf("Address: %s\n", acc.address);
        printf("Phone: %s\n", acc.phone);
        printf("Email: %s\n", acc.email);
        printf("Date of Birth: %s\n", acc.dob);
        printf("Balance: %.2f\n", acc.balance);
        printf("---------------------------------------------------------\n");
    }

    fclose(f);
}

void delete_account() {
    int targetAccount;
    printf("Enter account number to delete: ");
    scanf("%d", &targetAccount);

    FILE *f = fopen("accounts.dat", "rb");
    if (!f) {
        perror("Error opening file");
        return;
    }

    FILE *temp = fopen("temp.dat", "wb");
    if (!temp) {
        fclose(f);
        perror("Error creating temp file");
        return;
    }

    Account acc;
    int found = 0;

    while (fread(&acc, sizeof(Account), 1, f)) {
        if (acc.accountNumber == targetAccount) {
            found = 1;
            continue;  // skip writing this account (deleting)
        }
        fwrite(&acc, sizeof(Account), 1, temp);
    }

    fclose(f);
    fclose(temp);

    if (found) {
        remove("accounts.dat");
        rename("temp.dat", "accounts.dat");
        printf("Account %d deleted successfully.\n", targetAccount);
    } else {
        remove("temp.dat");
        printf("Account %d not found.\n", targetAccount);
    }
}

void edit_account() {
    int targetAccount;
    printf("Enter account number to edit: ");
    scanf("%d", &targetAccount);

    FILE *f = fopen("accounts.dat", "rb");
    if (!f) {
        perror("Error opening file");
        return;
    }

    FILE *temp = fopen("temp.dat", "wb");
    if (!temp) {
        fclose(f);
        perror("Error creating temp file");
        return;
    }

    Account acc;
    int found = 0;

    while (fread(&acc, sizeof(Account), 1, f)) {
        if (acc.accountNumber == targetAccount) {
            found = 1;
            printf("Editing account %d:\n", targetAccount);

            printf("Enter new name (current: %s): ", acc.name);
            getchar(); // consume leftover newline
            fgets(acc.name, sizeof(acc.name), stdin);
            acc.name[strcspn(acc.name, "\n")] = 0;

            printf("Enter new user ID (current: %s): ", acc.user_id);
            fgets(acc.user_id, sizeof(acc.user_id), stdin);
            acc.user_id[strcspn(acc.user_id, "\n")] = 0;

            printf("Enter new address (current: %s): ", acc.address);
            fgets(acc.address, sizeof(acc.address), stdin);
            acc.address[strcspn(acc.address, "\n")] = 0;

            printf("Enter new phone (current: %s): ", acc.phone);
            fgets(acc.phone, sizeof(acc.phone), stdin);
            acc.phone[strcspn(acc.phone, "\n")] = 0;

            printf("Enter new email (current: %s): ", acc.email);
            fgets(acc.email, sizeof(acc.email), stdin);
            acc.email[strcspn(acc.email, "\n")] = 0;

            printf("Enter new DOB (current: %s): ", acc.dob);
            fgets(acc.dob, sizeof(acc.dob), stdin);
            acc.dob[strcspn(acc.dob, "\n")] = 0;

            printf("Enter new balance (current: %.2f): ", acc.balance);
            scanf("%f", &acc.balance);
        }
        fwrite(&acc, sizeof(Account), 1, temp);
    }

    fclose(f);
    fclose(temp);

    if (found) {
        remove("accounts.dat");
        rename("temp.dat", "accounts.dat");
        printf("Account updated successfully.\n");
    } else {
        remove("temp.dat");
        printf("Account %d not found.\n", targetAccount);
    }
}


void search_account() {
    int targetAccount;
    printf("Enter account number to search: ");
    scanf("%d", &targetAccount);

    FILE *f = fopen("accounts.dat", "rb");
    if (!f) {
        perror("Error opening file");
        return;
    }

    Account acc;
    int found = 0;

    while (fread(&acc, sizeof(Account), 1, f)) {
        if (acc.accountNumber == targetAccount) {
            found = 1;
            printf("Account found:\n");
            printf("Account Number: %d\n", acc.accountNumber);
            printf("Name: %s\n", acc.name);
            printf("User ID: %s\n", acc.user_id);
            printf("Address: %s\n", acc.address);
            printf("Phone: %s\n", acc.phone);
            printf("Email: %s\n", acc.email);
            printf("DOB: %s\n", acc.dob);
            printf("Balance: %.2f\n", acc.balance);
            break;
        }
    }

    if (!found) {
        printf("Account %d not found.\n", targetAccount);
    }

    fclose(f);
}
