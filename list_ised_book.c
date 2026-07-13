#include "library.h"

void list_ised_book(ISSUE *ptr)
{
    ISSUE *temp = ptr;

    if (temp == NULL)
    {
        printf("\nNo Issued Books Available.\n");
        return;
    }

    printf("\n");
    printf("===============================================================================================================================\n");
    printf("%-8s %-8s %-8s %-20s %-12s %-12s %-12s %-8s %-10s\n",
           "IssueID",
           "BookID",
           "UserID",
           "User Name",
           "Issue Date",
           "Due Date",
           "Return",
           "Fine",
           "Status");
    printf("===============================================================================================================================\n");

    while (temp)
    {
        if (temp->status == 0)
        {
            printf("%-8d %-8d %-8d %-20s %02d/%02d/%04d %02d/%02d/%04d %-12s %-8d %-10s\n",
                   temp->is_id,
                   temp->bk_id,
                   temp->us_id,
                   temp->usname,
                   temp->is_date.date,
                   temp->is_date.mon,
                   temp->is_date.year,
                   temp->due_date.date,
                   temp->due_date.mon,
                   temp->due_date.year,
                   "-",
                   temp->fine,
                   "Pending");
        }
        else
        {
            printf("%-8d %-8d %-8d %-20s %02d/%02d/%04d %02d/%02d/%04d %02d/%02d/%04d %-8d %-10s\n",
                   temp->is_id,
                   temp->bk_id,
                   temp->us_id,
                   temp->usname,
                   temp->is_date.date,
                   temp->is_date.mon,
                   temp->is_date.year,
                   temp->due_date.date,
                   temp->due_date.mon,
                   temp->due_date.year,
                   temp->ret_date.date,
                   temp->ret_date.mon,
                   temp->ret_date.year,
                   temp->fine,
                   "Returned");
        }

        temp = temp->next;
    }

    printf("===============================================================================================================================\n");
}
