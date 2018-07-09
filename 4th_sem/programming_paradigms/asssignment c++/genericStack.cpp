#include <iostream>
 
using namespace std;


template <class T>
class Stack
{
	T a[1000];
	int size;
	int n;
	
    
	public:
		void initial(int n1);
		T top();
		void push(T n);
		void pop();
		void MaxSize();
		void currentsize();
		void IsEmpty();
		void Display();
		Stack() 
	    {       // Constructor
            n = 0;
        }

        ~Stack() { }    // Destructor
	      Stack(Stack &obj)      //copy_constructor
        { 
          n=0;
	     size=100;
	    }
//	    Stack(Stack &obj)      //copy_constructor
//	    { 
//	     n=obj.n;
//	     size=obj.size;
//	     int i;
//    	 for(i=0;i<n;i++)
//    	 {
//    		a[i]=obj.a[i];
//         }
//    	    
//	    }
//	
};

    template <class T>
    void Stack<T>::initial(int n1)
    {
    	size=n1;
    	cout<<"initialised"<<endl;
      	
	}
	template <class T>
    T Stack<T>::top() 
	{

       if (n == 0)
	    {
            cout<<"Error Stack Empty"<<endl;
            return -1;
            }
            return a[n-1];
            
    }
    
    template <class T>
    void Stack<T>::push(T d) 
	{
	    
        if (n < size)
            a[n++] = d;
        else
            cout<<"Error: stack full"<<endl;
    }   

    template <class T>
    void Stack<T> :: pop() {

            if (n == 0)
                cout<<"Error: stack empty"<<endl;
            else
                cout<<"the stack element deleted"<<a[n]<<endl;
                n--;
        }
        
    template <class T>
    void Stack<T>::Display(){
    	
    	int i;
    	for(i=0;i<n;i++)
    	{
    		cout<<a[i]<<endl;
        }
    	
    	
	}

struct ara{
	int x;
	int y;
}array[10];





int main()
{
	Stack<int> l1;
	Stack<int> l2=l1;
	l2.initial(5);
	l2.push(2);
	l2.push(3);
	l2.Display();
	
	
	
}
