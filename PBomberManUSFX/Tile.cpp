#include "Tile.h"

Tile::Tile()
{
	posicionTileX = 0;
	posicionTileY = 0;
	bomberman = nullptr;
	bomberRobot = nullptr;       //**************************
	muroCeramica = nullptr;
	muroMetal = nullptr;
	sueloCesped = nullptr;

}

Tile::Tile(int _posicionTileX, int _posicionTileY)
{
	posicionTileX = _posicionTileX;
	posicionTileY = _posicionTileY;
	bomberRobot = nullptr;   //****************************
	bomberman = nullptr;
	muroCeramica = nullptr;
	muroMetal = nullptr;
	sueloCesped = nullptr;
}