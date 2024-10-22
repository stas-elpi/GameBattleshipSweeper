#include "sgg/graphics.h"
#include "defines.h"
#include "game.h"
#include "mine.h"
#include "ships.h"
#include "numbers.h"
#include <random>
#include <time.h>
#define RANDOM() (rand()%10)


void game::draw()
{
	graphics::Brush br;
	br.outline_opacity = 0.0f;


	br.texture = ASSET_PATH + std::string("backround.png");
	graphics::drawRect(W_WIDTH / 2, W_HEIGHT / 2, W_WIDTH, W_HEIGHT, br);

	graphics::setFont(ASSET_PATH + std::string("font.ttf"));
	SET_COLOR(br.fill_color, 1.0f, 1.0f, 1.0f);
	graphics::drawText(6.0, 25.0, 0.5f, "Sink the ships avoiding the mines.The numbers will help you.(Right click for a flag)", br);

	for (auto mine : m_Mines)
	{
		mine->draw();
	}

	for (auto num : m_num)
	{
		num->draw();
	}

	for (auto shp : m_ships)
	{
		shp->draw();
	}
	
	for (auto Tile : m_Tiles)
	{
		Tile->draw();
	}
	if (m_state == LOST)
	{
		for (auto mine : m_Mines)
		{
			mine->draw2();
			

		}
		br.outline_opacity = 1.0f;
		graphics::setFont(ASSET_PATH + std::string("font.ttf"));
		SET_COLOR(br.fill_color, 1.0f, 1.0f, 1.0f);   
		graphics::drawText(8.0, 13.0, 3.0f, "YOU LOST :((", br);

		br.outline_opacity = 1.0f;
		graphics::setFont(ASSET_PATH + std::string("font.ttf"));
		SET_COLOR(br.fill_color, 1.0f, 0.0f, 0.0f);
		graphics::drawText(8.2, 13.0, 3.0f, "YOU LOST :((", br);
	}
	if(m_state== WON)
	{
		br.outline_opacity = 1.0f;
		graphics::setFont(ASSET_PATH + std::string("font.ttf"));
		SET_COLOR(br.fill_color, 1.0f, 1.0f, 1.0f);
		graphics::drawText(8.0, 13.0, 3.0f, "VICTORY!", br);

		br.outline_opacity = 1.0f;
		graphics::setFont(ASSET_PATH + std::string("font.ttf"));
		SET_COLOR(br.fill_color, 0.0f, 1.0f, 0.0f);
		graphics::drawText(8.2, 13.0, 3.0f, "VICTORY!", br);
	}
}

game* game::getObject()
{
	if (!m_object)
		m_object = new game;
	return m_object;
}


void game::update()
{
	if (m_state == INIT)
	{
		for (auto Tile : m_Tiles)
		{
			Tile->update();
		}

		for(auto ship: m_ships)
		{
			ship->update();
		}

		graphics::MouseState mouse_state;
		graphics::getMouseState(mouse_state);

		float mousex = graphics::windowToCanvasX(mouse_state.cur_pos_x);
		float mousey = graphics::windowToCanvasY(mouse_state.cur_pos_y);

		Tiles* tl = nullptr;
		for (auto tile : m_Tiles)
		{
			if (tile->contains(mousex, mousey))
			{
				tile->setHighlight(true);
				tl = tile;
			}
			else
			{
				tile->setHighlight(false);
			}
		}

		if (mouse_state.button_right_released && tl)
		{

			if (tl->get_flag() == false)
			{
				tl->set_flag(true);
				graphics::playSound(ASSET_PATH + std::string("flag.mp3"), 1.0, false);
			}
			else
			{
				tl->set_flag(false);
				graphics::playSound(ASSET_PATH + std::string("flag.mp3"), 1.0, false);
			}
		}

		if (mouse_state.button_left_released && tl)
		{
			delete tl;
			graphics::playSound(ASSET_PATH + std::string("opentile.mp3"),1.0, false);
		}

		for (auto ship : m_ships)
		{
			if (mouse_state.button_left_released && ship->contains(mousex, mousey) )
			{
				graphics::playSound(ASSET_PATH + std::string("ship.mp3"), 1.0, false);
				ship->ship_hit();
				done=done+1;		
			}
			
		}

		
		for (auto mine : m_Mines)
		{
			if (mine->contains(mousex, mousey) && mouse_state.button_left_released)
			{
				m_state = LOST;
				graphics::playSound(ASSET_PATH + std::string("bomb1.mp3"), 1.0, false);
				
				
			}

		}
		
		if(done>=16)
		{
			m_state=WON;
		}

		

	}
}



game::~game()
{
	for (auto tile : m_Tiles)
	{
		delete tile;
	}
	m_Tiles.clear();
	for (auto mine : m_Mines)
	{
		delete mine;
	}
	m_Mines.clear();
	for (auto shp : m_ships)
	{
		delete shp;
	}
	m_ships.clear();
	for (auto number : m_num)
	{
		delete number;
	}
	m_num.clear();
}




void game::init()
{
	

	done=0;
	/*m_state=LOADING;
	graphics::preloadbitmaps(ASSET_PATH);\\
	sleep(500)
	m_state=INIT;*/
	
	int i, j;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			Tiles* t = new Tiles();
			m_Tiles.push_front(t);

			t->set_posX((W_WIDTH * i / 12.3f) + W_WIDTH / 7.67);
			t->set_posY((W_HEIGHT * j / 12.3f) + W_HEIGHT / 7.55);
			mine_coordinates[i][j] = false;
			ship_coordinates[i][j] = false;


		}
	}
	
	ships* shp2 = new ship2();
	ships* shp3a = new ship3();
	ships* shp3b = new ship3();
	ships* shp4a = new ship4();
	ships* shp4b = new ship4();

	m_ships.push_front(shp2);
	m_ships.push_front(shp4a);
	m_ships.push_front(shp4b);
	m_ships.push_front(shp3a);
	m_ships.push_front(shp3b);

	srand(time(NULL));
	for (auto shp : m_ships)
	{
		if (shp) {
			bool check = false;
			while (check == false)
			{

				int ra_shipx = RANDOM2();
				int ra_shipy = RANDOM2();
				if (
					ship_coordinates[ra_shipx][ra_shipy] == false &&
					ship_coordinates[ra_shipx][ra_shipy + 1] == false &&
					ship_coordinates[ra_shipx][ra_shipy + 2] == false &&
					ship_coordinates[ra_shipx][ra_shipy + 3] == false)
				{
					shp->set_posX((W_WIDTH * ra_shipx / 12.3f) + W_WIDTH / 7.67);
					shp->set_posY((W_HEIGHT * ra_shipy / 12.3f) + W_HEIGHT / 7.55);
					shp->createShip();
					check = true;
					ship_coordinates[ra_shipx][ra_shipy] = true;
					ship_coordinates[ra_shipx][ra_shipy + 1] = true;
					ship_coordinates[ra_shipx][ra_shipy + 2] = true;
					ship_coordinates[ra_shipx][ra_shipy + 3] = true;
				}
				else
				{
					check = false;
				}				
			}
		}
	}






	
	for (int m = 0; m < 10; m++)
	{
		mine* narkh = new mine();
		m_Mines.push_front(narkh);

	}
	





	for (auto mine : m_Mines)
	{
		if (mine)
		{
			bool check = false;
			while (check == false)
			{
				int rdX = RANDOM();
				int rdY = RANDOM();
				if (ship_coordinates[rdX][rdY] == false &&
					mine_coordinates[rdX][rdY] == false)
				{
					mine->set_posX(rdX);
					mine->set_posY(rdY);
					mine_coordinates[rdX][rdY] = true;
					check = true;
				}
				else
				{
					check = false;
				}
			}				
		}
	}
	

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			numbers* num = new numbers();
			m_num.push_front(num);
			num->set_board_posX(i);
			num->set_board_posY(j);
			num->set_posX((W_WIDTH * i / 12.3f) + W_WIDTH / 7.67);
			num->set_posY((W_HEIGHT * j / 12.3f) + W_HEIGHT / 7.55);
		}
	}
	for (auto number : m_num)
	{
		if (mine_coordinates[number->get_board_posX()][number->get_board_posY()] == false)
		{
			number->m_drawable = true;
			if (number->get_board_posY() > 0 && number->get_board_posX() > 0)
			{
				if (mine_coordinates[number->get_board_posX() - 1][number->get_board_posY() - 1] == true)
				{
					number->minesaround = number->minesaround + 1;
				}
			}
			if (number->get_board_posY() > 0)
			{
				if (mine_coordinates[number->get_board_posX()][number->get_board_posY() - 1] == true)
				{
					number->minesaround = number->minesaround + 1;
				}
			}
			
			if (number->get_board_posX() > 0)
			{
				if (mine_coordinates[number->get_board_posX() - 1][number->get_board_posY()] == true)
				{
					number->minesaround = number->minesaround + 1;
				}
			}
			if (number->get_board_posX() > 0 && number->get_board_posY() < 9)
			{
				if (mine_coordinates[number->get_board_posX() - 1][number->get_board_posY() + 1] == true)
				{
					number->minesaround = number->minesaround + 1;
				}
			}
			if (number->get_board_posX() < 9)
			{
				if (mine_coordinates[(number->get_board_posX()) + 1][number->get_board_posY()] == true)
				{
					number->minesaround = number->minesaround + 1;
				}
			}
			if (number->get_board_posY() < 9)
			{

				if (mine_coordinates[number->get_board_posX()][number->get_board_posY() + 1] == true)
				{
					number->minesaround = number->minesaround + 1;
				}
			}
			if (number->get_board_posY() < 9 && number->get_board_posX() < 9)
			{
				if (mine_coordinates[number->get_board_posX() + 1][number->get_board_posY() + 1] == true)
				{
					number->minesaround = number->minesaround + 1;
				}
			}
			
			if (number->get_board_posX() < 9 && number->get_board_posY() > 0)
			{
				if (mine_coordinates[number->get_board_posX() + 1][number->get_board_posY() - 1] == true)
				{
					number->minesaround = number->minesaround + 1;
				}
		
			}
		}


	}
}

	

game* game::m_object = nullptr;

