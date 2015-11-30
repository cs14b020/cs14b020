#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>


struct SNode {
	char data;
	struct SNode* next;
};

typedef struct SNode s_node;
typedef struct SNode* node_ptr;

extern node_ptr bla;
extern node_ptr* head;

void instructions();
void print_stack(struct SNode* top);
void Push (struct SNode** top, char ch) ;                            //This function pushes character ch to the stack.
char Pop (struct SNode** top);							//This function pops top character from the stack. Assume stack is not empty.
bool IsEmpty(struct SNode* top);                                      //This function checks whether stack is empty.
char Top (struct SNode* top);                            //This function returns top element of stack. Assume stack is not empty.

