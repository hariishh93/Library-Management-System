#include <stdio.h>
#include <stdlib.h>
#include "library.h"

void save_book(BOOK **p, ISSUE **h, unsigned int w)
{
    static int m = 0;
    static int m2 = 0;

    static FILE *fp2 = NULL;
    static FILE *fp4 = NULL;
    static FILE *fp6 = NULL;

    if (w == 0)
    {
        FILE *fp1 = fopen("book.dat", "rb");
        FILE *fp3 = fopen("bookid.dat", "rb");
        FILE *fp5 = fopen("issue.dat", "rb");

        BOOK *temp;
        ISSUE *temp1;

        /*==========================
            LOAD BOOKS
        ==========================*/

        if (fp1 != NULL)
        {
            while (1)
            {
                temp = (BOOK *)malloc(sizeof(BOOK));

                if (temp == NULL)
                {
                    printf("Memory Allocation Failed\n");
                    break;
                }

                if (fread(&temp->id, sizeof(int), 1, fp1) != 1)
                {
                    free(temp);
                    break;
                }

                if (fread(temp->bkname, sizeof(char),
                          sizeof(temp->bkname), fp1)
                    != sizeof(temp->bkname))
                {
                    free(temp);
                    break;
                }

                if (fread(temp->auname, sizeof(char),
                          sizeof(temp->auname), fp1)
                    != sizeof(temp->auname))
                {
                    free(temp);
                    break;
                }

                if (fread(&temp->qnty,
                          sizeof(int), 1, fp1) != 1)
                {
                    free(temp);
                    break;
                }

                temp->next = *p;
                *p = temp;
            }

            fclose(fp1);
        }

        /*==========================
           LOAD DELETED IDS
        ==========================*/

        if (fp3 != NULL)
        {
            fread(&count, sizeof(count), 1, fp3);
            fread(&r2, sizeof(r2), 1, fp3);
            fread(&ic1, sizeof(ic1), 1, fp3);

            if (count > 0)
            {
                del = (int *)malloc(count * sizeof(int));

                if (del == NULL)
                {
                    fclose(fp3);
                    return;
                }

                for (unsigned int i = 0; i < count; i++)
                {
                    fread(&del[i], sizeof(int), 1, fp3);
                }
            }
            else
            {
                del = NULL;
            }

            fclose(fp3);
        }

        /*==========================
             LOAD ISSUED BOOKS
        ==========================*/

        if (fp5 != NULL)
        {
            while (1)
            {
                temp1 = (ISSUE *)malloc(sizeof(ISSUE));

                if (temp1 == NULL)
                {
                    printf("Memory Allocation Failed\n");
                    break;
                }

                if (fread(&temp1->is_id,
                          sizeof(int), 1, fp5) != 1)
                {
                    free(temp1);
                    break;
                }

                fread(&temp1->bk_id,
                      sizeof(int), 1, fp5);

                fread(&temp1->us_id,
                      sizeof(int), 1, fp5);

                fread(temp1->usname,
                      sizeof(char),
                      sizeof(temp1->usname),
                      fp5);

                fread(&temp1->is_date.date,
                      sizeof(int), 1, fp5);

                fread(&temp1->is_date.mon,
                      sizeof(int), 1, fp5);

                fread(&temp1->is_date.year,
                      sizeof(int), 1, fp5);

                fread(&temp1->due_date.date,
                      sizeof(int), 1, fp5);

                fread(&temp1->due_date.mon,
                      sizeof(int), 1, fp5);

                fread(&temp1->due_date.year,
                      sizeof(int), 1, fp5);

                fread(&temp1->ret_date.date,
                      sizeof(int), 1, fp5);

                fread(&temp1->ret_date.mon,
                      sizeof(int), 1, fp5);

                fread(&temp1->ret_date.year,
                      sizeof(int), 1, fp5);

                fread(&temp1->fine,
                      sizeof(int), 1, fp5);

                fread(&temp1->status,
                      sizeof(int), 1, fp5);

                temp1->next = *h;
                *h = temp1;
            }

            fclose(fp5);
        }

        return;
    }

    /*========================================
             SAVE BOOKS
    ========================================*/

    if (w == 1)
    {
        if (m == 0)
        {
            fp2 = fopen("book.dat", "wb");

            if (fp2 == NULL)
            {
                perror("book.dat");
                return;
            }
        }

        if (p != NULL && *p != NULL)
        {
            BOOK *temp = *p;

            if (temp->next != NULL)
            {
                m++;
                save_book(&(temp->next), NULL, 1);
                m--;
            }

            fwrite(&temp->id,
                   sizeof(int), 1, fp2);

            fwrite(temp->bkname,
                   sizeof(char),
                   sizeof(temp->bkname),
                   fp2);

            fwrite(temp->auname,
                   sizeof(char),
                   sizeof(temp->auname),
                   fp2);

            fwrite(&temp->qnty,
                   sizeof(int), 1, fp2);
        }

	        if (m == 0)
        {
            fclose(fp2);

            /*==============================
                SAVE DELETED ID LIST
            ==============================*/

            fp4 = fopen("bookid.dat", "wb");

            if (fp4 == NULL)
            {
                perror("bookid.dat");
                return;
            }

            fwrite(&count, sizeof(count), 1, fp4);
            fwrite(&r2, sizeof(r2), 1, fp4);
            fwrite(&ic1, sizeof(ic1), 1, fp4);

            if (count > 0 && del != NULL)
            {
                for (unsigned int i = 0; i < count; i++)
                {
                    fwrite(&del[i], sizeof(int), 1, fp4);
                }
            }

            fclose(fp4);

            /*==============================
                SAVE ISSUED BOOKS
            ==============================*/

            if (m2 == 0)
            {
                fp6 = fopen("issue.dat", "wb");

                if (fp6 == NULL)
                {
                    perror("issue.dat");
                    return;
                }
            }

            if (h != NULL && *h != NULL)
            {
                ISSUE *temp1 = *h;

                if (temp1->next != NULL)
                {
                    m2++;
                    save_book(NULL, &(temp1->next), 1);
                    m2--;
                }

                /* Order MUST match loading exactly */

                fwrite(&temp1->is_id,
                       sizeof(int), 1, fp6);

                fwrite(&temp1->bk_id,
                       sizeof(int), 1, fp6);

                fwrite(&temp1->us_id,
                       sizeof(int), 1, fp6);

                fwrite(temp1->usname,
                       sizeof(char),
                       sizeof(temp1->usname),
                       fp6);

                fwrite(&temp1->is_date.date,
                       sizeof(int), 1, fp6);

                fwrite(&temp1->is_date.mon,
                       sizeof(int), 1, fp6);

                fwrite(&temp1->is_date.year,
                       sizeof(int), 1, fp6);

                fwrite(&temp1->due_date.date,
                       sizeof(int), 1, fp6);

                fwrite(&temp1->due_date.mon,
                       sizeof(int), 1, fp6);

                fwrite(&temp1->due_date.year,
                       sizeof(int), 1, fp6);

                fwrite(&temp1->ret_date.date,
                       sizeof(int), 1, fp6);

                fwrite(&temp1->ret_date.mon,
                       sizeof(int), 1, fp6);

                fwrite(&temp1->ret_date.year,
                       sizeof(int), 1, fp6);

                fwrite(&temp1->fine,
                       sizeof(int), 1, fp6);

                fwrite(&temp1->status,
                       sizeof(int), 1, fp6);
            }

            if (m2 == 0)
            {
                fclose(fp6);
            }
        }
    }
}
