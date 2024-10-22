#pragma once
#include "sgg/graphics.h"
class mine
{
	public:
		void draw();
		void update();
		void set_posX(int x);
		void set_posY(int y);
		int get_posX();
		int get_posY();
		bool contains(float x, float y);
		void draw2();
	private:
		int m_coord[2];
		int posX;
		int posY;
};
