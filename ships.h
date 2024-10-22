#pragma once
#include "defines.h"
#include "sgg/graphics.h"


class ships 
{
	public:
		virtual void draw();
		virtual void update();
		virtual void createShip();
		virtual bool contains(float x, float y);
		virtual void ship_hit();
		virtual void set_posX(float x);
		virtual void set_posY(float y);
		virtual float get_posX();
		virtual float get_posY();
		virtual void destroy();
		ships();
		bool m_horizontal;
		float posX;
		float posY;
		bool dstr;
		

	private:
		float m_coord[8];


};

class ship2 : public ships
{
	public:
		void createShip();
		void draw();
		void update();
		void ship_hit();
		bool contains(float x, float y);
		bool m_horizontal = false;
		bool shipSmall = false;
		int hits;
		bool dstr=false;
		void set_posX(float x) { m_coord[0] = x; }
		void set_posY(float y) { m_coord[1] = y; }
		float get_posX() { return m_coord[0]; }
		float get_posY() { return m_coord[1]; }
		void destroy();

		float posX;
		float posY;
	private:
		
		float m_coord[8];

	
		
};

class ship3 : public ships
{
	public:
		void createShip();
		void draw();
		void update();
		
		bool contains(float x, float y);
		bool m_horizontal = false;
		int hits;
		bool dstr=false;
		void set_posX(float x) { m_coord[0] = x; }
		void set_posY(float y) { m_coord[1] = y; }
		float get_posX() { return m_coord[0]; }
		float get_posY() { return m_coord[1]; }
		void ship_hit();
		void destroy();
		float posX;
		float posY;
	private:
		float m_coord[8];

	
};

class ship4 : public ships
{
	public:
		void createShip();
		void draw();
		void update();
		bool contains(float x, float y);
		void ship_hit();
		bool m_horizontal = false;
		int hits;
		bool dstr=false;
		void set_posX(float x) { m_coord[0] = x; }
		void set_posY(float y) { m_coord[1] = y; }
		float get_posX() { return m_coord[0]; }
		float get_posY() { return m_coord[1]; }
		void destroy();
		float posX;
		float posY;
	private:
		float m_coord[8];
		
};
