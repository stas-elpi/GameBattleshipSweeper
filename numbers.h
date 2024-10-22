#pragma once
#include "defines.h"
#include "sgg/graphics.h"


class numbers
{
public:
	void draw();
	void update();
	void set_posX(float x) { m_coord[0] = x; }
	void set_posY(float y) { m_coord[1] = y; }
	float get_posX() { return m_coord[0]; }
	float get_posY() { return m_coord[1]; }
	void set_board_posX(int x) { m_board_coord[0] = x; }
	void set_board_posY(int y) { m_board_coord[1] = y; }
	int get_board_posX() { return m_board_coord[0]; }
	int get_board_posY() { return m_board_coord[1]; }
	int minesaround = 0;
	bool m_drawable = false;
	numbers();
	
private:
	float m_coord[2];
	int m_board_coord[2];
};

