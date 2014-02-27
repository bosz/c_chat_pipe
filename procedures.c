/*
	By Fongoh Martin.
	__echelon__
*/

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<string.h>
#include"procedures.h"
void check_or_create_pipe(char *fpipe, int mode)
{
	int res;
	
	if(access(fpipe, F_OK) != 0)
	{
		res=mkfifo(fpipe, mode);
		if( res != 0 )
		{
			fprintf(stderr, "The link cannot be created.\n");
			perror("Chatting error");
			exit(EXIT_FAILURE);
		}
	}
}


int open_check(char *fpipe, int mode)
{
	//printf("Opeining the file in %d mode\n", mode);
	int fd;
	fd=open(fpipe, mode);
	//printf("open returned %d \n", fd);
	if(fd < 0 )
	{
		fprintf(stderr, "Error opening the pipe\n");
		exit(EXIT_FAILURE);
	}
	return fd;
}

void welcome(char *nick)
{
	//(void)system("reset");
	printf("		%s \n\n", nick);
	printf("  **********************************\n  "
		   " |\t\t\t\t  |\n  "
		   " !\tC PIPE CHATTING CODE      |\n  "
		   " |\t\t\t\t  !\n  "
		   " \\______________________________/ \n");
	printf("\t\t\tq to quit");
	printf("\n\n");

}

void make_message(char *temp, char *buffer, char *nick)
{
	(void)strcpy(buffer, "## ");
	strcat(buffer, nick);
	strcat(buffer, " ## :");
	strcat(buffer, temp);
}

void have_u_ended(char *tbuf, char *nick, int fd1, int fd2)
{
	if(strcasecmp(tbuf, "q") == 0 )
	{
		printf("\n\n");
		printf("Thanks for using C_PIPE_CHATTING_CODE. user: %s\n\n", nick);
		printf("Codes are always welcomed. \n");
		printf("Powered by : Fongoh Martin Tayong, __echelon__ of MicroPacific Lab\n");
		printf("All rights reserved\n\n");
		close(fd1);		close(fd2);
		exit(EXIT_SUCCESS);
	}
}
