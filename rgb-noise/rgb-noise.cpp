#include "rgb-noise.h"

#define RAND_MAX 4096

constexpr double NOISE_SCALE = 2.0;
constexpr double NOISE_SPEED = 0.05;

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

		PerlinNoise noise;
		double time = 0.0;

		while (true)
		{
			for (uint8_t row = 0; row < meta->max_rows; row++)
			{
				for (uint8_t column = 0; column < meta->max_columns; column++)
				{
					double val = int(noise.noise(column / NOISE_SCALE, row / NOISE_SCALE, time) * 255.0);
					wooting_rgb_array_set_single(row, column, val, val, val);
				}
			}

			wooting_rgb_array_update_keyboard();
			time += NOISE_SPEED;
		}
	}
	else
	{
		std::cout << "Keyboard not connected; terminating." << std::endl;
	}

	wooting_rgb_close();

	system("pause");
	return 0;
}

void exiting()
{
	wooting_rgb_close();
}

int rand(int max)
{
	return std::rand() % max;
}
