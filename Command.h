#ifndef COMMAND_H
#define COMMAND_H

#include "Actor.h"
#include <iostream>

using std::cout;

class Command
{
public:
    virtual ~Command() {}
    virtual void execute(Actor* actor) = 0;
};

class MoveCommand : public Command
{
public:
    virtual void execute(Actor* actor)
    {
        //actor.x += 1;
    }
};

class DamageCommand : public Command
{
public:
    virtual void execute(Actor* actor)
    {
        cout << "Damage Taken.\n";
        //actor->damage(); // Player* playerOne is passed.
    }
};

#endif