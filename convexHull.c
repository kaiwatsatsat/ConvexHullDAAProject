#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct point
{
	int x,y;
	bool isInConvexHull;
};
typedef struct point point;

point* points;
int numberOfPoints;

/*****************************This segment of the program has all the sorting functions*******************************************/
int comparator(const void *p, const void *q)
{
	int l=((struct point *)p)->x;
	int r=((struct point *)q)->x;
	return(int)(l-r);
}
point* sortPointsByXCoord(point* parr, int size)
{
	//printf("Inside sorter\n");
	point* temp=(point*)malloc(sizeof(point)*size);
	for(int i=0;i<size;i++)
	{
		temp[i]=parr[i];
	}
	//printf("now exec qsort\n");
	qsort((void*)temp,size,sizeof(point),comparator);
	return temp;
	//return 0;
}
int comparatory(const void *p, const void *q)
{
	int l=((struct point*)p)->y;
	int r=((struct point*)q)->y;
	return(int)(l-r);
}
point* sortPointsByYCoord(point* parr, int size)
{
	point *temp=(point*)malloc(sizeof(point)*size);
	for(int i=0;i<size;i++)
	{
		temp[i]=parr[i];
	}
	qsort((void*)temp,size,sizeof(point),comparatory);
	return temp;
} 
/*********************************************************************************************************************************/

void printPoints(point parr[], int size)
{
	printf("These are the points:\n");
	printf("X-coord\t\tY-coord\t\tIsInConvexHull?\n");
	for(int i=0;i<size;i++)
	{
		printf("%d\t%d\t%d\n",parr[i].x,parr[i].y,parr[i].isInConvexHull);
	}
}
/*********************************************************************************************************************************/
//this function finds whether point whoseTofind is clockwise or counterclockwise from point
//withRespectTo using the pivot pivot
//          .(withRespectTo)  
//         /
//	  /    .(whoseToFind)
//	 /
//	/
//     .(pivot)     in this example, whoseToFind is clockwise from withRespectTo
//
//this function return 1 if whoseToFind is clockwise, -1 if anticlockwise and 0 if collinear
int findRotation(point pivot, point withRespectTo, point whoseToFind)  
{
	double D=((withRespectTo.x-pivot.x)*(whoseToFind.y-pivot.y))-((withRespectTo.y-pivot.y)*(whoseToFind.x-pivot.x));
	if(D==0)
		return 0;	
	else if(D<0)
		return 1;	
	else
		return -1;	
}
/*********************************************************************************************************************************/
int main()
{
	printf("Enter the number of points:\t");
	scanf("%d",&numberOfPoints);
	points=(point*)malloc(sizeof(point)*numberOfPoints);
	printf("Enter the x and y coordinates of the points now:\n");
	for(int i=0;i<numberOfPoints;i++)
	{
		scanf("%d%d",&points[i].x,&points[i].y);
		points[i].isInConvexHull=false;
	}
	printPoints(points,numberOfPoints);
	point* aa=sortPointsByXCoord(points,numberOfPoints);
	printf("\n\n");
	printPoints(aa,numberOfPoints);
	point* bb=sortPointsByYCoord(points,numberOfPoints);
	printf("\n\n");
	printPoints(bb,numberOfPoints);
}
