/* 			Group Project - 1       */
/* 		 A "Decomment" Program    	*/
/*----------------------------------*/
/* 			Group Information       */
/*----------------------------------*/
/* Abenezer Sleshi      ATR/7940/11 */
/* Aymen Mohammednur    ATR/5985/11 */
/* Bethelhem Teshibelay ETR/9292/11 */
/* Semere Habtu 		ATR/2583/11 */
/* Semere Tereffe		ATR/4113/11 */
/*----------------------------------*/


#include <stdio.h>
#include <stdlib.h>
#include "state.h" /* External enum for Statetype handling */



/*-------------------------------------------------------------------------------------------------*/
/* Handles states depending on the DFA 							           */
/*-------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------*/
/* handleNormalCodeState: Implement the NORMAL_CODE state of the DFA. c is the current DFA         */
/* character. *state specifies current state. Writes out char till state changes based on c        */
/*-------------------------------------------------------------------------------------------------*/
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

/*-------------------------------------------------------------------------------------------------*/
/* handleInCharLiteralState: Implement the IN_CHAR_LITERAL state of the DFA. c is the current      */
/* DFA chararacter. *state specifies input stream is inside char literal. Check for escape char    */
/*-------------------------------------------------------------------------------------------------*/
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

/*-------------------------------------------------------------------------------------------------*//* handleInStringState: Implement the IN_STR_LITERAL state of the DFA. c is the current DFA        *//* character. *state specifies the input stream is inside a string literal. check for escape char  */
/*-------------------------------------------------------------------------------------------------*/
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

/*-------------------------------------------------------------------------------------------------*/
/* handleEscapeCharState: Implement the ESCAPE_CHAR state of the DFA. c is the current DFA         */
/* chararacter. *state specifies input is inside an escape character. Treat as IN_CHAR_LITERAL     */
/*-------------------------------------------------------------------------------------------------*/
void handleEscapeCharState(State *state, char c)
{
	*state = IN_CHAR_LITERAL;
	putchar(c);	
}


/*-------------------------------------------------------------------------------------------------*//* handleEscapeStrState: Implement the ESCAPE_STR state of the DFA. c is the current DFA character *//* *state specifies the input stream is inside an escape character. Treat as IN_STR_LITERAL        */
/*-------------------------------------------------------------------------------------------------*/
void handleEscapeStrState(State *state, char c)
{
	*state = IN_STR_LITERAL;
	putchar(c);
}

/*-------------------------------------------------------------------------------------------------*/
/* handleCommentStarterState: Implement the COMMENT_STARTER state of the DFA. c is the current     */
/* DFA chararacter. Tracks code line and comment line. Change *state depending on what c is        */
/*------------------------------------------------------------------------------------------------ */
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

/*------------------------------------------------------------------------------------------------ *//* handleInsideCommentState: Implement the INSIDE_COMMENT state of the DFA. c is the current DFA   *//* character. *state specifies the state. Ignore chars including new line char until state changes */
/*-------------------------------------------------------------------------------------------------*/
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

/*-------------------------------------------------------------------------------------------------*//* handleCommentEnderState: Implement the COMMENT_ENDER state of the DFA. c is the current DFA     *//* character.*state specifies state to INSIDE_COMMENT till ending char found. Add space after end  */
/*-------------------------------------------------------------------------------------------------*/
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

/*------------------------------------------------------------------------------------------------*/
/* Helper functions for error handling							          */
/*------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------*/
/* lineCount: Takes initial position of *line and increments when input char is newline character */
/*------------------------------------------------------------------------------------------------*/
void lineCount(int *line, char c)
{
	if (c == '\n')
	{
		++*line;
	}
}


/*------------------------------------------------------------------------------------------------*/
/* checkTermination: Validate the state at the end of the code and throw error if                 */
/* there is an unterminated comment. Determines the last unterminated line by our static variable */
/*------------------------------------------------------------------------------------------------*/
void checkTermination(State *state, int last_comment_line)
{
	if (*state == INSIDE_COMMENT || *state == COMMENT_ENDER)
	{
		fprintf(stderr, "Error: Comment started on line %d is unterminated comment.\n", last_comment_line);
	}
}

