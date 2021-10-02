#include "rgb-noise.h"

int main()
{
	std::atexit(exiting);

	if (wooting_rgb_kbd_connected)
	{
		std::cout << "Keyboard connected; beginning."
			<< std::endl;

		const WOOTING_USB_META* meta = wooting_rgb_device_info();

		std::cout << "Meta retrieved: max_rows = " << (int)meta->max_rows
			<< ", max_columns = " << (int)meta->max_columns
			<< std::endl;
	}
	else
	{
		std::cout << "Keyboard not connected; terminating." << std::endl;
	}

	system("pause");
	return 0;
}

void exiting()
{
	if (wooting_rgb_kbd_connected)
		wooting_rgb_reset();
}
