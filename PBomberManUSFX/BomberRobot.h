#pragma once
#include<iostream>
#include"GamePawn.h"

using namespace std;

class BomberRobot : public GamePawn
{
private:


public:
	//Creamnos constructor
	BomberRobot(Texture* _textura, Tile* _tileActual);
	void setTileActual(Tile* _tileNuevo) override;

	void update2();
	void render();








};

