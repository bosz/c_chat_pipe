/*
	By Fongoh Martin.
	__echelon__
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include <fcntl.h>
#include<sys/types.h>
#include<string.h>
#include<stdlib.h>
//now the functions' header files
#include"procedures.h"
//the names of the 2 fifo pipes to be used for the chatting.
#define FIFO_RITE "comune.ff"
#define FIFO_READ "comune2.ff"
int main()
{
	system("clear");
	printf("INITIATOR 1\n\n");
	char nick[10], buffer[200];
	int fifofd[2];
	char tbuf[180];
	
/*
	fifofd[0] holds the file descriptor of the fifo pipe that this program will be reading from.
	fifofd[1] holds the file descriptor of the filo pipe that this program will be writting to.
	The res holds the return value of creating a read pipe(res[0]) and creating a write pipe(res[1]).	
*/

	check_or_create_pipe(FIFO_READ, 0777);
	check_or_create_pipe(FIFO_RITE, 0777);
	
	//the pipe was created succesfully. So we can move to the next step.
	
	
	fifofd[1]=open_check(FIFO_RITE, O_WRONLY);
	fifofd[0]=open_check(FIFO_READ, O_RDONLY);
	

	printf("Give your username: ");
	(void)fgets(nick, 9, stdin);
	(void)strtok(nick, "\n");

	welcome(nick);
	
	//testing if the pipe already exists. If it does not exist, the the pipes are created at the different levels of the if statements.	
	
	while(1)//the conversation goes in here.
	{
		
		printf("%s > ", nick);
		(void)fgets(tbuf, 100, stdin);
		(void)strtok(tbuf, "\n");
		
		make_message(tbuf, buffer, nick);
		
		write(fifofd[1], buffer, 100);
		
		have_u_ended(tbuf, nick, fifofd[0], fifofd[1]);

		read(fifofd[0], buffer, 100);
		printf("%s\n", buffer);
	}
	//close(fifofd[0]);
	//close(fifofd[1]);
	exit(EXIT_SUCCESS);
}
