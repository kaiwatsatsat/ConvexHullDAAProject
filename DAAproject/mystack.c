//this file contains stack for the project

point *stack;
int top,size;
void initStack(int ssize)
{
	stack=(point*)malloc(sizeof(point)*ssize);
	top=-1;
	size=ssize;
}
void push(point p)
{
	top++;
	stack[top]=p;
}
point pop()
{
	top--;
	return stack[top+1];
}
void printStack()
{
	for(int i=0;i<=top;i++)
	{
		printf("%lf\t%lf\n",stack[i].x,stack[i].y);
	}
}
	
