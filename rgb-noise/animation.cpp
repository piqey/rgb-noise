#include "animation.h"

double NOISE_SCALE = 2.0;
double NOISE_SPEED = 0.05;

uint8_t COLOR[3] = {255, 255, 255};

void startAnimation()
{
	const WOOTING_USB_META* meta = wooting_rgb_device_info();

	// std::cout << "Meta retrieved: max_rows = " << (int)meta->max_rows
	//	<< ", max_columns = " << (int)meta->max_columns
	//	<< std::endl;

	PerlinNoise noise;
	double time = 0.0;

	while (true)
	{
		for (uint8_t row = 0; row < meta->max_rows; row++)
		{
			for (uint8_t column = 0; column < meta->max_columns; column++)
			{
				double val = noise.noise(column / NOISE_SCALE, row / NOISE_SCALE, time);
				wooting_rgb_array_set_single(row, column, uint8_t(COLOR[0] * val), uint8_t(COLOR[1] * val), uint8_t(COLOR[2] * val));
			}
		}

		wooting_rgb_array_update_keyboard();
		time += NOISE_SPEED;
	}
}
