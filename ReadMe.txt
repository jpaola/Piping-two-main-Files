Instructions to run the Dates files:

1) Download main1.c, date.h, dates1.dat, main2.c (the output.dat will be created at runtime)

2) Make sure the 5 files are in the same folder

3) Find the files on your computer by providing valid location

    ex. paola@laptopvm:~/Desktop/ProgrammingIII/ProgrammingIII$...

4) To compile the files using either gcc or cc you must enter them in the following
	format:

	Note: to make the piping instruction process less lengthy, rename the files using the
			-o command on the command line. Here is an example of the renaming 
			process..

			gcc main1.c -o main1

			 AND

			gcc main2.c -o main2

	i) You must compile both files separately. 

	ii) Now that both main1.c and main2.c have been compiled and renamed, you can run the programs
	    using the pipe to pipeline both main programs. Make sure you process main1 before main2.
	    main1 reads from dates.dat then it gets piped with main2 while main2 outputs to output.dat file.

	So the order is important.

Instruction format: 

./main1 < dates1.dat | ./main2 > output.dat

5) The input for the first program will be a number of valid entries to be directed from the
   dates input file (dates1.dat). Non-positive numbers indicate to input all valid entries from
   dates to input file. The number is input between ./main1 AND <
   like this...

 For negative values:  ./main1 -12 < dates1.dat | ./main2 > output.dat
 For positive values:  ./main1 12 < dates1.dat | ./main2 > output.dat

 Note: If you want to test the programs with different values repeat step 5. If your OS does not 
 respond (which should not happen) simply recompile main1 and main2 (step 4), then run the piping instruction (step 5).