
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>

int curveshow(float v,float lt);
void main();
void single();
void custom();

//////////////////////////////////////////////////////////////////////////////
								void braces()
{//quick game
setcolor(BLUE);
settextstyle(7,0,5);
outtextxy(230,40,"MENU");
gotoxy(20,25);

printf("NAVIGATION %c %c DETAILS %c ENTER to select\n\t\t\tBackspace to Go Back",17,16,31);

setcolor(RED);
setlinestyle(2,2,0);
rectangle(200,150,400,350);
setcolor(0);
setlinestyle(0,2,0);

line(200,180,200,330);
line(400,180,400,330);

}

//////////////////////////////////////////////////////////////////////////////
void icons(int x)
{/////////////////////////////////////////////////////////////////////////////
//custom
int i=1,j=1;
setcolor(WHITE);
setfillstyle(1,15);

circle(520+x,255,45);
circle(520+x,255,30);
floodfill(560+x,255,WHITE);

for(;j<360;j+=45)
	{
		for(i=1;i<13;i++)
			arc(520+x,255,j,15+j,45+i) ;
	}
//////////////////////////////////////////////////////////////////////////////
//single

setcolor(15);
circle(300+x,220,20);
setfillstyle(1,15);
floodfill(300+x,220,15);
circle(270+x,250,10);
floodfill(270+x,250,15);
circle(330+x,250,10);
floodfill(330+x,250,15);

setfillstyle(1,15);
bar(270+x,240,330+x,270);
bar(260+x,250,340+x,310);
setcolor(0);
line(275+x,260,275+x,310);
line(325+x,260,325+x,310);
}

/////////////////////////////////////////////////////////////////////////////
							     int move(int d)
{
int k;
static int i=0;
for(k=0;k<220;i+=d,k+=20)
	{
	setfillstyle(1,0);
	bar(0,190,640,320);
	icons(i);
	delay (60);
	}
return i;
}
///////////////////////////////////////////////////////////////////////////
							void dropdown(int a)
{
if(a==0)
	{
	setcolor(YELLOW);
	settextstyle(3,0,3);
	outtextxy(160,420,"Single Play mode 5 Chances");
	}
if(a==-231)
	{
	setcolor(YELLOW);
	settextstyle(3,0,3);
	outtextxy(40,420,"Customise Your Game (NO. of Chances And Players)");
	}
}
//////////////////////////////////////////////////////////////////////////////
								void menu()
{
int a=0;
char k=0;
cleardevice();
braces();
	icons(0);
	while(k!=13)
		{
			k=getch();
			if(k==0)
			k=getch();
			switch(k)
				{
				case 75:
				  cleardevice();
				  braces();
				  a=move(-21);
				  break;

				case 77:
				  cleardevice();
				  braces();
				  a=move(+21);
				  break;

				case 80:
				  dropdown(a);
				  break;

				case 8:
				  main();
				  break;
				}
		}
	if(a==0)
		{
		cleardevice();
		single();
		}
	if(a==-231)
		{
		cleardevice() ;
		custom();
		}
}
///////////////////////////////////////////////////////////////////////////
							   void welcome()
{
int i,j,k;
setcolor(10);
for(k=0;k<16;k+=3)
{
 setfillstyle(1,k-1);
bar(0,0,640,480);
setbkcolor(176);
 for(i=0;i<9;i++)
	{
	setcolor(2+i/3);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,8);
	outtextxy(i,180," BOUNCE");
	delay(40);
	}
 }
curveshow(7.0,638);
setcolor(BLUE);
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
	 outtextxy(140,455,"       PRESS ANY KEY TO CONTINUE");
getch();
for(i=-100;i<540;i++)
	 {
	 setcolor(14);
	 line(i,160,170+i,230);
	 line(170+i,230,i,290);
	 delay(1);
	 }
cleardevice();
//			                                           LOADING...
setcolor(BLUE);
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
	 outtextxy(253,180,"LOADING....");
  setcolor(14);
  settextstyle(2,HORIZ_DIR,5);
	 outtextxy(100,400,"Tip : Score HITS MORE THAT NO OF MISS to win. ");

for(i=0;i<1200;i+=20)
     {
	setcolor(i/100);
	for(j=0;j<4;j++)
		  {
		  arc(300,200,i,3+i,80+j);
		  arc(300,200,10+i,12+i,80+j);
		  arc(300,200,21+i,22+i,80+j);
		  delay(15);
		  }
	setcolor(0);

	for(j=0;j<4;j++)
		{
		  arc(300,200,i,3+i,80+j);
		  arc(300,200,10+i,12+i,80+j);
		  arc(300,200,21+i,22+i,80+j);
		}
     }
cleardevice();
}
////////////////////////////////////////////////////////////////////////////
					   int curveshow(float v,float lt)
{
int j1,j2,x,c,m,n;
float i,k,h=1;
float l=300;

     for(x=0;x<=24;x+=4)
	{
	  j1=(441-((21-x)*(21-x)));
	  j2=(441-((17-x)*(17-x)));
	  for(i=0; i<=(21-x) && l<5500 ; i+=0.2)
		{
		k=i*i;
		l+=v*h;
		k=j1+k;
		setcolor(2);
		circle(l/10,k*0.4,2);
		circle(640-(l/10),k,2);
		c=getpixel(l/10+1,k+1);
		delay(12);
		setcolor(0);
		circle(l/10,k*0.4,2);
		circle(600-(l/10),k,2);
	}

     for( i=(17-x) ; i>=0 && l<5500 ; i-=0.2 )
	{
			k=i*i;
			l+=v*h;
			k=j2+k;
			setcolor(2);

		   if(i == 17 - x)
			{
				sound(200);
			}

		   circle(l/10,k*0.4,2);
		   circle(640-(l/10),k,2);
		   c=getpixel(l/10+1,k+1);
		   delay(12);
		   setcolor(4);
		   circle(l/10,k*0.4,2);
		   circle(600-(l/10),k,2);
		   nosound();
		   }
	  }
 setlinestyle(1,0,1);
 return 0;
}
////////////////////////////////////////////////////////////////////////////
						   int curve(float v,float lt)
{
int j1,j2,x,c,m,n;
float i,k,h=1;
float l=300;
setlinestyle(1,0,1);
     for(x=0;x<=24;x+=4)
	{                             //caliberation ...
	  j1=(441-((21-x)*(21-x)));
	  j2=(441-((17-x)*(17-x)));

	  for(i=0; i<=(21-x) && l<5500 ; i+=0.2)
		{

		if( k>300 && l>=10*lt && l<=10*(lt+20) )
			{
				h=-0.5;
			}

		if( h == -0.5 && l<500 )
			{
				h=0.25;
			}

		if( h==0.25f&& k>300 && l>=10*lt && l<=10*(lt+60) )
			{
				h=-0.12;
			}

		k=i*i;
		l+=v*h;
		k=j1+k;
		setcolor(0);
		circle(l/10,k,2);
		c=getpixel(l/10+1,k+1);

		if(c==4)
			{
			return 1;
			}
		delay(20);
		setcolor(15);
		circle(l/10,k,2);
	}

     for( i=(17-x) ; i>=0 && l<5500 ; i-=0.2 )
	{
		if(i == 17 - x)
			{
				l-=v*h;
			}

		if( k>300 && l>=10*lt && l<=10*(lt+60) )
			{
				h=-0.5;
			}

		if( h==-0.5f && l<300 )
			{
				h=0.25;
			}

		if( h==0.25f&& k>300 && l>=10*lt && l<=10*(lt+60)  )
			{
				h=-0.12;
			}

			k=i*i;
			l+=v*h;
			k=j2+k;
			setcolor(0);

		   if(i == 17 - x)
			{
				sound(200);
			}

		   circle(l/10,k,2);
		   c=getpixel(l/10+1,k+1);

		   if(c==4)
		   {
		   return 1;
		   }
		   delay(20);
		   setcolor(15);
		   circle(l/10,k,2);
		   nosound();
		   }
	  }
return k;
}
////////////////////////////////////////////////////////////////////////////
								float bar1()
{
int k=0;
float h=0;

setfillstyle(1,BLACK);
bar(590,70,620,250);
 while(1)
	{
		k=getch();
		if(k==0)
		k=getch();
			switch(k)
			{
				case 72:
				  if(h<180)
					 {
						h+=5;
						setcolor(RED);
						setfillstyle(2,RED);
						bar(590,250-h,620,250);
					  }
				  break;

				case 80:
				  if(h>0)
					  {
						h-=5;
						setfillstyle(1,BLACK);
						bar(590,70,620,250);
						setfillstyle(2,RED);
						bar(590,250-h,620,250);
					  }
				  break;

				case 115:
				  return h/2;
			}
	 }
return h/2;
}
////////////////////////////////////////////////////////////////////////////
							int display(int left)
{
char leftc[5];
int j,lt;
lt=150+rand()%300;
//				               		User interface plot
setlinestyle(0,0,1);
setfillstyle(1,9);
bar(0,0,560,480);
setcolor(0);
setfillstyle(1,8);

bar3d(0,442,530,500,20,20);
floodfill(535,444,0);
setfillstyle(1,8);
floodfill(200,440,0);
setcolor(YELLOW);
setfillstyle(1,YELLOW);
			      //  sun
circle(480,50,30);
floodfill(480,50,YELLOW);
setcolor(9);
setfillstyle(1,9);

pieslice(430,100,0,140,50);
pieslice(500,100,60,160,50);

setcolor(1);

arc(430,100,30,100,50);
arc(410,80,40,120,30);
arc(500,100,60,140,50);
arc(300,100,60,90,50);
arc(330,100,80,110,50);

setcolor(80);
setfillstyle(11,BLUE);
setcolor(150);
bar3d(10,30,30,441,20,20);
bar3d(lt,300,lt+30,441,20,10);
setfillstyle(1,4);
floodfill(lt+10,298,150);
setfillstyle(1,0);
floodfill(42,25,150);
floodfill(30,25,150);
floodfill(lt+40,310,150);
line(40,25,40,433);

for(j=0;j<20;j++)
	line(30,57+20*j,50,40+20*j);


					    //                   side bar |_|
setcolor(15);
setlinestyle(3,1,3);
rectangle(560,5,638,478);
setcolor(RED);
setlinestyle(0,1,3);
rectangle(562,7,636,476);

setcolor(YELLOW);
settextstyle(1,0,1);
outtextxy(570,21,"SET");
outtextxy(570,38,"POWER");
setfillstyle(1,0);
bar(571,70,586,210);
settextstyle(2,1,5);
setcolor(4);
outtextxy(572,70,"PRESS S to Shoot");

setcolor(11);
settextstyle(1,0,1);
outtextxy(570,278," Balls");
outtextxy(570,295," Left");
setcolor(0);
bar(585,370,615,395);

setcolor(2);
settextstyle(0,0,3);
sprintf(leftc,"%d",left);
outtextxy(590,370,leftc);

return lt;
}
/////////////////////////////////////////////////////////////////////////
							int game(int left)
{
int i=0,v,k,lt,l;
char miss[3],hits[3];
static int h=0,m=0;
lt= display(left);
v=bar1();
k=curve(v,lt);
delay(400);

    if( k==1 )
	  {
	  setcolor(GREEN);
	  for(i=0;i<9;i++)
		{
		setcolor(3+(i/4));
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
		outtextxy(100+i,200,"       TARGET");
		delay(30);
		}
	  delay(1000);
	  for(l=0;l<3;l++)
		{
		for(i=0;i<13;i++)
			  {
			  setcolor(9);
			  line(200,200+(3*i)+l,550,200+(3*i)+l);
			  delay(15);
			  }
		}
		h++;
	 }
else
	{
	setcolor(RED);
	for(i=0;i<10;i++)
		{
		setcolor(2+(i/4));
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
			outtextxy(100,100,"     <<<BETER Luck Next TIME>>>");
		delay(20);
		}
		delay(1500);
	for(l=0;l<3;l++)
		{
		for(i=0;i<13;i++)
			{
			setcolor(9);
			line(150,100+(3*i)+l,550,100+(3*i)+l);
			delay(10);
			}
		}
m++;
}

settextstyle(1,0,1);
setcolor(0);
setfillstyle(1,0);
bar(555,430,635,470);
setcolor(15);

if(m>=h)
	{
	 setcolor(RED);
	}
else
	{
	 setcolor(2);
	}

setcolor(RED);
settextstyle(2,0,5);
outtextxy(570,435,"MISS:");
setcolor(GREEN);
settextstyle(2,0,5);
outtextxy(570,450,"HITS:");

if(h>m)
	{
	setcolor(2);
	}
else
	{
	setcolor(4);
	}

sprintf(miss,"%d",m);
outtextxy(620,435,miss);


sprintf(hits,"%d",h);
outtextxy(620,450,hits);

return h;
}
//////////////////////////////////////////////////////////////////////////////
						void result(float k , float j)
{
float h;
h=k;
k=(100*k)/j;
cleardevice();

if(h>j/2)
	{
	setcolor(WHITE);
	  settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
	 outtextxy(10,100,"YOU  W O N !! ");
	}

setcolor(WHITE);
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
	 outtextxy(10,200,"Your Score Is");

gotoxy(50,15);
printf("  %f%%",k);
}
/////////////////////////////////////////////////////////////////////////////
								void single()
{
int i;
float k;
	for(i=0;i<5;i++)
		{
		k= game(5-i);
		}
result(k,5);
}
/////////////////////////////////////////////////////////////////////////////
								void custom()
{
int i,j;
float k;
setfillstyle(9,5);
bar(0,0,640,480);
setcolor(WHITE);
  settextstyle(TRIPLEX_FONT,0,2);
   outtextxy(10,100,"Enter the no of tries");
rectangle(400,100,460,130);
gotoxy(55,8) ;
scanf("%d",&j);
	for(i=0;i<j;i++)
		{
		k= game(j-i);
		}
result(k,j);
}
////////////////////////////////////////////////////////////////////////////
								void main()
{
 int gd=DETECT,gm,k;
 initgraph(&gd,&gm,"C:\\TurboC3\\BGI");

welcome();
cleardevice();

menu();

getch();
cleardevice();

gotoxy(1,13);
outtextxy(1,150,"  Wana GET One More try  ");
outtextxy(1,200," TO Prove Your PHYSICS Skills....");
outtextxy(1,250,"   (press enter)");
settextstyle(1,0,1);
outtextxy(200,400,"Any key to exit");
delay(200);

k=getch();

if(k==13)
main();

}

