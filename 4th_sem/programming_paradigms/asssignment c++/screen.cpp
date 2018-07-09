#include <iostream>
#include <stdlib.h>
using namespace std;
# define size 100

class Screen
{
	char disp[800][600];
	int  adj[6][6];
	int  rect[6][2];
		
	public:
		void Printscreen(int m,int n);
        void WhiteScreen();
		void ScreenDelete();		
	    void HorLine(int startx,int starty,int length);
		void DiagLine(int startx,int starty,int length,int type);
		void VerLine(int startx,int starty,int length);
		void initialize();
		void Choosenum();
		void Printnum();
		void PrintTriangle();
		void PrintVTriangle();
		void Rectangle();
		void Alphabet();
};

void check(int m,int n)
{
	if(m<0||m>=600||n<0||n>=800)
     {
     	exit(0);
		 }	
	
}


void Screen::initialize()
{
	int i,j,m;
	m=6;
	rect[0][0]=3;
	rect[0][1]=3;
	rect[1][0]=3;
	rect[1][1]=8;
	rect[2][0]=8;
	rect[2][1]=3;
	rect[3][0]=8;
	rect[3][1]=8;
	rect[4][0]=13;
	rect[4][1]=3;
	rect[5][0]=13;
	rect[5][1]=8;
	
	for(i=0;i<m;i++)
	{
	for(j=0;j<m;j++)
		{
			adj[i][j]=0;
		}
    }

	
}

void Screen::Choosenum()
{
	int num;
	cout<<"give the number you want to print from 0 to 9 "<<endl;
	cin>>num;
	switch(num)
	{
		case 0:
			adj[0][1]=1;
			adj[1][3]=1;
			adj[3][5]=1;
			adj[4][5]=1;
		    adj[2][4]=1;
		    adj[0][2]=1;
			break;
		case 1:
			adj[1][3]=1;
			adj[3][5]=1;
			break;
	    case 2:
	    	adj[0][1]=1;
			adj[1][3]=1;
			adj[2][3]=1;
			adj[2][4]=1;
			adj[4][5]=1;
			break;
		case 3:
			adj[0][1]=1;
			adj[1][3]=1;
			adj[2][3]=1;
			adj[3][5]=1;
			adj[4][5]=1;
			break;
		case 4:
			adj[0][2]=1;
			adj[2][3]=1;
			adj[1][3]=1;
			adj[3][5]=1;
			break;
		case 5:
			adj[0][1]=1;
			adj[0][2]=1;
			adj[2][3]=1;
			adj[3][5]=1;
			adj[4][5]=1;
			break;
		case 6:
			adj[0][1]=1;
			adj[0][2]=1;
			adj[2][3]=1;
			adj[3][5]=1;
			adj[4][5]=1;
			adj[2][4]=1;
			break;
		case 7:
			adj[1][3]=1;
			adj[3][5]=1;
			adj[0][1]=1;
			break;
		case 8:
			adj[0][1]=1;
			adj[0][2]=1;
			adj[2][3]=1;
			adj[3][5]=1;
			adj[4][5]=1;
			adj[2][4]=1;
			adj[1][3]=1;
			break;
		case 9:
			adj[0][1]=1;
			adj[0][2]=1;
			adj[2][3]=1;
			adj[3][5]=1;
			adj[4][5]=1;
			adj[1][3]=1;
			break;
		default:
		    cout<<"please  choose from 1 to 9";
			break;	
			
	}
	
	
}

void Screen::Printnum()
{
	int i,j;
	
	for(i=0;i<6;i++)
	{
	for(j=i;j<6;j++)
		{
			if(adj[i][j]==1)
			{
				
				adj[j][i]=1;
				if((j-i)==1)
				{
					
					HorLine(rect[i][0],rect[i][1],5);
					
				}
				if((j-i)==2)
				{
					VerLine(rect[i][0],rect[i][1],5);
				}
				
			}
		}
    }
	
	
}
void Screen::PrintTriangle()
{
	int i;
	for(i=0;i<6;i++)
	{
	    HorLine(10+i,10-i,2*i);
	}
}
void Screen::PrintVTriangle()
{
	int i;
	for(i=0;i<6;i++)
	{
	    VerLine(10-i,10+i,2*i);
	}

}


void Screen::WhiteScreen()
{
	int i,j;
	
	for(i=0;i<800;i++)
	   for(j=0;j<600;j++)
	       disp[i][j]='.';

	
}
void Screen::ScreenDelete()
{
	int i,j;
	
	for(i=0;i<800;i++)
	   for(j=0;j<600;j++)
	       disp[i][j]=' ';

	
	
}
void Screen::HorLine(int startx,int starty,int length)
{
	int i;
	for(i=0;i<=length;i++)
	{
		check(startx,starty+i);
		disp[startx][starty+i]='.';
	}
	
}
void Screen::DiagLine(int startx,int starty,int length,int type)
{
	int i;
	if(type==1)
	{
	for(i=0;i<=length;i++)
	{
		check(startx+i,starty+i);
		disp[startx+i][starty-i]='.';
	}	
	}
	if(type==0)
	{
	for(i=0;i<=length;i++)
	{
		check(startx+i,starty+i);
		disp[startx+i][starty+i]='.';
	}	
		
	}
	
}
	
void Screen::VerLine(int startx,int starty,int length)
{
	int i;
	for(i=0;i<=length;i++)
	{
		check(startx+i,starty);
		disp[startx+i][starty]='.';
	}
}

void Screen::Printscreen(int m,int n)
{
	int i,j;
	
	for(i=0;i<m;i++)
	  {
	  	
	    for(j=0;j<n;j++)
	     {
		  check(i,j);
	      cout<<disp[i][j];
	     }
	    cout<<"\n";
      }
}
void Screen::Rectangle()
{
	int i;
	for(i=0;i<7;i++)
	{
	  HorLine(10+i,10,7);
	}
	
}
void Screen::Alphabet()
{
	//drawing A
	DiagLine(10,10,8,0);
	DiagLine(10,10,8,1);
	HorLine(13,7,6);
	//drawing B
	VerLine(10,20,8);
	HorLine(10,20,3);
	VerLine(10,23,3);
	HorLine(13,20,6);
	VerLine(13,26,5);
	HorLine(18,20,6);
	//drawing C
	VerLine(10,30,8);
	HorLine(10,30,5);
	HorLine(18,30,5);
}

int main()
{
	Screen A;
	int type,node_no,ch,x,y,length;
 while(1)
        {
             cout <<"\n\n1.WhiteScreen  \n2.Horizintalline  \n3. Verticalline \n4.Diagonalline  \n5.printTriangle \n6.printRectangle  \n7.print right-Triangle \n8.printAlphabet \n9.printdigital number \n10.screen_delete \n0.exit \n Enter Your Choice : ";
             cin >> ch;
             switch(ch)
              {
               case 1:
                       A.WhiteScreen();
                       A.Printscreen(40,60);                                      
                       break;

               case 2:
               	       cout<<"give the length"<<endl;
               	       cin>>length;
               	       cout<<"give the x coordinate"<<endl;
               	       cin>>x;
               	       cout<<"give the y coordinate"<<endl;
               	       cin>>y;
                       A.HorLine(x,y,length);
                       A.Printscreen(40,60);
                       break;

               case 3:
               	       cout<<"give the length"<<endl;
               	       cin>>length;
               	       cout<<"give the x coordinate"<<endl;
               	       cin>>x;
               	       cout<<"give the y coordinate"<<endl;
               	       cin>>y;
               	       A.VerLine(x,y,length);
               	       A.Printscreen(40,60);
                       break;

               case 4:
               	       cout<<"give the length"<<endl;
               	       cin>>length;
               	       cout<<"give the x coordinate"<<endl;
               	       cin>>x;
               	       cout<<"give the y coordinate"<<endl;
               	       cin>>y;
               	       A.DiagLine(x,y,length,0);
               	       A.Printscreen(40,60);
                       break;             
                        

               case 5:  
                       A.PrintTriangle();
                       A.Printscreen(40,60);
                       break;
               case 6:  
                       A.Rectangle();
                       A.Printscreen(40,60);
                       break;
               case 7:  
                       A.PrintVTriangle();
                       A.Printscreen(40,60);
                       break;
               case 8:
			           A.Alphabet();
			           A.Printscreen(40,60);
                       break;
               case 9:
                       
                      A.initialize();
                      A.Choosenum();
                      A.Printnum();			           
			          A.Printscreen(40,60);
                      break; 
			   case 10:
			           A.ScreenDelete();
			           A.Printscreen(40,60);
                       break;	         
               case 0:  exit(0);

               default: cout<<"Wrong Choice...... Please Enter Again \n";
              }  // End of Switch
         }   // End of While	
	
}
