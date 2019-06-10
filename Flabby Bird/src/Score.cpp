#include "Score.h"
#include<iostream>
#include<string>
#include"Application.h"
Score::Score(int points):
	font(TTF_OpenFont("TIMESR.ttf",font_size)),
	width(30),
	texture(NULL),
	height(30),
	points(points)

{

	if( SDL_BYTEORDER == SDL_BIG_ENDIAN)
	{
		Rmask = 0xff000000;
		Gmask = 0x00ff0000;
		Bmask = 0x0000ff00;
		Amask = 0x000000ff;
	}
	else
	{
		Rmask = 0x000000ff;
		Gmask = 0x0000ff00;
		Bmask = 0x00ff0000;
		Amask = 0xff000000;
	}
}


Score::~Score(void)
{
	SDL_DestroyTexture(texture);
}

void Score::draw(SDL_Renderer *renderer)
{
	SDL_Surface*surface = SDL_CreateRGBSurface(0,Application::SCREEN_WIDTH,Application::SCREEN_HEIGHT,32,Rmask,Gmask,Bmask,Amask);
	char buffer[50];
	sprintf_s(buffer,"%d",points);
	SDL_Color text_color = {0,0,0};
	text_surface = TTF_RenderText_Solid(font,buffer,text_color);
	
	int x=10;
	int y=10;
	SDL_Rect dst = {x,y,width,height};
	SDL_BlitSurface(text_surface,&dst,surface,NULL);
	SDL_FreeSurface(text_surface);
	SDL_FreeSurface(surface);
}
