/*Output a position; takes 4 arguments:
   *POS:  String that lists pieces in row major order.
   step:  The step number (ignore next two args when step=0).
   piece: Piece that moved.
   dir:   Direction that the piece moved; 0=north, 1=east, 2=south, 3=west.
   */
void OutputPosition(char *POS, int step, char piece, int dir) {
static char *DirectionString[4] = {"north", "east", "south", "west"};
int i;
printf("\nStep %d",step);
if (step>0) printf(", move %c %s",piece,DirectionString[dir]);
printf(":\n");
for (i=0; i<BoardSize; i++) {
   printf("%c",POS[i]);
   if ( (i%BoardWidth) == (BoardWidth-1) ) printf("\n"); else printf(" ");
   }
}


/*Utility function to make a positive integer into a string with commas.*/
char *MakeString(int n) {
static int block[100];
static char s[100], *x;
int i=-1, j;
do {block[++i] = n%1000; n /= 1000;} while (n>0);
sprintf(s,"%d",block[i]);
if (block[i]<10) x=s+1; else if (block[i]<100) x=s+2; else x=s+3;
for (j=(i-1); j>=0; j--) {
   if (block[j]<10) sprintf(x,",00%d",block[j]);
   else if (block[j]<100) sprintf(x,",0%d",block[j]);
   else sprintf(x,",%d",block[j]);
   x += 4;
   }
sprintf(x,"%c",'\0');
return(s);
}


/*Print queue statistics.*/
void QueueStats(int Qarray, int Qmax, int Qfront, int Qrear) {
printf("\nQueue statistics:\n");
printf("   Queue array size: %s\n", MakeString(Qarray));
printf("   Max positions ever in queue: %s\n", MakeString(Qmax));
printf("   Index of Qfront: %s\n", MakeString(Qfront));
printf("   Index of Qrear: %s\n", MakeString(Qrear));
printf("   |Qfront-Qrear| = %s\n", MakeString(abs(Qfront-Qrear)));
}


/*Print hash statistics.*/
void HashStats(int Harray, int Hcount, int Hmax) {
printf("\nHash table statistics:\n");
printf("   Hash array size: %s\n", MakeString(Harray));
printf("   No. positions in hash table: %s\n", MakeString(Hcount));
printf("   Max bucket size: %s\n", MakeString(Hmax));
printf("\nHash buckets at the end:\n");
}


/*Print number of buckets of given size.*/
/*Call this function once for each bucket size, startiing at 0 and going*/
/*   up to the maximum bucket size (the Hmax argument to HashStats).*/
void BucketStat(int Bsize, int Bcount) {
printf("   buckets of size %d = %s\n", Bsize, MakeString(Bcount));
}
