//
//  tank.cpp
//  Tank Battle
//

#include "tank.h"

Player::Player(SDL_Renderer *ren, string file, int x, int y, int number){
    playerNumber = number;
  	imageS = IMG_Load(file.c_str());
    texture = SDL_CreateTextureFromSurface(ren,imageS);
  	if (texture == nullptr){
  		cout <<  "LoadTexture" << endl;
  	}
    
    if (number == 2){
        tank.x = 0;
        tank.y = 128;
    }
  	position.x = x;
    position.y = y;

    tank.h = 32;
    tank.w = 32;
    position.w = tank.w;
    position.h = tank.h;

    if(playerNumber == 1){
        key[0] = SDL_SCANCODE_UP;
        key[1] = SDL_SCANCODE_DOWN;
        key[2] = SDL_SCANCODE_LEFT;
        key[3] = SDL_SCANCODE_RIGHT;
    }else if(playerNumber == 2){
        key[0] = SDL_SCANCODE_W;
        key[1] = SDL_SCANCODE_S;
        key[2] = SDL_SCANCODE_A;
        key[3] = SDL_SCANCODE_D;
    }
}

Player::~Player(){
  SDL_DestroyTexture(texture);
}

void
Player::move(float delta, const Uint8 *keyposition){
    if (keyposition[key[0]]) { //UP
        position.y -= moveSpeed * delta;
        tank.x = 0;
        tank.y = 0;
        //return y;
    }else if(keyposition[key[1]]){ //DOWN
        position.y += moveSpeed * delta;
        tank.x = 0;
        tank.y = 64;
        //return y;
    }else if(keyposition[key[2]]){ //LEFT
        position.x -= moveSpeed * delta;
        tank.x = 0;
        tank.y = 96;
        //return x;
    }else if(keyposition[key[3]]){ //RIGHT
        position.x += moveSpeed * delta;
        tank.x = 0;
        tank.y = 32;
        //return x;
    }
}

void
Player::move2(float delta, const Uint8 *keyposition){
    if (keyposition[key[0]]) { //UP
        position.y -= moveSpeed * delta;
        tank.x = 0;
        tank.y = 128;
        //return y;
    }else if(keyposition[key[1]]){ //DOWN
        position.y += moveSpeed * delta;
        tank.x = 0;
        tank.y = 192;
        //return y;
    }else if(keyposition[key[2]]){ //LEFT
        position.x -= moveSpeed * delta;
        tank.x = 0;
        tank.y = 224;
        //return x;
    }else if(keyposition[key[3]]){ //RIGHT
        position.x += moveSpeed * delta;
        tank.x = 0;
        tank.y = 160;
        //return x;
    }
}
void
Player::turn(const Uint8 *keyposition){
    if (keyposition[key[0]]) { //UP
        tank.x = 0;
        if (playerNumber == 1){
            tank.y = 0;
        }else if(playerNumber == 2){
            tank.y= 128;
        }
        
        //return y;
    }else if(keyposition[key[1]]){ //DOWN
        tank.x = 0;
        if (playerNumber == 1){
            tank.y = 64;
        }else if(playerNumber == 2){
            tank.y= 192;
        }
        //return y;
    }else if(keyposition[key[2]]){ //LEFT
        
        tank.x = 0;
        if (playerNumber == 1){
            tank.y = 96;
        }else if(playerNumber == 2){
            tank.y= 224;
        }
        //return x;
    }else if(keyposition[key[3]]){ //RIGHT
        
        tank.x = 0;
        if (playerNumber == 1){
            tank.y = 32;
        }else if(playerNumber == 2){
            tank.y= 160;
        }
        //return x;
    }
}
void
Player::draw(SDL_Renderer *renderer) {
    SDL_RenderCopy(renderer, texture, &tank, &position);
}

