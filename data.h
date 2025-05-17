#ifndef DATA_H
#define DATA_H

#include "account.h"

int find_record(int account_no, Account *rec);
int update_record(int account_no, Account new_rec);

#endif
