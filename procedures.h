void check_or_create_pipe(char *, int );
//checks if the pipe exists. If not it create the pipe.

int open_check(char *, int);
//opens the file and tests if the operation was successful.

void welcome(char *);
//welcomes the user to the chatting program.

void make_message(char *, char *,  char *);
//makes the message by joining the nick and the message alongside some formatting.

void have_u_ended(char *, char *, int, int);
//this checks if the user has inputed the exit string.

