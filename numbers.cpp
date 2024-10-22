#include "numbers.h"

void numbers::draw()
{
	graphics::Brush br;
	br.outline_opacity = 0.0f;
	
	if (minesaround == 1 && m_drawable)
	{
		br.texture = ASSET_PATH + std::string("one.png");
		graphics::drawRect(m_coord[0], m_coord[1], TILE_SIZE + 0.25, TILE_SIZE, br);
	}
	if (minesaround == 2 && m_drawable)
	{
		br.texture = ASSET_PATH + std::string("two.png");
		graphics::drawRect(m_coord[0], m_coord[1], TILE_SIZE + 0.25, TILE_SIZE, br);
	}
	if (minesaround == 3 && m_drawable)
	{
		br.texture = ASSET_PATH + std::string("three.png");
		graphics::drawRect(m_coord[0], m_coord[1], TILE_SIZE + 0.25, TILE_SIZE, br);
	}
	
}


void numbers::update()
{
}


numbers::numbers()
{
	int minesaround = 0;
}
