#include <stdio.h>
#include <sys/types.h>//definitions of signed int and unsigned int
#include <unistd.h>//posix functions

int main()
{
	int k=0;
	
	pid_t pid;//signed 32 bit integer which stores the process id and can be used as an ineex to access process attribytes within the kernel

		do
		{
			printf("Enter a positive integer to run the Collatz Conjecture.\n"); 
  			scanf("%d", &k);	
		}while (k <= 0);//keeps running until the user enters a positive value

		pid = fork();//creates a child process which runs concurrently with the process that makes the fork() call 

		if (pid == 0)
		{
			printf("Pid = %d enters if block\n",pid);//checks if the pid=0 so that the child process can run
			printf("Child is working...\n");
			printf("%d\n",k);
			while (k!=1)//code for implementing Collatz conjecture
			{
				if (k%2 == 0)
				{
					k = k/2;
				}
				else if (k%2 == 1)
				{
					k = 3 * (k) + 1;
				}	
			
				printf("%d\n",k);
			}
		
			printf("Value of k in child process = %d\n", k);//displays 1 since only the child process executes collatz conjecture
			printf("Child process (%d) is done.\n", pid);
		}
		else
		{
			printf("Pid = %d enters else block\n", pid);
			printf("Parent process is waiting on child process...\n");
			wait();//parent is waiting for the child process to exexute.
			printf("Parent process (%d) is done.\n", pid);
			printf("Value of k in parent process = %d\n", k);//displays the users input since the parent process does not execute the collatz conjecture 
		}
	return 0; 
}
