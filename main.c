//This is the includes that I needed for this function
#include "readerwriter.c"

void main()
{
	//This is where I initilize all of my semaphores
    sem_init(&writerLock,0,1);
    sem_init(&All_lock,0,1);
	sem_init(&fairness1,0,1);
 
	int reader_count = 0, writer_count = 0, i = 0;	//
	FILE *fptr = fopen("scenarios.txt", "r");	//This is opening the file scenarios.txt to be read and setting the access to it as fptr
	char rw;	//This is the char that will hold the character from the file given

		//This loops through all of the characters in the file and puts them into rw
		while(fscanf(fptr, "%c", &rw)!=EOF)
        {
			if(rw== 'r')	//This is for the case that a read is told to happen 
			{
                sem_wait(&fairness1);	//This is the lock that makes sure that only one thread will be sent to the functions at a time

				//These create a pointer for ints and sets it to the writer count
				int* temp;
				temp = (int*)malloc(sizeof(int)*1);
				temp[0]= reader_count;

				pthread_t thread;	//This is the thread that will be sent through the reader functon
                pthread_create(&thread,NULL,reader,temp); //This creates the thread and sends it through the reader function 
				pthread_join(thread,NULL);	//This joins the thread after the thread has been run through the writer function
				reader_count++;	//This is increasing the the read count everytime read is called

                sem_post(&fairness1);	//This releases the lock so that another thread can be created and put through the functions
			}



			else if(rw== 'w')	//This is for the case that a write is told to happen 
			{
                sem_wait(&fairness1);	//This is the lock that makes sure that only one thread will be sent to the functions at a time

				//These create a pointer for ints and sets it to the writer count
				int* temp;
				temp = (int*)malloc(sizeof(int)*1);
				temp[0]= writer_count;
				
				pthread_t thread;	//This is the thread that will be sent through the writer functon
				pthread_create(&thread,NULL,writer,temp);	//This creates the thread and sends it through the writer function 
				pthread_join(thread,NULL);	//This joins the thread after the thread has been run through the writer function

				writer_count++;	//This is increasing the the write count everytime write is called

                sem_post(&fairness1);	//This releases the lock so that another thread can be created and put through the functions
			}
		}
		fclose(fptr);	//This closes the file
}
