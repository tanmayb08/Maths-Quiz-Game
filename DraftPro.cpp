#include <stdio.h>
#include <stdlib.h>
#include<conio.h>  
#include<graphics.h>  
#include<dos.h>
int gd=DETECT,gm;
char m[10]={"*"};

void game()
{
	int height = GetSystemMetrics(SM_CYSCREEN);
	int width = GetSystemMetrics(SM_CXSCREEN);
	int bx=255,by=470,bx1=323,by1=490;
	char ch;
   int response,ans;
   char temp[20];
   int correctAnswers = 0;
   int incorrectAnswers = 0; 
   initwindow(height,width,"Project",-3,-3);
   while(1)
   {
   	    flag:
        cleardevice();
        
        int lower=280 ,upper=445, ansy=250;
        int answer = 0;
        int a = rand() % 12;
        int b = rand() % 12;
        int n = (rand() % ( upper-lower+1 ))+lower;
        if(n==328 || n==328+3 || n==328-3 || n==408 || n==408+3 || n==408-3)
        goto flag;
        
        itoa(a,temp,10);
        outtextxy(250,220,temp);
        outtextxy(260,220,m);
        
        itoa(b,temp,10);
        outtextxy(270,220,temp);
        ans=a*b;
        int c1 = rand() % 289; 
        int c2 =0;
        int c3 =0;
    
    while(1)
    {
    	t:
    	cleardevice();
    	outtextxy(325,100,"Math Quiz");
        rectangle(250,234,328,496);
        rectangle(328,234,408,496);
        rectangle(408,234,488,496);
        itoa(a,temp,10);
        outtextxy(250,220,temp);
        outtextxy(260,220,m);
        itoa(b,temp,10);
        outtextxy(270,220,temp);
   	    setfillstyle(SOLID_FILL, RED);
        bar(bx,by,bx1,by1);
        
        itoa(ans,temp,10);
        outtextxy(n,ansy,temp);
		while(ansy!=470||ansy!=490)
		{
			cleardevice();
			itoa(ans,temp,10);
            outtextxy(n,ansy+10,temp);
            delay(10);
		}
        
        //itoa(ans,temp,10);
        //outtextxy(445,250,temp);
        ch=getch();
        switch(ch)
   	    {
   	    	case 'a':
   	    		if(bx>255)
   	    		{
   	    			bx-=80;
   	    	    	bx1-=80;
				}
				break;
   	    	case 'd':
   	    	    if(bx1<408)
   	    	    {
   	    	    	bx+=80;
			        bx1+=80;
				}
			    break;
		}
		goto t;
	}
       	goto flag;
	}
       // end:
   //	return ;
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
	printf("\n**********Maths Quiz**********\n");
    printf("\nEnter your choice: \n1.Start\n2.Exit\n\n");
    response=getche();
    switch(response)
    {
    	case '1':
    		game();
    	    break;
    	case '2':
    		exit(0);
    		break;
    	default:
    		printf("\ninvalid level selected\n");
	}
	
}
    
   
  /* initwindow(1000,1000,"Main menu");
   outtextxy(100,100,"\n********** Maths Quiz **********\n\n");
   outtextxy(200,200,"1.Easy");
   outtextxy(200,250,"2.Medium");
   outtextxy(200,300,"3.Hard");
   outtextxy(200,350,"4.Exit");*/
   //scanf("%d", &response);
    
	
   
        printf("\nThanks for playing!\n");
        return 0;
    

    
    getch();
}
