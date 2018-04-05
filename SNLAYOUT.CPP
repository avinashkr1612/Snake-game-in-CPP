#include(fstream.h>
#include<conio.h>
#include<string.h>
#include<process.h>
#include<dos.h>
void centertext(char *);
void singleplayer();
void multiplayer();
void credits();
void settings();
void main()
{
clrscr();
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
int ch;
_main:
window(1,1,80,25);
clrscr();
cout<<"\n\n\n\n\n\n";
centertext("MAIN MENU");
cout<<"\n\n\n";
centertext("1. Single Player");
centertext("2. Play Multiplayer");
centertext("3. Settings");
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
	case 3:    settings();
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
	cout<<"Single Player Content Goes Here";
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