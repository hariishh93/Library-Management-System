#include "library.h"

void ret_book(ISSUE *h, BOOK *p)
{
    ISSUE *temp = h;
    BOOK *temp1 = p;

    int bid, uid;

    time_t now;
    struct tm *t1;

    int d1, m1, y1;
    int d2, m2, y2;

    long long days1, days2, era, doe, y;
    unsigned yoe, doy, mp, day;

    printf("Enter Book ID and User ID : ");
    scanf("%d %d", &bid, &uid);

    while (temp)
    {
        if (temp->bk_id == bid &&
            temp->us_id == uid &&
            temp->status == 0)
            break;

        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Issue Record Not Found.\n");
        return;
    }

    time(&now);
    t1 = localtime(&now);

    d1 = t1->tm_mday;
    m1 = t1->tm_mon + 1;
    y1 = t1->tm_year + 1900;

    d2 = temp->due_date.date;
    m2 = temp->due_date.mon;
    y2 = temp->due_date.year;

    temp->status = 1;

    temp->ret_date.date = d1;
    temp->ret_date.mon = m1;
    temp->ret_date.year = y1;

    /* Current date to serial days */

    y = y1;
    mp = m1;
    day = d1;

    y -= (mp <= 2);
    era = (y >= 0 ? y : y - 399) / 400;
    yoe = (unsigned)(y - era * 400);
    doy = (153 * (mp + (mp > 2 ? -3 : 9)) + 2) / 5 + day - 1;
    doe = (long long)yoe * 365 + yoe / 4 - yoe / 100 + doy;
    days1 = era * 146097 + doe;

    /* Due date to serial days */

    y = y2;
    mp = m2;
    day = d2;

    y -= (mp <= 2);
    era = (y >= 0 ? y : y - 399) / 400;
    yoe = (unsigned)(y - era * 400);
    doy = (153 * (mp + (mp > 2 ? -3 : 9)) + 2) / 5 + day - 1;
    doe = (long long)yoe * 365 + yoe / 4 - yoe / 100 + doy;
    days2 = era * 146097 + doe;

    if (days1 > days2)
        temp->fine = (days1 - days2) * 5;
    else
        temp->fine = 0;

    while (temp1)
    {
        if (temp1->id == bid)
        {
            temp1->qnty++;
            break;
        }

        temp1 = temp1->next;
    }

    printf("\nBook Returned Successfully.\n");
    printf("Fine Amount : %d\n", temp->fine);
}
