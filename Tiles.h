#pragma once
class Tiles {
	public:
		void draw();
		void update();
		void set_posX(float x);
		void set_posY(float y);
		float get_posX() ;
		float get_posY();

		void setHighlight(bool h){m_highlighted = h; }
		bool contains(float x, float y);

		void set_flag(bool h);
		bool get_flag() { return m_flagged; }
		
	private:
		float m_coord[2];
		float m_rgb[3];
		float posX;
		float posY;

		bool m_highlighted = false;
		bool m_flagged = false;

		




};

