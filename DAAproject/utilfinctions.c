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
