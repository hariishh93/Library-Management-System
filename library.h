#ifndef LIBRARY_H
#define LIBRARY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*-------------------- Structures --------------------*/

typedef struct date
{
    int date;
    int mon;
    int year;
} DATE;

typedef struct book
{
    int id;
    char bkname[50];
    char auname[30];
    int qnty;

    struct book *next;

} BOOK;

typedef struct issue
{
    int is_id;
    int bk_id;
    int us_id;

    char usname[20];

    DATE is_date;
    DATE due_date;
    DATE ret_date;

    int fine;
    int status;

    struct issue *next;

} ISSUE;


/*---------------- Global Variables ----------------*/

extern unsigned int r;
extern unsigned int r2;
extern unsigned int count;
extern unsigned int ic1;

extern int *del;


/*---------------- Function Prototypes ----------------*/

void add_book(BOOK **);

void upd_book(BOOK *);

void rem_book(BOOK **);

void srch_book(BOOK *);

void allv_book(BOOK *);

void issue_book(BOOK *, ISSUE **);

void ret_book(ISSUE *, BOOK *);

void list_ised_book(ISSUE *);

void save_book(BOOK **, ISSUE **, unsigned int);

#endif
