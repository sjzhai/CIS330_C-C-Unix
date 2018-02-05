#include <SDL2/SDL.h>
#include <iostream>
#include <SDL2/SDL_image.h>
#include "tank.h"

const int SCREEN_WIDTH  = 1300;
const int SCREEN_HEIGHT = 660;


// void logSDLError(std::ostream &os, const std::string &msg){
// 	os << msg << " error: " << SDL_GetError() << std::endl;
// }
//
// SDL_Texture* loadTexture(const std::string &file, SDL_Renderer *ren){
// 	SDL_Surface *imageS = IMG_Load(file.c_str());
//   SDL_Texture *texture = nullptr;
//   texture = SDL_CreateTextureFromSurface(ren,imageS);
// 	if (texture == nullptr){
// 		logSDLError(std::cout, "LoadTexture");
// 	}
//
//   //SDL_FreeSurface(imageS);
//
// 	return texture;
// }
//
// void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, SDL_Rect dst, SDL_Rect clip){
// 	SDL_RenderCopy(ren, tex, &clip, &dst);
// }
//
// void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, SDL_Rect clip){
// 	SDL_Rect dst;
// 	dst.x = x;
// 	dst.y = y;
// 	dst.w = clip.w;
// 	dst.h = clip.h;
//
// 	//SDL_QueryTexture(tex, NULL, NULL, dst.w, dst.h);
//
//   renderTexture(tex, ren, dst, clip);
// }

// int move(float delta, const Uint8 *keyposition, float moveSpeed, SDL_Rect tank , int x, int y){
//   if (keyposition[key[0]]) {
//     y -= moveSpeed * delta;
//     tank.x = 0;
//     tank.y = 0;
//     std::cout << "hi" << '\n';
//     return y;
//   }else if(keyposition[key[1]]){
//     y += moveSpeed * delta;
//     tank.x = 0;
//     tank.y = 64;
//     return y;
//   }else if(keyposition[key[2]]){
//     x -= moveSpeed * delta;
//     tank.x = 0;
//     tank.y = 96;
//     return x;
//   }else if(keyposition[key[3]]){
//     x += moveSpeed * delta;
//     tank.x = 0;
//     tank.y = 32;
//     return x;
//   }
// }


int main(int, char**){


  // const Uint8 *keypostate;


  int x = 0;
	int y = 0;
  // SDL_Rect tank;
  // tank.x = 0;
  // tank.y = 0;
  // tank.w = 32;
  // tank.h = 32;

  //int framtime = 0;
  //float frameTime = 0;
  // int preTime = 0;
  // int currentTime = 0;
  // float delta = 0;
  //float moveSpeed = 300.0f;


  SDL_Init(SDL_INIT_VIDEO);

	//Setup our window and renderer

	SDL_Window *window = SDL_CreateWindow("Lesson8", SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  Player player1(renderer, "sprite.bmp", 0, 0, 1);
  const Uint8 *keypostate;

  SDL_SetRenderDrawColor(renderer,0xFF,0,0,0xFF);

  int preTime = 0;
  int currentTime = 0;
  float delta = 0;
  bool isRunning = true;
  SDL_Event ev;
  std::cout << "hi" << '\n';
  while (isRunning) {

    preTime = currentTime;
    currentTime = SDL_GetTicks();
    delta = (currentTime - preTime) / 1000.0f;
    while (SDL_PollEvent(&ev)!= 0) {

      if (ev.type == SDL_QUIT) {
        isRunning = false;
      }
    //   else if(ev.type == SDL_KEYDOWN){
    //     switch (ev.key.keysym.sym) {
    //       case SDLK_RIGHT:
    //         x += moveSpeed * delta;
    //         tank.x = 0;
    //         tank.y = 32;
    //           //std::cout << "hi" << '\n';
    //     }
    //   }
    }

    keypostate = SDL_GetKeyboardState(NULL);

    player1.move(delta, keypostate);

    //SDL_RendererClear(renderer);
    SDL_RenderClear(renderer);
    //renderTexture(image,renderer,x,y,tank);
    player1.draw(renderer);
    //SDL_RenderCopy(renderer,image, NULL, NULL);
    SDL_RenderPresent(renderer);
  }


  //SDL_DestroyTexture(image);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  IMG_Quit();
  SDL_Quit();

  return 0;
}
