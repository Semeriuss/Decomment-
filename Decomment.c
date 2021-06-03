#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

typedef enum Statetype {
	NORMAL_CODE,
	IN_CHAR_LITERAL,
	IN_STR_LITERAL,
	ESCAPE_CHAR,
	ESCAPE_STR,
	COMMENT_STARTER,
	INSIDE_COMMENT,
	COMMENT_ENDER,
} State;

void handleNormalCodeState(State *state, char c);
void handleCommentStarterState(State *state, char c, int *unterminated_line, int *code_line);
void handleInsideCommentState(State *state, char c);
void handleCommentEnderState(State *state, char c);
void handleInCharLiteralState(State *state, char c);
void handleInStringLiteralState(State *state, char c);
void handleEscapeCharState(State *state, char c);
void handleEscapeStrState(State *state, char c);

void lineCount(int *line, char c);
void checkTermination(State *state, int last_comment_line);

int main()
{
	State state = NORMAL_CODE;

	int code_line = 1;
	int unterminated_line = 1;

	for (;;)
	{
		char c = getchar();
		lineCount(&code_line, c);

		if (c == EOF) 
		{
			checkTermination(&state, unterminated_line);
			break;
		}

		switch(state)
		{
			case NORMAL_CODE:
				handleNormalCodeState(&state, c);
				break;

			case IN_CHAR_LITERAL:
				handleInCharLiteralState(&state, c);
				break;

			case IN_STR_LITERAL:
				handleInStringLiteralState(&state, c);
				break;

			case ESCAPE_CHAR:
				handleEscapeCharState(&state, c);
				break;

			case ESCAPE_STR:
				handleEscapeStrState(&state, c);
				break;

			case COMMENT_STARTER:
				handleCommentStarterState(&state, c, &unterminated_line, &code_line);
				break;

			case INSIDE_COMMENT:
				handleInsideCommentState(&state, c);
				break;

			case COMMENT_ENDER:
				handleCommentEnderState(&state, c);
				break;
		}
	}
	return 0;
}


void handleNormalCodeState(State *state, char c)
{
	if(c == '/')
	{
		*state = COMMENT_STARTER;
	}else if(c == '"')
	{
		*state = IN_STR_LITERAL;
		putchar(c);
	}else if(c == '\'')
	{
		*state = IN_CHAR_LITERAL;
		putchar(c);
	}
	else{
		*state = NORMAL_CODE;
		putchar(c);
	}
	
}


void handleEscapeCharState(State *state, char c)
{
	*state = IN_CHAR_LITERAL;
	putchar(c);	
}

void handleEscapeStrState(State *state, char c)
{
	*state = IN_STR_LITERAL;
	putchar(c);
}

void handleInCharLiteralState(State *state, char c) 
{
	putchar(c);
	if (c == '\\')
	{
		*state = ESCAPE_CHAR;
	}else if (c == '\'')
	{
		*state = NORMAL_CODE;
	}	
}


void handleInStringLiteralState(State *state, char c) 
{
	putchar(c);
	if (c == '\\')
	{
		*state = ESCAPE_CHAR;
	}else if (c == '"')
	{
		*state = NORMAL_CODE;
	}	
}



void handleCommentStarterState(State *state, char c, int *unterminated_line, int *code_line) 
{
	if (c == '*')
	{
		*state = INSIDE_COMMENT;
		*unterminated_line = *code_line;
	}else if ((c == '/') && *state == COMMENT_STARTER)
	{
		putchar(c);
		*state = COMMENT_STARTER;
	}else if (c == '/')
	{
		*state = COMMENT_STARTER;
	}else {
		*state = NORMAL_CODE;
		putchar('/');
		putchar(c);
	}
}

void handleInsideCommentState(State *state, char c)
{
	if (c == '*')
	{
		*state = COMMENT_ENDER;
	}

	if (c == '\n')
	{
		putchar(c);
	}
}

void handleCommentEnderState(State *state, char c)
{
	if (c == '/')
	{
		*state = NORMAL_CODE;
	}else if (c == '*')
	{
		*state = COMMENT_ENDER;
	}else{
		*state = INSIDE_COMMENT;
		putchar(' ');
	}
}

void lineCount(int *line, char c)
{
	if (c == '\n')
	{
		++*line;
	}
}

void checkTermination(State *state, int last_comment_line)
{
	if (*state == INSIDE_COMMENT || *state == COMMENT_ENDER)
	{
		fprintf(stderr, "Error: Comment started on line %d is unterminated comment.", last_comment_line);
	}
}

