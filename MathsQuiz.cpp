#include <stdio.h>
#include <stdlib.h>
#include<conio.h>  
#include<graphics.h>  
#include<dos.h>
#include<random>
#include<time.h>
int gd=DETECT,gm;
char m[10]={"*"};
int bx=255,by=470,bx1=323,by1=490;
int a,b;
int c,d;
int t1,t2;
int score;
int height = GetSystemMetrics(SM_CYSCREEN);
int width = GetSystemMetrics(SM_CXSCREEN);
int lower=280 ,upper=445;
int n,n1,n2;
char ch;
int multi,len=0;

void skeleton()
{
    char temp[20];
    outtextxy(325,100,"Maths Quiz");
    rectangle(250,234,328,496);
    rectangle(328,234,408,496);
    rectangle(408,234,488,496);
    
    itoa(t1,temp,10);
    outtextxy(250,220,temp);
    outtextxy(270,220,m);
    itoa(t2,temp,10);
    outtextxy(290,220,temp);
    
    outtextxy(600,400,"*****Controls*****");
    outtextxy(560,420,"Press A to move bar on left side.");
    outtextxy(560,440,"Press D to move bar on right side.");
}

void ans(int i)
{
	int a,ansy=250+i; 
	char temp[20];
    a=t1*t2;
	
	/*if(len==1)
	{
		itoa(a,temp,1);
		outtextxy(n,ansy,temp);
	}
	else
	{
		itoa(a,temp,10);
		outtextxy(n,ansy,temp);
	}*/
    itoa(a,temp,10);
	outtextxy(n,ansy,temp);
    itoa(c,temp,10);
    outtextxy(n1,ansy,temp); 
    itoa(d,temp,10);
    outtextxy(n2,ansy,temp); 
}

void newq()
{
	g:
	srand(time(NULL));
	a = rand() % 12;
    b = rand() % 12;
    c = rand() % 12;
    d = rand() % 12;
    if(c==a||c==b||d==a||d==b)
    goto g;
}

void newans()
{
	f:
	int l=255 , u=322 , l1=330 ,u1=405 , l2=410 , u2=485 ;
	srand(time(NULL));
	n = (rand() % ( upper-lower+1 ))+lower;
	
	if(n>250 && n<320) 
	{	
		n1 = (rand() % ( u1-l1+1 ))+l1;
	    n2 = (rand() % ( u2-l2+1 ))+l2;
	}
	else if(n>335 && n<390)
	{
		n1 = (rand() % ( u-l+1 ))+l;
	    n2 = (rand() % ( u2-l2+1 ))+l2;
	}
	else if(n>420 && n<488)
	{
		n1 = (rand() % ( u1-l1+1 ))+l1;
	    n2 = (rand() % ( u-l+1 ))+l;
	}
	else 
	{
		goto f;
	}
}

void bar()
{
   	setfillstyle(SOLID_FILL, RED);
    bar(bx,by,bx1,by1);
        switch(ch)
   	    {
   	    	case 'a':
   	    		if(bx>255)
   	    		{
   	    			bx-=80;
   	    	    	bx1-=80;
   	    	    	skeleton();
   	    	    	setfillstyle(SOLID_FILL, RED);
                    bar(bx,by,bx1,by1);
				}
				break;
   	    	case 'd':
   	    	    if(bx1<408)
   	    	    {
   	    	    	bx+=80;
			        bx1+=80;
			        skeleton();
			        setfillstyle(SOLID_FILL, RED);
                    bar(bx,by,bx1,by1);
				}
			    break;
			default:
				setfillstyle(SOLID_FILL, RED);
                bar(bx,by,bx1,by1);
		}
}

void showscore()
{
	char temp[20];
	outtextxy(50,100,"Score : ");
	itoa(score,temp,10);
	outtextxy(100,100,temp);
}

int game()
{   
	
	int t;
	int i;
	
	outtextxy(300,70,"                      Maths Quiz           ");
	
	outtextxy(300,100,"         **********How to play?**********");
    outtextxy(300,120,"   The question is given on the top of rectangle");
    outtextxy(300,140,"            Options are falling down");
    outtextxy(300,160,"Move the RED BAR at the bottam of appropriate column");
    
	outtextxy(600,400,"*****Controls*****");
    outtextxy(560,420,"Press A to move bar on left side.");
    outtextxy(560,440,"Press D to move bar on right side.");
	outtextxy(200,200,"Enter any key to start");
	getch();
	flag :
	t=0;
	i=250;
	skeleton();
	bar();
	newq();
	newans();
	t1=a;
	t2=b;
	/*multi=a*b;
	while(multi!=0)
    {
    	multi=multi/10;
    	len++;
	}*/
	while(1)
	{
		while(i!=470)
		{
			if(kbhit())
			{
				ch = getch();
			} 
			else
			{
				ch=0;
			}
			delay(200);
			cleardevice();
	    	ans(t);
	    	skeleton();
			bar();
			showscore();
	    	i+=10;
	    	t+=10;
		}
		if(n>bx && n<bx1)
		{
			score+=10;
			goto flag;
		}
		else
		{
			outtextxy(200,200,"Game Over");
			closegraph();
			return 0;
		}
		
	}
}

int main ()
{
   int gd=DETECT,gm; 
   int i;
   int response;
   int correctAnswers = 0;
   int incorrectAnswers = 0; 
   
while(1)
{
    system("CLS");
    printf("\n\nHighScore :%d \n",score);
    score=0;
	printf("\n**********Maths Quiz**********\n");
    printf("\nEnter your choice: \n1.Start\n2.Exit\n\n");
    response=getche();
    switch(response)
    {
    	case '1':
    		initwindow(height,width,"Project",-3,-3);
    		game();
    	    break;
    	case '2':
    		exit(0);
    		break;
    	default:
    		printf("\ninvalid level selected\n");
	}
}
    getch();
}
