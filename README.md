# README

To compile just run the **make** command in the shell since the makefile compiles the c code and produces an executable called **fib**

To execute the program run the **./fib < natural number >** command with a single number as argument representing the length of the fibonacci sequence to be produced. For example, to execute the fibonacci sequence with a length of 7 type the following command **./fib 7**. The expected output is the following sequence: 0, 1, 1, 2, 3, 5, 8

To remove the executable just run the following command **make clean**

The program is implemented using two threads: a parent thread and a child thread. The child thread is in charged of generating the fibonacci sequence with the length being a parameter provided by the user. The function in charge of doing this is the **runner** function which is the one running in the child thread. The function calculates the sequence using a loop instead of recursion. The function assigns the two first numbers of the sequence (0 and 1), and then calculates the following numbers in the sequence by adding the last two numbers. All the calculated numbers are stored in a dynamically allocated array that we later use in the parent thread to print the fibonacci sequence. That is why we need to wait for the child thread to finish before we can start printing the results. 
