#include <Windows.h>
#include "rgb-noise.h"

#define RAND_MAX 255
#define rand() std::rand()

int main()
{
	if (wooting_rgb_kbd_connected)
	{
		std::cout << "Keyboard connected!"
			<< std::endl;

		std::atexit(exiting);

		const WOOTING_USB_META* meta = wooting_rgb_device_info();

		std::cout << "Meta retrieved: max_rows = " << (int)meta->max_rows
			<< ", max_columns = " << (int)meta->max_columns
			<< std::endl;

		while (true)
		{
			for (uint8_t row = 0; row < meta->max_rows; row++)
			{
				for (uint8_t column = 0; column < meta->max_columns; column++)
				{
					wooting_rgb_array_set_single(row, column, rand(), rand(), rand());
				}
			}

			wooting_rgb_array_update_keyboard();
			
			Sleep(50uL);
		}
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
		wooting_rgb_close();
}
