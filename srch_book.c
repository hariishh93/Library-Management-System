#include "library.h"

void srch_book(BOOK *p)
{
    char c;
    char s[50], s2[50];
    char *s1;

    int id;
    int i;
    int found;

    if (p == NULL)
    {
        printf("No books available.\n");
        return;
    }

l3:

    printf("\n");
    printf("A/a : Search By Book ID\n");
    printf("B/b : Search By Book Name\n");
    printf("C/c : Search By Author Name\n");
    printf("D/d : Back\n");
    printf("Enter Choice : ");

    scanf(" %c", &c);

    if (c == 'A' || c == 'a')
    {
        BOOK *temp = p;
        found = 0;

        printf("Enter Book ID : ");
        scanf("%d", &id);

        while (temp)
        {
            if (temp->id == id)
            {
                printf("\n");
                printf("---------------------------------------------\n");
                printf("Book ID   : %d\n", temp->id);
                printf("Book Name : %s\n", temp->bkname);
                printf("Author    : %s\n", temp->auname);
                printf("Quantity  : %d\n", temp->qnty);
                printf("---------------------------------------------\n");

                found = 1;
                break;
            }

            temp = temp->next;
        }

        if (!found)
            printf("Book ID not found.\n");
    }

    else if (c == 'B' || c == 'b')
    {
        BOOK *temp = p;
        found = 0;

        printf("Enter Book Name : ");
        scanf(" %49[^\n]", s);

        s1 = s;

        while (*s1)
        {
            if (*s1 >= 'A' && *s1 <= 'Z')
                *s1 += 32;
            s1++;
        }

        while (temp)
        {
            i = 0;

            while (temp->bkname[i])
            {
                s2[i] = temp->bkname[i];

                if (s2[i] >= 'A' && s2[i] <= 'Z')
                    s2[i] += 32;

                i++;
            }

            s2[i] = '\0';

            if (strcmp(s2, s) == 0)
            {
                printf("---------------------------------------------\n");
                printf("Book ID   : %d\n", temp->id);
                printf("Book Name : %s\n", temp->bkname);
                printf("Author    : %s\n", temp->auname);
                printf("Quantity  : %d\n", temp->qnty);
                printf("---------------------------------------------\n");

                found = 1;
            }

            temp = temp->next;
        }

        if (!found)
            printf("Book not found.\n");
    }

    else if (c == 'C' || c == 'c')
    {
        BOOK *temp = p;
        found = 0;

        printf("Enter Author Name : ");
        scanf(" %29[^\n]", s);

        s1 = s;

        while (*s1)
        {
            if (*s1 >= 'A' && *s1 <= 'Z')
                *s1 += 32;
            s1++;
        }

        while (temp)
        {
            i = 0;

            while (temp->auname[i])
            {
                s2[i] = temp->auname[i];

                if (s2[i] >= 'A' && s2[i] <= 'Z')
                    s2[i] += 32;

                i++;
            }

            s2[i] = '\0';

            if (strcmp(s2, s) == 0)
            {
                printf("---------------------------------------------\n");
                printf("Book ID   : %d\n", temp->id);
                printf("Book Name : %s\n", temp->bkname);
                printf("Author    : %s\n", temp->auname);
                printf("Quantity  : %d\n", temp->qnty);
                printf("---------------------------------------------\n");

                found = 1;
            }

            temp = temp->next;
        }

        if (!found)
            printf("Author not found.\n");
    }

    else if (c == 'D' || c == 'd')
    {
        return;
    }

    else
    {
        printf("Invalid Choice.\n");
        goto l3;
    }
}
