#pragma once
#include <list>
#include <vector>
#include "Tiles.h"
#include "mine.h"
#include "ships.h"
#include "numbers.h"


class game 
{
	public:
		void draw();
		static game * getObject();
		void update();
		~game();
		void init();
		enum game_state {LOADING, INIT, LOST, WON};
		int done=0;
	private:
		game_state m_state = INIT;
		static game* m_object;
		std::list<Tiles*> m_Tiles;
		std::list<mine*> m_Mines;
		std::list<ships*> m_ships;
		bool mine_coordinates[10][10];
		bool ship_coordinates[10][10];
		std::list<numbers*> m_num;
		game(){}
		
		
};
