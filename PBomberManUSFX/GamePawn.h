#pragma once
#include "GameActor.h"
#include "./system/KeyboardInput.h"

class GamePawn :
    public GameActor
{
protected:
    KeyboardInput* keyboardInput;
    SDL_Keycode botonBomba = SDLK_b;
    SDL_Keycode botonArriba = SDLK_UP;
    SDL_Keycode botonAbajo = SDLK_DOWN;
    SDL_Keycode botonIzquierda = SDLK_LEFT;
    SDL_Keycode botonDerecha = SDLK_RIGHT;
protected:                                   //**********************************
    KeyboardInput* keyboardInput2;
    SDL_Keycode botonBomba2 = SDLK_p;
    SDL_Keycode botonArriba2 = SDLK_i;
    SDL_Keycode botonAbajo2 = SDLK_k;
    SDL_Keycode botonIzquierda2 = SDLK_j;
    SDL_Keycode botonDerecha2 = SDLK_l;             
    
public:
    // Constructores destructor
    GamePawn();
    GamePawn(Texture* _textura, Tile* _tileActual);
    ~GamePawn();
    // Metodos accesores

    void setBotomBomba(SDL_KeyCode _botonBomba) { botonBomba = _botonBomba; }
    void setBotomArriba(SDL_KeyCode _botonArriba) { botonArriba = _botonArriba; }
    void setBotomAbajo(SDL_KeyCode _botonAbajo) { botonAbajo = _botonAbajo; }
    void setBotomDerecha(SDL_KeyCode _botonDerecha) { botonDerecha = _botonDerecha; }
    void setBotomIzquierda(SDL_KeyCode _botonIzquierda) { botonIzquierda = _botonIzquierda; }

    void setBotomBomba2(SDL_KeyCode _botonBomba2) { botonBomba2 = _botonBomba2; }
    void setBotomArriba2(SDL_KeyCode _botonArriba2) { botonArriba2 = _botonArriba2; }
    void setBotomAbajo2(SDL_KeyCode _botonAbajo2) { botonAbajo2= _botonAbajo2; }
    void setBotomDerecha2(SDL_KeyCode _botonDerecha2) { botonDerecha2 = _botonDerecha2; }
    void setBotomIzquierda2(SDL_KeyCode _botonIzquierda2) { botonIzquierda2 = _botonIzquierda2; }




    // Metodos heredados
    virtual void render();
    virtual void update();
    virtual void update2();
    virtual void handleEvent(SDL_Event* _event){};
    virtual void deleteGameObjet();

    // Metodos especificos
    virtual void setTileActual(Tile* _tileNuevo) {};

};

