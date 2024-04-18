//Program name: pokdeng.h
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
void starting();
void loading();
void delay(long int ms);
void cardrand(int j,int rn[],int intcard[],char tcard[],char type_card[],char *rt[],int sn[],char *sc[],int hn[],char *hc[],int cn[],char *cc[],int dn[],char *dc[]);
void outputcom2(char *num_card[],char type_card[],int compoint1);
void outputcom3(char *num_card[],char type_card[],int compoint2);
void outputplayer2(char *num_card[],char type_card[],int playerpoint1);
void outputplayer3(char *num_card[],char type_card[],int playerpoint2);
int checkplayerpoint(int playerpoint);
int checkcompoint(int compoint);
int cdeng2(int intcard[],int cdeng);
int pdeng2(int intcard[],int cdeng);
int cdeng3(int intcard[],int cdeng);
int pdeng3(int intcard[],int cdeng);
int checkwin(int playerpoint,int compoint,int coin,int pdeng,int cdeng,int bet);
