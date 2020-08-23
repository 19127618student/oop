#include "Snakes.h"
#include "windows.h"
int main()
{
	Frames test_F;
	test_F.Draw_Frame();

	Baits test_Bait;
	test_Bait.Appear();

	Snake test_Snake;
	test_Snake.controlSnake(300);
	
	test_F.FixBug1();
	cout << endl << endl;
	return 0;
}