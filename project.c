#include <stdio.h>
//#include <stdlib.h>
#include<conio.h>  
#include<graphics.h>  
int main ()

{
	int gd=DETECT,gm;  
    initgraph(&gd,&gm,"c:\\turboc3\\bgi");  
    setbkcolor(9);  
    line(130,100,290,100);  
      
    line(165,100,165,155);  
    arc(150,155,100,0,15);  
    line(180,100,180,170);
	line(190,100,190,170);  
  
    circle(220,140,10);  
    line(220,130,255,130);  
    line(255,100,255,170);  
    line(265,100,265,170);  

   // getch();  
	
	/*
    int i;
    int response;
    int correctAnswers = 0;
    int incorrectAnswers = 0;

    printf("\nMath Quiz\n");
    printf("Please enter number of problems you would wish to try:");
    scanf("%d", &response);

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
    }*/

    return 0;
}
