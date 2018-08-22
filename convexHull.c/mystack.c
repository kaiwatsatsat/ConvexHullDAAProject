point* stack=NULL;
int top,size;

void initStack(int ssize)
{
  stack=(point *)malloc(ssize* sizeof(point));
  top=-1;
  size=ssize;
}

void deInitStack()
{
	top=-1;
}
void push(point p)
{
  top++;
  stack[top]=p;
}

point pop()
{
  point q=stack[top];
  top--;
  return q;
}
int getStackSize()
{
  return top+1;
}

point* getStackPointer()
{
  return stack;
}

void printStack()
{
  for(int i=0;i<=top;i++)
  {
     printf("%lf\t%lf\n",stack[i].x,stack[i].y);
  }
} 
