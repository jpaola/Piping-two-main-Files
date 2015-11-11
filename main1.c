#include "date.h"
/****************************************************************************************
  This program consists of two main programs. Main1 reads from a file , validating
  dates in month/day/year format where month, day, and year are integer values.
  The dates are validated based on leap year, number of months in a year, and number
  of days per month. The ouput of main1 becomes piped with main2 becoming main2's input.
  main2 then outputs valid dates in day/month/year format where month is 
  displayed with 3 letters representing the corresponding month. The output of main2 is
  displayed on the output.dat file. All corrupt dates are handled (skipped).

  Created by Paola Jiron on 11/10/15.
  Copyright © 2015 Paola Jiron. All rights reserved.

*****************************************************************************************/

int main(int argc, char const *argv[])
{
	/* variables used */
	char line[MAXLINE+1];			/* defines a line length */
	int input;
	int maxline = MAXLINE;

	/*
		Accept ./a.out # of lines to read 
		(ex. if 10 only print 10 lines only
		 iff dates are valid)

	*/
	if(argc == ARGNUM){
		input = atoi(argv[INPUT]);

		/* assign the new line length if greater than defined MAXLINE */
		if (input > maxline){
			input = maxline;
		}
		/* generate valid dates indicated by input if input is a positive value */
		if(input > 0){					
			while(input > 0 && getlin(line, sizeof(line)) > 0){
				generateDates(line);
				input--;
			}
		}else{	/* otherwise(for negative input), generate all valid dates */
			while(getlin(line, sizeof(line)) > 0){
				generateDates(line);	
			}
		}
	}	
	return 0;
}

/***********************************************
	Reads, validates, and outputs valid dates.
************************************************/
void generateDates(char line[]) {

	int day, month, year;

	/* read each line in file and ...*/
	if(sscanf(line, "%d/%d/%d", &month, &day, &year) == 3){

		/* validate them while the dates are valid */
		if(validDates(month, day, year) == VALID){

			printf("%d/%d/%d\n", day, month, year);
		}
	}
}

/***********************************************
		Validate the dates on dates1.dat
 ***********************************************/
int validDates(int month, int day, int year){

	int leapYear = ((year%4 == 0 && year%100 != 0)||(year%400 == 0));

	if((day >= 1 && day <= 31) && (month >= 1 && month <= 12)){
		if((month == JAN || month == MAR || month == MAY 
			|| month == JUL || month == AUG || month == OCT 
			|| month == DEC)){
			return VALID;	/* check if the month has a max of 31 days */
		}
		else if((month == APR || month == JUN || month == SEP 
			|| month == NOV) && (day >= 1 && day <= 30)){
			return VALID;	/* check if the month has a max of 30 days */
		}
		/* check if leap year */
		else if(((leapYear && month == FEB) && (day >= 1 && day <= 29))
			||((!leapYear && month == FEB) && (day >= 1 && day <= 28))){
			return VALID;	/* is a leap year */
		}
	}
	return INVALID;
}

/**********************************************
  getline: read a line into s, return length. 
 **********************************************/

int getlin(char s[], int lim){

	/* variables used */
	int c, length;

	for(length=0; length<lim-1 && (c = getchar()) != EOF && c!= '\n'; ++length){
		s[length] = c;
	}
	if(c == '\n'){
		s[length] = c;
		++length;
	}
	s[length] = '\0';
	return length;
}