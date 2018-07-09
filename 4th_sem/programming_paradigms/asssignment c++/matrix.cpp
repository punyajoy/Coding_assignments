#include <iostream>
#include <stdlib.h>
using namespace std;
# define size 100

class Matrix
{
	int mat[size][size];
	int n;
	int m;
    
	public:
		void Matrixcreate(int x,int y);
		void Matrixin();
		void Addition(Matrix a,Matrix b);
		void Multiplication(Matrix a,Matrix b);
		void IsEqual(Matrix a);
		void Transpose(Matrix a);
		void display();
		void submatrix(int rs,int rf,int cs,int cf);
		void Inverse(Matrix a);	
	
};

void Matrix::Matrixcreate(int x, int y)
{
	m=x;       //columns 
	n=y;       //rows 
}

void Matrix::Addition(Matrix A,Matrix B)
{
	
int i,j;
cout<<"addition of matrix A and B"<<endl;
  if(A.m!=B.m||A.n!=B.n)
  {
  	
  	cout<<"the matrix addition is not possible"<<endl;
  }
  else
  {
  	Matrixcreate(A.m,A.n);
  	for(i=0;i<m;i++)
  	{
  		for(j=0;j<n;j++)
  		{
  			
  			mat[i][j]=A.mat[i][j]+B.mat[i][j];
  	    }
  	}
  	
  	
  }  	
	
}
void Matrix::Transpose(Matrix A)
{
int i,j;
  
   	Matrixcreate(A.m,A.n);
  	for(i=0;i<m;i++)
  	{
  		for(j=0;j<n;j++)
  		{
  	     mat[i][j]=A.mat[j][i];	
		}
  	}
  
	
}


void Matrix::IsEqual(Matrix A)
{
int i,j,flag;
  if(m!=A.m||n!=A.n)
  {
  	
  	cout<<"the matrices are not equal"<<endl;
  }
  else
  {
  	Matrixcreate(A.m,A.n);
  	for(i=0;i<m;i++)
  	{
  		for(j=0;j<n;j++)
  		{
  			
  			if(mat[i][j]!=A.mat[i][j])
			  {
			  flag=1;
			  break;  
			  }
  	    }
  	    if(flag==1)
  	    {
  	    	break;
  	    	
		}
  	}
  	if(flag==0)
  	{
  	  cout<<"matrices are equal"<<endl;	
  		
	}
  	else
  	{
  	   cout<<"matrices are not equal"<<endl;
  	}
  }  	
	
}


void Matrix::Inverse(Matrix A)
{

 int i,j;
 float determinant=0;
 
 for(i=0;i<3;i++)
 {
  determinant = determinant + (A.mat[0][i]*(A.mat[1][(i+1)%3]*
  A.mat[2][(i+2)%3] - A.mat[1][(i+2)%3]*A.mat[2][(i+1)%3]));
 }
 if(determinant==0)
 {
  cout<<"Inverse does not exist (Determinant=0).\n";
 }
 else
 {
  cout<<"\nInverse of matrix is: \n";
 }
 for(i=0;i<3;i++)
 {
  for(j=0;j<3;j++)
  {
   cout<<((A.mat[(i+1)%3][(j+1)%3] *
    A.mat[(i+2)%3][(j+2)%3]) - (A.mat[(i+1)%3][(j+2)%3]*
     A.mat[(i+2)%3][(j+1)%3]))/ determinant<<"\t";
  }
  cout<<"\n";
  }
	
	
	
	
	
}






void Matrix::Multiplication(Matrix A,Matrix B)
{
	cout<<"multiplication of matrix A and B"<<endl;
	int i,j,k;
	if(A.n==B.m)
	{
		Matrixcreate(A.m,B.n);
		for (i = 0; i < A.m; i++)
        {
            for (j = 0; j < B.n; j++)
            {
                mat[i][j] = 0;
                for (int k = 0; k < A.n; k++)
                {
                    mat[i][j] = mat[i][j] + A.mat[i][k] * B.mat[k][j];
                }
            }
        }
		
		
		
	}
	else
	{
		cout<< "multiplication not possible"<<endl; 
			
	}
		
}













void Matrix::Matrixin()
{
	int i,j;
	cout<<"give the"<<m*n<<"elements";
	for(i=0;i<m;i++)
	{
		
		for(j=0;j<n;j++)
		 {
            		 	
		 	cin>>mat[i][j];		    
		}

	}
	
	
	
}
void Matrix::submatrix(int rs,int rf,int cs,int cf)
{
	int i,j;
	for(i=rs-1;i<rf;i++)
	{
		
		for(j=cs-1;j<cf;j++)
		 {
		 	
		 	cout<<mat[i][j]<<" ";		    
		}
		
		cout<<"\n";
		
	}
}
void Matrix::display()
{
	int i,j;
	for(i=0;i<m;i++)
	{
		
		for(j=0;j<n;j++)
		 {
		 	
		 	cout<<mat[i][j]<<" ";		    
		}
		
		cout<<"\n";
		
	}
}
int main()
{
   Matrix A,B,C,D,E,F,G;
   int a,b,c,d;
   A.Matrixcreate(2,2);
   B.Matrixcreate(2,2);
   A.Matrixin();
   B.Matrixin();
   A.display();
   cout<<"\n\n"<<endl;
   B.display();
   cout<<"\n\n"<<endl;
   C.Matrixcreate(3,3);
   C.Matrixin();
   C.display();
   cout<<"\n\n"<<endl;
   cout<<"give the starting row and ending row"<<endl;
   cin>>a>>b;
   cout<<"give the starting col and ending col"<<endl;
   cin>>c>>d;
   C.submatrix(a,b,c,d);
   cout<<"\n\n"<<endl;
   D.Multiplication(A,B);
   D.display();
   cout<<"\n\n"<<endl;
   E.Addition(A,B);
   E.display();
   cout<<"\n\n"<<endl;
   F.Matrixcreate(3,3);
   F.Matrixin();
   cout<<"printing inverse"<<endl;
   F.Inverse(A);
   F.display();
   cout<<"\n\n"<<endl;
   A.IsEqual(B);
   cout<<"printing transpose"<<endl;
   G.Transpose(F);
   G.display();
   
   	
}
