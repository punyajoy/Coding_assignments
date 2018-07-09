#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;

struct poly
{
    int coeff;
    int pow;
    poly *next;
};

class add2poly
{
   poly *poly1, *poly2, *poly3;
   
   public:
   
   add2poly()
     { 
	 poly1=poly2=poly3=NULL;
	 }
   void addpoly();
   void display();
};


void add2poly :: addpoly()
{
      int i,p;
      poly *newl=NULL,*end=NULL;
      cout<<"Enter Highest Power For x :\n";
      cin>>p;
      
    // Read First Polynomial
      cout<<"\nFirst Polynomial :\n";
      for(i=p;i>=0;i--)
      {
      newl=new poly;
      newl->pow=p;
      cout<<"Enter Co-efficient For Degree"<<i<<"::  ";
      cin>>newl->coeff;
      newl->next=NULL;
      if(poly1==NULL)
         poly1=newl;
      else
         end->next=newl;
      end=newl;
      }

    // Read Second polynomial
      cout<<"\n\nSecond Polynomial :\n";
      end=NULL;
      for(i=p;i>=0;i--)
      {
      newl=new poly;
      newl->pow=p;
      cout<<"Enter Co-efficient For Degree"<<i<<"::  ";
      cin>>newl->coeff;
      newl->next=NULL;
      if(poly2==NULL)
         poly2=newl;
      else
         end->next=newl;
      end=newl;
      }

      //Addition Logic
      poly *p1=poly1,*p2=poly2;
      end=NULL;
      while(p1 !=NULL && p2!=NULL)
	  {
        if(p1->pow == p2->pow)
		{
            newl=new poly;
            newl->pow=p--;
            newl->coeff=p1->coeff + p2->coeff;
            newl->next=NULL;
            if(poly3==NULL)
               poly3=newl;
            else
               end->next=newl;
            end=newl;
        }
        p1=p1->next;
        p2=p2->next;
      }
}

void add2poly :: display()
{
   poly *t=poly3;
   cout<<"\n\nAnswer After Addition is : ";
   while(t!=NULL)
   {
      cout.setf(ios::showpos);
      cout<<t->coeff;
      cout.unsetf(ios::showpos);
      cout<<"x"<<t->pow<<" ";
      t=t->next;
   }
}


int main()
{
    add2poly obj;
    obj.addpoly();
    obj.display();
    return 0;
}
