#include "library.h"

void upd_book(BOOK *p)
{
    char c, v;
    char s[50], s2[50], s3[30], s4[50];
    char *s1;
    int a;
    int r3 = 0;
    int i = 0;
    int k = 0;
    int qty;

    if (p == NULL)
    {
        printf("No records available.\n");
        return;
    }

    BOOK *temp = p;
    BOOK *t = p;

l3:
    printf("\n");
    printf("A/a : Search By Book ID\n");
    printf("B/b : Search By Book Name\n");
    printf("C/c : Back\n");
    printf("Enter Choice : ");
    scanf(" %c", &c);

    if (c == 'A' || c == 'a')
    {
l1:
        temp = p;
        k = 0;

        printf("Enter Book ID : ");
        scanf("%d", &a);

l2:
        printf("\n");
        printf("A/a : Update Author Name\n");
        printf("B/b : Update Book Name\n");
        printf("Q/q : Update Quantity\n");
        printf("Enter Choice : ");
        scanf(" %c", &v);

        if (v == 'A' || v == 'a')
        {
            printf("Enter New Author Name : ");
            scanf(" %29[^\n]", s3);

            while (temp)
            {
                if (temp->id == a)
                {
                    strcpy(temp->auname, s3);
                    printf("Author updated successfully.\n");
                    k = 1;
                    break;
                }

                temp = temp->next;
            }
        }
        else if (v == 'B' || v == 'b')
        {
            printf("Enter New Book Name : ");
            scanf(" %49[^\n]", s4);

            while (temp)
            {
                if (temp->id == a)
                {
                    strcpy(temp->bkname, s4);
                    printf("Book name updated successfully.\n");
                    k = 1;
                    break;
                }

                temp = temp->next;
            }
        }
        else if (v == 'Q' || v == 'q')
        {
            printf("Enter New Quantity : ");
            scanf("%d", &qty);

            while (temp)
            {
                if (temp->id == a)
                {
                    temp->qnty = qty;
                    printf("Quantity updated successfully.\n");
                    k = 1;
                    break;
                }

                temp = temp->next;
            }
        }
        else
        {
            printf("Invalid Choice.\n");
            goto l2;
        }

        if (!k)
            printf("Book ID not found.\n");
    }

    else if (c == 'B' || c == 'b')
    {
        printf("Enter Book Name : ");
        scanf(" %49[^\n]", s);

        s1 = s;

        while (*s1)
        {
            if (*s1 >= 'A' && *s1 <= 'Z')
                *s1 += 32;
            s1++;
        }

        t = p;
        r3 = 0;

        while (t)
        {
            i = 0;

            while (t->bkname[i])
            {
                s2[i] = t->bkname[i];

                if (s2[i] >= 'A' && s2[i] <= 'Z')
                    s2[i] += 32;

                i++;
            }

            s2[i] = '\0';

            if (strstr(s2, s) != NULL)
            {
                printf("---------------------------------------------\n");
                printf("ID      : %d\n", t->id);
                printf("Book    : %s\n", t->bkname);
                printf("Author  : %s\n", t->auname);
                printf("Quantity: %d\n", t->qnty);
                printf("---------------------------------------------\n");

                r3 = 1;
                break;
            }

            t = t->next;
        }

        if (!r3)
            printf("Book not found.\n");
        else
            goto l1;
    }

    else if (c == 'C' || c == 'c')
    {
        return;
    }

    else
    {
        printf("Invalid Choice.\n");
        goto l3;
    }
}
