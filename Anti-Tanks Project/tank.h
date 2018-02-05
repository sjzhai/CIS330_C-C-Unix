//
//  tank.h
//  Tank Battle
//

#ifndef tank_h
#define tank_h

#include <SDL2/SDL.h>
#include <iostream>
#include <SDL2/SDL_image.h>
#include <string>
using namespace std;

class Player
{
  public:
    Player(SDL_Renderer *renderer, string file, int x, int y, int number);
    ~Player();

    int x;
    int y;
    void move(float delta, const Uint8 *keypositions);
    void move2(float delta, const Uint8 *keypositions);
    void turn(const Uint8 *keyposition);
    void draw(SDL_Renderer *renderer);
    
    
    SDL_Surface *imageS;
    SDL_Texture *texture = nullptr;
    SDL_Rect position;
    float moveSpeed = 192.0f;
    SDL_Scancode key[4];
    int playerNumber;


private:
  SDL_Rect tank;
};

#endif /* tank_h */
