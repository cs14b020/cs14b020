#include"stack.h"

#define MAX_LENGTH 1000


bool IsBalanceParanthesis (char* s);
bool IsOpenBrace(char a);
bool IsCloseBrace(char a);
bool AreMatchingBraces(char a,char b);

int main() {
	char  a[MAX_LENGTH];
	scanf("%s",a);
	
	if(IsBalanceParanthesis (a))
		printf("BALANCED\n");
	else
		printf("not Balanced\n");
	return 0;
}


bool IsBalanceParanthesis (char* s) {
	char* temp = s;
	int l = strlen(s);
	int j;
	for(j=0;j<l;j++) {
		if(IsOpenBrace(temp[j])) {
			Push(head,temp[j]);
		}else if(IsCloseBrace(temp[j])) {
			if(head == NULL) {
				return 0;
			}else if(!AreMatchingBraces(bla->data,temp[j])) {
				return 0;
			}else if(AreMatchingBraces(bla->data,temp[j])) {
				Pop(head);
			}
	
		}
	}
	
	if(IsEmpty(bla))
		return 1;	
}


bool IsOpenBrace(char a) {
	if(a == '(' || a == '[' || a == '{')
		return 1;
	else
		return 0;
}

bool IsCloseBrace(char a) {
	if(a == ')' || a == '}' || a == ']')
		return 1;
	else
		return 0;
}

bool AreMatchingBraces(char a,char b) {
	if( a == '[' ) {
		if( b == ']' )
			return 1;
		else
			return 0;
	}

	if( a == '(' ) {
		if( b == ')' )
			return 1;
		else
			return 0;
	}

	if( a == '{' ) {
		if( b == '}' )
			return 1;
		else
			return 0;
	}

}

