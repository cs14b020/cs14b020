/** 
	Write a function to count the number of occurrences of string s 2 in a given string s 1 . Your function
	should have the following signature:

	• int strstrN(char* s1, char* s2)

	For example, strstrN when invoked with parameters (aaabbbaa, aa) returns 3 whereas when invoked
	with parameters (aaabbbaa, aab) returns 1.  

**/


#include<stdio.h>
#include<string.h>

int strstrN(char* s1 , char* s2) {

	int l1 = strlen(s1);
	int l2 = strlen(s2);
	int count = 0;
	int i;

	for(i=0;i <= l1-l2 ; i++) {
		if(!strncmp(s1+i,s2,l2))
			count++;
	}

	return count;

}

int main(int argc , char **argv) {

	char *s1,*s2;											// input taken as command line arguments
	s1 = argv[1];
	s2 = argv[2];

	printf("%d\n",strstrN(s1,s2));
 
	return 0;
}
