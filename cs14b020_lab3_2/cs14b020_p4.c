#include<stdio.h>


int sum(int *ptr1 , int *ptr2) {
	
	int *left,*right;
	if(ptr1 < ptr2) {      // left points to leftmost && right points to rightmost
		left=ptr1;
		right=ptr2;
	} else {
		left=ptr2;
		right=ptr1;		
	}
	int sum=0;
	
	if(left == right)		// if both pointers point to same element then just element is returned
		return(*left);
	do {
		sum = sum + *(left);
		left++ ;
	} while(left != right);
	
	sum += *(right);
	
	return sum ;
}

int main() {
	int i,j,k,n;
	scanf("%d",&n);
	int a[n];

	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	scanf("%d %d",&j,&k);

	printf("%d\n",sum(&a[j],&a[k]));

	return 0;
}

