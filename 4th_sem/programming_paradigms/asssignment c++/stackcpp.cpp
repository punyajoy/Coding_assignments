#include <iostream>
 
using namespace std;
class Stack
{
	int a[1000];
	int size;
	int n;
	
    
	public:
		void initial(int n1);
		int top();
		void push(int n);
		void pop();
		void MaxSize();
		void currentsize();
		void IsEmpty();
		void Display();
		Stack() 
	    {       // Constructor
            n = 0;
        }

        ~Stack() { }           // Destructor
//	    Stack(Stack &obj)      //copy_constructor
//	    { 
//	     n=0;
//	     size=100;
//	    }
	    Stack(Stack &obj)      //copy_constructor
	    { 
	     n=obj.n;
	     size=obj.size;
	     int i;
    	 for(i=0;i<n;i++)
    	 {
    		a[i]=obj.a[i];
         }
    	    
	    }
	
};


    void Stack::initial(int n1)
    {
    	size=n1;
    	cout<<"initialised"<<endl;
      	
	}
    int Stack::top() 
	{

       if (n == 0)
	    {
            cout<<"Error Stack Empty"<<endl;
            return -1;
            }
            return a[n-1];
            
    }

    void Stack::push(int d) 
	{
	    
        if (n < size)
            a[n++] = d;
        else
            cout<<"Error: stack full"<<endl;
    }   

    void Stack :: pop() {

            if (n == 0)
                cout<<"Error: stack empty"<<endl;
            else
                cout<<"the stack element deleted"<<a[n]<<endl;
                n--;
        }

    void Stack::Display(){
    	
    	int i;
    	for(i=0;i<n;i++)
    	{
    		cout<<a[i]<<endl;
        }
    	
    	
	}

    





int main()
{
	Stack l1;
	l1.initial(4);
	l1.push(5);
	l1.push(3);
	Stack l2=l1;
	l2.Display();
		
}
