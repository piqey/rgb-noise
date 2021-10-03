#include "rgb-noise.h"

int main()
{
	if (wooting_rgb_kbd_connected())
	{
		bool terminate = false;

		std::cout << "Keyboard connected!"
			<< std::endl;

		std::thread threadAnimation(startAnimation);

		while (!terminate)
		{
			terminate = doMenu();
		}

		threadAnimation.detach();

		Sleep(250);

		wooting_rgb_reset();
	}
	else
	{
		std::cout << "Keyboard not connected; terminating." << std::endl;
	}

	return 0;
}
