#include<iostream>
#include<conio.h>
#include<cstdlib>
using namespace std;
bool gameover;
const int width =50;
const int height =30;
int x,y,fruitx,fruity,score;
enum edirection{ stop =0,LEFT , RIGHT ,UP ,DOWN};
edirection dir;
void setup()
{
            gameover =false;
            dir = stop;   
            x=width/2;
            y=height/2;
            fruitx=rand()%width;
            fruity=rand()%height;
            score=0;     
}
void draw()
{
   system("cls");
   for(int i=0;i<width+1;i++)
   cout<<"#";
   cout<<endl;
   for(int i=0;i<height;i++)
   {
          for(int j=0;j<width;j++)
          {
                 if(j==0)
                 cout<<"#";
                 else if(j==width-1)
                 cout<<"#";
                 else if(i==y && j==x)
                 cout<<"O";
                 else if(i==fruity && j== fruitx)
                 cout<<"f";
                 else
                 cout<<" ";
          }
          cout<<endl;
   }
   for(int i=0;i<width+2;i++)
           cout<<"#";
   cout<<endl;
   cout<<"score="<<score<<endl;
}
void input()
{
    if(kbhit())
    {
           switch( getch())
           {
                  case 'a':
                         dir=LEFT;
                         //x--; //also works without logic
                         break;
                  case 'd':
                         dir=RIGHT;
                      //   x++;
                         break;
                  case 'w':
                         dir=UP;
                        // y--;
                         break;
                  case 'x':
                         dir=DOWN;
                         //y++;
                         break;
                  case 'z':
                         gameover=true;
                         break;     
           }
    }
}
void logic()
{
      switch( dir)
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
                  default :
                         break;     
           }
      if(x>width || x<0 || y>height || y<0)
                 gameover=true;
      if(x==fruitx && y==fruity)
      {
              score+=1;
              fruitx=rand()%width;
            fruity=rand()%height;
      }
                  
}
int main()
{
    setup();
        while(!gameover)
                        {
                            draw();
                            input();
                            logic();
                            //sleep(10);
                        }
    return 0;                    
}
