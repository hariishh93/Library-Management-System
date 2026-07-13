#include "library.h"

void issue_book(BOOK *p1, ISSUE **p2)
{
    ISSUE *temp = (ISSUE *)malloc(sizeof(ISSUE));

    if (temp == NULL)
    {
        printf("Memory Allocation Failed.\n");
        return;
    }

    BOOK *b1 = p1;

    char ch1[11];
    char ch2[11];
    char ch3;

    static unsigned int i1 = 1;

    int bid, uid;

lab1:

    printf("Enter Book ID and User ID : ");
    scanf("%d %d", &bid, &uid);

    while (b1)
    {
        if (b1->id == bid)
            break;

        b1 = b1->next;
    }

    if (b1 == NULL)
    {
        printf("Invalid Book ID.\n");
        goto lab1;
    }

    printf("\n");
    printf("Book ID   : %d\n", b1->id);
    printf("Book Name : %s\n", b1->bkname);
    printf("Author    : %s\n", b1->auname);
    printf("Quantity  : %d\n\n", b1->qnty);

    if (b1->qnty <= 0)
    {
        printf("Book Not Available.\n");
        free(temp);
        return;
    }

    printf("Book Available.\n");

    printf("\n");
    printf("Enter Book ID UserID UserName IssueDate DueDate\n");
    printf("Date Format : DD/MM/YYYY\n");

    scanf(" %d %d %19s %10s %10s",
          &temp->bk_id,
          &temp->us_id,
          temp->usname,
          ch1,
          ch2);

    temp->ret_date.date = 0;
    temp->ret_date.mon = 0;
    temp->ret_date.year = 0;

    temp->is_id = i1++;

    temp->fine = 0;
    temp->status = 0;

    sscanf(ch1,
           "%d/%d/%d",
           &temp->is_date.date,
           &temp->is_date.mon,
           &temp->is_date.year);

    sscanf(ch2,
           "%d/%d/%d",
           &temp->due_date.date,
           &temp->due_date.mon,
           &temp->due_date.year);

lab2:

    printf("Save Record (Y/N): ");
    scanf(" %c", &ch3);

    if (ch3 == 'Y' || ch3 == 'y')
    {
        temp->next = *p2;
        *p2 = temp;

        ic1 = i1;

        b1->qnty--;

        printf("Book Issued Successfully.\n");
    }

    else if (ch3 == 'N' || ch3 == 'n')
    {
        free(temp);
        printf("Record Not Saved.\n");
    }

    else
    {
        printf("Invalid Input.\n");
        goto lab2;
    }
}
