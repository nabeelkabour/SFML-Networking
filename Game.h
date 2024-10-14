#ifndef GAME_H
#define GAME_H

#include "olcPixelGameEngine.h"
//#include "olcPGEX_Gamepad.h"
//#include "olcPGEX_MiniAudio.h"
#include "SFML/Network.hpp"
#include <ctime>
#include "Actor.h"
#include "InputHandler.h"
#include "Observer.h"
#include "Player.h"
#include "Networking.h"

#define SCREENWIDTH 500
#define SCREENHEIGHT 500


class Game : public olc::PixelGameEngine
{
public:
	std::vector<olc::vi2d> points;
	bool pressed = false;
	float timerPing = 0.f;
	float timeLast = 0.f;
	float currentTime = 0.f;
	float timeDelta = 0.f;

	Player* playerOne;
	Player* playerTwo;
	Announcements* announcer;
	Server server;

	InputHandler inputHandler;
	Actor player, enemy;

	Game();
	bool OnUserCreate() override;
	bool OnUserUpdate(float fElapsedTime) override;
};

extern Game game;

#endif