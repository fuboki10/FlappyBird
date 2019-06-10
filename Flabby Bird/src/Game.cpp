#include "Game.h"
#include<SDL.h>
#include"pipe.h"
#include"LoadTextureh.h"
#include"Score.h"

Game::Game(SDL_Renderer *renderer):
	counter(0),
	renderer(renderer),
	pipeTexture(loadTexture(renderer,"tube2.bmp")),
	bird(renderer),
	m_pipe(renderer,pipeTexture,300,true),
	points(0),
	score(points)
{
}




bool Game::tick(bool isMouseDown)
{
	if( counter++ % 2000 == 0)
	{
		auto y = rand()% (Application::SCREEN_HEIGHT - 200 - 250 - 100 )+100;
		tubeList.emplace_back(renderer,pipeTexture, y + 250 , false);
		tubeList.emplace_back(renderer,pipeTexture, y , true);
		points++;

	}
	bird.tick(isMouseDown);
	m_pipe.tick();
	SDL_Rect birdRect;
	birdRect.x = bird.x - 5/2;
	birdRect.y = bird.y - 5/2;
	birdRect.w = 5;
	birdRect.h = 5;
	SDL_Rect res;
	for (auto &tube : tubeList)
	{
		tube.tick();
		if(tube.isup)
		{
			SDL_Rect tubeRect;
			tubeRect.x = tube.x - 128;
			tubeRect.y = tube.y - 10000;
			tubeRect.w = 256;
			tubeRect.h = 10000;
			if(SDL_IntersectRect(&birdRect,&tubeRect,&res))
			{
				return false;
			}
		}
		else{
			SDL_Rect tubeRect;
			tubeRect.x = tube.x - 128;
			tubeRect.y = tube.y;
			tubeRect.w = 256;
			tubeRect.h = 10000;
			if(SDL_IntersectRect(&birdRect,&tubeRect,&res))
			{
				return false;
			}

		}

	}
	return bird.y < Application::SCREEN_HEIGHT;
}

int Game::exec()
{

	auto oldTick = SDL_GetTicks();
	bool isMouseDown =false;
	for (auto gameClose = false ; !gameClose ;)
	{
		SDL_Event e;
		if (SDL_PollEvent(&e))
		{
			switch (e.type)
			{
			case SDL_MOUSEBUTTONDOWN:
				isMouseDown =true;
				break;
			case SDL_MOUSEBUTTONUP:
				isMouseDown =false;
				break;
			case SDL_QUIT:
				gameClose =true;
				break;
			}


		}
		auto currentTick = SDL_GetTicks();
		for(auto i = oldTick ; i<currentTick ;++i)
		{if(!(tick(isMouseDown)))
		return 1;}
		oldTick = currentTick;
		SDL_SetRenderDrawColor(renderer,0x00,0xff,0xff,0xff);
		SDL_RenderClear(renderer);
		bird.draw();
		for(auto &tube:tubeList)
			tube.draw();
		score.draw(renderer);
		SDL_RenderPresent(renderer);

	}
	return 0;
}