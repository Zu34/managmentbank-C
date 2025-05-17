#ifndef DATA_H
#define DATA_H

#include "account.h"

int find_record(int account_no, struct record *rec);
int update_record(int account_no, struct record new_rec);

#endif
