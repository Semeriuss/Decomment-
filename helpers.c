/*--------------------------*/
/* Group Information        */
/*--------------------------*/
/* Abenezer Sileshi     ATR */
/* Aymen Mohammednur    ATR */
/* Bethelihem Teshibelay ATR*/
/* Semere Habtu ATR/2583/11 */
/* Semere Tereffe ATR       */
/*--------------------------*/


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "state.h"



/*-------------------------------------------------------------------------------------------------*/
/* Handles states depending on the DFA 							           */
/*-------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------*/
/* handleNormalCodeState: Implement the NORMAL_CODE state of the DFA. c is the current DFA         */
/* character. *state specifies state. Writes out char till state changes based on c                */
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
/* DFA chararacter. Track code line and comment line. Change state according to c                  */
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
/* lineCount: to count the lines of code processed                                                */
/*------------------------------------------------------------------------------------------------*/
void lineCount(int *line, char c)
{
	if (c == '\n')
	{
		++*line;
	}
}


/*------------------------------------------------------------------------------------------------*/
/* checkTermination: to validate the state at the end of the code and throw error if              */
/* there is an unterminated comment.                                                              */
/*------------------------------------------------------------------------------------------------*/
void checkTermination(State *state, int last_comment_line)
{
	if (*state == INSIDE_COMMENT || *state == COMMENT_ENDER)
	{
		fprintf(stderr, "Error: Comment started on line %d is unterminated comment.", last_comment_line);
	}
}

