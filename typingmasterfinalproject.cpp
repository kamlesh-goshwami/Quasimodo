//#include<stdio.h>
//#include<ctime>
//#include<iostream>
//#include<time.h>
//#include<cstring>
#include<bits/stdc++.h>
using namespace std;
int t=10,level;
float accuracy,gross,net;
char name[20];
void startgame()
{

 //   cout<<str;
	//time_t start,end;
	cout<<"1.easy mode \n 2. normal mode \n 3.hard mode\n";
	int p;
	cout<<"enter the choice "<<endl;
	cin>>level;
	FILE *f1,*f2,*f3,*f6;
	switch(level)
	{
		case 1: f1=fopen("level1.txt","r");
		f6=fopen("level1.txt","r");
		break;
		case 2: f1=fopen("level2.txt","r");
		f6=fopen("level2.txt","r");
		break;
		case 3: f1=fopen("level3.txt","r");
		f6=fopen("level3.txt","r");
		break;
	}
//	f6=f1;
		char ch;
		char st[30];
	while(fscanf(f1,"%s",st)!=EOF)
	printf("%s ",st);
	fclose(f1);
 char str[5000];

    cout << "\n\nstart typing\n";
    getchar();
    time_t start,end;
    start=time(NULL);
    //getline (cin, str);
//    gets(str);
	end=time(NULL);
	float tam=(difftime(end,start))/60;
	 cout<<"\n time taken during typing "<<tam<<endl;
    f2=fopen("check.txt","w");
    fputs(str,f2);
    fclose(f2);
   // f1=fopen("level1.txt","r");
   f3=fopen("check.txt","r");
   if(f3==NULL)
   cout<<"f3 is null"<<endl;
   char cuff[50],duff[50];
   int right=0,count=0;
   while((fscanf(f6,"%s",cuff)!=EOF) &&(fscanf(f3,"%s",duff)!=EOF))
   {

   //	cout<<cuff<<"  "<<duff<<endl;
   	    if(strcmp(cuff,duff)==0)
   	    right++;
   	    count++;
   }
   FILE *f4=fopen("scorecard.txt","a");
   gross=(float)count/tam;
   net=(float)right/tam;
   accuracy=float(right)*100/count;
   cout<<"gross speed "<<gross<<" wpm "<<"net speed "<<net<<" wpm "<<" accuracy "<<accuracy<<"%"<<endl;
   fprintf(f4,"%s %s  %s %f %s %d %s %f %s %f\n","name",name,"accuracy",accuracy,"level ",level,"gross speed ",gross,"net speed ",net);
  fclose(f4);

}
void score()
{
	FILE *f5;
	printf("the scorecard till now is following\n");
	f5=fopen("scorecard.txt","r");
	char ch;
	while((ch=fgetc(f5))!=EOF)
	printf("%c",ch);
}
void sett()
{
	cout<<"set the time limit\n";
	cout<<"\n enter 1  for  30 sec \n enter 2 for 60 sec \n enter 3 for 120sec\n ";
	cout<<"\nenter the time \n"<<endl;
	int p;
	cin>>p;
	switch(p)
	{
		case 1: t=30 ;break;
		case 2: t=60 ;break;
		case 3: t=120;break;
	//	default :
	}

}
void help()
{
	cout<<"\n there is all instruction are given just read once and be patience\n" <<endl;
}
void aboutme()
{
	cout<<"\n myself roshan kumar sharma , i belong to jaipur and pursuing btech from nit agartala\n "<<endl;
}
int main()
{
	char c;
	do
{
	FILE *f1,*f2,*f3,*f4;
printf("1.start game \n 2. scorecard\n 3.set the time limit \n 4.help\n 5. about me \n 6 .exit()\n");
int choice;
printf("enter yoour choice \n");
scanf("%d",&choice);

switch(choice)
{
	case 1:
	printf("enter the name \n");
scanf("%s",name);
	startgame();
		break;
	case 2:score();
	break;
	case 3: sett();
	break;
	case 4:help();
	break;
	case 5: aboutme();
	break;
	case 6: exit(0);
	break;
	default : printf(" \nyou have entered wrong choice now back in main menu\n");
	main();

}

//char c;
cout<<" \ndo u want to go at main menu press y or Y for main menu  \n"<<endl;
cin>>c;
}
while(c=='y'||c=='Y');
}










