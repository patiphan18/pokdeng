//Program name: pokdenglib.c
#include"pokdeng.h"
void cardrand(int j,int rn[],int intcard[],char tcard[],char type_card[],char *rt[],int sn[],char *sc[],int hn[],char *hc[],int cn[],char *cc[],int dn[],char *dc[])
{
	int i,n;
	do{
	n=0;
	rn[j] = rand()%4;
	intcard[j] = rn[j];
	type_card[j] = tcard[rn[j]];
	if(rn[j]==0){
	rn[j] = rand()%13;
		for(i=0;i<13;i++){
			if(sn[i]==rn[j]){
			sn[i]=-1;
			rt[j]=sc[rn[j]];
			n=n+1;
			}
		}
	}
	else if(rn[j]==1){
	rn[j] = rand()%13;
		for(i=0;i<13;i++){
			if(hn[i]==rn[j]){
			hn[i]=-1;
			rt[j]=hc[rn[j]];
			n=n+1;
			}
		}
	}
	else if(rn[j]==2){
	rn[j] = rand()%13;
		for(i=0;i<13;i++){
			if(cn[i]==rn[j]){
			cn[i]=-1;
			rt[j]=cc[rn[j]];
			n=n+1;
			}
		}
	}
	else if(rn[j]==3){
	rn[j] = rand()%13;
		for(i=0;i<13;i++){
			if(dn[i]==rn[j]){
			dn[i]=-1;
			rt[j]=dc[rn[j]];
			n=n+1;
			}
		}
	}
	
	}while(n!=1);
	
	return;
}

int checkwin(int playerpoint,int compoint,int coin,int pdeng,int cdeng,int bet)
{
	if(playerpoint>compoint){
		printf("			YOU WIN!!\n");
		coin = coin + (bet * pdeng);
	}
	else if(playerpoint==compoint){
		printf("			YOU TIE!!\n");
		
	}
	else{
		printf("			YOU LOSE!!\n");
		coin = coin - (bet * cdeng);
	}

	return coin;
}

int checkplayerpoint(int playerpoint)
{
	if(playerpoint%10 == 0){
		playerpoint = 0;
	}
	else if(playerpoint>10){
		playerpoint = playerpoint%10;
	}
	return playerpoint;
}

int checkcompoint(int compoint)
{
	if(compoint%10 == 0){
		compoint = 0;
	}
	else if(compoint>10){
		compoint = compoint%10;
	}
	return compoint;
}

void outputcom2(char * num_card[],char type_card[],int compoint1)
{
	int i;
	printf("		     Computer Card\n");
	for(i=1;i<=3;i+=2){
		if(type_card[i]=='S'){
			printf("%s Spade\n",num_card[i]);
		}
		else if(type_card[i]=='H'){
			printf("%s Heart\n",num_card[i]);
		}
		else if(type_card[i]=='C'){
			printf("%s Clover\n",num_card[i]);
		}
		else if(type_card[i]=='D'){
			printf("%s Diamond\n",num_card[i]);
		}
	}
	printf("Computer Point = %d\n",compoint1);
	printf("		*********	*********\n");
	printf("		*%s    *	*%s    *\n",num_card[1],num_card[3]);
	printf("		*       *	*       *\n");
	printf("		*   %c   *	*   %c   *\n",type_card[1],type_card[3]);	
	printf("		*       *	*       *\n");
	printf("		*    %s*	*    %s*\n",num_card[1],num_card[3]);
	printf("		*********	*********\n");
	printf("\n");
	return ;
}

void outputcom3(char * num_card[],char type_card[],int compoint2)
{
	int i;
	printf("		     Computer Card\n");
	for(i=1;i<=5;i+=2){
		if(type_card[i]=='S'){
			printf("%s Spade\n",num_card[i]);
		}
		else if(type_card[i]=='H'){
			printf("%s Heart\n",num_card[i]);
		}
		else if(type_card[i]=='C'){
			printf("%s Clover\n",num_card[i]);
		}
		else if(type_card[i]=='D'){
			printf("%s Diamond\n",num_card[i]);
		}
	}
	printf("Computer Point = %d\n",compoint2);
	printf("	*********	*********	*********\n");
	printf("	*%s    *	*%s    *	*%s    *\n",num_card[1],num_card[3],num_card[5]);
	printf("	*       *	*       *	*       *\n");
	printf("	*   %c   *	*   %c   *	*   %c   *\n",type_card[1],type_card[3],type_card[5]);	
	printf("	*       *	*       *	*       *\n");
	printf("	*    %s*	*    %s*	*    %s*\n",num_card[1],num_card[3],num_card[5]);
	printf("	*********	*********	*********\n");
	printf("\n");	
	return ;
}

void outputplayer2(char * num_card[],char type_card[],int playerpoint1)
{
	int i;
	printf("\n");	
	printf("		*********	*********\n");
	printf("		*%s    *	*%s    *\n",num_card[0],num_card[2]);
	printf("		*       *	*       *\n");
	printf("		*   %c   *	*   %c   *\n",type_card[0],type_card[2]);	
	printf("		*       *	*       *\n");
	printf("		*    %s*	*    %s*\n",num_card[0],num_card[2]);
	printf("		*********	*********\n");		
	printf("			Your Card\n");
	
	for(i=0;i<=2;i+=2){
		if(type_card[i]=='S'){
			printf("%s Spade\n",num_card[i]);
		}
		else if(type_card[i]=='H'){
			printf("%s Heart\n",num_card[i]);
		}
		else if(type_card[i]=='C'){
			printf("%s Clover\n",num_card[i]);
		}
		else if(type_card[i]=='D'){
			printf("%s Diamond\n",num_card[i]);
		}
	}
	printf("Your Point = %d\n",playerpoint1);
	return ;
} 

void outputplayer3(char * num_card[],char type_card[],int playerpoint2)
{
	int i;
	printf("\n");
	printf("	*********	*********	*********\n");
	printf("	*%s    *	*%s    *	*%s    *\n",num_card[0],num_card[2],num_card[4]);
	printf("	*       *	*       *	*       *\n");
	printf("	*   %c   *	*   %c   *	*   %c   *\n",type_card[0],type_card[2],type_card[4]);	
	printf("	*       *	*       *	*       *\n");
	printf("	*    %s*	*    %s*	*    %s*\n",num_card[0],num_card[2],num_card[4]);
	printf("	*********	*********	*********\n");
	printf("			Your Card\n");
	for(i=0;i<=4;i+=2){
		if(type_card[i]=='S'){
			printf("%s Spade\n",num_card[i]);
		}
		else if(type_card[i]=='H'){
			printf("%s Heart\n",num_card[i]);
		}
		else if(type_card[i]=='C'){
			printf("%s Clover\n",num_card[i]);
		}
		else if(type_card[i]=='D'){
			printf("%s Diamond\n",num_card[i]);
		}
	}
	printf("Your Point = %d\n",playerpoint2);
	return ;
}

int pdeng2(int intcard[],int pdeng)
{
	if(intcard[0]==intcard[2]){
		pdeng = 2;
	}
	return pdeng;
}

int cdeng2(int intcard[],int cdeng)
{
	if(intcard[1]==intcard[3]){
		cdeng = 2;
	}
	return cdeng;
}

int pdeng3(int intcard[],int pdeng)
{
	if(intcard[0]==intcard[2] && intcard[0]==intcard[4]){
		pdeng = 3;
	}
	return pdeng;
}

int cdeng3(int intcard[],int cdeng)
{
	if(intcard[1]==intcard[3] && intcard[1]==intcard[5]){
		cdeng = 3;
	}
	return cdeng;
}

void delay(long int ms)
{
	clock_t timeDelay  = ms + clock();
	while(timeDelay > clock());
	return ;
}

void loading()
{
		system("clear");
		printf(" 	___          	\n");
		printf(" 	| |         	\n");
		printf(" 	| |           	\n");
		printf(" 	| |     	\n");
		printf(" 	| |        	\n");
		printf(" 	| |_____     	\n");
		printf(" 	|_______|    	\n");
		delay(300);

		system("clear");
		printf(" 	___         _________   	\n");
		printf(" 	| |        |  _____  |   	\n");
		printf(" 	| |        | |     | |   	\n");
		printf(" 	| |        | |     | |  	\n");
		printf(" 	| |        | |     | |  	\n");
		printf(" 	| |_____   | |_____| |  	\n");
		printf(" 	|_______|  |_________|  	\n");
		delay(300);
		
		system("clear");
		printf(" 	___         _________      _____        	\n");
		printf(" 	| |        |  _____  |    | | | |        			\n");
		printf(" 	| |        | |     | |   | |   | |    				\n");
		printf(" 	| |        | |     | |  | |_____| |    	\n");
		printf(" 	| |        | |     | |  |  _____  |  		\n");
		printf(" 	| |_____   | |_____| |  | |     | |     		\n");
		printf(" 	|_______|  |_________|  |_|     |_|  	 	\n");
		delay(300);

		system("clear");
		printf(" 	___         _________      _____     _______     	\n");
		printf(" 	| |        |  _____  |    | | | |    | ____ |    			\n");
		printf(" 	| |        | |     | |   | |   | |   | |   | |   				\n");
		printf(" 	| |        | |     | |  | |_____| |  | |    | |  	\n");
		printf(" 	| |        | |     | |  |  _____  |  | |    | |  		\n");
		printf(" 	| |_____   | |_____| |  | |     | |  | |___| |   		\n");
		printf(" 	|_______|  |_________|  |_|     |_|  |______|	 	\n");
		delay(300);
		
		system("clear");
		printf(" 	___         _________      _____     _______     ___  		\n");
		printf(" 	| |        |  _____  |    | | | |    | ____ |    | |  			\n");
		printf(" 	| |        | |     | |   | |   | |   | |   | |   | |  			\n");
		printf(" 	| |        | |     | |  | |_____| |  | |    | |  | |  			\n");
		printf(" 	| |        | |     | |  |  _____  |  | |    | |  | | 		\n");
		printf(" 	| |_____   | |_____| |  | |     | |  | |___| |   | | 	\n");
		printf(" 	|_______|  |_________|  |_|     |_|  |______|	 |_|  	\n");
		delay(300);
		
		system("clear");
		printf(" 	___         _________      _____     _______     ___  ___    ___   			\n");
		printf(" 	| |        |  _____  |    | | | |    | ____ |    | |  | |    | |   			\n");
		printf(" 	| |        | |     | |   | |   | |   | |   | |   | |  | ||   | |   					\n");
		printf(" 	| |        | |     | |  | |_____| |  | |    | |  | |  | | |  | |     		\n");
		printf(" 	| |        | |     | |  |  _____  |  | |    | |  | |  | |  | | |   		\n");
		printf(" 	| |_____   | |_____| |  | |     | |  | |___| |   | |  | |   || |   	\n");
		printf(" 	|_______|  |_________|  |_|     |_|  |______|	 |_|  |_|    |_|   	\n");
		delay(300);
		
		system("clear");
		printf(" 	___         _________      _____     _______     ___  ___    ___   ___________			\n");
		printf(" 	| |        |  _____  |    | | | |    | ____ |    | |  | |    | |   | |_______|			\n");
		printf(" 	| |        | |     | |   | |   | |   | |   | |   | |  | ||   | |   | |					\n");
		printf(" 	| |        | |     | |  | |_____| |  | |    | |  | |  | | |  | |   | |  ______			\n");
		printf(" 	| |        | |     | |  |  _____  |  | |    | |  | |  | |  | | |   | | |____| |		\n");
		printf(" 	| |_____   | |_____| |  | |     | |  | |___| |   | |  | |   || |   | |______| |		\n");
		printf(" 	|_______|  |_________|  |_|     |_|  |______|	 |_|  |_|    |_|   |__________|		\n");
		delay(300);
		system("clear");
	return ;
}

void starting()
{
	int a = 92;

		system("clear");
		printf("(%c_/)                   (%c_/)\n",a,a);
    	printf("(*-*)                   (*-*)\n");
     	printf("/  >POKDENG          GAME<  %c\n",a);
     	
     	printf("(%c_/)                   (%c_/)\n",a,a);
    	printf("(*-*)                   (*-*)\n");
     	printf("/  >POKDENG          GAME<  %c\n",a);
		delay(300);
		
		system("clear");
		printf("  (%c_/)               (%c_/)\n",a,a);
    	printf("  (*-*)               (*-*)\n");
     	printf("  /  >POKDENG      GAME<  %c\n",a);
     	
     	printf("  (%c_/)               (%c_/)\n",a,a);
    	printf("  (*-*)               (*-*)\n");
     	printf("  /  >POKDENG      GAME<  %c\n",a);
		delay(300);
		
		system("clear");
		printf("    (%c_/)           (%c_/)\n",a,a);
    	printf("    (*-*)           (*-*)\n");
     	printf("    /  >POKDENG  GAME<  %c\n",a);
     	
     	printf("    (%c_/)           (%c_/)\n",a,a);
    	printf("    (*-*)           (*-*)\n");
     	printf("    /  >POKDENG  GAME<  %c\n",a);
		delay(300);
		
		system("clear");
	return ;
}
