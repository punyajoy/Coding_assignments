#include <iostream>
#include<math.h>
#include <stdlib.h>
using namespace std;
# define size 1000
int cartesian[100][100];
class Set{
    
	int set[1000];
	int n;
    
	public:
	    void setin();
	    void Input();
	    void Input(int k);
		void Union(Set a,Set b);
		void Intersection(Set a,Set b);
		void Complement(Set a);
		void SetDiff(Set a,Set b);
		void IfEqual(Set a,Set b);
		void Cartesianproduct(Set a[],int n);
		void Distinct(Set a);
		void AllValues();     // it means medians standard deviation and mean
		void Display();
		void Powerset();	
		void print(int m,int n);
		
	
};
void Set::setin()
{
	
    int a;
    cout<<"give the value of n"<<endl;
    cin>>a;    
	n=a;
	
}

void Set::Input(int k)
{
	int i;
	for (i=0;i<k;i++)
	{
		set[i]=i+1;
		printf("%d",i+1);
		
	}
	
	
}

void Set::Input()
{
	int i;
	cout<<"give the elements of array"<<endl;
	for (i=0;i<n;i++)
	{
		cin>>set[i];
		
	}
	
	
}

void Set::SetDiff(Set A,Set B)
{
  int i,j,k,flag;
  cout<<"intersection"<<endl; 
  	k=0;
  	
  for(i=0;i<A.n;i++)
  { 
    flag=0;
  	for(j=0;j<B.n;j++)
  	{
  		if(A.set[i]==B.set[j])
  		{    
  	        flag=1;
			 		
		  }
  		
    }
    if(flag==0)
    {
    	set[k++]=A.set[i];
	}
}	
	
	
	
	
	
	
	
	
	
	
	
	
	
}









void Set::Union(Set A,Set B)
{
	
  int i,j,k,flag;
  cout<<"union"<<endl; 
  	
  for(i=0;i<A.n;i++)
  {
    set[i]=A.set[i];
  }	
  k=i;
  for(i=0;i<B.n;i++)
  { flag=0;
  	for(j=0;j<A.n;j++)
  	{
  		if(set[j]==B.set[i])
  		{
  	         flag=1;
			 break;		
		  }
  		
    }
    if(flag==0)
    {
    	set[k++]=B.set[i];
    	
	}
    
	}	
	n=k;
}


void Set::Intersection(Set A,Set B)
{
  int i,j,k,flag;
  cout<<"intersection"<<endl; 
  	k=0;
  	flag=0;
  for(i=0;i<B.n;i++)
  { 
  	for(j=0;j<A.n;j++)
  	{
  		if(A.set[j]==B.set[i])
  		{    set[k++]=B.set[i];
  	         flag=1;
			 		
		  }
  		
    }
}
	
	if(flag==0)
    {
    	cout<<"Disjoint sets"<<endl;    	
    }
	n=k;
}

void Set::Display(){
    	
    	int i;
    	for(i=0;i<n;i++)
    	{
    		cout<<set[i]<<endl;
        }
    	
}
void Set::Complement(Set A)
{
	int i,j;
	cout<<"taking universal matrix as all numbers from 1 to 100"<<endl;
	Set U;
	U.Input(100);
	
	int k=0;
	
	for(i=0;i<U.n;i++)
	{
	int flag=0;	
      for(j=0;j<A.n;j++)
  	{  
  		if(U.set[i]==A.set[j])
  		{    
		  flag=1;
		  
		}
	}
	
	if(flag==0)
	{
		set[k++]=U.set[i];
	}
	
  }
  
	n=k;
	
}


void Set::IfEqual(Set A,Set B)
{
  int i,j,k,flag;
  
  cout<<"Equal or not"<<endl; 
  	k=0;
  if(A.n!=B.n)
  {
  	cout<<"the sets are not equal"<<endl;
  }
  else
  { 
   flag=0;
   for(i=0;i<B.n;i++)
  {
  	for(j=0;j<A.n;j++)
  	{
  		if(A.set[j]!=B.set[i])
  		{
		  flag=1;
		  break;     			 		
		}
  		
    }
   }
}
	
	if(flag==0)
    {
    	cout<<"Disjoint sets"<<endl;    	
    }
	n=k;


}

void Set::Cartesianproduct(Set a[], int k)
{
	int col,tem,p,row,i,j,l,count;
	col=k;
	row=1;
	p=k;
	for(i=0;i<k;i++)
	{
		
		row=row*a[i].n;
		
	}
	
	int temp=row;
	
	i=0;
	do{
		
		count=row/(a[i].n);
		row=count;
	    j=0;
		while(j!=temp)
		{
			for(k=0;k<a[i].n;k++)
			{
				for(l=0;l<count;l++)
				{
					cartesian[j][i]=a[i].set[k];
					j++;
								
				}
		}
	}
					
	i++;	
}while(i!=p);
	
	
print(temp,col);	
}

int binary(int num)
{
    int rem;
    rem=0;
    if(num>1)
    {
     	
     rem = num % 2;
     rem= 10*binary(num / 2)+rem;
     }
     else
     {
     rem=num;
	 }
	 return rem;
     
}


void Set::Powerset(){
	int i,j,count;
	
	for(i=0;i<pow(2,n);i++)
	{
	   count=0;
       j=binary(i);
       cout<<"{";
       while(j>0)		
		{
			if(j%10==1)
			{
			    cout<<set[count]<<" ";
		    }
		    count++;
			j=j/10;
		}
		cout<<"}";
	    cout<<"\n"<<endl;
		
			
	}
	
}

	
void Set::print(int m,int n)
{
	int i,j;
	for(i=0;i<m;i++)
	{
		printf("(");
		for(j=0;j<n;j++)
		 {
		 	
		 	printf("%d,",cartesian[i][j]);		    
		}
		printf(")");
		printf("\n");
		
	}
	
	
	
	
	
}

float calculateSD(int data[])
{
    float sum = 0.0, mean, standardDeviation = 0.0;

  int i;

    for(i = 0; i < 10; ++i)
    {
        sum += (float)data[i];
    }

    mean = sum/10;

    for(i = 0; i < 10; ++i)
        standardDeviation += pow(data[i] - mean, 2);

    return sqrt(standardDeviation / 10);
}










void Set::AllValues(){
int median1,median2, mode,count[30];
int pos1,pos2;
int sum=0;
float mean=0.0;

for(int b=0;b<n;b++)
{
sum=sum+set[b];
}
cout<<"sum is"<<sum;
int small,pos,temp;

for(int i=0;i<n-1;i++)
{
small=set[i];
pos=i;
for(int j=i+1;j<n;j++)
{
if(small>set[j])
{
small=set[j];
pos=j;
}
}
temp=set[pos];
set[pos]=set[i];
set[i]=temp;
}
mean=sum/n;
cout<<"\n mean is"<<mean<<endl;
if(n%2!=0)
{
pos1=pos2=(n+1)/2;
}
else
{
pos1=n/2;
pos2=n/2 +1;
}
median1=set[pos1];
median2=set[pos2];
cout<<"median is "<<median1<<"\t"<<median2<<endl;
cout<<"standard-deviation"<<calculateSD(set)<<endl;
}





int main()
{
	int a,i;
	cout<<"powerset of A set"<<endl;
    Set A,B,C,D,E,F,G,H;
    A.setin();
    A.Input();
    A.Powerset();
    
    cout<<"cartesian product of an array of sets"<<endl;
	Set X[100];
	cout<<"no of sets in cartesian product"<<endl;
	cin>>a;
	for(i=0;i<a;i++)
	{
		X[i].setin();
		X[i].Input();
			
	}
	B.Cartesianproduct(X,a);
	
	A.setin();
	A.Input();
	B.setin();
	B.Input();
    C.Union(A,B);
    C.Display();
    D.Intersection(A,B);
    D.Display();
	E.Complement(A);
    E.Display();
    cout<<""<<endl;
	A.AllValues();
	cout<<""<<endl;
	G.IfEqual(A,B);
	G.Display();
	H.SetDiff(A,B);
	H.Display();

}
