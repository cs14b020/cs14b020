#include "stack.h"

node_ptr bla;
node_ptr* head = &bla;

void instructions()  {
	printf("slect a number to do their respective operations : \n"
		   "1 . Push a character onto the stack \n"
		   "2 . pop top char from the stack assuming non empty \n"
		   "3 . check whether stack is empty \n"
		   "4 . Get the element at the top of the stack \n"
		   "Enter the operation no. to be done :  ");
	
	int n;
	scanf("%d",&n) ;
	
	switch(n) {
		
		case 1 : {
			char c;
			getchar();
			scanf("%c",&c);
			Push(head,c);
			return;
		}
		case 2 : {
			printf("the element %c got popped \n",Pop(head));
			return;
		}
		case 3 : {
			if(IsEmpty(*head))
				printf("the stack is empty\n");
			else
				printf("the stack is not empty\n");
			return;
		}
		case 4 : {			 	
			printf("the topmost element of the stack is %c \n",Top(*head));
			return;
		}
	}
		

	return;
}


void Push (struct SNode** top, char ch) {
	node_ptr new_node =(node_ptr)malloc(sizeof(s_node));
	new_node->data = ch ;
	new_node->next = NULL;
	if(*top == NULL){
		*top = new_node;
	}else {
		new_node->next = *top;
		*top = new_node;
	}
	return;
}


char Pop (struct SNode** top) {
	node_ptr new = *top;
	char a;
	a = new->data;
	node_ptr temp = new->next;
	new->next = NULL;
	free(new);
	*head = temp;
	return(a);
}

bool IsEmpty(struct SNode* top) {
	if(top == NULL)
		return 1;
	else
		return 0;		
}

char Top (struct SNode* top) {
	node_ptr new = top;
	char a;
	a = new->data;
	return(a);	
}

void print_stack(struct SNode* top) {
	node_ptr temp = top;
	while(temp != NULL) {
		printf("%c>>",temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
	return ;	
}





