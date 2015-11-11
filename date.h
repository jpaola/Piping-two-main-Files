#ifndef date_h
#define date_h

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

enum months { JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};

/* NIL = 0 since JAN = 1 */
char *themonth[] = {"NIL", "JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};

#define VALID 1 					/* valid date */
#define INVALID 0					/*  invalid date */
#define MAXLINE 1000			/* buffer size for line read in file */
#define ARGNUM 2				/* commandline argument numbers */
#define INPUT 1 				/* input line length  where linelength is within 0 and MAXLINE */
int validDates(int month, int day, int year);	/* date validator */
int getlin(char s[], int lim);
void generateDates(char line[]);		

#endif