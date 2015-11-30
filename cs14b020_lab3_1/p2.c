#include<stdio.h>
#include<string.h>
#include <stdlib.h>

void str_rev(char* s1, char *s2) {          // function that reverses string s1 and stores it in s2

	int l = strlen(s1); 
	char rev[l+1];
	int i;

	for(i=0 ; i<l ; i++) {
		rev[i] = *(s1+l-1-i) ;
	}

	rev[l] = '\0';
	strcpy(s2,rev);				
														
	return ;
}

char* str_mirror(char * s1) {            
	
	char *temp;
	temp = (char *)malloc(sizeof(s1));     // allocating memory to temp to store the reverse of s1
	str_rev(s1,temp);
										
	return strcat(s1,temp);

}

int main(int argc , char **argv) {         // input taken as command line arguments
	
	char* s1;
	s1 = argv[1];
				
	printf("%s\n",str_mirror(s1));

	return 0;
}
