#include "menu.h"

bool doMenu()
{
	bool shouldExit = false;
	int chosen = 0;

	system("cls");

	std::cout << "Wooting RGB Noise" << std::endl
		<< std::endl
		<< "\t1) Change color" << std::endl
		<< "\t2) Change speed" << std::endl
		<< "\t3) Change scale" << std::endl
		<< "\t4) Exit" << std::endl
		<< std::endl
		<< "Selection: ";

	std::cin >> chosen;

	system("cls");

	switch (chosen)
	{
	case 1:
		promptColor();
		break;
	case 2:
		promptSpeed();
		break;
	case 3:
		promptScale();
		break;
	case 4:
		shouldExit = true;
		break;
	}

	return shouldExit;
}

void promptColor()
{
	int r = 255, g = 255, b = 255;

	std::cout << "R: ";
	std::cin >> r;

	std::cin.get();
	std::cout << "G: ";
	std::cin >> g;

	std::cin.get();
	std::cout << "B: ";
	std::cin >> b;

	COLOR[0] = (uint8_t)r;
	COLOR[1] = (uint8_t)g;
	COLOR[2] = (uint8_t)b;
}

void promptSpeed()
{
	std::cout << "Speed: ";
	std::cin >> NOISE_SPEED;
}

void promptScale()
{
	std::cout << "Scale: ";
	std::cin >> NOISE_SCALE;
}
