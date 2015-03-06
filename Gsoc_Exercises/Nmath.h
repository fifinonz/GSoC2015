#ifndef _NmathH_
#define _NmathH_



struct triangle {
	int x;
	int y;
	int z;
};
typedef struct triangle triangle;

struct tri_type {
	int type;
	float area;
};
typedef struct tri_type tri_type;

float mysqrt(float num);

tri_type* classify(triangle *tri1);

/**************************************************
			Custom Functions
***************************************************/

/* 1. Classify a Triangle */
tri_type *  classify(triangle *tri1)

{
		static tri_type  result;
		static tri_type *resultptr;
		float s, t; 
		int a, b, c ;

/* Assign sides to variables a,b,c */

	 a=tri1->x;
	 b=tri1->y;
	 c=tri1->z;

/* Evaluate Triangle sides */

	 if ((a + b > c && a + c > b && b + c  > a) && ( a > 0 && b > 0 && c > 0)) {
		
/* Calculate area of Triangle */

		s = (a+b+c) / 2.0;
		t =s * (s - a) * (s - b) * (s - c);
		result.area = mysqrt(t); 

/* Equilateral Triangle */
		
			if (a== b && b == c) {
				result.type =1;	 
			
						}
/* Isoceles Triangle */

				else if (a == b || b == c || a == c) {
					result.type =2;	
				
					}
/* Scalene Triangle */

				else {
						result.type =3;	
					
				}
			} /* end nested if */

/* Input not a triangle */

	else {
		result.area =0.0;			
		result.type =4;
	}
	

	
/* Return result to client */
	
	resultptr = &result;

	return resultptr;
}

/* 2. Calculate Square root */

float mysqrt(float num)
{
float i,j;
j=0.0001;


for(i=0;i<num;i=i+j)
{
if((i*i)>num)
{
i=i-j;
break;
}
}

return i;
}





#endif
 /*end _NmathH_*/
