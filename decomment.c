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
#include "state.h" /* External enum declaration for State type */

/*-------------------------------------------------------------------*/
/* External function template declarations used to handle each state */
/* in the DFA 														 */
/*-------------------------------------------------------------------*/
extern void handleNormalCodeState(State *state, char c);
extern void handleCommentStarterState(State *state, char c,
					int *unterminated_line, int *code_line);
extern void handleInsideCommentState(State *state, char c);
extern void handleCommentEnderState(State *state, char c);
extern void handleInCharLiteralState(State *state, char c);
extern void handleInStringLiteralState(State *state, char c);
extern void handleEscapeCharState(State *state, char c);
extern void handleEscapeStrState(State *state, char c);

/*-------------------------------------------------------------------*/
/* External helper function declarations for error handling 	     */
/*-------------------------------------------------------------------*/

extern void lineCount(int *line, char c);
extern void checkTermination(State *state, int last_comment_line);

/*-------------------------------------------------------------------*/
/*main: Read text from stdin. Remove comment. Write text to stdout if*/
/*text ends valid code. Return 0.  Writes error if text ends with    */
/*unterminated comment.Return 1										 */
/*-------------------------------------------------------------------*/
int main(void)
{
	State state = NORMAL_CODE; /* Starting state in the source code */

	/* static variable to count the line number in the code         */
	static int code_line = 1;

	/* static variable to index where a comment starts in case it   */
	/* terminates without closing 									*/
	static int unterminated_line = 1;

	for (;;)
	{
		char c = getchar();
		lineCount(&code_line, c);

		if (c == EOF)
		{
			checkTermination(&state, unterminated_line);
			break;
		}

		switch (state)
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
