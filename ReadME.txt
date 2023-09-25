To compile my program:
- Use the command:  $ gcc -o main main.c -lpthread
- The Makefile can also be used to compile the code

To run my program:
- You must include scenarios.txt in the same directory to run and make sure you have a      scenario for the program.
- You could modify the scenario.txt file to test other scenarios (1 scenario per run). 
- run ./main to see the result.


$ gcc -o main  main.c  -lpthread
./main
Reader[0] is created..
Reader[0] is reading
Reader[0] finished reading
Reader[1] is created..
Reader[1] is reading
Reader[1] finished reading
Reader[2] is created..
Reader[2] is reading
Reader[2] finished reading
Reader[3] is created..
Reader[3] is reading
Reader[3] finished reading
Writer[0] is created..
Writer[0] is writing
Writer[0] finished writing
Reader[4] is created..
Reader[4] is reading
Reader[4] finished reading
Reader[5] is created..
Reader[5] is reading
Reader[5] finished reading
Reader[6] is created..
Reader[6] is reading
Reader[6] finished reading

