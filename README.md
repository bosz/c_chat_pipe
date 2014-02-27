c_chat_pipe
===========

using pipes to chat locally on same computer, 2 terminals in a half duplex manner


 C_PIPE_CHATTING
 ==============
	
	The check_or_create_pipe is a function that takes the name(string) of a pipe. It test if the pipe exists. If yes, then it does not do anything(pipe already present). But if the pipe does not exists, it tries creating it using the mkfifo function and also test if the creation was done successfully by using the return value of the mkfifo function. If that return value != 0,  then that means the fifo pipe was not create, thus it returns an error message to the user.
	
	The open_check function takes the fifo pipe and opens it in mode. After open attempt, it checks if the attempt was successfull. If no, then it prints an error message to the user else, control is passed back to main.
	
	CONVERSATION:
		process 1: inito
		process 2: recco
	
	while(1)
	{
	init opens fifopipe1 in read mode and recco opens fifopipe1 in write mode
	inito opens fifopipe2 in write mode while recco opens fifopipe2 in read mode.
	
	inito reads data from stdin and writes it to fifopipe2. 
	recco reads info sent by inito from fifopipe2 and writes it to stdout.
	
	recco replies by reading from stdin and writing to fifopipe1
	inito reads from fifopipe1, the message sent by recco
	The process starts back afresh.
	}
	
	
	BUGS
	----
	This program communicates in a both directions but one process at a time(half duplex).
	Also, the communication must be started by the executable of the initiator.c, communicating with the executable of the receiver.c.
	For this version, it follows a receive and acknowledge format. ie, when one process sends, the other process must send some message(what ever the message) before that same process can communicate. One process cant send two messages at the same time without receiving a response from the other process.
Example: init: hello
		 rec : hi
		 init: how
		 rec : fine 
		 .
		 .
		 .
		 .
		 end of conversation.(ctrl+z or ctrl+z) to stop conversation
		 							
		 			BUT, 
		 init: hello
		 init: what?
		 that is wrong cos init has sent two messages without waiting for res to respond to the first message.
		 This is the way this version runs. If u don't like it like that, i earge u to do the modification and upload the patch to where this one was downloaded and then send me a mail to my inbox for notification. 
		 
		 COMPILATION AND USE
		 ==================
		 
	compile the initiator.c adding the procedures.c file to it.
	same goes for the receiver.c.
	execute executable of the 2 above compiles on two separate terminals and start chatting with ur self(haha, chat with myself?).
	
	gcc -Wall -o inito initiator.c procedures.c
	gcc -Wall -o recco receiver.c procedures.c
	
	terminal 1 > ./inito
	terminal 2 > ./recco
	
	
*********************************************************
														*********************************************************
I am looking forward to those that can optimize the code. Its still relatively small and fragile.
Much still needs to be done on the code.
The next step i will be working on is to implement it over a network.
Contributions are always welcomed and its free with no warrantee. Can be distributed freely.
				*						*													Thanks
				*	*				*	*													Coder: Fongoh Martin T
				*		*		*		*													AKA: __echelon__
				*			*			*													FET
				*						*													UB
																							fongohmartin@gmail.com
				*						*													all rights reserved.
				*						*				*********************************************************
*********************************************************

 	
