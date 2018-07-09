#include<stdio.h>
#include<string.h>
struct queue{                             // creating a single lane in the car parking area
	   char carno[10][11];
	   int front;
	   int rear;
};

struct queue rows[5],waiting;             /* creating five lanes for car parking and one for waiting the 
                                           the waiting lane is not perfectly a queue as elelment can be accesed from anywhere but it can work as queue*/

/* general operation on queue*/
 
void qinsert2(int i,char x[11])             //insert a element in queue of lanes 
{
	strcpy(rows[i].carno[++rows[i].rear],x);
 } 
void qdelete(struct queue r)                // delete function is slightly modified here we replace the element to be deleted with a "NULL"
 {
    strcpy(r.carno[r.front++],"NULL"); 	
 }
int is_full(struct queue r)                 //checks whether a lane or waiting  is totally filled or not 
{
	int flag=0;
	int i;
	for(i=0;i<10;i++)
	{
		if(strcmp(r.carno[i],"NULL")==0)
		{ 
		  flag=1;
		  break;
		}
		
	}
	return flag;
 } 
 int is_empty(struct queue r)                   //checks whether a queue is totally empty or not 
 {
 	int flag;
 	if(r.rear=-1)
 	{
 	  flag=1;
	  }
 	return flag;
 }
 
 
/*end of general operation on queue, a operation is missed that is creation of queue,which is done  simultaneously for all*/

//this part consist of no of moves by  each car
 
 struct moves{
 	  char car_no[11];
 	  int moves;
 	
 };
 
 struct moves car[100];
 
 void initmoves()                     // initialise  the car moves structure 
 {
 	int i;
 	for(i=0;i<100;i++)
 	{
 		strcpy(car[i].car_no,"NULL");
	 }
 	
  } 
 
 void displaymoves()                   // displays the no of moves 
 {
 	int i;
 	for(i=0;i<100;i++)
 	{
 		if(strcmp(car[i].car_no,"NULL")==0)
 		break;
 		printf("\n%s   %d",car[i].car_no,car[i].moves); 		
	 }
 }
 
 int search(char car_no[11])           // search for a particular car in the moves region 
 {
  int i;
   for(i=0;i<100;i++)
   {
   if (strcmp(car[i].car_no,car_no)==0)
		 break;
    }
    return i;
 }
 /*end of car moves*/ 
/*waiting lane functions*/
 void waitdelete(int lane)    // car is shifted from waiting lane to parking lane
 {
	int i;
	qinsert2(lane,waiting.carno[waiting.front]);
    for(i=0;i<waiting.rear;i++)
	{
	  strcpy(waiting.carno[i],waiting.carno[i+1]);
	  int n=search(waiting.carno[i+1]);
      car[n].moves=car[n].moves+1;
 		   	
	}
	waiting.rear=waiting.rear-1;
		
 }
 void deleted(int pos)             //car is out of the waiting lane
 {
	int i;
    for(i=pos;i<waiting.rear;i++)
	{
	  strcpy(waiting.carno[i],waiting.carno[i+1]);
	  int n=search(waiting.carno[i+1]);
 	  car[n].moves=car[n].moves+1;
 		   	
	}
	waiting.rear=waiting.rear-1;
}

//qinsert is already defined
void qinsert(struct queue row,char x[11])   //insert a element in queue of waiting 
{
	strcpy(row.carno[++row.rear],x);
	int n=search(x);
	car[n].moves=car[n].moves+1;
 		   	
 }
 int searchwait(char car_no[11])
 {
 	int i;
	for(i=0;i<10;i++)
	{
	  if(strcmp(waiting.carno[i],car_no)==0)	
		break;
	}
    return i;	
 }
 // display for wait
 void displaywait()
 {
 	int i;
 	for(i=0;i<waiting.rear;i++)
 	{
 		printf("\n%s",waiting.carno[i]);
	 }
 	
 }
 
 
/*waiting lane finished*/





/* operation on the whole parking lot*/ 
 void init()                           //  the total parking lot is initialised 
  {
	int i,j;
	for(i=0;i<5;i++)
	{
		rows[i].front=0;
		rows[i].rear=-1;
		for(j=0;j<10;j++)
			{
			strcpy(rows[i].carno[j],"NULL");
			}	
	}
	waiting.rear=-1;
	waiting.front=0;
	
  }  

void display()                              // this function displays the status of total lane if a slot is empty it shows "null" 
{                                             
	int i,j;
	for(i=0;i<5;i++)
       {
       	printf("lane %d \t",i+1);
       	for(j=0;j<10;j++)
       	{
       		printf("%s  ",rows[i].carno[j]);
       		      		
		   }
		 printf("\n");  
	    }
	
}

 int arrive(char car_no[11])                 // this function controls the total arrival into the lane 
 {
 	int i,flag=0;
 	for(i=0;i<5;i++)
 	{
 	   if(is_full(rows[i]))
 	    {
 	    	qinsert2(i,car_no);
 	    	flag=1;
 	    	break;
		 }
	 }
	 if(!flag)
	 {
	 	qinsert(waiting,car_no);
        	     	
	 }
 	return i;
 }
 
 
 int depart(char car_no[11],int lane)           // departure from the parking lot 
 {
 	int i,j,flag=0;
 	  for(i=0;i<10;i++)
 	  {
 				
 		if(strcmp(rows[lane].carno[i],car_no)==0)
 		{
 			
 		   	printf("\nyour car with the number plate %s is moved out\n",car_no);
 		   	int m=search(car_no);
 		   	car[m].moves=car[m].moves+1;
 		   	printf("\nyour car moved %d times\n",car[m].moves);
 		    flag=1;
			break;
		 }
      }
        printf("\n %d \n",rows[lane].rear);
        printf("\n %d \n",i);
	    if(flag==1)
	     {
	       for(j=i;j<=rows[lane].rear;j++) 
 	     {
 		    strcpy(rows[lane].carno[j],rows[lane].carno[j+1]);
 		    int n=search(rows[lane].carno[j+1]);
 		    car[n].moves=car[n].moves+1;
 		   	
 	     }
 	       rows[lane].rear=rows[lane].rear-1;
 	       printf("\n %d \n",rows[lane].rear);
 	       
 	       for(j=0;j<i;j++)
 	       {
            int m=search(rows[lane].carno[j]);
 		   	car[m].moves=car[m].moves+1;
 	   }
    }
    else 
    {
    	printf("\ncar not found.....searching in waiting area\n");
    	int k=searchwait(car_no);
    	if(k==10)
	        printf("\ncar not found in waiting lane\nsorry but your car is not garaged here");
    		else 
    		{
			printf("\nyour car is found in the waiting lane...");
    		printf("%s",waiting.carno[k]);
    		int o=search(waiting.carno[k]);
    		car[o].moves=car[o].moves+1;
 		   	printf("\nyour car moved %d times\n",car[o].moves);
    		deleted(k);
    	    }
    }
	return j;
 	
}

 
 void main()
{
  
  init();
  initmoves();
  displaymoves();
  display();
  char carno[11],ch='y',status;
  int lane, lanegiven, lanegive,temp; 
  while(ch=='y')
  {
  printf("\ngive your car no...");
  fflush(stdin);
  scanf("%s",carno);
  printf("\n give whether you want to arrive(A) or depart(D)?");  	
  fflush(stdin);
  scanf("%c",&status);
  switch(status)
  {
  	case 'A': 
  	            strcpy(car[temp].car_no,carno);
  	            int lanegive=arrive(carno);
  	            printf("\nyour car is parked in %d lane\n",lanegive+1);
  		        display();
  		        temp++;
				break;
  		        
  	case 'D':	
  	            printf("\ngive the lane your car was..");
  	            scanf("%d", &lanegiven);
  	            depart(carno,lanegiven-1);
  	            if(waiting.rear!=-1)
  	            {
				 waitdelete(lanegiven-1);
			    }
  	            printf("\n");
  	            display();
				  break;
  	default:
	            printf("choice not specified");
				            
	}	
	displaymoves();
	printf("\ndo you want to continue? \n press y for continuation");
    fflush(stdin);
    scanf("%c",&ch);
 }

}





