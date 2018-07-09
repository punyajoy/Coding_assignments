#include<iostream>
#include<stdlib.h>
using namespace std;

  // Class //
template <typename T>
class stack
{ 
    private :
             T arr[10];
             int top;

    public :
    	     stack();
    	     stack(stack &c);
	         void Initialize();
			 void Push(T x);
			 void Pop();
			 void GetMaxSize();
			 void CurrentSize();
			 void IsEmpty();
			 void Display();    
             
}; //end of class

struct str
  {
    float a;
  };

   // Global Variables //
int n=-1,i; 
str st;
int val1;
short val2;
float val3;
double val4;
char val5;               

   // Constructor //
            template <typename T>
            stack<T> :: stack()
            {
			}

          template <typename T>
          stack<T> :: stack(stack &c)
           {
           	top=c.top;
           	for(int k=0;k<=c.top;k++)
           	{
           		arr[k]=c.arr[k];
			   }
		   }
		   
   // Initialize Function // 
           template <typename T>
           void stack<T> :: Initialize()
              { 
                            
                top=-1;

                cout<<"New Stack Created";
              }

   // Push Function // 
             template <typename T>
             void stack<T> :: Push(T x)
              {
                 
                                 if(top >  9)
                       {
                           cout <<"Stack Overflow";
                           return;
                       }
                 arr[++top]=x;
                 cout <<x<<" is Pushed.";
               }

   // Pop Function // 
             template <typename T>
             void stack<T> :: Pop()
               {

                                  if(top <0)
                   {
                         cout <<"Stack Underflow";
                         return;
                    }
                    cout <<arr[top--]<<" is Popped.";
                }

    // GetMaxsize Function //
	         template <typename T> 
             void stack<T> :: GetMaxSize()
               {
                 cout<<"Max Size = 10";
               }

   // CurrentSize Function // 
               template <typename T>
              void stack<T> :: CurrentSize()
               {
                 cout<<"Current Size = "<<top+1;
               }

   // IsEmpty Function // 
              template <typename T>
              void stack<T> :: IsEmpty()
               {
                if (top==-1)
                 cout<<"Yes";
                 else
                 cout<<"No";
                }

   // Display Function // 
              template <typename T>
             void stack<T> :: Display()
               {
                       if(top<0)
                    {
                            cout <<" Stack is Empty";
                            return;
                    }
                    for(int j=top;j>=0;j--)
                    cout <<arr[j] <<" ";
                }

   // Main Function // 
int main()
{
	stack <float> s[5];
     int ch,st1,st2,choice;
     while(1)
        {
             cout <<"\n\n1. Create New Stack  \n2. Push  \n3. Pop  \n4. Max Size  \n5. Current Size  \n6. Stack Empty  \n7. Display  \n8. Copy Constructor  \n9. = Operator  \n10. Exit\n Enter Your Choice : ";
             cin >> ch;
             switch(ch)
              {
               case 1:  
			             n++;
                         if(n>4)
                          {
                                  cout<<"No More Stack Creation Possible.";
                                  n--;
                          }
			              else
						   s[n].Initialize();
                        break;

               case 2:  
			            cout<<"Enter the Stack No.";
                        cin>>i;
                          if(--i>n)
                                   cout<<"Stack Doesn't Exist.\n";
                        else   
                        {
						
                         cout<<"\n1.Int  \n2.Short  \n3.Float  \n4.Double  \n5.Char  \n6.Struct ";
                         cin>>choice;
                         switch(choice)
                          {

                            case 1:  int val1;
                                     cout <<"Enter the Element : ";
                                     cin >> val1;
                                     s[i].Push(val1);
                                     break;

                             case 2:  short int val2;
                                     cout <<"Enter the Element : ";
                                     cin >> val2;
                                     s[i].Push(val2);
                                     break;

                              case 3:  float val3;
                                     cout <<"Enter the Element : ";
                                     cin >> val3;
                                     s[i].Push(val3);
                                     break;

                             case 4:  double val4;
                                     cout <<"Enter the Element : ";
                                     cin >> val4;
                                     s[i].Push(val4);
                                     break;
                             case 5:  char val5;
                                     cout <<"Enter the Element : ";
                                     cin >> val5;
                                     s[i].Push(val5);
                                     break;


                              case 6:
                                     cout <<"Enter the Element : ";
                                     cin >> st.a;
                                     s[i].Push(st.a);
                                     break;
                             }
                          }
                         
                        break;

               case 3: 
			            cout<<"Enter the Stack No.";
                        cin>>i;
                         if(--i>n)
                           cout<<"Stack Doesn't Exist.\n";
                         else    
                           s[i].Pop();
                         break;

               case 4:  
			            cout<<"Enter the Stack No.";
                        cin>>i;
                         if(--i>n)
                            cout<<"Stack Doesn't Exist.\n";
                         else         
                        s[i].GetMaxSize();
                        break;

               case 5:  cout<<"Enter the Stack No.";
                        cin>>i;
                         if(--i>n)
                            cout<<"Stack Doesn't Exist.\n";
                         else 
                        s[i].CurrentSize();
                        break;

               case 6:  cout<<"Enter the Stack No.";
                        cin>>i;
                         if(--i>n)
                            cout<<"Stack Doesn't Exist.\n";
                         else 
                        s[i].IsEmpty();
                        break;

               case 7:  cout<<"Enter the Stack No.";
                        cin>>i;
                         if(--i>n)
                            cout<<"Stack Doesn't Exist.\n";
                         else 
                        s[i].Display();
                        break;
               case 8:  cout<<"Enter the Stack No.";
                        cin>>i;
                         if(--i>n)
                            cout<<"Stack Doesn't Exist.\n";
                         else 
			             {
						 stack <float> a=s[i];
						  cout<<"Source Stack :\n";
						     s[i].Display();
						     cout<<"\nNew Stack :\n";
						     a.Display();
                          }
						  break;
			   case 9:	cout<<"Enter the Source Stack No.";
                        cin>>st1;
                        cout<<"Enter the Destination Stack No.";
                        cin>>st2;
                        if((--st1>n)||(--st2>n))
                            cout<<"Stacks Don't Exist.\n";
                         else 
                          {
						     s[st2]=s[st1];
						     cout<<"Source Stack :\n";
						     s[st1].Display();
						     cout<<"\nDestination Stack :\n";
						     s[st2].Display();
					      }
			             break;	  
               case 10:  exit(0);

               default: cout<<"Wrong Choice...... Please Enter Again \n";
              }  // End of Switch
         }   // End of While
return (0);
}  // End of Main
