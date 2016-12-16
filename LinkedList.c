//christa caggiano 
//cs21a P0 
//25 Oct 2016

#include <stdio.h>
#include <stdlib.h>


//define vertex structure, from github code Lists.c
//change type from char to int 
typedef struct vbody {
   struct vbody *NEXT;
   int DATA;
} *TypeVertex;

//defines first vertex in new list from github code Lists.c 
typedef TypeVertex TypeList;

//allocates memory new vertex type, from Lists.c
TypeVertex NEWVERTEX() {
    TypeVertex p = (TypeVertex) malloc(sizeof(struct vbody));
    if (p==NULL) {printf("Malloc for a new vertex failed."); exit(1);}
    return p;
}

//creates empty list, from Lists.c
TypeList X=NULL;

//inserts new vertex to back of list if the next vertex is not NULL 
//changed from char to int
void INSERT(int c, TypeVertex v, TypeList *L) {
    TypeVertex w = NEWVERTEX();
    w->DATA = c;

    if (v==NULL) {
       w->NEXT = *L;
       *L = w;
       }
    else {
       w->NEXT = v->NEXT;
       v->NEXT = w;
       }
}

//prints linked list, from Lists.c
//modified so it doesn't print out vertex number 
void PrintList(TypeList L) {
    TypeVertex v;
    for (v=L; v!=NULL; v = v->NEXT) printf("%d\n",v->DATA);
}

int main() {

    TypeVertex v;
    
    //decides if user wants to keep entering linked lists, which they probably 
    //do because this is the most fun a gal could have 
   	int user_loves_linked_lists = 1;

   	//intializes a char array so the user can input their numbers. hopefully their numbers are less
   	//than 30 places
   	char user_input[30];

   	//intializes a check to see if the user inputs a blank line right off the bat
   	int isEmpty = 9; 

   	//friendily greets the user. C is polite 
   	printf("Hello. \n"); 
   
    //while the user wants to input a linked list, this block of code first checks if the 
   	//user entered a blank line to begin. It then compares the values that the user inputs 
   	//while by being pretty annoying and having to convert the string the user inputted into 
   	//an int. If the value they entered is greater than anything else on the list, it is entered 
   	//at the end. 
   	while (user_loves_linked_lists == 1){
	   	if(*user_input == '\n') { 
	   		printf("List is empty.");
	   	} else { 

	   		printf("\nINPUT LIST (one integer per line followed by an empty line): \n");
	   		fgets(user_input, 30, stdin); 
   			v=X;

   			isEmpty = 1; 

		    while (1) {

		    	if(*user_input == '\n') break;
		    	isEmpty = 0; 

		    	int user_input_int = atoi(user_input); 

          		TypeVertex last_v = NULL;
		    	while ( (v!=NULL) && (user_input_int>=(v->DATA)) ){
		    		last_v = v;
		    		v = v->NEXT;
		    	} 
		    	INSERT(user_input_int,last_v,&X);
		    	v=X; 

		    	fgets(user_input, 30, stdin);     	
		    }
		}

		//the list is printed, but if it is empty, the user is curtly 
		//informed of this 
		printf("\nSorted List:\n"); 
    	if (isEmpty == 1) {
    		printf("List is Empty."); 
    		printf("\n");
    	} else {
			PrintList(X);
    		printf("\n");
    	}

    	//checks if the user wants to keep the fun rolling 
		printf("Do you want to sort another list? Enter Y/N \n"); 
		fgets(user_input, 30, stdin);
		if (*user_input=='n'||*user_input=='N'){
			break;
		}
		else{
			user_loves_linked_lists = 1; //continue
		}     	
		
		X = NULL; 
	}

	//bye! thanks for reading these comments
	printf("Goodbye. \n"); 
	
	//returns a zero, because, C. 
    return 0;
}

