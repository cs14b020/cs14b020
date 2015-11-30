/**
// finds the reflection of the point (x1,y1) in the line joined by (x2,y2);(x3,y3) and stores it in (ref_x,ref_y)
void reflection(float x1,float y1,float x2,float y2,float x3,float y3,float ref_x,float ref_y) {
	float a,b,c;
	a = y3 - y2 ;
	b = x2 - x3 ;
	c = x3*y2 - x2*y3;

	float d;
	d = -(a*x1+b*y1+c)/(a*a+b*b);

	ref_x = a*d + x1;
	ref_y = b*d + y1;

	return;
} 


float total_angle(int i, struct vertex* polygon,int n,float x,float y) {
	int j;
	float sum = 0;
	for(j=0;j<n;j++){
		if(j != i) {		
			float det;
			float dot;

			float x1 = polygon[j].x_coordinate;
			float y1 = polygon[j].y_coordinate;

			if(j != n-1) {
				float x2 = (j != i-1) ? polygon[j+1].x_coordinate : polygon[j+2].x_coordinate ;
				float y2 = (j != i-1) ? polygon[j+1].y_coordinate : polygon[j+2].y_coordinate ;
			}else {
				float x2 = (i != 0) ? polygon[0].x_coordinate : polygon[1].x_coordinate ;
				float y2 = (i != 0) ? polygon[0].y_coordinate : polygon[1].y_coordinate ;
				
	
			dot = (x1-x)(x2-x)+(y1-x)(y2-y);
			det = (x1-x)(y2-y)-(x2-x)(y1-y);

			sum += atan2(det,dot);
		}
	}

	return sum;
}

void find_config(int i,struct vertex* polygon,int n) {
	float ref_x,ref_y;
	float x1 = polygon[i].x_coordinate;
	float y1 = polygon[i].y_coordinate;

	if( i !=0 && i != n-1) {
		float x2 = polygon[i-1].x_coordinate;
		float y2 = polygon[i-1].y_coordinate;
		float x3 = polygon[i+1].x_coordinate;
		float y3 = polygon[i+1].y_coordinate;
		reflection( x1, y1, x2, y2, x3, y3, ref_x, ref_y);			
	}else if(i == 0){
		float x2 = polygon[n-1].x_coordinate;
		float y2 = polygon[n-1].y_coordinate;
		float x3 = polygon[i+1].x_coordinate;
		float y3 = polygon[i+1].y_coordinate;
		reflection( x1, y1, x2, y2, x3, y3, ref_x, ref_y);			
	}else if(i == n-1){
		float x2 = polygon[i-1].x_coordinate;
		float y2 = polygon[i-1].y_coordinate;
		float x3 = polygon[0].x_coordinate;
		float y3 = polygon[0].y_coordinate;
		reflection( x1, y1, x2, y2, x3, y3, ref_x, ref_y);			
	}

	if( fabs(fabs(total_angle(i,polygon,n,x1,y1))-2*PI) < 0.001 ) {
		polygon[i].config = 1;
	}
}
**/


