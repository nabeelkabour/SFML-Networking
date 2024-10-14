#ifndef PLAYER_H
#define PLAYER_H

#include "olcUTIL_Geometry2D.h"
#include "Actor.h"
#include "Observer.h"

class Player : public Subject, public Actor
{
	std::string name = "Player";
	int32_t hp = 100;

public:
	Player() {}
	Player(float _x, float _y) : Actor(_x, _y) {}
	Player(olc::vf2d pos) : Actor(pos) {}

	bool collidesWith(Actor* other)
	{
		return overlaps(collisionMask, other->collisionMask);
	}

	void damage(uint32_t _dmg)
	{
		hp -= _dmg;

		notify(*this, Event::DAMAGE);
	}
};

#endif