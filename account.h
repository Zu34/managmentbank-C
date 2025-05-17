#ifndef ACCOUNT_H
#define ACCOUNT_H

typedef struct {
    char name[60];
    int accountNumber;
    char user_id[20];
    char address[100];
    char phone[20];
    char email[40];
    char dob[12];
    float balance;
} Account;

void add_account();
void view_accounts();
void delete_account();
void edit_account();
void search_account();

#endif

