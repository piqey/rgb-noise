#include <iostream>
#include "wooting-rgb-sdk.h"

int main()
{
	if (wooting_rgb_kbd_connected)
	{
		std::cout << "Keyboard connected; beginning." << std::endl;
	}
	else
	{
		std::cout << "Keyboard not connected; terminating." << std::endl;
	}

	system("pause");
	return 0;
}
