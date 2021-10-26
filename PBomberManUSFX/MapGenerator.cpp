#include "MapGenerator.h"

MapGenerator::MapGenerator()
{
	anchoPantalla = 0;
	altoPantalla = 0;
	renderer = nullptr;
}

MapGenerator::MapGenerator(SDL_Renderer* _renderer, int _anchoPantalla, int _altoPantalla, TilesGraph* _tilesGraph):
	anchoPantalla(_anchoPantalla),
	altoPantalla(_altoPantalla),
	renderer(_renderer),
	tilesGraph(_tilesGraph)
{
	
}

bool MapGenerator::crearObjetosJuego(string _path)
{
	// Crea un flujo de archivo
	fstream file;

	// Abrir el archivo
	file.open(_path.c_str(), ios::in);

	if (file.is_open() == false) {
		std::cout << "No se pudo abrir el archivo de mapa" << std::endl;
		return false;
	}

	string line;
	

	Texture* texturaBomberRobot;
	texturaBomberRobot = new Texture();
	Texture* texturaBomberman;
	texturaBomberman = new Texture();
	Texture* texturaBomberwoman;
	texturaBomberwoman = new Texture();
	Texture* texturaMuroMetal;
	texturaMuroMetal = new Texture();
	Texture* texturaMuroCeramica;
	texturaMuroCeramica = new Texture();
	Texture* texturaSueloCesped;
	texturaSueloCesped = new Texture();
	
	Texture::renderer = renderer;

	texturaBomberRobot->loadFromImage("resources/robot2O.png");
	texturaBomberman->loadFromImage("resources/bomberman2O.png");
	texturaBomberwoman->loadFromImage("resources/bomber2OF.png");
	texturaMuroCeramica->loadFromImage("resources/ceramicaO.png");
	texturaMuroMetal->loadFromImage("resources/metalO2.png");
	texturaSueloCesped->loadFromImage("resources/pisoO.png");
	
	int x = 0;
	int y = 0;
	int bombermanPosicionX = -1;
	int bombermanPosicionY = -1;
	int bomberwomanPosicionX = -1;
	int bomberwomanPosicionY = -1;
	int bomberRobotPosicionX = -1;
	int bomberRobotPosicionY = -1;

	while (getline(file, line)) {
		vector<char> chars(line.begin(), line.end());
		x = 0;

		for (int i = 0; i < chars.size(); i++) {
			if (chars[i] != ' ') {
				GameObject* objetoNuevo = nullptr;
				Tile* tileNuevo = tilesGraph->getTileEn(x, y);
				switch (chars[i]) {
				case '0':
					objetoNuevo = new SueloCesped(texturaSueloCesped, tileNuevo);
					if (x > bombermanPosicionX && bombermanPosicionX == -1) {
						bombermanPosicionX = x;
						bombermanPosicionY = y;
					}


					if (x > bomberwomanPosicionX || y > bomberwomanPosicionY) {
						bomberwomanPosicionX = x;
						bomberwomanPosicionY = y;
					}
					if (x < bomberRobotPosicionX || y> bomberRobotPosicionX ) {
						bomberRobotPosicionX = x;
						bomberRobotPosicionY = y;
					}

					//pilaObjetosJuegoMurosMetal.Insertar((GameActor*)objetoNuevo);

					break;
					//modifique nombre


				case '1':
					objetoNuevo = new MuroCeramica(texturaMuroCeramica, tileNuevo);
					
					//tarea
					
				
					if (x % 2 == 0 && y % 2 == 0) {
						int key = 0;
						mObjeMCP[key] = { x,y };
						key = x * TilesGraph::anchoTilesGraph + y;
						for (auto i = mObjeMCP.begin(); i != mObjeMCP.end();++i ) {

							cout << x << " " ;
							cout << y << " " ;

						}
					}
				
					
					break;
				case '2':
					objetoNuevo = new MuroMetal(texturaMuroMetal, tileNuevo);
					
					break;
					/*case 'B':
						objetoNuevo = new Bomberman(texturaBomberman, tileNuevo);
						break;*/
				}

				if (objetoNuevo != nullptr) {
					((GameActor*)objetoNuevo)->setPosicionX(x * 34);
					((GameActor*)objetoNuevo)->setPosicionY(y * 34);
					vectorObjectosJuego.push_back(objetoNuevo);
					x++;
				}
			}
		}
		y++;
	}


	
	GameObject* objetoBomberman = nullptr;
	Tile* tileNuevo = tilesGraph->getTileEn(bombermanPosicionX, bombermanPosicionY);
	objetoBomberman = new Bomberman(texturaBomberman, tileNuevo);
	if (objetoBomberman != nullptr) {
		((GameActor*)objetoBomberman)->setPosicionX(bombermanPosicionX * 34);
		((GameActor*)objetoBomberman)->setPosicionY(bombermanPosicionY * 34);
		vectorObjectosJuego.push_back(objetoBomberman);
	}

	GameObject* objetoBomberwoman = nullptr;
	tileNuevo = tilesGraph->getTileEn(bomberwomanPosicionX, bomberwomanPosicionY);
	objetoBomberwoman = new Bomberman(texturaBomberwoman, tileNuevo);
	if (objetoBomberwoman != nullptr) {
		((GameActor*)objetoBomberwoman)->setPosicionX(bomberwomanPosicionX * 34);
		((GameActor*)objetoBomberwoman)->setPosicionY(bomberwomanPosicionY * 34);
		((GamePawn*)objetoBomberwoman)->setBotomBomba(SDLK_o);
		((GamePawn*)objetoBomberwoman)->setBotomArriba(SDLK_w);
		((GamePawn*)objetoBomberwoman)->setBotomAbajo(SDLK_s);
		((GamePawn*)objetoBomberwoman)->setBotomIzquierda(SDLK_a);
		((GamePawn*)objetoBomberwoman)->setBotomDerecha(SDLK_d);

		vectorObjectosJuego.push_back(objetoBomberwoman);
	}
	GameObject* objetoBomberRobot = nullptr;
	tileNuevo = tilesGraph->getTileEn(bomberRobotPosicionX, bomberRobotPosicionY);
	objetoBomberRobot = new RobotBomber(texturaBomberRobot, tileNuevo);
	if (objetoBomberRobot != nullptr) {
		((GameActor*)objetoBomberRobot)->setPosicionX(bomberRobotPosicionX * 34);
		((GameActor*)objetoBomberRobot)->setPosicionY(bomberRobotPosicionY * 34);
	   ((GamePawn*)objetoBomberRobot)->setBotomBomba(SDLK_p);
		((GamePawn*)objetoBomberRobot)->setBotomArriba(SDLK_i);
		((GamePawn*)objetoBomberRobot)->setBotomAbajo(SDLK_k);
		((GamePawn*)objetoBomberRobot)->setBotomIzquierda(SDLK_j);
		((GamePawn*)objetoBomberRobot)->setBotomDerecha(SDLK_l);
		

		vectorObjectosJuego.push_back(objetoBomberRobot);
	}



	return false;
}

void MapGenerator::transferirObjetosJuego(vector<GameObject*>& _vectorObjetosJuegoDestino)
{
	for (int i = 0; i < vectorObjectosJuego.size(); i++) {
		_vectorObjetosJuegoDestino.push_back(vectorObjectosJuego[i]);
	}
}
