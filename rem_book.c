#include "library.h"

void rem_book(BOOK **p)
{
    char c;
    char s[50], s2[50];
    char *s1;

    int a;
    int found = 0;
    int i = 0;
    int i1 = 0;
    int *t2 = NULL;

    if (*p == NULL)
    {
        printf("No books available to delete.\n");
        return;
    }

    BOOK *temp = *p;
    BOOK *prev = NULL;
    BOOK *t = *p;

    printf("\n");
    printf("I/i : Delete By Book ID\n");
    printf("N/n : Delete By Book Name\n");
    printf("Enter Choice : ");
    scanf(" %c", &c);

    if (c == 'I' || c == 'i')
    {
l1:
        temp = *p;
        prev = NULL;
        found = 0;

        printf("Enter Book ID : ");
        scanf("%d", &a);

        while (temp)
        {
            if (temp->id == a)
            {
                if (prev == NULL)
                    *p = temp->next;
                else
                    prev->next = temp->next;

                free(temp);

                printf("Book ID %d deleted successfully.\n", a);

                count++;

                del = realloc(del, count * sizeof(int));

                if (del == NULL)
                {
                    printf("Memory allocation failed.\n");
                    exit(EXIT_FAILURE);
                }

                t2 = del;

                while (i1 < (int)(count - 1))
                {
                    t2++;
                    i1++;
                }

                *t2 = a;

                if (count > 1)
                {
                    for (int m = 0; m < (int)count - 1; m++)
                    {
                        for (int n = m + 1; n < (int)count; n++)
                        {
                            if (del[m] > del[n])
                            {
                                int x = del[m];
                                del[m] = del[n];
                                del[n] = x;
                            }
                        }
                    }
                }

                found = 1;
                break;
            }

            prev = temp;
            temp = temp->next;
        }

        if (!found)
            printf("Book ID not found.\n");
    }

    else if (c == 'N' || c == 'n')
    {
        printf("Enter Book Name : ");
        scanf(" %49[^\n]", s);

	if(*s=='\0')
	{
		printf("No input entered....\n");
		return;
	}


        s1 = s;

        while (*s1)
        {
            if (*s1 >= 'A' && *s1 <= 'Z')
                *s1 += 32;

            s1++;
        }

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
                printf("-------------------------------------\n");
                printf("ID       : %d\n", t->id);
                printf("Book     : %s\n", t->bkname);
                printf("Author   : %s\n", t->auname);
                printf("Quantity : %d\n", t->qnty);
                printf("-------------------------------------\n");

                goto l1;
            }

            t = t->next;
        }

        printf("Book not found.\n");
    }

    else
    {
        printf("Invalid Choice.\n");
    }
}
