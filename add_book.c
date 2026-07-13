#include "library.h"

void add_book(BOOK **p)
{
    BOOK *temp = (BOOK *)malloc(sizeof(BOOK));

    if (temp == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    static unsigned int r1 = 1;

    printf("Enter the Book Name, Author Name and Quantity:\n");
    scanf(" %49[^\n] %29[^\n] %d", temp->bkname, temp->auname, &temp->qnty);

    if ((r1 == 1) && (r2 != 0))
        r1 = r2 + 1;

    if (count == 0)
    {
        temp->id = r1++;
        r2 = temp->id;
    }
    else
    {
        temp->id = *del;
        del++;
        count--;
    }

    if (*p == NULL)
    {
        temp->next = NULL;
        *p = temp;
    }
    else
    {
        temp->next = *p;
        *p = temp;
    }

    printf("\nBook Added Successfully.\n");
    printf("Book ID : %d\n", temp->id);
}
