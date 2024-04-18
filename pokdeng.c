//Program name: pokdeng.c
#include"pokdeng.h"
int main()
{
	struct Info{
	//This variable keep all spade card
	char *spade[13];
	//This variable keep all heart card
	char *heart[13];
	//This variable keep all clover cards
	char *clover[13];				
	//This variable keep all diamond card
	char *diamond[13];	
	};

	struct Info card = {" A Spade"," 2 Spade", " 3 Spade"," 4 Spade",
			" 5 Spade"," 6 Spade"," 7 Spade"," 8 Spade",
			" 9 Spade","10 Spade"," K Spade"," Q Spade",
			" J Spade"," A Heart"," 2 Heart"," 3 Heart",
			" 4 Heart"," 5 Heart"," 6 Heart"," 7 Heart",
			" 8 Heart"," 9 Heart","10 Heart"," K Heart",
			" Q Heart"," J Heart"," A Clover"," 2 Clover", 
			" 3 Clover"," 4 Clover"," 5 Clover"," 6 Clover",
			" 7 Clover"," 8 Clover"," 9 Clover","10 Clover",	
			" K Clover"," Q Clover"," J Clover"," A Diamond",
			" 2 Diamond"," 3 Diamond"," 4 Diamond"," 5 Diamond",
			" 6 Diamond"," 7 Diamond"," 8 Diamond"," 9 Diamond",
			"10 Diamond"," K Diamond"," Q Diamond"," J Diamond"	
	};
	
	//This variable keep type of card for output	
	char tcard[4] = {'S','H','C','D'};
	
	//This variable keep number of card for output
	char *ncard[13] = {" A "," 2 "," 3 "," 4 "," 5 "," 6 "," 7 "," 8 "," 9 ","10 "," K "," Q "," J "};
	
	char *num_card[6]; //random string from ncard[13] and keep in this variable
	char *rtype2[6]; //keep string type card (Spade,Heart,Clover,Diamond)
	char type_card[6]; //keep type card (S,H,C,D)
	int intcard[6]; //keep number of type cards
	int rnum[6]; //random number
	int s_num[13],h_num[13],c_num[13],d_num[13]; //keep 13 numbers for 4 type cards
			
	int i,j,usernametaken,regisfail; //this variable use to check condition
	int menu1,MenuStart,Play,Draw,backtostart; //this variable use to check condition
	
	int playerpoint1 = 0,playerpoint2 = 0; //player point for 2 cards and 3 cards
	int compoint1 = 0,compoint2 = 0; //computer point for 2 cards and 3 cards
	
	int coin = 100,level = 1,bet; //use to keep data in game
	int cdeng,pdeng; //check deng of computer cards and deng of player cards
	
	int alluse,size; //keep number of users
	
	char user[20]; //get username from user
	char pass[20]; //get password from user
	char passagain[20]; //get password again from user
	
	char user2[20]; //get username from file
	char pass2[20]; //get password form file
	
	char user3[20] = {"q4z3x1y2o5"}; //this variable use to check how many users in loop
	char pass3[20] = {"q4z3x1y2o5"}; //this variable use to check how many users in loop
	
	FILE *data; //use to open file data.txt
	FILE *dcoin; //use to open file coin.txt
	FILE *dlevel; //use to open file level.txt
	
	char Home[2],Reg[2],Start[2],Playagain[2],next[2],thirdCard[2],PDGame[2]; //this variable use for input number of menu
	
	unsigned int seed; //use in srand function
	
	//Set time for random number unique
	seed = time(NULL);
	srand(seed);
	
	system("clear");
	
	data = fopen("user.txt","r");
	if(!data){
	data = fopen("user.txt","a");
	dcoin = fopen("coin.txt","a");
	dlevel = fopen("level.txt","a");
	coin = 0;
	level = 0;
	fprintf(data,"generateusername\nganeratepassword\n",user,pass);
	fprintf(dcoin,"%d\n",coin);
	fprintf(dlevel,"%d\n",level);
	fclose(data);
	fclose(dcoin);
	fclose(dlevel);
	}
	
		loading();
	do{
		do{
		system("clear");
		printf("********************** Home **********************\n\n");
		printf("		(1): Login\n");
		printf("		(2): Register\n");
		printf("		(3): Exit\n");
		printf("\n**************************************************\n");
		printf("Enter menu: ");
		scanf("%s",Home);
		}while(strcmp(Home,"1")!=0 && strcmp(Home,"2")!=0 && strcmp(Home,"3")!=0);
	
		if(strcmp(Home,"3")==0){
			system("clear");
			printf("\n	***** GOODBYE!! *****\n");
			return 0;
		}
		
		else if(strcmp(Home,"2")==0){
			usernametaken = 0;
			do{
				regisfail = 0;
			do{
				system("clear");
				if(regisfail==1){
					printf("*************************** Register Fail **************************\n");
					printf("********************** Password does not match *********************\n\n");
				}
			
				if(usernametaken!=0){
					printf("*************************** Register Fail **************************\n");
					printf("****************** Username has already been taken *****************\n\n");	
				}
					
				do{
					system("clear");
					printf("***************************** Register *****************************\n");
					printf("	- Username & Password must be 3-10 characters \n");
					printf("********************************************************************\n");
					printf("Enter Username: ");
					scanf("%s",&user);
					printf("Enter Password: ");
					scanf("%s",&pass);
					printf("Confirm Password: ");
					scanf("%s",&passagain);
				}while(strlen(user)>10||strlen(user)<3 || strlen(pass)>10||strlen(pass)<3);
				
				printf("***** Please check your infomation *****\n");

				do{
					printf("	(1): Register confirm\n	(2): Back to home\n");
					printf("Enter menu: ");
					scanf("%s",&Reg);
				}while(strcmp(Reg,"1")!=0 && strcmp(Reg,"2")!=0); 
	
				if(strcmp(Reg,"2")==0){
					regisfail = 1;
					break;
				} //break and back to menu
	
				if(strcmp(pass,passagain)!=0){
					regisfail = 1;
				} //if password and confirm password deos not match
				else if(strcmp(pass,passagain)==0){
					regisfail = 0;
				}
	
			}while(strcmp(pass,passagain)!=0); //do while for check password and password again
		
	if(strcmp(Reg,"1")==0){
	
	data = fopen("user.txt","r");
	
		while(fscanf(data,"%s",user2) && fscanf(data,"%s",pass2)){
			
			if(strcmp(user,user2)==0 && strcmp(user,user3)==0){
				fclose(data);
				regisfail = 0;
				break;
			}
			
			if(feof(data)){
				printf("\n	***** Register Success *****\n");
				printf("- Please remember your username and password\n");
				fclose(data);
				regisfail = 2;
				break;
			}
			
		}//while loop check username and password for Register
	
	}//if cf = 1 do this loop
	
	usernametaken++; //use to check username has already been taken
	
	}while(regisfail>3||regisfail<1); //do while loop for register again
	
	if(regisfail==2){	
		data = fopen("user.txt","a");
		dcoin = fopen("coin.txt","a");
		dlevel = fopen("level.txt","a");
		
		level = 1;
		coin = 100;
		fprintf(data,"%s\n%s\n",user,pass);
		fprintf(dcoin,"%d\n",coin);
		fprintf(dlevel,"%d\n",level);
		
		fclose(data);
		fclose(dcoin);
		fclose(dlevel);
	
		do{
			printf("	(1): Exit game\n	(2): Back to home\n");
			printf("Enter menu: ");
			scanf("%s",&Reg);
		}while(strcmp(Reg,"1")!=0 && strcmp(Reg,"2")!=0); 
	
		if(strcmp(Reg,"1")==0){
			return 0;
		}
	}//if regisfail = 2
	
	} //if menu = 2
	
	else if(strcmp(Home,"1")==0){
		do{
		data = fopen("user.txt","r");
		system("clear");
		printf("******************** Login ********************\n\n");
		printf("Enter Username: ");
		scanf("%s",&user);
		printf("Enter Password: ");
		scanf("%s",&pass);
		
		size=0;
	
		while(fscanf(data,"%s",user2) && fscanf(data,"%s",pass2)){
			
		if(strcmp(user,user2)==0 && strcmp(pass,pass2)==0){
				system("clear");
				printf("******************** Login Complete ********************\n");
				fclose(data);
			do{
				printf("****************** Please enter number ******************\n\n");
				printf("	(0): Next to menu start\n	(1): Exit game\n");
				printf("\n********************************************************\n");
				printf("Enter menu: ");
				scanf("%s",&Reg);
				system("clear");
			}while(strcmp(Reg,"0")!=0 && strcmp(Reg,"1")!=0); 
	
			if(strcmp(Reg,"1")==0){
				return 0;
			}
			
		break;
		}
			
			if(feof(data)){
				printf("\n***** Please check your username or password *****\n");
				fclose(data);
				do{
					printf("	(1): Login again\n	(2): Back to home\n");
					printf("Enter menu: ");
					scanf("%s",&Reg);
				}while(strcmp(Reg,"1")!=0 && strcmp(Reg,"2")!=0);
				break ;
			}
			
		size++;
		}//while loop check username and password for login
	

	
		}while(strcmp(Reg,"1")==0); //do while loop for login again
		
		int coin2[size],level2[size];
		dcoin = fopen("coin.txt","r");	
		dlevel = fopen("level.txt","r");
	
		for(i=0;i<=size;i++){
			fscanf(dcoin,"%d\n",&coin2[i]);
			fscanf(dlevel,"%d\n",&level2[i]);
		}
	
		fclose(dcoin);
		fclose(dlevel);
	
		coin = coin2[size];
		level = level2[size];
	
		}//if(menu = 1)
	
	}while(strcmp(Reg,"2")==0); //do while loop for back to menu
	
	do{
		data = fopen("user.txt","r");
		alluse = 0;
		while(fscanf(data,"%s",user3) && fscanf(data,"%s",pass3)){
			if(feof(data)){
				break ;
			}	
		alluse++;
		}//check how many user in game
		fclose(data);
	
	do{
	backtostart = 0;
	
	do{system("clear");
		printf("*****************Pok Deng Game*****************\n");
		printf("\n");
		printf("		(1): Start game\n");
		printf("		(2): Information\n");
		printf("		(3): Ranking\n");
		printf("		(4): Exit\n");
		printf("\n");
		printf("***********************************************\n");
		printf("Enter number: ");
		scanf("%s",&PDGame);
	}while(strcmp(PDGame,"1")!=0 && strcmp(PDGame,"2")!=0 && strcmp(PDGame,"3")!=0 && strcmp(PDGame,"4")!=0);
	
	
	if(strcmp(PDGame,"1")==0){	
	do{
	//start level 1
		if(level==1){
			if(coin<=0){
				coin = 100;
			}
			
		cdeng = 1;
		pdeng = 1;
		playerpoint1 = 0;
		playerpoint2 = 0;
		compoint1 = 0;
		compoint2 = 0;
	
	//do while loop for bet coin
		do{
			system("clear");
			printf("***** Level = %d *****\n",level);	
			printf("***** Coin = %d *****\n",coin);
			printf("\nHow many coin do you want to bet(1-Allcoin)\n");
			printf("Enter coin: ");
			scanf("%d",&bet);
		}while(bet>coin||bet<1);
		
	//print animation	
		starting();
	
	//generate number card and keep in array
		for(i=0;i<13;i++){
			s_num[i] = i;
			h_num[i] = i;
			c_num[i] = i;
			d_num[i] = i;
		}
		
	//random 6 card
		cardrand(0,rnum,intcard,tcard,type_card,rtype2,s_num,card.spade,h_num,card.heart,c_num,card.clover,d_num,card.diamond);
		cardrand(1,rnum,intcard,tcard,type_card,rtype2,s_num,card.spade,h_num,card.heart,c_num,card.clover,d_num,card.diamond);
		cardrand(2,rnum,intcard,tcard,type_card,rtype2,s_num,card.spade,h_num,card.heart,c_num,card.clover,d_num,card.diamond);
		cardrand(3,rnum,intcard,tcard,type_card,rtype2,s_num,card.spade,h_num,card.heart,c_num,card.clover,d_num,card.diamond);
		cardrand(4,rnum,intcard,tcard,type_card,rtype2,s_num,card.spade,h_num,card.heart,c_num,card.clover,d_num,card.diamond);
		cardrand(5,rnum,intcard,tcard,type_card,rtype2,s_num,card.spade,h_num,card.heart,c_num,card.clover,d_num,card.diamond);
	
	//generate point for 6 card and keep in array
		for(i=0;i<6;i++){
			num_card[i] = ncard[rnum[i]];
		}
	
	//Calculate point 6 card
		for(i=0;i<6;i++){
			if(rnum[i]>=9){
				rnum[i]=10;
			}
			else{
				rnum[i]=rnum[i]+1;
			}
		}
		
	//Calculate player point and computer point	
		compoint1 = rnum[1] + rnum[3];
		compoint2 = rnum[1] + rnum[3] + rnum[5];
		playerpoint1 = rnum[0] + rnum[2];
		playerpoint2 = rnum[0] + rnum[2] + rnum[4];
	
	//check playerpoint
		playerpoint1 = checkplayerpoint(playerpoint1);
		playerpoint2 = checkplayerpoint(playerpoint2);

	//check computerpoint
		compoint1 = checkcompoint(compoint1);
		compoint2 = checkcompoint(compoint2);
	
		printf("	Level: %d\n",level);
		
		if(compoint1>=8){
			cdeng = cdeng2(intcard,cdeng);
			pdeng = pdeng2(intcard,pdeng);
			outputcom2(num_card,type_card,compoint1);
			coin = checkwin(playerpoint1,compoint1,coin,pdeng,cdeng,bet);
			outputplayer2(num_card,type_card,playerpoint1);
		}
		
		else if((playerpoint1>=8)&&(compoint1>=6)){	
			cdeng = cdeng2(intcard,cdeng);
			pdeng = pdeng2(intcard,pdeng);
			outputcom2(num_card,type_card,compoint1);
			coin = checkwin(playerpoint1,compoint1,coin,pdeng,cdeng,bet);
			outputplayer2(num_card,type_card,playerpoint1);
		}
	
		else if((playerpoint1>=8)&&(compoint1<6)){	
			cdeng = cdeng3(intcard,cdeng);
			pdeng = pdeng2(intcard,pdeng);
			outputcom3(num_card,type_card,compoint2);
			coin = checkwin(playerpoint1,compoint2,coin,pdeng,cdeng,bet);
			outputplayer2(num_card,type_card,playerpoint1);
		}
		
		else{
			do{
				system("clear");
				printf("Level: %d\n",level);
				outputplayer2(num_card,type_card,playerpoint1);
				
				printf("Do you want more card?\n");
				printf("(1)Yes (2)No: ");
				scanf("%s",&thirdCard);
			}while(strcmp(thirdCard,"1")!=0 && strcmp(thirdCard,"2")!=0); 
			
			if(strcmp(thirdCard,"1")==0){
				Draw = 1;
			}
			else if(strcmp(thirdCard,"2")==0){
				Draw = 2;
			}
		
			switch(Draw){
				
			case 1: system("clear");
				printf("Level: %d\n",level);
				if(compoint1<6){
					cdeng = cdeng3(intcard,cdeng);
					pdeng = pdeng3(intcard,pdeng);
					outputcom3(num_card,type_card,compoint2);
					coin = checkwin(playerpoint2,compoint2,coin,pdeng,cdeng,bet);
					outputplayer3(num_card,type_card,playerpoint2);	
				}
				else if(compoint1>=6){
					cdeng = cdeng2(intcard,cdeng);
					pdeng = pdeng3(intcard,pdeng);
					outputcom2(num_card,type_card,compoint1);
					coin = checkwin(playerpoint2,compoint1,coin,pdeng,cdeng,bet);
					outputplayer3(num_card,type_card,playerpoint2);
				}		
				break;
		
				case 2: system("clear");
					printf("Level: %d\n",level);
					if(compoint1<6){
						cdeng = cdeng3(intcard,cdeng);
						pdeng = pdeng2(intcard,pdeng);
						outputcom3(num_card,type_card,compoint2);
						coin = checkwin(playerpoint1,compoint2,coin,pdeng,cdeng,bet);
						outputplayer2(num_card,type_card,playerpoint1);
					}
					else if(compoint1>=6){
						cdeng = cdeng2(intcard,cdeng);
						pdeng = pdeng2(intcard,pdeng);
						outputcom2(num_card,type_card,compoint1);
						coin = checkwin(playerpoint1,compoint1,coin,pdeng,cdeng,bet);
						outputplayer2(num_card,type_card,playerpoint1);
					}
				break;
				
			}//switch draw
			
		}//Player input number for draw a card
		
	//read file
		int coin2[alluse],level2[alluse];
		dcoin = fopen("coin.txt","r");	
		dlevel = fopen("level.txt","r");
		for(i=1;i<=alluse;i++){
			fscanf(dcoin,"%d\n",&coin2[i]);
			fscanf(dlevel,"%d\n",&level2[i]);
		}
		coin2[size+1] = coin;
		level2[size+1] = level;
		fclose(dcoin);
		fclose(dlevel);
	
	//update file
		dcoin = fopen("coin.txt","w");	
		dlevel = fopen("level.txt","w");
		for(i=1;i<=alluse;i++){
			fprintf(dcoin,"%d\n",coin2[i]);
			fprintf(dlevel,"%d\n",level2[i]);
		}
		fclose(dcoin);
		fclose(dlevel);
	
		if(coin>=200){
			printf("***** Level:1 Clear!! *****\n");
			level = 2;
			coin = 200;
			
			int coin2[alluse],level2[alluse];
			dcoin = fopen("coin.txt","r");	
			dlevel = fopen("level.txt","r");
			for(i=1;i<=alluse;i++){
				fscanf(dcoin,"%d\n",&coin2[i]);
				fscanf(dlevel,"%d\n",&level2[i]);
			}
			coin2[size+1] = coin;
			level2[size+1] = level;
			fclose(dcoin);
			fclose(dlevel);
				
			dcoin = fopen("coin.txt","w");	
			dlevel = fopen("level.txt","w");	
			for(i=1;i<=alluse;i++){
				fprintf(dcoin,"%d\n",coin2[i]);
				fprintf(dlevel,"%d\n",level2[i]);
			}
			fclose(dcoin);
			fclose(dlevel);
		}//level 1 clear and update file 
		
		do{
			printf("Enter (1) to next: ");
			scanf("%s",&next);
		}while(strcmp(next,"1")!=0); 
	
	}//level 1 end
	
	//start level 2
	else if(level==2){
		if(coin<=0){
			coin = 200;
		}
		cdeng = 1;
		pdeng = 1;
		playerpoint1 = 0;
		playerpoint2 = 0;
		compoint1 = 0;
		compoint2 = 0;
	
	//do while loop for bet coin
		do{
			system("clear");
			printf("***** Level = %d *****\n",level);	
			printf("***** Coin = %d *****\n",coin);
			printf("\nHow many coin do you want to bet(1-Allcoin)\n");
			printf("Enter coin: ");
			scanf("%d",&bet);
		}while(bet>coin||bet<1);
		
	//print animation	
		starting();
	
	do{
	
	//generate number card and keep in array
		for(i=0;i<13;i++){
			s_num[i] = i;
			h_num[i] = i;
			c_num[i] = i;
			d_num[i] = i;
		}
		
	//random 6 card
		cardrand(0,rnum,intcard,tcard,type_card,rtype2,s_num,card.spade,h_num,card.heart,c_num,card.clover,d_num,card.diamond);
		cardrand(1,rnum,intcard,tcard,type_card,rtype2,s_num,card.spade,h_num,card.heart,c_num,card.clover,d_num,card.diamond);
		cardrand(2,rnum,intcard,tcard,type_card,rtype2,s_num,card.spade,h_num,card.heart,c_num,card.clover,d_num,card.diamond);
		cardrand(3,rnum,intcard,tcard,type_card,rtype2,s_num,card.spade,h_num,card.heart,c_num,card.clover,d_num,card.diamond);
		cardrand(4,rnum,intcard,tcard,type_card,rtype2,s_num,card.spade,h_num,card.heart,c_num,card.clover,d_num,card.diamond);
		cardrand(5,rnum,intcard,tcard,type_card,rtype2,s_num,card.spade,h_num,card.heart,c_num,card.clover,d_num,card.diamond);
	
	//generate point for 6 card and keep in array
		for(i=0;i<6;i++){
			num_card[i] = ncard[rnum[i]];
		}
	
	//Calculate point 6 card
		for(i=0;i<6;i++){
			if(rnum[i]>=9){
				rnum[i]=10;
			}
			else{
				rnum[i]=rnum[i]+1;
			}
		}
		
	//Calculate player point and computer point	
		compoint1 = rnum[1] + rnum[3];
		compoint2 = rnum[1] + rnum[3] + rnum[5];
		playerpoint1 = rnum[0] + rnum[2];
		playerpoint2 = rnum[0] + rnum[2] + rnum[4];
	
	//check playerpoint
		playerpoint1 = checkplayerpoint(playerpoint1);
		playerpoint2 = checkplayerpoint(playerpoint2);

	//check computerpoint
		compoint1 = checkcompoint(compoint1);
		compoint2 = checkcompoint(compoint2);
	
	}while(compoint2<6);
	
		printf("	Level: %d\n",level);
		
		if(compoint1>=8){
			cdeng = cdeng2(intcard,cdeng);
			pdeng = pdeng2(intcard,pdeng);
			outputcom2(num_card,type_card,compoint1);
			coin = checkwin(playerpoint1,compoint1,coin,pdeng,cdeng,bet);
			outputplayer2(num_card,type_card,playerpoint1);
		}
		
		else if((playerpoint1>=8)&&(compoint1>=6)){	
			cdeng = cdeng2(intcard,cdeng);
			pdeng = pdeng2(intcard,pdeng);
			outputcom2(num_card,type_card,compoint1);
			coin = checkwin(playerpoint1,compoint1,coin,pdeng,cdeng,bet);
			outputplayer2(num_card,type_card,playerpoint1);
		}
	
		else if((playerpoint1>=8)&&(compoint1<6)){	
			cdeng = cdeng3(intcard,cdeng);
			pdeng = pdeng2(intcard,pdeng);
			outputcom3(num_card,type_card,compoint2);
			coin = checkwin(playerpoint1,compoint2,coin,pdeng,cdeng,bet);
			outputplayer2(num_card,type_card,playerpoint1);
		}
		
		else{
			do{
				system("clear");
				printf("Level: %d\n",level);
				outputplayer2(num_card,type_card,playerpoint1);
				
				printf("Do you want more card?\n");
				printf("(1)Yes (2)No: ");
				scanf("%s",&thirdCard);
			}while(strcmp(thirdCard,"1")!=0 && strcmp(thirdCard,"2")!=0); 
			
			if(strcmp(thirdCard,"1")==0){
				Draw = 1;
			}
			else if(strcmp(thirdCard,"2")==0){
				Draw = 2;
			}
		
			switch(Draw){
				
			case 1: system("clear");
				printf("Level: %d\n",level);
				if(compoint1<6){
					cdeng = cdeng3(intcard,cdeng);
					pdeng = pdeng3(intcard,pdeng);
					outputcom3(num_card,type_card,compoint2);
					coin = checkwin(playerpoint2,compoint2,coin,pdeng,cdeng,bet);
					outputplayer3(num_card,type_card,playerpoint2);	
				}
				else if(compoint1>=6){
					cdeng = cdeng2(intcard,cdeng);
					pdeng = pdeng3(intcard,pdeng);
					outputcom2(num_card,type_card,compoint1);
					coin = checkwin(playerpoint2,compoint1,coin,pdeng,cdeng,bet);
					outputplayer3(num_card,type_card,playerpoint2);
				}		
				break;
		
				case 2: system("clear");
					printf("Level: %d\n",level);
					if(compoint1<6){
						cdeng = cdeng3(intcard,cdeng);
						pdeng = pdeng2(intcard,pdeng);
						outputcom3(num_card,type_card,compoint2);
						coin = checkwin(playerpoint1,compoint2,coin,pdeng,cdeng,bet);
						outputplayer2(num_card,type_card,playerpoint1);
					}
					else if(compoint1>=6){
						cdeng = cdeng2(intcard,cdeng);
						pdeng = pdeng2(intcard,pdeng);
						outputcom2(num_card,type_card,compoint1);
						coin = checkwin(playerpoint1,compoint1,coin,pdeng,cdeng,bet);
						outputplayer2(num_card,type_card,playerpoint1);
					}
				break;
				
			}//switch draw
			
		}//Player input number for draw a card
		
	//read file
		int coin2[alluse],level2[alluse];
		dcoin = fopen("coin.txt","r");	
		dlevel = fopen("level.txt","r");
		for(i=1;i<=alluse;i++){
			fscanf(dcoin,"%d\n",&coin2[i]);
			fscanf(dlevel,"%d\n",&level2[i]);
		}
		coin2[size+1] = coin;
		level2[size+1] = level;
		fclose(dcoin);
		fclose(dlevel);
	
	//update file
		dcoin = fopen("coin.txt","w");	
		dlevel = fopen("level.txt","w");
		for(i=1;i<=alluse;i++){
			fprintf(dcoin,"%d\n",coin2[i]);
			fprintf(dlevel,"%d\n",level2[i]);
		}
		fclose(dcoin);
		fclose(dlevel);
	
		if(coin>=500){
			printf("***** Level:2 Clear!! *****\n");
			level = 3;
			coin = 1000;
			
			int coin2[alluse],level2[alluse];
			dcoin = fopen("coin.txt","r");	
			dlevel = fopen("level.txt","r");
			for(i=1;i<=alluse;i++){
				fscanf(dcoin,"%d\n",&coin2[i]);
				fscanf(dlevel,"%d\n",&level2[i]);
			}
			coin2[size+1] = coin;
			level2[size+1] = level;
			fclose(dcoin);
			fclose(dlevel);
				
			dcoin = fopen("coin.txt","w");	
			dlevel = fopen("level.txt","w");	
			for(i=1;i<=alluse;i++){
				fprintf(dcoin,"%d\n",coin2[i]);
				fprintf(dlevel,"%d\n",level2[i]);
			}
			fclose(dcoin);
			fclose(dlevel);
		}//level 2 clear and update file 
		
		do{
			printf("Enter (1) to next: ");
			scanf("%s",&next);
		}while(strcmp(next,"1")!=0); 
	
	}//level 2 end
	
	//start level 3
		else if(level==3){
		if(coin<100){
			coin = 1000;
		}
		cdeng = 1;
		pdeng = 1;
		playerpoint1 = 0;
		playerpoint2 = 0;
		compoint1 = 0;
		compoint2 = 0;
	
	//do while loop for bet coin
		do{
			system("clear");
			printf("***** Level = %d *****\n",level);	
			printf("***** Coin = %d *****\n",coin);
			printf("\nHow many coin do you want to bet(100-Allcoin)\n");
			printf("Enter coin: ");
			scanf("%d",&bet);
		}while(bet>coin||bet<100);
		
	//print animation	
		starting();
	
	//generate number card and keep in array
		for(i=0;i<13;i++){
			s_num[i] = i;
			h_num[i] = i;
			c_num[i] = i;
			d_num[i] = i;
		}
		
	//random 6 card
		cardrand(0,rnum,intcard,tcard,type_card,rtype2,s_num,card.spade,h_num,card.heart,c_num,card.clover,d_num,card.diamond);
		cardrand(1,rnum,intcard,tcard,type_card,rtype2,s_num,card.spade,h_num,card.heart,c_num,card.clover,d_num,card.diamond);
		cardrand(2,rnum,intcard,tcard,type_card,rtype2,s_num,card.spade,h_num,card.heart,c_num,card.clover,d_num,card.diamond);
		cardrand(3,rnum,intcard,tcard,type_card,rtype2,s_num,card.spade,h_num,card.heart,c_num,card.clover,d_num,card.diamond);
		cardrand(4,rnum,intcard,tcard,type_card,rtype2,s_num,card.spade,h_num,card.heart,c_num,card.clover,d_num,card.diamond);
		cardrand(5,rnum,intcard,tcard,type_card,rtype2,s_num,card.spade,h_num,card.heart,c_num,card.clover,d_num,card.diamond);
	
	//generate point for 6 card and keep in array
		for(i=0;i<6;i++){
			num_card[i] = ncard[rnum[i]];
		}
	
	//Calculate point 6 card
		for(i=0;i<6;i++){
			if(rnum[i]>=9){
				rnum[i]=10;
			}
			else{
				rnum[i]=rnum[i]+1;
			}
		}
		
	//Calculate player point and computer point	
		compoint1 = rnum[1] + rnum[3];
		compoint2 = rnum[1] + rnum[3] + rnum[5];
		playerpoint1 = rnum[0] + rnum[2];
		playerpoint2 = rnum[0] + rnum[2] + rnum[4];
	
	//check playerpoint
		playerpoint1 = checkplayerpoint(playerpoint1);
		playerpoint2 = checkplayerpoint(playerpoint2);

	//check computerpoint
		compoint1 = checkcompoint(compoint1);
		compoint2 = checkcompoint(compoint2);

	//When player point in first random >= 8
	if(playerpoint1>=8||playerpoint2>=8){
		
		for(i=0;i<13;i++){
			s_num[i] = i;
			h_num[i] = i;
			c_num[i] = i;
			d_num[i] = i;
		}
	
	cardrand(0,rnum,intcard,tcard,type_card,rtype2,s_num,card.spade,h_num,card.heart,c_num,card.clover,d_num,card.diamond);
	cardrand(1,rnum,intcard,tcard,type_card,rtype2,s_num,card.spade,h_num,card.heart,c_num,card.clover,d_num,card.diamond);
	cardrand(2,rnum,intcard,tcard,type_card,rtype2,s_num,card.spade,h_num,card.heart,c_num,card.clover,d_num,card.diamond);
	cardrand(3,rnum,intcard,tcard,type_card,rtype2,s_num,card.spade,h_num,card.heart,c_num,card.clover,d_num,card.diamond);
	cardrand(4,rnum,intcard,tcard,type_card,rtype2,s_num,card.spade,h_num,card.heart,c_num,card.clover,d_num,card.diamond);
	cardrand(5,rnum,intcard,tcard,type_card,rtype2,s_num,card.spade,h_num,card.heart,c_num,card.clover,d_num,card.diamond);
	
		for(i=0;i<6;i++){
			num_card[i] = ncard[rnum[i]];
		}
	
		
		for(i=0;i<6;i++){
			if(rnum[i]>=9){
				rnum[i]=10;
			}
			else{
				rnum[i]=rnum[i]+1;
			}
		}
		compoint1 = rnum[1] + rnum[3];
		compoint2 = rnum[1] + rnum[3] + rnum[5];
		playerpoint1 = rnum[0] + rnum[2];
		playerpoint2 = rnum[0] + rnum[2] + rnum[4];
	
	
		//check playerpoint
		playerpoint1 = checkplayerpoint(playerpoint1);
		playerpoint2 = checkplayerpoint(playerpoint2);

		//check computerpoint
		compoint1 = checkcompoint(compoint1);
		compoint2 = checkcompoint(compoint2);
		
	}//player point in first random >= 8
	
		printf("	Level: %d\n",level);
		
		if(compoint1>=8){
			cdeng = cdeng2(intcard,cdeng);
			pdeng = pdeng2(intcard,pdeng);
			outputcom2(num_card,type_card,compoint1);
			coin = checkwin(playerpoint1,compoint1,coin,pdeng,cdeng,bet);
			outputplayer2(num_card,type_card,playerpoint1);
		}
		
		else if((playerpoint1>=8)&&(compoint1>=6)){	
			cdeng = cdeng2(intcard,cdeng);
			pdeng = pdeng2(intcard,pdeng);
			outputcom2(num_card,type_card,compoint1);
			coin = checkwin(playerpoint1,compoint1,coin,pdeng,cdeng,bet);
			outputplayer2(num_card,type_card,playerpoint1);
		}
	
		else if((playerpoint1>=8)&&(compoint1<6)){	
			cdeng = cdeng3(intcard,cdeng);
			pdeng = pdeng2(intcard,pdeng);
			outputcom3(num_card,type_card,compoint2);
			coin = checkwin(playerpoint1,compoint2,coin,pdeng,cdeng,bet);
			outputplayer2(num_card,type_card,playerpoint1);
		}
		
		else{
			do{
				system("clear");
				printf("Level: %d\n",level);
				outputplayer2(num_card,type_card,playerpoint1);
				
				printf("Do you want more card?\n");
				printf("(1)Yes (2)No: ");
				scanf("%s",&thirdCard);
			}while(strcmp(thirdCard,"1")!=0 && strcmp(thirdCard,"2")!=0); 
			
			if(strcmp(thirdCard,"1")==0){
				Draw = 1;
			}
			else if(strcmp(thirdCard,"2")==0){
				Draw = 2;
			}
		
			switch(Draw){
				
			case 1: system("clear");
				printf("Level: %d\n",level);
				if(compoint1<6){
					cdeng = cdeng3(intcard,cdeng);
					pdeng = pdeng3(intcard,pdeng);
					outputcom3(num_card,type_card,compoint2);
					coin = checkwin(playerpoint2,compoint2,coin,pdeng,cdeng,bet);
					outputplayer3(num_card,type_card,playerpoint2);	
				}
				else if(compoint1>=6){
					cdeng = cdeng2(intcard,cdeng);
					pdeng = pdeng3(intcard,pdeng);
					outputcom2(num_card,type_card,compoint1);
					coin = checkwin(playerpoint2,compoint1,coin,pdeng,cdeng,bet);
					outputplayer3(num_card,type_card,playerpoint2);
				}		
				break;
		
				case 2: system("clear");
					printf("Level: %d\n",level);
					if(compoint1<6){
						cdeng = cdeng3(intcard,cdeng);
						pdeng = pdeng2(intcard,pdeng);
						outputcom3(num_card,type_card,compoint2);
						coin = checkwin(playerpoint1,compoint2,coin,pdeng,cdeng,bet);
						outputplayer2(num_card,type_card,playerpoint1);
					}
					else if(compoint1>=6){
						cdeng = cdeng2(intcard,cdeng);
						pdeng = pdeng2(intcard,pdeng);
						outputcom2(num_card,type_card,compoint1);
						coin = checkwin(playerpoint1,compoint1,coin,pdeng,cdeng,bet);
						outputplayer2(num_card,type_card,playerpoint1);
					}
				break;
				
			}//switch draw
			
		}//Player input number for draw a card
		
	//read file
		int coin2[alluse],level2[alluse];
		dcoin = fopen("coin.txt","r");	
		dlevel = fopen("level.txt","r");
		for(i=1;i<=alluse;i++){
			fscanf(dcoin,"%d\n",&coin2[i]);
			fscanf(dlevel,"%d\n",&level2[i]);
		}
		coin2[size+1] = coin;
		level2[size+1] = level;
		fclose(dcoin);
		fclose(dlevel);
	
	//update file
		dcoin = fopen("coin.txt","w");	
		dlevel = fopen("level.txt","w");
		for(i=1;i<=alluse;i++){
			fprintf(dcoin,"%d\n",coin2[i]);
			fprintf(dlevel,"%d\n",level2[i]);
		}
		fclose(dcoin);
		fclose(dlevel);
	
		if(coin>=1000){
			printf("***** Level:3 Clear!! *****\n");
			level = 4;
			coin = 1000;
			
			int coin2[alluse],level2[alluse];
			dcoin = fopen("coin.txt","r");	
			dlevel = fopen("level.txt","r");
			for(i=1;i<=alluse;i++){
				fscanf(dcoin,"%d\n",&coin2[i]);
				fscanf(dlevel,"%d\n",&level2[i]);
			}
			coin2[size+1] = coin;
			level2[size+1] = level;
			fclose(dcoin);
			fclose(dlevel);
				
			dcoin = fopen("coin.txt","w");	
			dlevel = fopen("level.txt","w");	
			for(i=1;i<=alluse;i++){
				fprintf(dcoin,"%d\n",coin2[i]);
				fprintf(dlevel,"%d\n",level2[i]);
			}
			fclose(dcoin);
			fclose(dlevel);
		}//level 3 clear and update file 
				
		do{
			printf("Enter (1) to next: ");
			scanf("%s",&next);
		}while(strcmp(next,"1")!=0); 
	
	}//level 3 end 
	
	//start level 4
		else if(level==4){
		if(coin<1000){
			coin = 10000;
		}
		cdeng = 1;
		pdeng = 1;
		playerpoint1 = 0;
		playerpoint2 = 0;
		compoint1 = 0;
		compoint2 = 0;
	
	//do while loop for bet coin
		do{
			system("clear");
			printf("***** Level = %d *****\n",level);	
			printf("***** Coin = %d *****\n",coin);
			printf("\nHow many coin do you want to bet(1000-Allcoin)\n");
			printf("Enter coin: ");
			scanf("%d",&bet);
		}while(bet>coin||bet<1000);
		
	//print animation	
		starting();
	
	do{
	//generate number card and keep in array
		for(i=0;i<13;i++){
			s_num[i] = i;
			h_num[i] = i;
			c_num[i] = i;
			d_num[i] = i;
		}
		
	//random 6 card
		cardrand(0,rnum,intcard,tcard,type_card,rtype2,s_num,card.spade,h_num,card.heart,c_num,card.clover,d_num,card.diamond);
		cardrand(1,rnum,intcard,tcard,type_card,rtype2,s_num,card.spade,h_num,card.heart,c_num,card.clover,d_num,card.diamond);
		cardrand(2,rnum,intcard,tcard,type_card,rtype2,s_num,card.spade,h_num,card.heart,c_num,card.clover,d_num,card.diamond);
		cardrand(3,rnum,intcard,tcard,type_card,rtype2,s_num,card.spade,h_num,card.heart,c_num,card.clover,d_num,card.diamond);
		cardrand(4,rnum,intcard,tcard,type_card,rtype2,s_num,card.spade,h_num,card.heart,c_num,card.clover,d_num,card.diamond);
		cardrand(5,rnum,intcard,tcard,type_card,rtype2,s_num,card.spade,h_num,card.heart,c_num,card.clover,d_num,card.diamond);
	
	//generate point for 6 card and keep in array
		for(i=0;i<6;i++){
			num_card[i] = ncard[rnum[i]];
		}
	
	//Calculate point 6 card
		for(i=0;i<6;i++){
			if(rnum[i]>=9){
				rnum[i]=10;
			}
			else{
				rnum[i]=rnum[i]+1;
			}
		}
		
	//Calculate player point and computer point	
		compoint1 = rnum[1] + rnum[3];
		compoint2 = rnum[1] + rnum[3] + rnum[5];
		playerpoint1 = rnum[0] + rnum[2];
		playerpoint2 = rnum[0] + rnum[2] + rnum[4];
	
	//check playerpoint
		playerpoint1 = checkplayerpoint(playerpoint1);
		playerpoint2 = checkplayerpoint(playerpoint2);

	//check computerpoint
		compoint1 = checkcompoint(compoint1);
		compoint2 = checkcompoint(compoint2);
		
	}while(compoint2<0);
	
		printf("	Level: %d\n",level);
		
		if(compoint1>=8){
			cdeng = cdeng2(intcard,cdeng);
			pdeng = pdeng2(intcard,pdeng);
			outputcom2(num_card,type_card,compoint1);
			coin = checkwin(playerpoint1,compoint1,coin,pdeng,cdeng,bet);
			outputplayer2(num_card,type_card,playerpoint1);
		}
		
		else if((playerpoint1>=8)&&(compoint1>=6)){	
			cdeng = cdeng2(intcard,cdeng);
			pdeng = pdeng2(intcard,pdeng);
			outputcom2(num_card,type_card,compoint1);
			coin = checkwin(playerpoint1,compoint1,coin,pdeng,cdeng,bet);
			outputplayer2(num_card,type_card,playerpoint1);
		}
	
		else if((playerpoint1>=8)&&(compoint1<6)){	
			cdeng = cdeng3(intcard,cdeng);
			pdeng = pdeng2(intcard,pdeng);
			outputcom3(num_card,type_card,compoint2);
			coin = checkwin(playerpoint1,compoint2,coin,pdeng,cdeng,bet);
			outputplayer2(num_card,type_card,playerpoint1);
		}
		
		else{
			do{
				system("clear");
				printf("Level: %d\n",level);
				outputplayer2(num_card,type_card,playerpoint1);
				
				printf("Do you want more card?\n");
				printf("(1)Yes (2)No: ");
				scanf("%s",&thirdCard);
			}while(strcmp(thirdCard,"1")!=0 && strcmp(thirdCard,"2")!=0); 
			
			if(strcmp(thirdCard,"1")==0){
				Draw = 1;
			}
			else if(strcmp(thirdCard,"2")==0){
				Draw = 2;
			}
		
			switch(Draw){
				
			case 1: system("clear");
				printf("Level: %d\n",level);
				if(compoint1<6){
					cdeng = cdeng3(intcard,cdeng);
					pdeng = pdeng3(intcard,pdeng);
					outputcom3(num_card,type_card,compoint2);
					coin = checkwin(playerpoint2,compoint2,coin,pdeng,cdeng,bet);
					outputplayer3(num_card,type_card,playerpoint2);	
				}
				else if(compoint1>=6){
					cdeng = cdeng2(intcard,cdeng);
					pdeng = pdeng3(intcard,pdeng);
					outputcom2(num_card,type_card,compoint1);
					coin = checkwin(playerpoint2,compoint1,coin,pdeng,cdeng,bet);
					outputplayer3(num_card,type_card,playerpoint2);
				}		
				break;
		
				case 2: system("clear");
					printf("Level: %d\n",level);
					if(compoint1<6){
						cdeng = cdeng3(intcard,cdeng);
						pdeng = pdeng2(intcard,pdeng);
						outputcom3(num_card,type_card,compoint2);
						coin = checkwin(playerpoint1,compoint2,coin,pdeng,cdeng,bet);
						outputplayer2(num_card,type_card,playerpoint1);
					}
					else if(compoint1>=6){
						cdeng = cdeng2(intcard,cdeng);
						pdeng = pdeng2(intcard,pdeng);
						outputcom2(num_card,type_card,compoint1);
						coin = checkwin(playerpoint1,compoint1,coin,pdeng,cdeng,bet);
						outputplayer2(num_card,type_card,playerpoint1);
					}
				break;
				
			}//switch draw
			
		}//Player input number for draw a card
		
	//read file
		int coin2[alluse],level2[alluse];
		dcoin = fopen("coin.txt","r");	
		dlevel = fopen("level.txt","r");
		for(i=1;i<=alluse;i++){
			fscanf(dcoin,"%d\n",&coin2[i]);
			fscanf(dlevel,"%d\n",&level2[i]);
		}
		coin2[size+1] = coin;
		level2[size+1] = level;
		fclose(dcoin);
		fclose(dlevel);
	
	//update file
		dcoin = fopen("coin.txt","w");	
		dlevel = fopen("level.txt","w");
		for(i=1;i<=alluse;i++){
			fprintf(dcoin,"%d\n",coin2[i]);
			fprintf(dlevel,"%d\n",level2[i]);
		}
		fclose(dcoin);
		fclose(dlevel);
	
		if(coin>=10000){
			printf("***** Level:4 Clear!! *****\n");
			level = 5;
			coin = 10000;
			
			int coin2[alluse],level2[alluse];
			dcoin = fopen("coin.txt","r");	
			dlevel = fopen("level.txt","r");
			for(i=1;i<=alluse;i++){
				fscanf(dcoin,"%d\n",&coin2[i]);
				fscanf(dlevel,"%d\n",&level2[i]);
			}
			coin2[size+1] = coin;
			level2[size+1] = level;
			fclose(dcoin);
			fclose(dlevel);
				
			dcoin = fopen("coin.txt","w");	
			dlevel = fopen("level.txt","w");	
			for(i=1;i<=alluse;i++){
				fprintf(dcoin,"%d\n",coin2[i]);
				fprintf(dlevel,"%d\n",level2[i]);
			}
			fclose(dcoin);
			fclose(dlevel);
		}//level 4 clear and update file 
		
		do{
			printf("Enter (1) to next: ");
			scanf("%s",&next);
		}while(strcmp(next,"1")!=0); 
	
	}//level 4 end
	
	//start level 5
	else if(level==5){
		if(coin<=1000){
			coin = 10000;
		}
		cdeng = 1;
		pdeng = 1;
		playerpoint1 = 0;
		playerpoint2 = 0;
		compoint1 = 0;
		compoint2 = 0;
	
	//do while loop for bet coin
		do{
			system("clear");
			printf("***** Level = %d *****\n",level);	
			printf("***** Coin = %d *****\n",coin);
			printf("\nHow many coin do you want to bet(1000-Allcoin)\n");
			printf("Enter coin: ");
			scanf("%d",&bet);
		}while(bet<1000||bet>coin);
		
	//print animation
		starting();
	
	do{
	//generate number card and keep in array
		for(i=0;i<13;i++){
			s_num[i] = i;
			h_num[i] = i;
			c_num[i] = i;
			d_num[i] = i;
		}
		
	//random 6 card
		cardrand(0,rnum,intcard,tcard,type_card,rtype2,s_num,card.spade,h_num,card.heart,c_num,card.clover,d_num,card.diamond);
		cardrand(1,rnum,intcard,tcard,type_card,rtype2,s_num,card.spade,h_num,card.heart,c_num,card.clover,d_num,card.diamond);
		cardrand(2,rnum,intcard,tcard,type_card,rtype2,s_num,card.spade,h_num,card.heart,c_num,card.clover,d_num,card.diamond);
		cardrand(3,rnum,intcard,tcard,type_card,rtype2,s_num,card.spade,h_num,card.heart,c_num,card.clover,d_num,card.diamond);
		cardrand(4,rnum,intcard,tcard,type_card,rtype2,s_num,card.spade,h_num,card.heart,c_num,card.clover,d_num,card.diamond);
		cardrand(5,rnum,intcard,tcard,type_card,rtype2,s_num,card.spade,h_num,card.heart,c_num,card.clover,d_num,card.diamond);
	
	//generate point for 6 card and keep in array
		for(i=0;i<6;i++){
			num_card[i] = ncard[rnum[i]];
		}
	
	//Calculate point 6 card
		for(i=0;i<6;i++){
			if(rnum[i]>=9){
				rnum[i]=10;
			}
			else{
				rnum[i]=rnum[i]+1;
			}
		}
		
	//Calculate player point and computer point	
		compoint1 = rnum[1] + rnum[3];
		compoint2 = rnum[1] + rnum[3] + rnum[5];
		playerpoint1 = rnum[0] + rnum[2];
		playerpoint2 = rnum[0] + rnum[2] + rnum[4];
	
	//check playerpoint
		playerpoint1 = checkplayerpoint(playerpoint1);
		playerpoint2 = checkplayerpoint(playerpoint2);

	//check computerpoint
		compoint1 = checkcompoint(compoint1);
		compoint2 = checkcompoint(compoint2);
	
	}while(compoint2<7);
	
		printf("	Level: %d\n",level);
		
		if(compoint1>=8){
			cdeng = cdeng2(intcard,cdeng);
			pdeng = pdeng2(intcard,pdeng);
			outputcom2(num_card,type_card,compoint1);
			coin = checkwin(playerpoint1,compoint1,coin,pdeng,cdeng,bet);
			outputplayer2(num_card,type_card,playerpoint1);
		}
		
		else if((playerpoint1>=8)&&(compoint1>=6)){	
			cdeng = cdeng2(intcard,cdeng);
			pdeng = pdeng2(intcard,pdeng);
			outputcom2(num_card,type_card,compoint1);
			coin = checkwin(playerpoint1,compoint1,coin,pdeng,cdeng,bet);
			outputplayer2(num_card,type_card,playerpoint1);
		}
	
		else if((playerpoint1>=8)&&(compoint1<6)){	
			cdeng = cdeng3(intcard,cdeng);
			pdeng = pdeng2(intcard,pdeng);
			outputcom3(num_card,type_card,compoint2);
			coin = checkwin(playerpoint1,compoint2,coin,pdeng,cdeng,bet);
			outputplayer2(num_card,type_card,playerpoint1);
		}
		
		else{
			do{
				system("clear");
				printf("Level: %d\n",level);
				outputplayer2(num_card,type_card,playerpoint1);
				
				printf("Do you want more card?\n");
				printf("(1)Yes (2)No: ");
				scanf("%s",&thirdCard);
			}while(strcmp(thirdCard,"1")!=0 && strcmp(thirdCard,"2")!=0); 
			
			if(strcmp(thirdCard,"1")==0){
				Draw = 1;
			}
			else if(strcmp(thirdCard,"2")==0){
				Draw = 2;
			}
		
			switch(Draw){
				
			case 1: system("clear");
				printf("Level: %d\n",level);
				if(compoint1<6){
					cdeng = cdeng3(intcard,cdeng);
					pdeng = pdeng3(intcard,pdeng);
					outputcom3(num_card,type_card,compoint2);
					coin = checkwin(playerpoint2,compoint2,coin,pdeng,cdeng,bet);
					outputplayer3(num_card,type_card,playerpoint2);	
				}
				else if(compoint1>=6){
					cdeng = cdeng2(intcard,cdeng);
					pdeng = pdeng3(intcard,pdeng);
					outputcom2(num_card,type_card,compoint1);
					coin = checkwin(playerpoint2,compoint1,coin,pdeng,cdeng,bet);
					outputplayer3(num_card,type_card,playerpoint2);
				}		
				break;
		
				case 2: system("clear");
					printf("Level: %d\n",level);
					if(compoint1<6){
						cdeng = cdeng3(intcard,cdeng);
						pdeng = pdeng2(intcard,pdeng);
						outputcom3(num_card,type_card,compoint2);
						coin = checkwin(playerpoint1,compoint2,coin,pdeng,cdeng,bet);
						outputplayer2(num_card,type_card,playerpoint1);
					}
					else if(compoint1>=6){
						cdeng = cdeng2(intcard,cdeng);
						pdeng = pdeng2(intcard,pdeng);
						outputcom2(num_card,type_card,compoint1);
						coin = checkwin(playerpoint1,compoint1,coin,pdeng,cdeng,bet);
						outputplayer2(num_card,type_card,playerpoint1);
					}
				break;
				
			}//switch draw
			
		}//Player input number for draw a card
		
	//read file
		int coin2[alluse],level2[alluse];
		dcoin = fopen("coin.txt","r");	
		dlevel = fopen("level.txt","r");
		for(i=1;i<=alluse;i++){
			fscanf(dcoin,"%d\n",&coin2[i]);
			fscanf(dlevel,"%d\n",&level2[i]);
		}
		coin2[size+1] = coin;
		level2[size+1] = level;
		fclose(dcoin);
		fclose(dlevel);
	
	//update file
		dcoin = fopen("coin.txt","w");	
		dlevel = fopen("level.txt","w");
		for(i=1;i<=alluse;i++){
			fprintf(dcoin,"%d\n",coin2[i]);
			fprintf(dlevel,"%d\n",level2[i]);
		}
		fclose(dcoin);
		fclose(dlevel);
	
		if(coin>=100000){
			printf("***** Level:5 Clear!! *****\n");
			level = 6;
			coin = 100000;
			
			int coin2[alluse],level2[alluse];
			dcoin = fopen("coin.txt","r");	
			dlevel = fopen("level.txt","r");
			for(i=1;i<=alluse;i++){
				fscanf(dcoin,"%d\n",&coin2[i]);
				fscanf(dlevel,"%d\n",&level2[i]);
			}
			coin2[size+1] = coin;
			level2[size+1] = level;
			fclose(dcoin);
			fclose(dlevel);
				
			dcoin = fopen("coin.txt","w");	
			dlevel = fopen("level.txt","w");	
			for(i=1;i<=alluse;i++){
				fprintf(dcoin,"%d\n",coin2[i]);
				fprintf(dlevel,"%d\n",level2[i]);
			}
			fclose(dcoin);
			fclose(dlevel);
		}//level 5 clear and update file 
		
		do{
			printf("Enter (1) to next: ");
			scanf("%s",&next);
		}while(strcmp(next,"1")!=0); 
	
	}//level 5 end
	
	else if(level==6){
		printf("*************************************************\n\n");
		printf("	- Now you can clear all level\n");
		printf("	- We will update another level in the future\n");
		printf("\n*************************************************\n");
	}
	
		do{
			system("clear");
			printf("Now Level = %d\n",level);
			printf("Now coin = %d\n",coin);
			printf("*************** MENU ***************\n");
			printf("	(1): Play again\n	(2): Back to menu start\n	(3): Exit game\n");
			printf("************************************\n");
			printf("Enter menu: ");
			scanf("%s",&Playagain);
		}while(strcmp(Playagain,"1")!=0 && strcmp(Playagain,"2")!=0 && strcmp(Playagain,"3")!=0); 
	
		}while(strcmp(Playagain,"2")!=0 && strcmp(Playagain,"3")!=0);
		
		if(strcmp(Playagain,"2")==0){
			backtostart = 1;
			continue ;
		}
			
		else if(strcmp(Playagain,"3")==0){
			system("clear");
			printf("\n	***** GOODBYE!! *****\n");
			return 0;
		}
	
	} //case 1
		
	if(strcmp(PDGame,"2")==0){
		char M_Info[2];
		int CardP01,CardP02,ans;
		do{
			system("clear");
			printf("************************************ Infomation ************************************\n");
			printf("	(1): All Card\n");
			printf("	(2): Rules\n");
			printf("	(3): How to clear game\n");
			printf("Enter menu: ");
			scanf("%s",M_Info);
		}while(strcmp(M_Info,"1")!=0 && strcmp(M_Info,"2")!=0 && strcmp(M_Info,"3")!=0);
		if(strcmp(M_Info,"1")==0){
		system("clear");
				printf("************************************ CARD ************************************\n");
				for(i=0;i<13;i++){
					printf("	%s	%s	%s	%s\n",card.spade[i],card.heart[i],card.clover[i],card.diamond[i]);
				}
				printf("******************************************************************************\n");
			}
		else if(strcmp(M_Info,"2")==0){
			system("clear");
			printf("************************************ RULES ************************************\n");
			printf(" 1. If your point >= 10 ,Yourpoint = yourpoint % 10\n");
			printf(" 2. If computer point < 8 ,You can draw card\n");
			printf(" 3. If computer point >= 8 ,You can not draw card\n");
			printf(" 4. If Your point >= 8 ,You can not draw card but computer can draw card\n");
			printf(" 5. If Your coin < min bet coin your coin will reset to begin\n");
		}
		else if(strcmp(M_Info,"3")==0){
			system("clear");
			printf("******************************* How to clear game *******************************\n");
			printf("  level(1) Keep coin >= 200\n");
			printf("  level(2) Keep coin >= 500\n");
			printf("  level(3) Keep coin >= 1000\n");
			printf("  level(4) Keep coin >= 10000\n");
			printf("  level(5) Keep coin >= 100000\n");
		}
			do{
				printf("\n(1): Back to menu start\n(2): Exit game\n");
				printf("Enter menu: ");
				scanf("%s",&Start);
			}while(strcmp(Start,"1")!=0 && strcmp(Start,"2")!=0); 
			
	} //case 2
		
	if(strcmp(PDGame,"3")==0){
				system("clear");
				struct USER{
					char ruser[20];
					char rpass[20];
				};
				struct USER Rank[alluse];
				char tuser[20];
				int rcoin[alluse];
				int rlevel[alluse];
				int templ,tempc;
				
				data = fopen("user.txt","r");
				dcoin = fopen("coin.txt","r");	
				dlevel = fopen("level.txt","r");
				for(i=0;i<alluse;i++){
					fscanf(data,"%s\n",Rank[i].ruser);
					fscanf(data,"%s\n",Rank[i].rpass);
					fscanf(dcoin,"%d\n",&rcoin[i]);
					fscanf(dlevel,"%d\n",&rlevel[i]);
				}
				
				for(i=1;i<alluse;i++){
					for(j=1;j<i;j++){
						if(rlevel[i]>rlevel[j]){
							templ = rlevel[i];
							rlevel[i] = rlevel[j];
							rlevel[j] = templ;
							tempc = rcoin[i];
							rcoin[i] = rcoin[j];
							rcoin[j] = tempc;
							strcpy(tuser,Rank[i].ruser);
							strcpy(Rank[i].ruser,Rank[j].ruser);
							strcpy(Rank[j].ruser,tuser);	
						}
					}
				}
				for(i=1;i<alluse;i++){
					for(j=1;j<i;j++){
						if(rlevel[i]==rlevel[j] && rcoin[i]>rcoin[j]){
							templ = rlevel[i];
							rlevel[i] = rlevel[j];
							rlevel[j] = templ;
							tempc = rcoin[i];
							rcoin[i] = rcoin[j];
							rcoin[j] = tempc;
							strcpy(tuser,Rank[i].ruser);
							strcpy(Rank[i].ruser,Rank[j].ruser);
							strcpy(Rank[j].ruser,tuser);	
						}
					}
				}
				
				for(i=1;i<alluse;i++){
				}
					printf("********************************* Ranking *********************************\n\n");
					printf("	No.		Level		Coin		Player\n\n");		
				for(i=1;i<alluse;i++){
					printf("	%d		%d		%d		%s\n",i,rlevel[i],rcoin[i],Rank[i].ruser);
				}
				fclose(dcoin);
				fclose(dlevel);

			do{
				printf("\n(1): Back to menu start\n(2): Exit game\n");
				printf("Enter menu: ");
				scanf("%s",&Start);
			}while(strcmp(Start,"1")!=0 && strcmp(Start,"2")!=0); 
	
	} //case 3
		
	if(strcmp(PDGame,"4")==0){
		system("clear");
		printf("\n	***** GOODBYE!! *****\n");
		return 0;	
	} //case 4 
	
	}while(backtostart==1);
	
	}while(strcmp(Start,"1")==0); //Back to Menu Start
	
	return 0;
}
