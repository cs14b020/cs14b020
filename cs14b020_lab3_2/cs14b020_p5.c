#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct vertex {
    int vertex_no;
    float x_coordinate;
    float y_coordinate;
	bool config;// wether it is convex or concave at that point config is 1 when >180 and 0 when <180 at that point
};

//function that finds the array index of vertce with max x coordinate and storesit to variable pointed by i
void max_x_coordinate(struct vertex* polygon,int n,int* i);

int main() {
	int n;
    scanf("%d\n",&n);
    struct vertex polygon[n];
    int i;
    for( i=0 ; i<n ; i++) {
        scanf("%d %f %f",&polygon[i].vertex_no,&polygon[i].x_coordinate,&polygon[i].y_coordinate);
    }
	i=0;
	max_x_coordinate(polygon,n,&i);

	float x1 = (i != 0) ? polygon[i-1].x_coordinate : polygon[n-1].x_coordinate ;//vertex preciding the max x vertex
	float y1 = (i != 0) ? polygon[i-1].y_coordinate : polygon[n-1].y_coordinate ;
	float x2 = polygon[i].x_coordinate;											 //vertex of max vertex
	float y2 = polygon[i].y_coordinate;												
	float x3 = (i != n-1) ? polygon[i+1].x_coordinate : polygon[0].x_coordinate ;//vertex succeding the max x vertex
	float y3 = (i != n-1) ? polygon[i+1].y_coordinate : polygon[0].y_coordinate ;

	int cmp = ((x2-x1)*(y3-y2)-(x3-x2)*(y2-y1)) ; // std to compare all the vertex as vertex with max x has angle<180
	
	int count = 0; // count for angles > 180 degrees
	for(i=0 ; i<n ; i++) {
		x1 = (i != 0) ? polygon[i-1].x_coordinate : polygon[n-1].x_coordinate ;
		y1 = (i != 0) ? polygon[i-1].y_coordinate : polygon[n-1].y_coordinate ;
		x2 = polygon[i].x_coordinate;
		y2 = polygon[i].y_coordinate;
		x3 = (i != n-1) ? polygon[i+1].x_coordinate : polygon[0].x_coordinate ;
		y3 = (i != n-1) ? polygon[i+1].y_coordinate : polygon[0].y_coordinate ;

//vertex with cross product of incident sides same sign as of max vertex has <180 and opp sign >180		
		if(((x2-x1)*(y3-y2)-(x3-x2)*(y2-y1))*cmp < 0){
			polygon[i].config = 1;	
			printf("%d\n",i+1); 
			count++;
		}
	}

	if(count == 0)
		printf("0\n");

	return 0;

}


void max_x_coordinate(struct vertex* polygon,int n,int* i) {
	int j=0;
	int max = polygon[0].x_coordinate;

	for(j=0;j<n;j++) {
		if(max < polygon[j].x_coordinate){
			max = polygon[j].x_coordinate;
			*i = j;	
		}	
	}

	return;

}














