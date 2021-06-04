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


