#include "library.h"

int main(void)
{
    int f = 0;
    int v;

    BOOK *hptr = NULL;
    ISSUE *hptr1 = NULL;

    /* Load saved records */
    save_book(&hptr, &hptr1, 0);

    while (1)
    {
        printf("\n");
        printf("+===========================================+\n");
        printf("|        LIBRARY MANAGEMENT SYSTEM          |\n");
        printf("+===========================================+\n");
        printf("| 1. Add New Book                          |\n");
        printf("| 2. Update Book Details                   |\n");
        printf("| 3. Remove Book                           |\n");
        printf("| 4. Search Book                           |\n");
        printf("| 5. View All Books                        |\n");
        printf("| 6. Issue Book                            |\n");
        printf("| 7. Return Book                           |\n");
        printf("| 8. List Issued Books                     |\n");
        printf("| 9. Save Records                          |\n");
        printf("|10. Exit                                  |\n");
        printf("+===========================================+\n");

        printf("Enter your choice : ");
        scanf("%d", &v);

        switch (v)
        {
            case 1:
                add_book(&hptr);
                break;

            case 2:
                upd_book(hptr);
                break;

            case 3:
                rem_book(&hptr);
                break;

            case 4:
                srch_book(hptr);
                break;

            case 5:
                allv_book(hptr);
                break;

            case 6:
                issue_book(hptr, &hptr1);
                break;

            case 7:
                ret_book(hptr1, hptr);      /* Fixed prototype */
                break;

            case 8:
                list_ised_book(hptr1);
                break;

            case 9:
                save_book(&hptr, &hptr1, 1);
                printf("Data saved successfully.\n");
                break;

            case 10:
                save_book(&hptr, &hptr1, 1);
                f = 1;
                break;

            default:
                printf("Invalid Choice.\n");
        }

        if (f)
            break;
    }

    printf("\nThank You...\n");

    return 0;
}
