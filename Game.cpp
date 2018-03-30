#include<iostream>
using namespace std;
bool gameOver;
const int width = 20;
const int height = 20;
int x, y, x0, y0, fruitX, fruitY, score1, score2;
enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;
void Setup()
{
    
}
void Draw()
{
    
}
void Input()
{

}
void Logic()
{

}
int main()
{
    Setup();
    while(!gameOver)
    {
        Draw();
        Input();
        Logic();
        //sleep(10);
    }
    
    return 0;
}
