#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LENGTH 20 // max length of names aand depts

struct student {
	int s_rollno ;
	char* s_name ;
	char* s_dept ;
	struct student *next_ptr;
} ;

struct student *Slist ;   // pointer to head node
struct student *Elist ;	  // pointer to end node

typedef struct student Student ;
typedef struct student* Student_Ptr ;


void instructions();
void addAtBack(char* name, int rollno, char* dept);
void addAtIndex(char* name, int rollno, char* dept, int k);
int delete(int rollno);
int getRollno(int k);
int getDept(char* dept);
void printList(Student_Ptr start);

int main() {
	instructions();
	printList(Slist);	
	printf("Do u wish to continue (enter y if yes) : ");
	char wish;
	getchar();
	scanf("\n%c",&wish);
	while(wish == 'y') {
		instructions();
		printList(Slist);
		printf("Do u wish to continue (enter y if yes) : ");
		getchar();
		scanf("%c",&wish);
	}
		
}

void instructions()  {
	printf("slect a number to do their respective operations : \n"
		   "1 . Adding a new student to the list at the back \n"
		   "2 . Adding a new student to the list at index k \n"
		   "3 . Deleting an existing student from the list with a certain rollno.\n"
		   "4 . to get rollno. of student at index k \n"
		   "5 . to get count of people of a dept \n"
		   "Enter the operation no. to be done :  ");
	
	int n;
	scanf("%d",&n) ;
	
	switch(n) {
		
		case 1 : {
			char name[MAX_LENGTH];
			char dept[MAX_LENGTH];
			int rollno;

			printf("enter name :") ; 
			scanf("%s",name);			 	
		
			printf("enter dept :") ; 
			scanf("%s",dept);			 	
			
			printf("enter rollno :") ; 
			scanf("%d",&rollno);			 	
			
			addAtBack(name,rollno,dept) ;
			return;
		}
		case 2 : {
			char name[MAX_LENGTH];
			char dept[MAX_LENGTH];
			int rollno,index;

			printf("enter name :") ; 
			scanf("%s",name);			 	
		
			printf("enter dept :") ; 
			scanf("%s",dept);			 	
			
			printf("enter rollno :") ; 
			scanf("%d",&rollno);			 	
			
			printf("enter index :") ; 
			scanf("%d",&index);			 	
			
			if(!addAtIndex(name,rollno,dept,index)) 
				printf("$$ %d added at index %d\n",rollno,index);
			return;
		}
		case 3 : {
			int rollno;

			printf("enter rollno :") ; 
			scanf("%d",&rollno);
		
			if(delete(rollno) == -1)
				printf("$$ %d couldnot be deleted\n",rollno);
			return;
		}
		case 4 : {			 	
			int index;

			printf("enter index :") ; 
			scanf("%d",&index);
		
			printf("$$ rollno at index %d is %d\n",index,getRollno(index));
			return;
		}
		case 5 : {
			char dept[MAX_LENGTH];

			printf("enter dept :") ; 
			scanf("%s",dept);
			
			printf("$$ no. of people in the dept %s are %d\n",dept,getDept(dept));
			return ;
		}
			
					
	}

	return;
}


void addAtBack(char* name, int rollno, char* dept) {
	Student_Ptr node =(Student_Ptr)malloc(sizeof(Student));
	node->s_name = (char *)malloc((strlen(name)+1)*sizeof(char)) ;
	node->s_dept = (char *)malloc((strlen(dept)+1)*sizeof(char)) ;	

	if(node!=NULL) {
		node->s_name = name ;
		node->s_rollno = rollno ;
		node->s_dept = dept ;
		node->next_ptr = NULL ;

		if(Slist == NULL) {
			Slist = node ; 
			Elist = node ;
		}else {
			Elist->next_ptr = node;
			Elist = node ;
		}
	}else {
		printf("student couldnot be added due to lack of sufficient memory \n");	
	}
	
	return ;
}

void addAtIndex(char* name, int rollno, char* dept, int k) {
	Student_Ptr node =(Student_Ptr)malloc(sizeof(Student));
	node->s_name = (char *)malloc((strlen(name)+1)*sizeof(char)) ;
	node->s_dept = (char *)malloc((strlen(dept)+1)*sizeof(char)) ;	
	
	if(node != NULL) {
		node->s_name = name ;
		node->s_rollno = rollno ;
		node->s_dept = dept ;
		node->next_ptr = NULL ;

		Student_Ptr curr = Slist ;
		Student_Ptr prev = NULL ;
		int i=1;

		while(curr != NULL && i<k) {
			prev = curr ;
			curr = curr->next_ptr;
			i++;
		}
		
		if(prev == NULL) {
			node->next_ptr = Slist ;
			Slist = node ;
		} else if(curr != NULL) {
			prev->next_ptr = node;
			node->next_ptr = curr;
		} else if(curr == NULL) {
			prev->next_ptr = node;
			Elist = node;
		}
	}else {
		printf("student couldnot be added due to lack of sufficient memory \n");
	}
	
	return ; 
}

int delete(int rollno) {
	Student_Ptr curr = Slist ;
	Student_Ptr prev = NULL;

	while(curr != NULL && curr->s_rollno != rollno) {
		prev = curr ;
		curr = curr->next_ptr;
	}

	if(curr == NULL ) {
		return -1 ;
	} else if(prev != NULL) {
		if(curr->next_ptr == NULL){
			Elist = prev;
			prev->next_ptr=NULL;
			free(curr);
			return 1;
		}
		prev->next_ptr = curr->next_ptr;
		curr->next_ptr = NULL;
		free(curr);
		return 1;	
	}else if(prev == NULL) {
		Slist = curr->next_ptr;
		curr->next_ptr = NULL;
		free(curr);
		return 1;
	}
}

int getRollno(int k) {
	int i=1 ;
1	Student_Ptr curr = Slist ;
	while(curr != NULL && i!=k){
		curr = curr->next_ptr;
		i++;
	}	
	return(curr->s_rollno) ;
}

int getDept(char* dept) {
	int count=0 ;
	Student_Ptr curr = Slist ;
	while(curr != NULL ){
		if(strcmp(dept,curr->s_dept) == 0)
			count++;
		curr = curr->next_ptr;
	}	
	return(count) ;

}

void printList(Student_Ptr start) {
	Student_Ptr temp = start;
	while(temp != NULL) {
		printf("%d->",temp->s_rollno);
		temp = temp->next_ptr;	
	}
	printf("NULL\n");
}
