#include<iostream.h>
#include<iomanip.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<dos.h>
#include<fstream.h>
#include<conio.h>
void centertext(char *);
void score_store(char *,int);
void singleplayer();
void multiplayer();
void credits();
void dispgameover();
void leaderboard();
int gameOver;
const int width = 50;
const int height = 20;
int x, y, x0, y0, fruitX, fruitY, score1, score2;
int tailX[100], tailY[100];
int nTail;
enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;
void showloading();
void Setup()
{
    gameOver = 0;
    dir = STOP;

    x = width/2;
    y = height/2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score1 = 0;
    score2 = 0;
}
void Draw()
{
    system("cls"); //clears the screen
    for(int i = 0;i < width+2;i++)
    cout << "м";  //upper boundary
    cout << endl;

    for(i =0; i <height; i++)
    {
	for(int j = 0;j < width;j++)
	{
	    if(j == 0)
		cout << "л";   //Boundary Left
	    if( i== y && j== x)
	    {   textcolor(GREEN);
		cprintf("");  //Face
	    }
	    else if(i==fruitY && j==fruitX)
		printf("%c",1);
	    else
	    {
		int print = 0;
		for(int k=0;k<nTail;k++)
		{
		    if(tailX[k] == j && tailY[k] == i)
		    {   cprintf("");   //Snake Body
			print = 1;
		    }
		}
		if(!print)
			cout << " ";
	    }

	    if(j== width - 1)
		cout << "л";
	}
	cout << endl;
    }

    for(i = 0; i < width+2;i++)
    cout << "п"; //Lower Boundary
    cout << endl;
    cout << "Score: " << score1 <<endl;
}
void Input()
{
    if(kbhit())
    {
	switch(getch())
	{
	    case 'a':
		dir = LEFT;
		break;
	    case 'd':
		dir = RIGHT;
		break;
	    case 's':
		dir = DOWN;
		break;
	    case 'w':
		dir = UP;
		break;
	    case 'x':
		gameOver = 1;
		break;
	}
    }
}
void Logic()
{
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for(int i=1;i<nTail;i++)
    {
	prev2X = tailX[i];
	prev2Y = tailY[i];
	tailX[i] = prevX;
	tailY[i] = prevY;
	prevX = prev2X;
	prevY = prev2Y;
    }
    switch(dir)
    {
	case LEFT:
	    x--;
	    break;
	case RIGHT:
	    x++;
	    break;
	case UP:
	    y--;
	    break;
	case DOWN:
	    y++;
	    break;
	default:
	    break;
    }
    //if(x > width || x < 0 || y > height || y < 0)   if i wanna end the game on hitting the wall
      //  gameOver = true;
    if(x>=width)
    x=0;
    else if(x<0)
    x=width-1;
    if(y>=height)
    y=0;
    else if(y<0)
    y=height-1;
    for(i=0;i<nTail;i++)
	if(tailX[i] == x && tailY[i] == y)
	gameOver = 1;
    if(x == fruitX && y == fruitY)
	{
	    score1 = score1+10;
	    fruitX = rand()%width;
	    fruitY = rand()%height;
	    nTail++;
	}
}
int main()
{   _setcursortype(_NOCURSOR);
    showloading();
int ch;
_main:
window(1,1,80,25);
clrscr();
cout<<"\n\n\n\n\n\n";
centertext("MAIN MENU");
cout<<"\n\n\n";
centertext("1. Single Player");
centertext("2. Play Multiplayer");
centertext("3. Leader Board");
centertext("4. Credits");
centertext("5. Exit");
cout<<"\n\n\n";
centertext("Enter Your Choice :");
cout<<"\t\t\t\t      ";
cin>>ch;
switch(ch)
{  	case 1:    singleplayer();
		   break;
	case 2:    multiplayer();
		   break;
	case 3:    leaderboard();
		   break;
	case 4:    credits();
		   break;
	case 5:	   exit(0);
		   break;
	default:   cout<<"Wrong choice!!! Enter again";
		   getch();
		   goto _main;
}
goto _main;


}
void showloading()
{
system("cls");
cout<<"                      ммммммммммммм          ммлллмм                   \n";
cout<<"                   мллллллллпплллллллм     млллллллллм                 \n";
cout<<"                 мллллллллл    ллппппп    ллллп   плллм                \n";
cout<<"                ллллллллллллммлллммммм    ллллм   млллл                \n";
cout<<"               ллллллллллллллллллллллп     плллллллллл                 \n";
cout<<"              лллллллллллллпппппппп          плллллпп                  \n";
cout<<"              лллллллллллл                                             \n";
cout<<"              ллллллллллллм                                            \n";
cout<<"              ллллллллллллллллллллллллллллллллм                        \n";
cout<<"               ллллллллллллллллллллллллллллллллллм                     \n";
cout<<"                ллллллллллллллллллллллллллллллллллл                    \n";
cout<<"                 плллллллллллллллллллллллллллллллллл                   \n";
cout<<"                   пллллллллллллллллллллллллллллллллл                  \n";
cout<<"                                          плллллллллл                  \n";
cout<<"                                           лллллллллл                  \n";
cout<<"                                ммммммммммллллллллллл                  \n";
cout<<"                             мллллллллллллллллллллллл                  \n";
cout<<"                            лллллллллллллллллллллллл                    \n";
cout<<"                            ллллллллллллллллллллллп                     \n";
cout<<"                             пллллллллллллллллллп                       \n";
cout<<"                               ппппппппппппппп                          \n";
delay(1000);
window(10,21,70,25);
cout<<"Loading";
window(10,22,70,25);
for(int x=0;x<60;x++)
{
	cout<<"л";
	delay(60);
}
window(10,23,70,25);
cout<<"completed...";
window(10,24,70,25);
cout<<"Press any Key to continue...";
}
void centertext(char *s)
{  int space = (80 - strlen(s))/2;
   for(int i=0;i<space;i++)
   {  cout<<" ";
   }
   for(i=0;i<strlen(s);i++)
   {   cout<<s[i];
   }
   cout<<endl;
}
void singleplayer(){
	clrscr();

    Setup();
    while(!gameOver)
    {
	Draw();
	Input();
	Logic();
	delay(60);
    }   dispgameover();
	getch();
}
void multiplayer(){
	clrscr();
	cout<<"Multiplayer Content Goes HEre";
	getch();
}
void settings(){
	clrscr();
	cout<<"\n\n\n";
	centertext("SETTINGS");

	getch();
}
void credits(){
	clrscr();
	cout<<"\n\n\n";
	centertext("CREDITS");
	cout<<"\n\n";
	centertext("Shashank Srivastava");
	endl;endl;
	centertext("Avinash Kumar");
	endl;endl;
	centertext("Sakshi Jha");
	endl;endl;
	centertext("Fahad");
	cout<<"\n\n\n";
	window(25,1,25,80);
	centertext("Press Any key to go back!!!");
	getch();
}
void dispgameover()
{
clrscr();
cout<<"             ллллллллл       ллллллл     ллл         ллл  ллллллллл   \n";
cout<<"          мммппппппппп    мммпппппппммм  лллллл   лллллл  лллпппппп   \n";
cout<<"          ллл             ллл       ллл  лллпппмммпппллл  ллл         \n";
cout<<"          ллл    лллллл   ллл       ллл  ллл   ллл   ллл  ллллллл     \n";
cout<<"          ллл    пппллл   ллллллллллллл  ллл         ллл  лллпппп     \n";
cout<<"          ллл       ллл   ллл       ллл  ллл         ллл  ллл         \n";
cout<<"             лллллллллл   ллл       ллл  ллл         ллл  ллллллллл   \n";
cout<<"             пппппппппп   ппп       ппп  ппп         ппп  ппппппппп   \n";
cout<<"\n";
cout<<"            ллллллл       ллл         ллл  ллллллллл   ллллллллл      \n";
cout<<"         мммпппппппммм    ллл         ллл  лллпппппп   лллппппппммм   \n";
cout<<"         ллл       ллл    ллл         ллл  ллл         ллл      ллл   \n";
cout<<"         ллл       ллл    ллл         ллл  ллллллл     лллммммммллл   \n";
cout<<"         ллл       ллл    пппммм   мммппп  лллпппп     ллллллллллл    \n";
cout<<"         ллл       ллл       ллл   ллл     ллл         ллл   ллл      \n";
cout<<"            ллллллл             ллл        ллллллллл   ллл      ллл   \n";
cout<<"            ппппппп             ппп        ппппппппп   ппп      ппп   \n";
cout<<"                                                                      \n";
char name[25]="UNKNOWN";
cout<<"\t\t\t\tYOUR SCORE : "<<score1<<endl;
cout<<"Enter Your Name : ";
scanf("%s",name);
score_store(name,score1);
getch();
}
void score_store(char _name[25],int sc)
{ofstream fout;   //Write data on file
 fout.open("leader.txt",ios::ate);
 fout<<_name<<" "<<sc<<endl;
 fout.close();
}
void leaderboard()
{   char data[30];
    int score_;
    ifstream fin;
    fin.open("leader.txt",ios::in);
    clrscr();
   while(!fin.eof())
    {   fin>>data;
	fin>>score_;
	cout<<"\n\n\n"<<setw(40)<<"NAME : SCORE\n\n";
	cout<<setw(40)<<data<<" : "<<score_<<endl;
    }
    getch();
}