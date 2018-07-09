#include<stdio.h>
#include<math.h>
void main()
{
	int percent;
	printf("\nType percentage: ");
	scanf("%d",&percent);
	while(percent>100)
	{
		printf("give your correct percentage");
		scanf("%d",&percent);
	 } 
	 switch(percent/10)
	 {
	 	case 0: 
	 	case 1:
	 	case 2:printf("\n fail");break;
	 	case 3:
	 	case 4:printf("\n third division");break;
	 	case 5:printf("\n second division");break;
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:printf("\n first division");break;	
	 	
	 	
	 }
}
