#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct point
{
	double x,y;
	bool isInConvexHull;
};
typedef struct point point;

/*********************************************************************************************************************************/ 
void printPoints(point parr[], int size)
{
	printf("These are the points:\n");
	printf("X-coord\t\tY-coord\t\tIsInConvexHull?\n");
	for(int i=0;i<size;i++)
	{
		printf("%lf\t%lf\t%d\n",parr[i].x,parr[i].y,parr[i].isInConvexHull);
	}
}
/*********************************************************************************************************************************/
/*this function finds whether point whoseTofind is clockwise or counterclockwise from point
  withRespectTo using the pivot pivot
            .(withRespectTo)  
           /
  	  /    .(whoseToFind)
  	 /
  	/
       .(pivot)     in this example, whoseToFind is clockwise from withRespectTo

  this function return 1 if whoseToFind is clockwise, -1 if anticlockwise and 0 if collinear
*/
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
//below four functions are recursive function for finding candidate points of the convex hull in the four p-rects
void bottomLeftOperation(point* sortedAccToX, point* sortedAccToY, point* parr, point BL_xmin, point BL_ymin)
{
}
void bottomRightOperation(point* sortedAccToX, point* sortedAccToY, point* parr, point BR_ymin, point BR_xmax)
{
}
void topLeftOperation(point* sortedAccToX, point* sortedAccToY, point* parr, point TL_xmin, point TL_ymax)
{
}
void topRightOperation(point* sortedAccToX, point* sortedAccToY, point* parr, point TR_ymax, point TR_xmax)
{
}
//below two functions are just the comparator functions needed for the qsort function used in findConvexHull()
int comparatorx(const void *p, const void *q)
{
	double l=((struct point *)p)->x;
	double r=((struct point *)q)->x;
	if((int)(l-r)==0)
	{
		return (int)((((struct point *)p)->y)-(((struct point *)q)->y));
	}
	return(int)(l-r);
}
int comparatory(const void *p, const void *q)
{
	double l=((struct point*)p)->y;
	double r=((struct point*)q)->y;
	if((int)(l-r)==0)
	{
		return (int)((((struct point *)p)->x)-(((struct point *)q)->x));
	}
	return(int)(l-r);
}
//the below function when executed will alter the isInConvexHull flag of each element in parr
void findConvexHull(point* parr, int size)
{
	point  BL_xmin, BL_ymin, BR_ymin, BR_xmax, TL_xmin, TL_ymax, TR_ymax, TR_xmax;
	bool areThereManyXmin=false,areThereManyYmin=false,areThereManyXmax=false,areThereManyYmax=false;	//these boolean flags store whether there are more than one point with same extreme x or y coordinate
	point* sortedAccToX=(point*)malloc(sizeof(point)*size);	//the below two pointers will store two different 
	point* sortedAccToY=(point*)malloc(sizeof(point)*size);
	//the below code is all about sorting the two arrays pointed by sortedAccToX and sortedAccToY according to x and y coordinates
	for(int i=0;i<size;i++)
	{
		sortedAccToX[i]=parr[i];
		sortedAccToY[i]=parr[i];
	}
	qsort((void*)sortedAccToX,size,sizeof(point),comparatorx);
	qsort((void*)sortedAccToY,size,sizeof(point),comparatory);
	printPoints(sortedAccToX,size);
	printPoints(sortedAccToY,size);
}
/*********************************************************************************************************************************/
int main()
{
	point* points;
	int numberOfPoints;
	printf("Enter the number of points:\t");
	scanf("%d",&numberOfPoints);
	points=(point*)malloc(sizeof(point)*numberOfPoints);
	printf("Enter the x and y coordinates of the points now:\n");
	for(int i=0;i<numberOfPoints;i++)
	{
		scanf("%lf%lf",&points[i].x,&points[i].y);
		points[i].isInConvexHull=false;
	}
	printPoints(points,numberOfPoints);
	/*point* aa=sortPointsByXCoord(points,numberOfPoints);
	printf("\n\n");
	printPoints(aa,numberOfPoints);
	point* bb=sortPointsByYCoord(points,numberOfPoints);
	printf("\n\n");
	printPoints(bb,numberOfPoints);*/
	findConvexHull(points,numberOfPoints);
}
