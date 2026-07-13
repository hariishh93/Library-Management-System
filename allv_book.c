#include "library.h"

void allv_book(BOOK *hptr)
{
    BOOK *temp = hptr;

    if (temp == NULL)
    {
        printf("\nNo Books Available.\n");
        return;
    }

    printf("\n");
    printf("=======================================================================================\n");
    printf("%-10s %-30s %-25s %-10s\n",
           "Book ID",
           "Book Name",
           "Author",
           "Quantity");
    printf("=======================================================================================\n");

    while (temp)
    {
        printf("%-10d %-30s %-25s %-10d\n",
               temp->id,
               temp->bkname,
               temp->auname,
               temp->qnty);

        temp = temp->next;
    }

    printf("=======================================================================================\n");
}
