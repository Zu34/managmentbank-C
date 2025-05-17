
#include <stdio.h>
#include "account.h" 
#include "data.h"

int find_record(int account_no, Account *rec) {
    FILE *fp = fopen("record.bin", "rb");
    if (!fp) return 0;

    while (fread(rec, sizeof(*rec), 1, fp)) {
        if (rec->accountNumber == account_no) {  // ✅ FIXED
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}

int update_record(int account_no, Account new_rec) {
    FILE *fp = fopen("record.bin", "rb");
    FILE *tmp = fopen("temp.bin", "wb");
    int found = 0;
    Account rec;

    while (fread(&rec, sizeof(rec), 1, fp)) {
        if (rec.accountNumber == account_no) {  // ✅ FIXED
            fwrite(&new_rec, sizeof(new_rec), 1, tmp);
            found = 1;
        } else {
            fwrite(&rec, sizeof(rec), 1, tmp);
        }
    }

    fclose(fp);
    fclose(tmp);
    remove("record.bin");
    rename("temp.bin", "record.bin");

    return found;
}
