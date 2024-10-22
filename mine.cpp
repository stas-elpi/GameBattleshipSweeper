#include "mine.h"
#include "defines.h"

void mine::draw()
{
	graphics::Brush br;
	br.outline_opacity = 0.0f;

	br.texture = ASSET_PATH + std::string("mine.png");
	graphics::drawRect(((W_WIDTH * m_coord[0] / 12.3f) + W_WIDTH / 7.67), ((W_HEIGHT * m_coord[1] / 12.3f) + W_HEIGHT / 7.55), TILE_SIZE + 0.25, TILE_SIZE, br);
}
void mine::draw2()
{
	graphics::Brush br;
	br.outline_opacity = 0.0f;

	br.texture = ASSET_PATH + std::string("minered.png");
	graphics::drawRect(((W_WIDTH * m_coord[0] / 12.3f) + W_WIDTH / 7.67), ((W_HEIGHT * m_coord[1] / 12.3f) + W_HEIGHT / 7.55), TILE_SIZE + 0.25, TILE_SIZE, br);

	//sleep(300);
	
	
	
}


void mine::update()
{
}

void mine::set_posX(int x)
{
	m_coord[0] = x;
}

void mine::set_posY(int y)
{
	m_coord[1] = y;
}

int mine::get_posX()
{
	return m_coord[0];
}

int mine::get_posY()
{
	return m_coord[1];
}

bool mine::contains(float x, float y)
{
	if ((x > (((W_WIDTH * m_coord[0] / 12.3f) + W_WIDTH / 7.67) - 1.22) &&
		(y > ((W_HEIGHT * m_coord[1] / 12.3f) + W_HEIGHT / 7.55) - TILE_SIZE * 0.5) &&
		x < (((W_WIDTH * m_coord[0] / 12.3f) + W_WIDTH / 7.67) + 1.22) &&
		y < (((W_HEIGHT * m_coord[1] / 12.3f) + W_HEIGHT / 7.55) + TILE_SIZE * 0.5 - 0.1)))
	{
		return true;
	}
	else
	{
		return false;
	}
}
