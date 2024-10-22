#include "ships.h"

void ships::draw()
{
}

void ships::update()
{
}

void ships::createShip()
{
}

bool ships::contains(float x, float y)
{
	return false;
}

void ships::ship_hit()
{
}

void ships::set_posX(float x)
{
	m_coord[0] = x;
}

void ships::set_posY(float y)
{
	m_coord[1] = y;
}



float ships::get_posX()
{
	return m_coord[0];
}

float ships::get_posY()
{
	return m_coord[1];
}

void ships::destroy()
{
}


ships::ships()
{
}

void ship2::createShip()
{
	m_coord[2] = m_coord[0];
	m_coord[3] = m_coord[1] + (W_WIDTH * 1 / 14.1f);
	hits=0;

}

void ship2::draw()
{
	graphics::Brush br;
	br.outline_opacity = 0.0f;

	if(hits>2)
	{
		hits=2;
	}

	if (hits==2) 
	{
		SET_COLOR(br.fill_color, 1.0f, 0.0f, 0.0f);
		destroy();
		

	}

	br.texture = ASSET_PATH + std::string("ploiofront2.png");
	graphics::drawRect(m_coord[0], m_coord[1], TILE_SIZE + 0.25, TILE_SIZE, br);
	br.texture = ASSET_PATH + std::string("ploioback2.png");
	graphics::drawRect(m_coord[2], m_coord[3], TILE_SIZE + 0.25, TILE_SIZE, br);
}

void ship2::update()
{
	
}

bool ship2::contains(float x, float y)
{
	if ((x > (m_coord[0] - 1.22)) &&
		(y > (m_coord[1] - TILE_SIZE * 0.5)) &&
		(x < (m_coord[0] + 1.22)) &&
		(y < (m_coord[1] + TILE_SIZE * 0.5 - 0.1)))
	{
		return true;
	}
	if ((x > (m_coord[2] - 1.22)) &&
		(y > (m_coord[3] - TILE_SIZE * 0.5)) &&
		(x < (m_coord[2] + 1.22)) &&
		(y < (m_coord[3] + TILE_SIZE * 0.5 - 0.1)))
	{
		return true;
	}
	return false;
}

void ship2::ship_hit()
{
	hits=hits+1;
}

void ship2::destroy()
{
	dstr=true;
}




void ship3::createShip()
{
	
		m_coord[2] = m_coord[0];
		m_coord[3] = m_coord[1] + (W_WIDTH * 1 / 14.1f);;
		m_coord[4] = m_coord[0];
		m_coord[5] = m_coord[1] + (W_WIDTH * 2 / 14.1f);
		hits=0;

	
}

void ship3::draw()
{
	graphics::Brush br;
	br.outline_opacity = 0.0f;
	if(hits>3)
	{
		hits=3;
	}
	if (hits==3) 
	{
		SET_COLOR(br.fill_color, 1.0f, 0.0f, 0.0f);
		destroy();
		
	}

	br.texture = ASSET_PATH + std::string("ploiofront2.png");
	graphics::drawRect(m_coord[0], m_coord[1], TILE_SIZE + 0.25, TILE_SIZE, br);
	br.texture = ASSET_PATH + std::string("ploiomid2.png");
	graphics::drawRect(m_coord[2], m_coord[3], TILE_SIZE + 0.25, TILE_SIZE, br);
	br.texture = ASSET_PATH + std::string("ploioback2.png");
	graphics::drawRect(m_coord[4], m_coord[5], TILE_SIZE + 0.25, TILE_SIZE, br);
}

void ship3::update()
{
	
}

bool ship3::contains(float x, float y)
{
	if ((x > (m_coord[0] - 1.22)) &&
		(y > (m_coord[1] - TILE_SIZE * 0.5)) &&
		(x < (m_coord[0] + 1.22)) &&
		(y < (m_coord[1] + TILE_SIZE * 0.5 - 0.1)))
	{
		return true;
	}
	if ((x > (m_coord[2] - 1.22)) &&
		(y > (m_coord[3] - TILE_SIZE * 0.5)) &&
		(x < (m_coord[2] + 1.22)) &&
		(y < (m_coord[3] + TILE_SIZE * 0.5 - 0.1)))
	{
		return true;
	}
	if ((x > (m_coord[4] - 1.22)) &&
		(y > (m_coord[5] - TILE_SIZE * 0.5)) &&
		(x < (m_coord[4] + 1.22)) &&
		(y < (m_coord[5] + TILE_SIZE * 0.5 - 0.1)))
	{
		return true;
	}
	return false;
}

void ship3::destroy()
{
	dstr=true;
}

void ship3::ship_hit()
{
	hits=hits+1;
}



void ship4::createShip()
{	
	
	if (m_horizontal == false)
	{
		m_coord[2] = m_coord[0];
		m_coord[3] =  m_coord[1]+ ((W_WIDTH * 1) / 14.1f);
		m_coord[4] = m_coord[0];
		m_coord[5] = m_coord[1] + ((W_WIDTH * 2) / 14.1f);
		m_coord[6] = m_coord[0];
		m_coord[7] = m_coord[1] + ((W_WIDTH * 3) / 14.1f);
		hits=0;

	}
	
}

void ship4::draw()
{
	graphics::Brush br;
	br.outline_opacity = 0.0f;
	
	if(hits>4)
	{
		hits=4;
	}

	if (hits==4) 
	{
		SET_COLOR(br.fill_color, 1.0f, 0.0f, 0.0f);
		destroy();
		
	}

	br.texture = ASSET_PATH + std::string("ploiofront2.png");
	graphics::drawRect(m_coord[0], m_coord[1], TILE_SIZE + 0.25, TILE_SIZE, br);
	br.texture = ASSET_PATH + std::string("ploiomid2.png");
	graphics::drawRect(m_coord[2], m_coord[3], TILE_SIZE + 0.25, TILE_SIZE, br);
	br.texture = ASSET_PATH + std::string("ploiomid2.png");
	graphics::drawRect(m_coord[4], m_coord[5], TILE_SIZE + 0.25, TILE_SIZE, br);
	br.texture = ASSET_PATH + std::string("ploioback2.png");
	graphics::drawRect(m_coord[6], m_coord[7], TILE_SIZE + 0.25, TILE_SIZE, br);
}

void ship4::update()
{

}

bool ship4::contains(float x, float y)
{
	if ((x > (m_coord[0] - 1.22)) &&
		(y > (m_coord[1] - TILE_SIZE * 0.5)) &&
		(x < (m_coord[0] + 1.22)) &&
		(y < (m_coord[1] + TILE_SIZE * 0.5 - 0.1)))
	{
		return true;
	}
	if ((x > (m_coord[2] - 1.22)) &&
		(y > (m_coord[3] - TILE_SIZE * 0.5)) &&
		(x < (m_coord[2] + 1.22)) &&
		(y < (m_coord[3] + TILE_SIZE * 0.5 - 0.1)))
	{
		return true;
	}
	if ((x > (m_coord[4] - 1.22)) &&
		(y > (m_coord[5] - TILE_SIZE * 0.5)) &&
		(x < (m_coord[4] + 1.22)) &&
		(y < (m_coord[5] + TILE_SIZE * 0.5 - 0.1)))
	{
		return true;
	}
	if ((x > (m_coord[6] - 1.22)) &&
		(y > (m_coord[7] - TILE_SIZE * 0.5)) &&
		(x < (m_coord[6] + 1.22)) &&
		(y < (m_coord[7] + TILE_SIZE * 0.5 - 0.1)))
	{
		return true;
	}
	return false;
}

void ship4::ship_hit()
{
	hits=hits+1;
}

void ship4::destroy()
{
	dstr=true;
}



