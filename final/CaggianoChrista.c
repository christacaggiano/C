#include <stdio.h>
#include <stdlib.h>
/*#include <Output.h>*/
#include <Puzzle.h>

#define False 0
#define True 1



typedef struct puzzleBoard {
   char board [BoardHeight][BoardWidth];
   char * original;
} *TypePuzzleBoard;


TypePuzzleBoard newPuzzleBoard(char letters[BoardSize]) {
    TypePuzzleBoard b = (TypePuzzleBoard) malloc(sizeof(struct puzzleBoard));
    if (b==NULL) {printf("Malloc for a new puzzle board failed."); exit(1);}

    int i;
    int j;
    int position= 0;
    for (i=0; i<BoardHeight; i++){
    	for (j=0; j<BoardWidth; j++){
    		b->board[i][j] = letters[position];
    		position++;
    	}
    }
    b->original = letters;
    /*
    printf(b->original);
    printf("\n");
    */

    return b;

}

int arePositionsEqual(TypePuzzleBoard b, TypePuzzleBoard b2){
	int i;
    int j;

	for (i=0; i<BoardHeight; i++){
    	for (j=0; j<BoardWidth; j++){
    		if (b->board[i][j]!=b2->board[i][j]){
    			return False;
    		}
    	}
    }
    return True;

}

/* Modified from https://github.com/iamaaditya/C-tutorial/blob/master/List.c */
typedef struct vbody {
   struct vbody *NEXT;
   TypePuzzleBoard board;
} *TypeVertex;

typedef TypeVertex TypeList;

TypeVertex NEWVERTEX() {
    TypeVertex p = (TypeVertex) malloc(sizeof(struct vbody));
    if (p==NULL) {printf("Malloc for a new vertex failed."); exit(1);}
    p->NEXT = NULL;
    return p;
}

/* Insert at end of linkedList */
void INSERT(TypePuzzleBoard b, TypeList *L) {
    TypeVertex w = NEWVERTEX();
    w->board = b;
    w->NEXT = *L;
    *L = w;
}

TypeList X=NULL;
void printBoard(TypePuzzleBoard b) {
    int i;
    int j;
    for (i=0; i<BoardHeight; i++){
    	for (j=0; j<BoardWidth; j++){
    		printf("%c", b->board[i][j]);
    	}

    	printf("\n");
    }
}

void PrintList(TypeList L) {
	int i=0;
    TypeVertex v;
    for (v=L; v->NEXT!=NULL; v = v->NEXT){
    	printf("board %d\n", ++i);
    	printBoard(v->board);
    } 
}

typedef struct hashTable {
   TypeList array [HashArraySize];
} *TypeHashTable;

TypeHashTable newHashTable() {
    TypeHashTable h = (TypeHashTable) malloc(sizeof(struct hashTable));
    if (h==NULL) {printf("Malloc for a new hash table failed."); exit(1);}
    int i;
    for (i=0; i<HashArraySize; i++){
    	TypeList X = NEWVERTEX();
    	h->array[i] = X;
    }
    return h;
}

int isBoardInList(TypeList L, TypePuzzleBoard b) {
    TypeVertex v;
    for (v=L; v->NEXT!=NULL; v = v->NEXT){
    	if ( arePositionsEqual(v->board, b)){
    		return True;
    	}
    } 
    return False;
}

int HASH(TypePuzzleBoard b){
	return 0;
}


void insertIntoTable(TypeHashTable h, TypePuzzleBoard b){
	int index = HASH(b);
	INSERT(b, &(h->array[index]));
}


typedef struct queue {
   TypePuzzleBoard array[QueueArraySize];
   int front;
   int rear;
   int size;
} *TypeQueue;

TypeQueue newQueue() {
    TypeQueue q = (TypeQueue) malloc(sizeof(struct queue));
    if (q==NULL) {printf("Malloc for a new queue failed."); exit(1);}
    q->front = 0;
    q->rear = 0;
    q->size = 0;
    int i;
    for (i=0; i<QueueArraySize; i++){
    	q->array[i] =  NULL;
    }
    return q;
}

void Enqueue(TypePuzzleBoard b, TypeQueue q){
	if (q->size >= QueueArraySize){
		printf("QUEUE is full =(\n"); exit(1);
	}
	q->array[q->rear] = b;
	q->rear = q->rear + 1;
	if (q->rear == QueueArraySize){
		q->rear = 0;
	}
	q->size = q->size + 1;
}

TypePuzzleBoard Dequeue(TypeQueue q){
	if (q->size == 0){
		printf("No solution =(\n"); exit(1);
	}
	TypePuzzleBoard temp = q->array[q->front];
	q->front = q->front + 1;
	q->size = q->size - 1;
	return temp;
}


int main() {

	TypePuzzleBoard b = newPuzzleBoard(StartBoard); 
	TypePuzzleBoard b2 = newPuzzleBoard(GoalBoard); 
	

	TypeQueue q = newQueue();
	Enqueue(b, q);
	Enqueue(b2, q);

	printBoard(Dequeue(q));
	printf("_____\n");
	printBoard(Dequeue(q));
	printBoard(Dequeue(q));
	/*
	TypeHashTable h = newHashTable();
	insertIntoTable(h, b);
	insertIntoTable(h, b2);
	PrintList(h->array[0]);

	TypePuzzleBoard b3 = newPuzzleBoard("DITE$.$.NAY.");

	printf("%d\n",isBoardInList(h->array[0], b));
	printf("%d\n",isBoardInList(h->array[0], b2));
	printf("%d\n",isBoardInList(h->array[0], b3));

	printf("%d", arePositionsEqual(b, b2) );
	printf("%d", arePositionsEqual(b3, b2) );
	TypePuzzleBoard b3 = newPuzzleBoard(GoalBoard); 

	X = NEWVERTEX();
	PrintList(X);
	printf("PRINTING 4 REAL #1\n");
	INSERT(b,&X);
	PrintList(X);
	printf("PRINTING 4 REAL #2\n");
	INSERT(b2,&X);
	PrintList(X); */
	return 0; 
}

