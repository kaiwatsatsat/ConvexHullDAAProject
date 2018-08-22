void printPoints(point parr[],int size)
{
   printf("These are the points\n");
   printf("X-coordinate\tY-coordinate\n");
   for(int i=0;i<size;i++)
   {
     printf("%lf\t%lf\n",parr[i].x,parr[i].y);
   }
}

/*===================
Let withRespectTo(p0),pivot(p1),whoseToFind(p2) be three distinct points and we want to determine whether whoseToFind is clockwise or anticlockwise from pivot with respect to withRespectTo. 

(p2-p0)x(p1-p0)=(x2-x0)(y1-y0)-(x1-x0)(y2-y0)
If sign of cross product is 
-ve, p2 is counterclkwise wrt p1
+ve, p2 is clkwise wrt p1
0  , all are collinear

p2.
  |\
  | \.p1    Here, p2 is counterclockwise wrt p1.
  | /
  |/
  .
  p0 */

int findRotation(point whoseToFind,point withRespectTo,point pivot)
{
  double D= ((whoseToFind.x-withRespectTo.x)*(pivot.y-withRespectTo.y))-((pivot.x-withRespectTo.x)*(whoseToFind.y-withRespectTo.y));
  if(D<0)  //counterclockwise
    return 1;
  else if(D>0) //clockwise
    return -1;
  else
    return 0;
}

