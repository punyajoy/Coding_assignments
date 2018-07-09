#include<iostream>
#include<stdlib.h>
using namespace std;
#define MAX 5

  // Class //
class stack
{
    private :
             int arr[10];
             int top;
    public :
             stack();
             stack(stack &c);

                         void Initialize();
                         void Push(int x);
                         void Pop();
                         void GetMaxSize();
                         void CurrentSize();
                         void IsEmpty();
                         void Display();

         stack operator +(stack c)
           {
            stack t;
            t.top=-1;
            int k,j;

          for(k=0;(k<=top) && (t.top<9);k++)
            t.arr[++t.top]=arr[k];
            for(j=0;(j<=c.top) && (t.top<9);j++)
            t.arr[++t.top]=c.arr[j];
            return t;
           }


}; //end of class

int n=-1,i;  // Global Variables

   // Constructor //
            stack :: stack()
            {
            }

   // Copy Constructor //
          stack :: stack(stack &c)
           {
                top=c.top;
                for(int k=0;k<=c.top;k++)
                {
                        arr[k]=c.arr[k];
                           }
                   }

   // Initialize Function // 
           void stack :: Initialize()
              {

                top=-1;

                cout<<"New Stack Created";
              }

   // Push Function // 
             void stack :: Push(int x)
              {

                                 if(top >  8)
                       {
                           cout <<"Stack Overflow";
                           return;
                       }
                 arr[++top]=x;
                 cout <<x<<" is Pushed.";
               }

   // Pop Function // 
             void stack :: Pop()
               {

                                  if(top <0)
                   {
                         cout <<"Stack Underflow";
                         return;
                    }
                    cout <<arr[top--]<<" is Popped.";
                }

    // GetMaxsize Function // 
             void stack :: GetMaxSize()
               {
                 cout<<"Max Size = 10";
               }

   // CurrentSize Function // 
              void stack :: CurrentSize()
               {
                 cout<<"Current Size = "<<top+1;
               }

   // IsEmpty Function // 
              void stack :: IsEmpty()
               {
                if (top==-1)
                 cout<<"Yes";
                 else
                 cout<<"No";
                }

   // Display Function // 
             void stack :: Display()
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
        stack s[MAX];
     int ch,st1,st2,st3;
     while(1)
        {
             cout <<"\n\n1. Create New Stack  \n2. Push  \n3. Pop  \n4. Max Size  \n5. Current Size  \n6. Stack Empty  \n7. Display  \n8. Copy Constructor  \n9. = Operator  \n10. Stack Count  \n11. Add Stacks  \n12. Exit  \n Enter Your Choice : ";
             cin >> ch;
             switch(ch)
              {
               case 1:
                                     n++;
                         if(n>MAX-1)
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
                        cout <<"Enter the Element";
                        cin >> ch;
                        if(--i>n)
                                   cout<<"Stack Doesn't Exist.\n";
                        else
                          s[i].Push(ch);
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
                                                 stack a=s[i];
                                                  cout<<"Source Stack :\n";
                                                     s[i].Display();
                                                     cout<<"\nNew Stack :\n";
                                                     a.Display();
                          }
                                                  break;
               case 9:  cout<<"Enter the Source Stack No.";
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
               case 10:  cout<<"No. of Stacks Created : ";
                         cout<<n+1;
                        break;
               case 11:  cout<<"Enter the Base Stack No.";
                         cin>>st1;
                         cout<<"Enter the Additional Stack No.";
                         cin>>st2;
                         cout<<"Enter the Resultant Stack No.";
                         cin>>st3;
                         if((--st1>n)||(--st2>n)||(--st3>n))
                            cout<<"Stacks Don't Exist.\n";
                         else
                          {
                                                     s[st3]=s[st1]+s[st2];
                                                     cout<<"Base Stack :\n";
                                                     s[st1].Display();
                                                     cout<<"\nAdditional Stack :\n";
                                                     s[st2].Display();
                                                     cout<<"\nResultant Stack :\n";

                                                     s[st3].Display();


                                              }
                                     break;

               case 12:  exit(0);

               default: cout<<"Wrong Choice...... Please Enter Again \n";
              }  // End of Switch
         }   // End of While
return (0);
}  // End of Main
