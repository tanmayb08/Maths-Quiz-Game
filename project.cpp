#include <stdio.h>
#include <stdlib.h>
#include<conio.h>  
#include<graphics.h>  
#include<dos.h>
int gd=DETECT,gm;

void game()
{
	int height = GetSystemMetrics(SM_CYSCREEN);
	int width = GetSystemMetrics(SM_CXSCREEN);
	int bx=255,by=470,bx1=323,by1=490;
	char ch;
  // initgraph(&gd,&gm,"c:\\turboc3\bgi"); 
   initwindow(height,width,"Project",-3,-3);
  /* outtextxy(325,100,"Math Quiz");
   rectangle(250,234,328,496);
   rectangle(328,234,408,496);
   rectangle(408,234,483,496);*/
   
   while(1)
   {
   	    flag:
        //system("CLR");
        cleardevice();
        outtextxy(325,100,"Math Quiz");
        outtextxy(250,220,"a+b");
        rectangle(250,234,328,496);
        rectangle(328,234,408,496);
        rectangle(408,234,488,496);
   	    setfillstyle(SOLID_FILL, RED);
        bar(bx,by,bx1,by1);
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
		goto flag;
        //if(GetAsyncKeyState(VK_RIGHT))
            
       // else if(GetAsyncKeyState(VK_LEFT))
            
       // if(GetAsyncKeyState(VK_RETURN))
       //     break;
       // delay(10);
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
	printf("\n**********Maths Quiz**********\n");
    printf("\nEnter your choice: \n1.Start\n2.Exit\n\n");
    scanf("%d", &response);
    switch(response)
    {
    	case 1:
    		game();
    	    break;
    	case 2:
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
    
	
   
    if(response == 0)
    {
        printf("\nThanks for playing!\n");
        return 0;
    }

    for(i=0; i<response; i++)
    {
        int answer = 0;
        int a = rand() % 12;
        int b = rand() % 12;
        printf("\n%d * %d = ",a ,b);
        scanf("%d", &answer);
        if((a * b) == answer){
            printf("\nCongratulations You are correct!\n");
            correctAnswers++;
        }
        else{
            printf("Sorry you were incorrect!\n");
            incorrectAnswers++;
        }

    }
    printf("\n\nYour Results:\n\n\n");
    printf("Number Incorrect: %d\n", incorrectAnswers);
    printf("Number Correct: %d\n", correctAnswers);
    if(correctAnswers > incorrectAnswers){
        printf("You Passed!\nGood work!\n\n");
    }
    else{
        printf("You did not pass!\nYou need more work!\n\n");
    }
    getch();
}
