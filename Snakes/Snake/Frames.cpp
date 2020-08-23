#include "Snakes.h"
#include "DH.h"

Frames::Frames()
{
	Width = 30;
	Height = 30;
	Check_lose = 0;
	Score = 0;
	Width *= 2;
}
void Frames::GameOver()
{
	if(Check_lose == 1)
	{
		cout << "\nYou Lose\n";
	}
}
int Frames::Scores()
{
	return Score;
}
void Frames::Draw_Frame()
{
	float width = Width;
	for(int i=0;i<width+1;i+=2)
	{
		gotoXY(i, 0);
		cout << "*";
		gotoXY(i, Height);
		cout << "*";
	}
	for(int i=0;i<Height+1;i++)
	{
		gotoXY(0, i);
		cout << "*";
		gotoXY(width, i);
		cout << "*";
	}
}
void Frames::FixBug1()
{
	gotoXY(0, Height+5);
}

Point::Point()
{
	Pos_x = Pos_y = 0;
}
Point::Point(int x, int y)
{
	Pos_x = x;
	Pos_y = y;
}
void Point::display_Bait()
{
	cout << "xx";
}
void Point::display_Snake_Horizontal()
{
	cout << "==";
}
void Point::display_Snake_Vertical()
{
	cout << "||";
}

Baits::Baits()
{
	float Width = Frames::getW();
	float Height = Frames::getH();
	srand(time(0));
	int res = (rand() % ((int)Width - 3 + 1)) + 1;
	Pos_x = res;
	res = (rand() % ((int)Height - 3 + 1)) + 1;
	Pos_y = res;
}
void Baits::Appear()
{
	Point Bait(Pos_x,Pos_y);
	gotoXY(Pos_x, Pos_y);
	Bait.display_Bait();
}

Snake::Snake()
{
	Pos_x = 10;
	Pos_y = 10;
}

void Snake::controlSnake(int sleep)
{
	int x = Pos_x;
	int y = Pos_y;
	int flag = 0;
	
	while (true)
	{
		if (_kbhit())
		{
			char ct = _getch();
			if (ct == 'w')
			{
				flag = 1;
			}
			else if(ct == 's')
			{
				flag = 0;
			}
			else if (ct == 'a')
			{
				flag = 4;
			}
			else if (ct == 'd')
			{
				flag = 3;
			}
		}
		
		gotoXY(x-1, y);
		cout << "   ";
		
		gotoXY(Pos_x, Pos_y);
		Point S(Pos_x, Pos_y);

		if (flag == 0 || flag == 1)
			S.display_Snake_Vertical();
		else
			S.display_Snake_Horizontal();
		
		if (Pos_y == Frames::getH()) flag = 1;
		if (Pos_y == 0) flag = 0;
		if (Pos_x == Frames::getW()) flag = 4;
		if (Pos_x == 0) flag = 3;

		x = Pos_x;
		y = Pos_y;
		if(flag == 0)
		{
			y = Pos_y;
			Pos_y++;
		}
		else if (flag == 1)
		{
			y = Pos_y;
			Pos_y--;	
		}
		else if(flag == 3)
		{
			x = Pos_x;
			Pos_x+=2;			
		}
		else if(flag == 4)
		{
			x = Pos_x;
			Pos_x-=2;	
		}
		
		
		Sleep(sleep);
	}
}


