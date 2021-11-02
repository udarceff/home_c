#ifndef GETTEMP_H
#define GETTEMP_H

int generate_year();
int get_month();
int get_day(int arg, int arg2);
int get_temp(int arg);

struct templist {
    int day;
    int month;
    int year;
    int temper;
};


#endif