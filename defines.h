
#pragma once
#include <random>
#include <thread>
#include <chrono>
#define W_WIDTH 30.0f
#define W_HEIGHT 26.0f
#define ASSET_PATH ".\\assets\\"
#define SET_COLOR(m, r, g, b){m[0]=r, m[1]=g, m[2]=b;}
#define TILE_SIZE 2.2f
#define RANDOM() (rand()%10)
#define RANDOM2() (rand()%7)


inline void sleep(int ms)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}


