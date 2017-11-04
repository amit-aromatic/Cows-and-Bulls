#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream.h>
#include <ctype.h>
#include "graphics.cpp"

void main()
{
 char t,rand[4],inp[2000],name[80];
 int i,j,r,cow,bul,chances=10;

 clrscr();
 fallvert("COWS  AND  BULLS");
 wait();
 clrscr();
 _setcursortype(_SOLIDCURSOR);
 cout<<"\n\n		Game to test your intelligence...\n\n\n\n";
 cout<<"Computer has thought a 4 digit (all different) number and you have to guess it\n\n"
     <<"cows  = no. of correct digits in your guess\n"
     <<"bulls = no. of digits at their correct position"
     <<"\n\n\n\n\n\n\nif you clear 5th stage, you become a champion.\n\nEnter 'e' as your GUESS to exit."
     <<"\n\n\n\nPress any key to continue...";
 getch();

 FILE *fp;
 fp=fopen("highscor.cbl","r");
 if(fp==NULL)
  {
   fp=fopen("highscor.cbl","w");
   fprintf(fp,"NONE !");
   fclose(fp);
   fp=fopen("highscor.cbl","r");
  }

 fscanf(fp," %[^\n]",name);
 fclose(fp);
 randomize();

do
{
 for(i=0;i<3;i++)
  {
   clrscr();
   gotoxy(30,12);
   cout<<"[ STAGE      "<<11-chances<<" ]";
   gotoxy(80,25);
   waitp(0.5);
   clrscr();
   waitp(0.5);
  }
 clrscr();

 for (i=0;i<4;i++)
  {
   r= random(100)+1;

   int g=r;
   for (int f=0;f<g;f++)      // otherwise, random was not random !!!
    {
     r= random(9)+1;
    }

   t= r+48;
   if(i==0)
    rand[i]=t;
   else
   {
    for(j=0;j<i;j++)
     {
      if (t==rand[j])
       {
	i--;
	break;
       }
     else rand[i]=t;
    }
   }
  }

  // cheat code
  //for(i=0;i<4;i++)
  //cout<<rand[i];

 cout<<"COWS AND BULLS 				ENTER 'e' to EXIT\n\nLAST Champion : "<<name<<"\n";
 hline();


 cout<<"\n\n\n\n\n          Guess                      cows                     bulls";


for(int g=0;g<chances;g++)
 {
  //clrscr();

  int c,b;
  c=b=0;

  for(i=0;i<chances;i++)
   {
    gotoxy(1,12+i);
    cout<<"     "<<i+1;
   }

  gotoxy(10,12+g);

  cin>>inp;

  if(toupper(inp[0])=='E')// && toupper(inp[1])=='X' && toupper(inp[2])=='I' && toupper(inp[3])=='T' )
  exit(0);


  for(i=0;i<4;i++)
   {
    if(inp[0]<49 || inp[0]>58) goto in;

    for(j=0;j<i;j++)
     {
      if (inp[i]==inp[j] || inp[i]<49 || inp[i]>58)
       {
	in:
	gotoxy(10,12+g);
	cout<<"                                                            ";
	g--;
	goto wronginp;
       }
     }
   }

  for(i=0;i<4;i++)
   {
    for(j=0;j<4;j++)
     {
      if (inp[i]==rand[j])
       c++;
     }
   }

  for(i=0;i<4;i++)
   {
    if(inp[i]==rand[i])
     b++;
   }

  if(c==4 && b==4)
   {
   // gotoxy(10,25);
   // cout<<"CONGRATS !             YOU GUESSED THE CORRECT NUMBER";
   // getch();
    goto next;
   }


  gotoxy(14,12+g);
  cout<<"  ";
  hlinep(65,'Í');
  gotoxy(36,12+g);
  cout<<"   "<<c<<"   ";
  gotoxy(61,12+g);
  cout<<"   "<<b<<"   ";

  wronginp:
  ;
 }

 gotoxy(10,25);

 _setcursortype(_NORMALCURSOR);

 cout<<"SORRY !  YOU LOOSE.... THE CORRECT NUMBER IS : ";
 for(i=0;i<4;i++)
   cout<<rand[i];
 gotoxy(80,25);
 getch();

 goto end;

 next:

 chances--;

}while(chances>=6);

 fp=fopen("highscor.cbl","w");

 clrscr();


 cout<<"\n\nYOU WIN THE CHAMPIONSHIP !!!\n\n"
     <<"Enter your name Mr. Genius : ";

 scanf(" %[^\n]",name);
 fprintf(fp,"%s",name);
 fclose(fp);

 clrscr();

 cout<<"\n\nOoooo.... Nice name !\n\nWhat are your hobbies ?\n\n- ";
 scanf(" %[^\n]",name);
 cout<<"\n\nOooo Kaaay... So this make you so intelligent... Point is noted SIR... \n\nYou will always be my inspiration...\n\nKeep rocking... and don't forget me !!!\n\nWaiting for your next visit...\n\nBaaayeeeeeeeee !";

 getch();

 end:
 ;
}






