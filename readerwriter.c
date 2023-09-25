//This is the includes that I needed for this function
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

int i, j; //These are the ints that I will need throughout the code

//These are the decleration of the semaphores
sem_t writerLock;
sem_t All_lock;
sem_t fairness1;

//This is the writer function 
void* writer(void* num)
{
    //This locks All_lock so no other function can run and writerLock so no writer can operate
    sem_wait(&All_lock);
    sem_wait(&writerLock);

    int writerID=((int*)num)[0]; //This creates writerID int and sets it to num
	printf("Writer[%d] is created..\n", writerID); //Prints when a writer is created 
    printf("Writer[%d] is writing\n", writerID); //Prints when a writer is writing

    //This is the loop that simulates the writing
    int x=0, T = rand()%10000;
    for(i = 0; i < T; i++)
    {
        for(j = 0; j < T; j++)
        {
            x=i*j;
        }
    }

	printf("Writer[%d] finished writing\n", writerID); //Prints when a writer is done writing

    //Releases the locks for the writerLock and All_lock
    sem_post(&writerLock);
    sem_post(&All_lock);
	return NULL;
}

//This is the reader function 
void* reader(void* num)
{
    //This locks All_lock so no other function can run and writerLock so no writer can operate
    sem_wait(&All_lock);
    sem_wait(&writerLock);

	int readerID=((int*)num)[0]; //This creates readerID int and sets it to num
	printf("Reader[%d] is created..\n", readerID); //Prints when the reader is created
	printf("Reader[%d] is reading\n", readerID); //Prints when the reader is reading

    //This is the loop that simulates the writing
    int x=0, T = rand()%10000;
    for(i = 0; i < T; i++)
    {
        for(j = 0; j < T; j++)
        {
            x=i*j;
        }
    }

	printf("Reader[%d] finished reading\n", readerID); //Prints when the reader is done

    //Releases the locks for the writerLock and All_lock
    sem_post(&writerLock);
    sem_post(&All_lock);
    return NULL;
}