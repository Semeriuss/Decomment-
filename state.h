/*--------------------------*/
/* Group Information        */
/*--------------------------*/
/* Abenezer Sileshi     ATR */
/* Aymen Mohammednur    ATR */
/* Bethelihem Teshibelay ATR*/
/* Semere Habtu ATR/2583/11 */
/* Semere Tereffe ATR       */
/*--------------------------*/


/* Enum to keep track of the state      */
/* Aliased as State                     */
/* used by decommenter and helper codes */

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


