#pragma once
#ifndef _Snakes_
#define _Snakes_
#include <vector>
#include <iostream>
using namespace std;

class Frames
{
protected:
	float Width;
	float Height;
	bool Check_lose;
	int Score;
public:
	Frames();
	void Draw_Frame();
	void GameOver();
	int Scores();
	void FixBug1();
	float getW() { return Width; }
	float getH() { return Height; }
};

class Point : public Frames
{
protected:
	int Pos_x;
	int Pos_y;
public:
	Point();
	Point(int x, int y);
	void display_Bait();
	void display_Snake_Horizontal();
	void display_Snake_Vertical();
};
class Snake : public Point
{
private:
	bool Head;
public:
	Snake();
	void updatePosPerTime();
	void controlSnake(int sleep);
};

class Baits : public Point
{
protected:
public:
	Baits();
	void Appear();
};

class Player : public Frames
{
public:
	
};

#endif