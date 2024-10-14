#include "Game.h"
#include "Actor.h"
//#include "Resources.h"
//#include "Items.h"
//#include "Particle.h"
#include "InputHandler.h"
#include "Command.h"
#include "Observer.h"
#include "Prototype.h"
#include "Player.h"

Game game;

enum Cmd : uint8_t
{
    ping,
    click
};


Game::Game()
{
	sAppName = "SFML PGE";
}

bool Game::OnUserCreate()
{
	//srand(time(NULL));

    inputHandler._buttonX = new DamageCommand;
    announcer = new Announcements;
    playerOne = new Player(100.f, 100.f);
    playerTwo = new Player(200.f, 100.f);

    playerOne->addObserver(announcer);

	return true;
}

bool Game::OnUserUpdate(float fElapsedTime)
{
	Clear(olc::BLACK);

    //currentTime += fElapsedTime;

   // timerPing += fElapsedTime;

    //if (timerPing >= 1.5f)
    //{
    //    sf::Packet packetTx;
    //    timeLast = currentTime;
    //    packetTx << Cmd::ping;
    //    client.send(packetTx);

    //    timerPing = 0.f;
    //}

    server.update(fElapsedTime);

    //game.DrawString(100, 100, std::to_string(timeDelta * 1000) + "ms"); 

    Command* command = inputHandler.handleInput(this);

    if (command)
    {
        command->execute(playerOne);
        playerOne->damage(5);
    }

    //DrawCircle(playerOne->x, playerOne->y, 10);
    //Actor* arbPrototype = new Actor(100, 100);


    //Spawner* actorSpawner = new SpawnerFor<Actor>();

    //Actor* actor = actorSpawner->spawnMonster();

    //FillCircle(actor->x, actor->y, 20);

    if (playerOne->collidesWith(playerTwo))
    {
        cout << "Players colliding\n";
    }

    playerOne->position.x -= GetKey(olc::Key::LEFT).bHeld * fElapsedTime * 50.f;
    playerOne->position.x += GetKey(olc::Key::RIGHT).bHeld * fElapsedTime * 50.f;
    playerOne->collisionMask.pos = playerOne->position;

    //circle<float>(playerOne->collisionMask);
    DrawCircle(playerOne->position, 10.f);
    DrawCircle(playerTwo->position, 10.f);

	return true;
}