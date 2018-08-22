#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include"structdeclare.h"
#include"utilfunctions.c"
#include"mystack.c"
int comparatorx(const void *p,const void *q)
{
	double l=((point *)p)->x;
	double r=((point *)q)->x;
	double a=((point *)p)->y;
	double b=((point *)q)->y;
	if(l>r)
		return 1;
	else if(l<r)
		return -1;
	else
	{
		if(a>b)
			return 1;
		else if(a<b)
			return -1;
		else{}
	}
}	
int orientation(point p, point q, point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
 
    if (val == 0) return 0;  // colinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}


int comparatory(const void *p,const void *q)
{
	double l=((point *)p)->y;
	double r=((point *)q)->y;
	double a=((point *)p)->x;
	double b=((point *)q)->x;
	if(l>r)
		return 1;
	else if(l<r)
		return -1;
	else
	{
		if(a>b)
			return 1;
		else if(a<b)
			return -1;
		else{}
	}
}

//bottomleftoperation
void bottomLeftOperation(point *sortedAccToX,point *sortedAccToY,int size,point BL_Xmin,point BL_Ymin)
{ 
	int i;
	point BL_Xmin2= {0}, BL_Ymin2 = {0};
	for(i=0;i<size;i++)
	{
		if(sortedAccToX[i].x>BL_Xmin.x && sortedAccToX[i].x< BL_Ymin.x && sortedAccToX[i].y>BL_Ymin.y && sortedAccToX[i].y< BL_Xmin.y)
		{
			BL_Xmin2=sortedAccToX[i];
			break;
		}
	}
	for(i=0;i<size;i++)
	{
		if(sortedAccToY[i].x>BL_Xmin.x && sortedAccToY[i].x< BL_Ymin.x && sortedAccToY[i].y>BL_Ymin.y && sortedAccToY[i].y< BL_Xmin.y)
		{
			BL_Ymin2=sortedAccToY[i];
			break;
		}
	}
	if(BL_Xmin2.x==EmptyStruct.x && BL_Ymin2.x==EmptyStruct.x && BL_Xmin2.y==EmptyStruct.y &&  BL_Ymin2.y==EmptyStruct.y)
	{
		return;
	}
	else if(BL_Xmin2.x == BL_Ymin2.x && BL_Xmin2.y == BL_Ymin2.y)
	{
		int D=findRotation(BL_Xmin2,BL_Xmin,BL_Ymin);
		if(D<=0)
		{
			push(BL_Xmin2);
			return;
		}
	}
	else if(BL_Xmin2.x != BL_Ymin2.x || BL_Xmin2.y != BL_Ymin2.y)
	{
		int xmin2rotvalue=findRotation(BL_Xmin2,BL_Xmin,BL_Ymin);
		int ymin2rotvalue=findRotation(BL_Ymin2,BL_Xmin,BL_Ymin);
		if(xmin2rotvalue ==1 && ymin2rotvalue ==1)
		{
			return;
		}
		else if((xmin2rotvalue<=0 && ymin2rotvalue==1)||(xmin2rotvalue==1 && ymin2rotvalue<=0))
		{
			if(xmin2rotvalue<=0) 
			{
				push(BL_Xmin2);
			}
			else if(ymin2rotvalue<=0) 
			{
				push(BL_Ymin2);
			}
			else{}
			return;
		}
		else if(xmin2rotvalue <=0 && ymin2rotvalue <=0)
		{
			push(BL_Xmin2);
			push(BL_Ymin2);
			bottomLeftOperation(sortedAccToX,sortedAccToY,size,BL_Xmin2,BL_Ymin2);
		}
		else{}
	}
	else{}   
}

//bottomright  
void bottomRightOperation(point *sortedAccToX,point *sortedAccToY,int size,point BR_Xmax,point BR_Ymin)
{ 
	int i;
	point BR_Ymin2={0},BR_Xmax2={0};
	for(i=0;i<size;i++)
	{
		if(sortedAccToY[i].x>BR_Ymin.x && sortedAccToY[i].x<BR_Xmax.x && BR_Ymin.y<sortedAccToY[i].y && sortedAccToY[i].y<BR_Xmax.y)
		{
			BR_Ymin2=sortedAccToY[i];
			break;
		}
	}
	for(i=size-1;i>=0;i--)
	{
		if(sortedAccToX[i].x>BR_Ymin.x && sortedAccToX[i].x<BR_Xmax.x && BR_Ymin.y<sortedAccToX[i].y && sortedAccToX[i].y<BR_Xmax.y)
		{
			BR_Xmax2=sortedAccToX[i];
			break;
		}
	}
	if(BR_Ymin2.x==EmptyStruct.x && BR_Xmax2.x==EmptyStruct.x && BR_Ymin2.y==EmptyStruct.y && BR_Xmax2.y==EmptyStruct.y)
	{
		return;
	}
	else if(BR_Ymin2.x==BR_Xmax2.x && BR_Ymin2.y==BR_Xmax2.y )
	{
		int D=findRotation(BR_Xmax2,BR_Ymin,BR_Xmax);
		if(D<=0)
		{
			push(BR_Xmax2);
			return;
		}
	}
	else if(BR_Ymin2.x!=BR_Xmax2.x || BR_Ymin2.y!=BR_Xmax2.y)
	{
		int xmax2rotvalue=findRotation(BR_Xmax2,BR_Ymin,BR_Xmax);
		int ymin2rotvalue=findRotation(BR_Ymin2,BR_Ymin,BR_Xmax);
		if(xmax2rotvalue ==1 && ymin2rotvalue ==1)
		{
			return;
		}
		else if((xmax2rotvalue ==1 && ymin2rotvalue<=0)|| (ymin2rotvalue ==1 && xmax2rotvalue<=0))
		{
			//add to convex hull set
			if(xmax2rotvalue<=0)
			{
				push(BR_Xmax2);
			}
			else if(ymin2rotvalue<=0)
			{
				push(BR_Ymin2);
			}
			else{}
			return;
		}
		else if(xmax2rotvalue <=0 && ymin2rotvalue <=0)
		{ 
			push(BR_Xmax2);
			push(BR_Ymin2);
			bottomRightOperation(sortedAccToX,sortedAccToY,size,BR_Xmax2,BR_Ymin2);
		}
		else{}
	}
	else{}   
}

//topright
void topRightOperation(point *sortedAccToX,point *sortedAccToY,int size,point TR_Xmax,point TR_Ymax)
{
	int i;
	point TR_Xmax2={0},TR_Ymax2={0};
	for(int i=size-1;i>=0;i--)
	{
		if(sortedAccToX[i].x>TR_Ymax.x && sortedAccToX[i].x<TR_Xmax.x && TR_Xmax.y<sortedAccToX[i].y  && sortedAccToX[i].y<TR_Ymax.y)
		{
			TR_Xmax2=sortedAccToX[i];
			break;
		}
	}
	for(int i=size-1;i>=0;i--)
	{
		if(sortedAccToY[i].x>TR_Ymax.x && sortedAccToY[i].x<TR_Xmax.x && TR_Xmax.y<sortedAccToY[i].y  && sortedAccToY[i].y<TR_Ymax.y)
		{
			TR_Ymax2=sortedAccToY[i];
			break;
		}
	}
	if(TR_Ymax2.x==EmptyStruct.x && TR_Xmax2.x==EmptyStruct.x && TR_Ymax2.y==EmptyStruct.y && TR_Xmax2.y==EmptyStruct.y)
	{
		return;
	}
	else if(TR_Ymax2.x==TR_Xmax2.x && TR_Xmax2.y==TR_Ymax2.y)
	{
		int D=findRotation(TR_Xmax2,TR_Xmax,TR_Ymax);
		if(D<=0)
		{
			//add to convex hull set
			push(TR_Xmax2);
			return;
		}
	}
	else if(TR_Ymax2.x!=TR_Xmax2.x || TR_Xmax2.y!=TR_Ymax2.y)
	{
		int xmax2rotvalue=findRotation(TR_Xmax2,TR_Xmax,TR_Ymax);
		int ymax2rotvalue=findRotation(TR_Ymax2,TR_Xmax,TR_Ymax);
		if(xmax2rotvalue ==1 && ymax2rotvalue ==1)
		{
			return;
		}
		else if((xmax2rotvalue<=0 && ymax2rotvalue==1) || (xmax2rotvalue ==1 && ymax2rotvalue<=0))
		{
			//add to convex hull set
			if(xmax2rotvalue<=0) 
			{
				push(TR_Xmax2);
			}
			else if(ymax2rotvalue<=0) 
			{
				push(TR_Ymax2);
			}
			else{}
			return;
		}
		else if(xmax2rotvalue <=0 && ymax2rotvalue <=0)
		{
			push(TR_Xmax2);
			push(TR_Ymax2);
			topRightOperation(sortedAccToX,sortedAccToY,size,TR_Xmax2,TR_Ymax2);
		}
		else{}  
	}
	else{} 
}

//topleft
void topLeftOperation(point *sortedAccToX,point *sortedAccToY,int size,point TL_Xmin,point TL_Ymax)
{
	int i;
	point TL_Xmin2={0},TL_Ymax2={0};
	for(int i=0;i<size;i++)
	{
		if(sortedAccToX[i].x>TL_Xmin.x && sortedAccToX[i].x<TL_Ymax.x && TL_Xmin.y<sortedAccToX[i].y && sortedAccToX[i].y<TL_Ymax.y)
		{
			TL_Xmin2=sortedAccToX[i];
			break;
		}
	}
	for(int i=size-1;i>=0;i--)
	{
		if(sortedAccToY[i].x>TL_Xmin.x && sortedAccToY[i].x<TL_Ymax.x && TL_Xmin.y<sortedAccToY[i].y && sortedAccToY[i].y<TL_Ymax.y)
		{
			TL_Ymax2=sortedAccToY[i];
			break;
		}
	}
	if(TL_Ymax2.x==EmptyStruct.x && TL_Xmin2.x==EmptyStruct.x && TL_Ymax2.y==EmptyStruct.y && TL_Xmin2.y==EmptyStruct.y)
	{
		return;
	}
	else if(TL_Ymax2.x==TL_Xmin2.x && TL_Ymax2.y==TL_Xmin2.y )
	{
		int D=findRotation(TL_Xmin2,TL_Ymax,TL_Xmin);
		if(D<=0)
		{
			//add to convex hull set
			push(TL_Xmin2);
			return;
		}
	}
	else if(TL_Ymax2.x!=TL_Xmin2.x || TL_Ymax2.y!=TL_Xmin2.y )
	{
		int xmin2rotvalue=findRotation(TL_Xmin2,TL_Ymax,TL_Xmin);
		int ymax2rotvalue=findRotation(TL_Ymax2,TL_Ymax,TL_Xmin);
		if(xmin2rotvalue ==1 && ymax2rotvalue ==1)
		{
			return;
		}
		else if((xmin2rotvalue==1 && ymax2rotvalue<=0)||(xmin2rotvalue<=0 && ymax2rotvalue ==1))
		{
			//add to convex hull set
			if(xmin2rotvalue<=0)
			{
				push(TL_Xmin2);
			}
			else if(ymax2rotvalue<=0) 
			{
				push(TL_Ymax2);
			}
			else{}
			return;
		}
		else if(xmin2rotvalue <=0 && ymax2rotvalue <=0)
		{
			push(TL_Xmin2);
			push(TL_Ymax2);
			topLeftOperation(sortedAccToX,sortedAccToY,size,TL_Xmin2,TL_Ymax2);
		}
		else{}
	}
	else{}   
}

void findConvexHull(point *parr, int size)
{
	point BL_Xmin,BL_Ymin,BR_Ymin,BR_Xmax,TL_Xmin,TL_Ymax,TR_Xmax,TR_Ymax;
	point *sortedAccToX=(point *)malloc(size*sizeof(point));
	point *sortedAccToY=(point *)malloc(size*sizeof(point));
	for(int i=0;i<size;i++)
	{
		sortedAccToX[i]=parr[i];
		sortedAccToY[i]=parr[i];
	}
	qsort((void *)sortedAccToX,size,sizeof(point),comparatorx);
	qsort((void *)sortedAccToY,size,sizeof(point),comparatory);
	printf("These are the points sorted acc to x coord:\n");
//	printPoints(sortedAccToX,size);
	printf("These are the points sorted acc to y coord:\n");
//	printPoints(sortedAccToY,size);
 	initStack(size);	
	BL_Xmin=sortedAccToX[0];
	BL_Ymin=sortedAccToY[0];
	TR_Xmax=sortedAccToX[size-1];
	TR_Ymax=sortedAccToY[size-1];
	//BR_Ymin
	for(int i=0;i<size;i++)
	{ 
		if(sortedAccToY[i].y==BL_Ymin.y)
		{
			BR_Ymin=sortedAccToY[i];
			push(BR_Ymin);
			continue;
		}
		break;
	}
	//BR_Xmax
	for(int i=size-1;i>=0;i--)
	{
		if(sortedAccToX[i].x==TR_Xmax.x)
		{
			BR_Xmax=sortedAccToX[i];
			push(BR_Xmax);
			continue;
		}
		break;
	}
	//TL_Xmin
	for(int i=0;i<size;i++)
	{ 
		if(sortedAccToX[i].x==BL_Xmin.x)
		{
			TL_Xmin=sortedAccToX[i];
			push(TL_Xmin);
			continue;
		}
		break;
	}
	//TL_Ymax
	for(int i=size-1;i>=0;i--)
	{
		if(sortedAccToY[i].y==TR_Ymax.y)
		{
			TL_Ymax=sortedAccToY[i];
			push(TL_Ymax);
			continue;
		}
		break;
	}
	BL_Xmin=BL_Ymin=BR_Xmax=BR_Ymin=TL_Xmin=TL_Ymax=TR_Xmax=TR_Ymax=parr[0];
	printf("\nThese are the extreme points:\n");
	printf("BL_Xmin:\t%lf\t%lf\n",BL_Xmin.x,BL_Xmin.y);
	printf("BL_Ymin:\t%lf\t%lf\n",BL_Ymin.x,BL_Ymin.y);
	printf("BR_Xmax:\t%lf\t%lf\n",BR_Xmax.x,BR_Xmax.y);
	printf("BR_Ymin:\t%lf\t%lf\n",BR_Ymin.x,BR_Ymin.y);
	printf("TL_Xmin:\t%lf\t%lf\n",TL_Xmin.x,TL_Xmin.y);
	printf("TL_Ymax:\t%lf\t%lf\n",TL_Ymax.x,TL_Ymax.y);
	printf("TR_Xmax:\t%lf\t%lf\n",TR_Xmax.x,TR_Xmax.y);
	printf("TR_Ymax:\t%lf\t%lf\n",TR_Ymax.x,TR_Ymax.y);
	bottomLeftOperation(sortedAccToX,sortedAccToY,size,BL_Xmin,BL_Ymin);
	bottomRightOperation(sortedAccToX,sortedAccToY,size,BR_Xmax,BR_Ymin);
	topRightOperation(sortedAccToX,sortedAccToY,size,TR_Xmax,TR_Ymax);
	topLeftOperation(sortedAccToX,sortedAccToY,size,TL_Xmin,TL_Ymax);
	printf("\n\nStack:\n");
//	printStack();
	///////
	printf("Now we will use jarvis march to remove concave points from the hull\n");
	int stackSize=getStackSize();
	point* sparr=(point*)malloc(sizeof(point)*(stackSize+2));
	printf("before memcpy\n");
	memcpy(sparr,getStackPointer(),stackSize*sizeof(point));
	deInitStack();
	printf("after deinitstack\n");
//	printStack();
	printf("after memcpy:\n");
//	for(int i=0;i<stackSize;i++)
//	{
//		printf("%lf\t%lf\n",sparr[i].x,sparr[i].y);
//	}
	if(stackSize<3)
		printf("There are only two points on stack and no further jarvis procesing is required\n");
	int l=0;
	//	qsort((void *)sparr,stackSize,sizeof(point),comparatory);
	for(int i=1;i<stackSize;i++)
	{
		if(sparr[i].x<sparr[l].x)
		{
			l=i;
		}
	}
	printf("\nl=%d\n",l);
	int p=l,q;
	while(true)
	{
		push(sparr[p]);
		q=(p+1)%stackSize;
		for(int i=0;i<stackSize;i++)
		{
			if(findRotation(sparr[i],sparr[q],sparr[p])==1&&i!=p&&i!=q)	  //ipq
			{
			//	y++;	
				q=i;
			//	printf("\nlala%d\n",q);
			}
		}
		//printf("FOR FINISHED%d\n",p);
		p=q;
		if(p==l)
			break;
	}
	//do
	//{}
	printf("final:\n");
	printStack();
	//printf("\n%d\n",y);
}

int main()
{
	point *points;
	int numberOfPoints;
	printf("Enter the number of points:");
	scanf("%d\n",&numberOfPoints);
	points=(point*)malloc(numberOfPoints*sizeof(point));
	for(int i=0;i<numberOfPoints;i++)
	{
		scanf("%lf%lf",&points[i].x,&points[i].y);
	}
//	printPoints(points,numberOfPoints);
	findConvexHull(points,numberOfPoints);
	return 0;
}

 
