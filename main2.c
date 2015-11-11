#include "date.h"

int main(int argc, char const *argv[])
{
	/* variables used */
	int day, month, year, value;
	FILE *fpointer;

	/* read input date and display in 1JAN2015 format */
	while(scanf("%d/%d/%d", &day, &month, &year) == 3){
		printf("%d %s %d\n", day, themonth[month], year);
	}

	/* if openned, if it opens successfully return the file, if it fails return NULL */
	printf("\nOpenning the file...\n\n");
	if ((fpointer = fopen("dates1.dat","r")) != NULL)
	{
		/* while there are still characters in file... */
		while((value = getc(fpointer)) != EOF){
			printf("%c", value);
		}
	}

	/*	close file */
	fclose(fpointer);

	printf("\n\nSuccess! The File has now been closed.\n");
	return 0;
}	