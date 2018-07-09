//considering a graph which is directed//

#include <iostream>
#include <stdlib.h>
#include "set.h"
using namespace std;
# define size 1000
#define MAX 50

int z=0;
int v=1;
int w=0;
int patharray[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top=0;

class Graph
{
	
    
	public:
		Set V;
	    Set E;
	    int arr[100];
	    void Graphin();
        void Graphin(int m);
		void GrInput();
		void Subgraph();
		void Graphunion(Graph a,Graph b);
		void Graphintersection(Graph a,Graph b);
		void Disconnectedver();
		void degreeofnode(int k);
		void pathbetweenvertex();    			
	    void DisplayG();
	    int  search(int k);
};

void Graph::Graphin()
{
	cout<<"give the number of vertices of the graph"<<endl;
	V.setin();
	cout<<"give the number of edges of the graph"<<endl;
	E.setin();
	if(V.n*V.n<E.n)
	{
		cout<<"given data is wrong please give again"<<endl;
		Graphin(); 
	}
}
void Graph::Graphin(int m)
{
	V.n=m;
	cout<<"give the number of edges of the graph"<<endl;
	E.setin();
	if(V.n*V.n<E.n)
	{
		cout<<"given data is wrong please give again"<<endl;
		Graphin(); 
	}
}
//assuming integers as graph vertices and integers combined together as a edge//
// eg if 1 ,3 are vertices then 13 may be a edge//

void Graph::GrInput()
{
	V.Input();
	E.InputV(V);    //give the edges as two digit no where tens place denotes starting vertices 
	              //and ones place denote ending vertices
}
void Graph::DisplayG()
{
	cout<<"The vertices of the graph"<<endl;
	V.Display();
	cout<<"The edges of the graph"<<endl;
    E.Display();
	
}
int Graph::search(int k)
{
	int j;
	j=V.search(k);
	return j;
}

void Graph::Subgraph()
{
	Graph SG;
	int s[100],f[100],i,count,printflag,flag1,flag2,k,ch;
	printflag=0;
	cout<<"the vertices and edges of the original graph"<<endl;
    V.Display();
    E.Display();
	
	for(i=0;i<E.n;i++)
	{
	  	s[i]=E.set[i]/10;  //storing the starting vertex
	  	f[i]=E.set[i]%10;  //storing ending vertex
	}
	ch=0;
	count=0;
	i=0;
	cout<<"give the vertices in Sub graph"<<endl;
	while(ch==0)
	{
		cin>>k;
		SG.V.set[i]=k;
		i++;
		count++;
		cout<<"do u want to continue \n 0: for yes \n 1: for no"<<endl;
		cin>>ch;
		
	}
	SG.V.n=count;
	SG.V.Display();
	cout<<"choose the edges to be included in the subgraph"<<endl;
	for(i=0;i<E.n;i++)
	{
		flag1=SG.search(s[i]);
		flag2=SG.search(f[i]);
			
		if(flag1==1&&flag2==1)
		{
			
			cout<<E.set[i]<<" ";
			printflag=1;
		}
	
	}
	
	cout<<" "<<endl;
	if(printflag==1)
	{
	 SG.Graphin( count );
     SG.E.InputV(V);
    }
    SG.DisplayG();	
	
	
}


void Graph::Disconnectedver()
{
	int i,count,flag1,flag2,k,ch,disc[100];
	Set Start,Final,G,D;
	for(i=0;i<E.n;i++)
	{
	  	Start.set[i]=E.set[i]/10;  //storing the starting vertex
	  	Final.set[i]=E.set[i]%10;  //storing ending vertex
	}
	Start.n=i;
	Final.n=i;
	G.Union(Start,Final);
    D.SetDiff(V,G);
    cout<<"the disconnected vertex/vertices"<<endl;
    D.Display();
}

void Graph::Graphintersection(Graph A,Graph B)
{
	V.Intersection(A.V,B.V);
	E.Intersection(A.E,B.E);
	
}

void Graph::Graphunion(Graph A,Graph B)
{
	V.Union(A.V,B.V);
	E.Union(A.E,B.E);
	
}

void Graph::degreeofnode(int k)
{
	int count,i;
	count=0;
	Set Start,Final;
	for(i=0;i<E.n;i++)
	{
	  	Start.set[i]=E.set[i]/10;  //storing the starting vertex
	  	Final.set[i]=E.set[i]%10;  //storing ending vertex
	}
	Start.n=i;
	Final.n=i;
	count=Start.Searchfreq(k);
	count=count+Final.Searchfreq(k);
	
	cout<<"the degree of the node:";
	cout<<count<<endl;
	
}

void push(int val)
{
	if(top<MAX)
	{
		stack[top] =val;
		top++;
	}
	else
	{
		printf("Stack is full");
	}
	
}
int pop()
{
	int val;
	if(top>0)
	{
	    top--;
		val =stack[top];
	    return val;
	}
	else
	{
		printf("\nStack is empty");
		return -1;
	}
	
}
void display()
{
	int i;
	printf("\n");
	for(i=0;i<top;i++)
	  printf("%d\t",stack[i]);
	
}
void disp(int n)
{
	int i;
	printf("\n");
	for(i=0;i<n;i++)
	  printf("%d",i+1);
	  
	printf("\n"); 
	  for(i=0;i<n;i++)
	  printf("%d",visited[i]);

}

int random(int n)
{
	
	int i;
	i=rand()%n;
	return i;
}
int searchzeros(int n,int arr[])
{
	int i,flag;
	flag=0;
	for(i=0;i<n;i++)
	{
		if(visited[i]==0&&arr[i]==1)
		{ 
		flag=1;
		break;
	    }
	}
	
	return flag;
}
void findpath(int G[MAX][MAX],int initial,int end,int n)
{   int qdeleted,i,j;
    
	push(initial+1);
    visited[initial]=1;
    
    for(i=0;i<n;i++)
    {
    	
    	if(i==end&&G[initial][i]==1)
    	{
    	   push(end+1);
	        for(j=0;j<top;j++)
	        {  patharray[w][v]=stack[j];
	            v=v+1;
	        }
	         qdeleted=pop();
		patharray[w][0]=v-1;
		v=1;
		w=w+1;
		 		
		}
    	
    	else if(visited[i]==0&&G[initial][i]==1)
				   {
	
				   	  findpath(G,i,end,n);
		   	
				   }
	    if(i==n-1)
		{
		qdeleted=pop();
    	visited[qdeleted-1]=0;
        }
        
	}
	  
	}

void Graph::pathbetweenvertex()
{
	int m,r,ctr,arr[MAX][MAX],t,i,j,k,l,initial,final;
	
	cout<<"\nthe adjacency matrix is:"<<endl;
	m=V.n;
	
	Set Start,Final;
	for(i=0;i<E.n;i++)
	{
	  	Start.set[i]=E.set[i]/10;  //storing the starting vertex
	  	Final.set[i]=E.set[i]%10;  //storing ending vertex
	}
	Start.n=i;
	Final.n=i;
	
	for(i=0;i<m;i++)
	{
		for(j=i;j<m;j++)
		{
			arr[i][j]=0;
		}
			
	}
	for(i=0;i<E.n;i++)
	{
	   arr[Start.set[i]-1][Final.set[i]-1]=1;  	
    }
		
	cout<<"\n";
	for(i=0;i<m+1;i++)
	{
		printf("%d  ",i);
		for(j=0;j<m;j++)
		{
			if(i==0)
		        printf("%d   ",j+1);
		    else
		        printf("%d   ",arr[i-1][j]);
	   	
      	}
      	
      	printf("\n");

	}
	printf("give the initial and final position with in range:-");
	ctr=0;
	do{
	printf("\nintial position:");	
	scanf("%d",&initial);
	printf("\nfinal position: ");
	scanf("%d",&final);
	if(initial<=m&&final<=m)
	    break;
	if(ctr>=0)
	{
		printf("\nplease give the numbers again");
		
	}
	ctr=ctr+1;
   }while(initial>m||final>m);
   visited[final-1]=1;
   findpath(arr,initial-1,final-1,m);
   printf("\n");
   cout<<"path-length  path"<<endl;
   for(i=0;i<w;i++)
      {
      	 if(patharray[i][0]>0)
	       {
	       	 cout<<patharray[i][0]<<"\t\t";
	       	
	         for (j=1;j<m+1;j++)
	          {
		          printf("%d ",patharray[i][j]);
              }
        }
      printf("\n");    
          
    }     
   
    
}

   
   






int main()
{
	
 Graph A,B,C,D;
 int type,node_no,ch;
 
 cout<<"give the vertices and edges for graph A"<<endl;
 A.Graphin();	
 A.GrInput();
 
 cout<<"give the vertices and edges for graph B"<<endl;
 B.Graphin();
 B.GrInput();
 while(1)
        {
             cout <<"\n\n1. find the intersection betweeen A and B  \n2. Find the union of A and B  \n3. find the degree of  a node of graph \n4.find the path between two vertex of graphs   \n5. find the disconnected vertices \n6. find the subgraph of a graph  \n0. Exit  \n Enter Your Choice : ";
             cin >> ch;
             switch(ch)
              {
               case 1:
                       C.Graphintersection(A,B);
                       C.DisplayG();                                 
                       break;

               case 2:
                       D.Graphunion(A,B);
                       D.DisplayG();	 
                       break;

               case 3:
               	       cout<<" give the graph you want to find the degree of a node 1.A and 2.B"<<endl;
               	       cin>>type;
               	       if(type==1)
               	       {
               	       	  A.DisplayG();
               	       	  cout<<"give the node whose degree needs to be found out"<<endl;
               	       	  cin>>node_no;
               	          A.degreeofnode(node_no);  	
						  }
               	       if(type==2)
               	       {
               	       	  B.DisplayG();
               	       	  cout<<"give the node whose degree needs to be found out"<<endl;
               	       	  cin>>node_no;
               	          B.degreeofnode(node_no);
               	       	  }
                       break;

               case 4:
               	       cout<<" give the graph you want to find the path between vertex 1.A and 2.B"<<endl;
               	       cin>>type;
               	       if(type==1)
               	       {
               	       	  A.DisplayG();
               	       	  A.pathbetweenvertex();
 
               	       	  }
               	       if(type==2)
               	       {
               	       	  B.DisplayG();
                          B.pathbetweenvertex();
           	       	    }
                       break;
                                    
                        

               case 5:  
                       cout<<" give the graph you want to find the disconnected vertex 1.A and 2.B"<<endl;
               	       cin>>type;
               	       if(type==1)
               	       {
               	       	  A.DisplayG();
               	       	  cout<<"\n";
					   	  A.Disconnectedver(); 
               	       	  }
               	       if(type==2)
               	       {
               	       	  B.DisplayG();
                          cout<<"\n";
					   	  B.Disconnectedver(); 
           	       	    }
                       break;
               case 6:  
                       cout<<" give the graph you want to find the disconnected vertex 1.A and 2.B"<<endl;
               	       cin>>type;
               	       if(type==1)
               	       {
               	       	  cout<<"\n";
					   	  A.Subgraph(); 
               	       	  }
               	       if(type==2)
               	       {
               	       	  cout<<"\n";
					   	  B.Subgraph(); 
           	       	    }
                       break;
               case 0:  exit(0);

               default: cout<<"Wrong Choice...... Please Enter Again \n";
              }  // End of Switch
         }   // End of While	
	
	
	
}
