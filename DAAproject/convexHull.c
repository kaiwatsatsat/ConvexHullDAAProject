#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "DAAproject.h"
#include "mystack.c"
#include "utilfinctions.c"

/*****            These are the utility functions defined in utilfinctions.h******************************************************* 
1)->  void printPoints(point parr[], int size);
///////////////
2)->  int findRotation(point pivot, point withRespectTo, point whoseToFind);
this function finds whether point whoseTofind is clockwise or counterclockwise from point withRespectTo using the pivot pivot
            .(withRespectTo)  
           /
  	  /    .(whoseToFind)
  	 /
  	/
       .(pivot)     in this example, whoseToFind is clockwise from withRespectTo
this function return 1 if whoseToFind is clockwise, -1 if anticlockwise and 0 if collinear
*********************************************************************************************************************************/
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
	point  BL_xmin, BL_ymin, BR_ymin, BR_xmax, TL_xmin, TL_ymax, TR_ymax, TR_xmax,temp;
	double tempy;
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
	BL_xmin=sortedAccToX[0];
	BL_ymin=sortedAccToY[0];
	BR_ymin=sortedAccToY[0];
	for(int i=1;i<size;i++)
	{
		if(sortedAccToY[i].y==BR_ymin.y)
		{
			BR_ymin=sortedAccToY[i];
			continue;
		}
		break;
	}
	BR_xmax=sortedAccToX[size-1];
	for(int i=size-2;i>=0;i--)
	{
		if(sortedAccToX[i].x==BR_xmax.x)
		{
			BR_xmax=sortedAccToX[i];
			continue;
		}
		break;
	}
	TL_xmin=sortedAccToX[0];
	for(int i=1;i<size;i++)
	{
		if(sortedAccToX[i].x==TL_xmin.x)
		{
			TL_xmin=sortedAccToX[i];
			continue;
		}
		break;
	}
	TL_ymax=sortedAccToY[size-1];
	for(int i=size-2;i>=0;i--)
	{
		if(sortedAccToY[i].y==TL_ymax.y)
		{
			TL_ymax=sortedAccToY[i];
			continue;
		}
		break;
	}
	TR_ymax=sortedAccToY[size-1];
	TR_xmax=sortedAccToX[size-1];
	printf("\n\n");
	printf("BL_xmin->\t%lf\t%lf\n",BL_xmin.x,BL_xmin.y);
	printf("BL_ymin->\t%lf\t%lf\n",BL_ymin.x,BL_ymin.y);
	printf("BR_ymin->\t%lf\t%lf\n",BR_ymin.x,BR_ymin.y);
	printf("BR_xmax->\t%lf\t%lf\n",BR_xmax.x,BR_xmax.y);
	printf("TR_xmax->\t%lf\t%lf\n",TR_xmax.x,TR_xmax.y);
	printf("TR_ymax->\t%lf\t%lf\n",TR_ymax.x,TR_ymax.y);
	printf("TL_ymax->\t%lf\t%lf\n",TL_ymax.x,TL_ymax.y);
	printf("TL_xmin->\t%lf\t%lf\n",TL_xmin.x,TL_xmin.y);

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
	findConvexHull(points,numberOfPoints);
}
