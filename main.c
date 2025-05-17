#include <stdio.h>
#include "account.h"
#include "auth.h"
#include "transactions.h"
#include "utils.h"

int main() {
    int choice;
    if (!login()) {
        printf("Login failed.\n");
        return 1;
    }

    while (1) {
        printf("\n---- BANK MANAGEMENT ----\n");
        printf("1. Add Account\n2. View Accounts\n3. Delete Account\n");
        printf("4. Edit Account\n5. Search Account\n");
        printf("6. Deposit\n7. Withdraw\n8. View Balance\n");
        printf("0. Exit\nChoose option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: add_account(); break;
            case 2: view_accounts(); break;
            case 3: delete_account(); break;
            case 4: edit_account(); break;
            case 5: search_account(); break;
            case 6: deposit(); break;
            case 7: withdraw(); break;
            case 8: view_balance(); break;
            case 0: return 0;
            default: printf("Invalid option.\n");
        }
    }
}
