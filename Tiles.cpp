#include "Tiles.h"
#include "sgg/graphics.h"
#include "defines.h"

void Tiles::draw()
{
	graphics::Brush br;
	if (m_highlighted) 
	{
		SET_COLOR(br.fill_color, 1.0f, 0.0f, 0.0f);
	}
	else
	{
		SET_COLOR(br.fill_color, 1.0f, 1.0f, 1.0f);
	}
	br.outline_opacity = 0.0f;
	if (m_flagged == false)
	{
		br.texture = ASSET_PATH + std::string("tile.png");
	}
	else
	{
		br.texture = ASSET_PATH + std::string("flag.png");
	}
		
	graphics::drawRect(m_coord[0], m_coord[1], TILE_SIZE+0.25, TILE_SIZE, br);
}

void Tiles::update()
{
	
}

void Tiles::set_posX(float x)
{
	m_coord[0] = x;
}

void Tiles::set_posY(float y)
{
	m_coord[1] = y;
}

float Tiles::get_posX()
{
	return m_coord[0];
}

float Tiles::get_posY()
{
	return m_coord[1];
}



bool Tiles::contains(float x, float y)
{
	if((x>m_coord[0]-1.22) && (y>m_coord[1]-TILE_SIZE*0.5) &&
		x<(m_coord[0]+1.22) && y<(m_coord[1]+TILE_SIZE*0.5-0.1))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Tiles::set_flag(bool k)
{
	m_flagged = k; 
}
