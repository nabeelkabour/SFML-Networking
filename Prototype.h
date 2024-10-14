#ifndef PROTOTYPE_H
#define PROTOTYPE_H

#include "Actor.h"

class Spawner
{
public:
	virtual ~Spawner() {}
	virtual Actor* spawnMonster() = 0;
};

template<class T>
class SpawnerFor : public Spawner
{
public:
	//SpawnerFor(T* inst) : _inst(inst) {}
	virtual T* spawnMonster() { return new T(); }
};

#endif