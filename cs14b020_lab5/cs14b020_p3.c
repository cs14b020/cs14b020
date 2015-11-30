#include"stack.h"

#define MAX_LENGTH 1000

struct position {
	int x;	
	int y;
};

struct position FinalPosition (char* s);

int main() {
	char  a[MAX_LENGTH];
	scanf("%s",a);
	printf("(%d,%d)\n",FinalPosition (a).x,FinalPosition (a).y);
	return 0;
}


struct position FinalPosition (char* s) {
	struct position cood;
	cood.x = 0;
	cood.y = 0;
	int l=strlen(s);
	int i;

	for(i=0;i<l;i++) {
		if(s[i] == 'L' || s[i] == 'R' || s[i] == 'U' || s[i] == 'D')
			Push(head,s[i]);
		else if(s[i] == 'B') {
			i++;
			int v=0;
			int j=0;
			int t=0;
			while((s[i] <= '9' && s[i] >= '0')) {
				j = s[i] - 48;
				v = 10*v + j;
				i++;
				t++;
			}
			i--;
			if(v>i-t)
				return cood;
			for( j=0 ; j<v ; j++)
				Pop(head);
		}
	}

	if(bla == NULL)
		return cood;
	
	while(bla != NULL) {

		if(bla->data == 'R') {
			cood.x++;
		}else if(bla->data == 'L') {
			cood.x--;			
		}else if(bla->data == 'U') {
			cood.y++;
		}else if(bla->data == 'D') {
			cood.y--;
		}
		
		Pop(head);
	} 

	return cood;
}
