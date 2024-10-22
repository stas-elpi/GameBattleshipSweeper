#include "sgg/graphics.h"
#include "defines.h"
#include <string>
#include "game.h"

void draw()
{
	game* gamedraw = game::getObject();
	gamedraw->draw();
}


void update(float frame)
{
	game* gamedraw = game::getObject();
	gamedraw->update();
}

int main(int argc, char ** argv)
{

	graphics::createWindow(900, 600, "BattleshipSweeper");

	game* game = game::getObject();
	game->init();

	graphics::setCanvasSize(30,26);
	graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);


	graphics::setDrawFunction(draw);
	graphics::setUpdateFunction(update);

	graphics::startMessageLoop();

	return 0;
}