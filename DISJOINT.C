#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct disjoint
{
int parent[10];
int rank[10];
int n;
}dis;
void makeset()
{
int i;
for(i=0;i<dis.n;i++)
{
dis.parent[i]=i;
dis.rank[i]=0;
}
}
void display()
{
int i;
printf("\n present");
for(i=0;i<dis.n;i++)
{
printf("%d\t",dis.parent[i]);
}
printf("\nrank");
for(i=0;i<dis.n;i++)
{
printf("%d\t",dis.rank[i]);
}
}
int find(int x)
{
if(dis.parent[x]!=x)
{
dis.parent[x]=find(dis.parent[x]);
}
return dis.parent[x];
}
void Union(int x,int y)
{
int setx=find(x);
int sety=find(y);
if(setx==sety)
{
return;
}
if(dis.rank[setx]>dis.rank[sety])
{
dis.parent[sety]=setx;
dis.rank[sety]=-1;
}
else if(dis.rank[setx]<dis.rank[sety])
{
dis.parent[setx]=sety;
dis.rank[setx]=-1;
}
else
{
dis.parent[sety]=setx;
dis.rank[setx]+=1;
dis.rank[sety]=-1;
}
}
void main()
{
int choice,x,y;clrscr();

while(1)
{
printf("\nDisjoint set operations\n\n1.Make set\n2.Find\n3.union\n4.display\n5.exit\nEnter your choice=");
scanf("%d",&choice);
switch(choice)
{
case 1:printf("\nEnter no. of elements in a set\n");
scanf("%d",&dis.n);
makeset();
break;
case 2:printf("enter two elements to find they are connected\n");
scanf("%d%d",&x,&y);
if(find(x)==find(y))
printf("\n%d and %d are connected to a single leader %d/n",x,y,find(x));
else
printf("\nDisconnected components");
break;
case 3:
printf("\nEnter two elements to perform union");
scanf("%d%d",&x,&y);
Union(x,y);
break;
case 4:display();
break;
case 5:exit(1);
}}getch();}
