/*************************************************************************************/
/*"NITE and DAY" Puzzle                                                              */
/*************************************************************************************/

/*Special symbols.*/
#define SymbolBlank '.' /*Symbol that denotes a blank square.*/
#define SymbolFixed '$' /*Symbol that cannot move.*/

/*Board dimensiona.*/
#define BoardHeight 3
#define BoardWidth 4
#define BoardSize  12

/*Start position.*/
/* N I T E */
/* $ . $ . */
/* D A Y . */
#define StartBoard "NITE$.$.DAY."

/*Goal position.*/
/* D A Y . */
/* $ . $ . */
/* N I T E */
#define GoalBoard  "DAY.$.$.NITE"

/*Number of moves in a minimal length solution for this puzzle,*/
/*   where one move is defined as s moving a piece vertically or horizontally*/
/*   to an adjacent unoccupied square (and the SymbolFixed piece cannot move).*/
#define MinSolution 66

/*Data structure parameters.*/
#define QueueArraySize 50000  /*Queue goes from 0 to QueueArraySize-1.*/
#define HashArraySize 1000003 /*Hash table goes from 0 to HashArraySize-1.*/
#define HashStatsMAX 50       /*Max number of hash bucket size statistics to keep.*/
