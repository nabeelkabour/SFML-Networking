#ifndef OBSERVER_H
#define OBSERVER_H

#include <cstdint>
#include "Entity.h"
#include <iostream>
#include <vector>


enum class Event : uint16_t
{
	NONE,
	DAMAGE,
	FIRST_BLOOD
};

class Observer
{
public:
	virtual ~Observer() {}
	virtual void onNotify(const Entity& entity, Event event) = 0;
};

class Subject
{
	std::vector<Observer*> _observers;

protected:
	void notify(const Entity& entity, Event event)
	{
		for (auto _observer : _observers)
		{
			_observer->onNotify(entity, event);
		}
	}

public:
	void addObserver(Observer* observer)
	{
		_observers.push_back(observer);
	}

	void removeObserver(Observer* observer)
	{
		for (uint16_t i = 0; i < _observers.size(); ++i)
		{
			if (observer == _observers[i])
			{
				_observers.erase(_observers.begin() + i);
				break;
			}
		}
	}
};

class Announcements : public Observer
{
	bool firstBlood = false;

public:
	virtual void onNotify(const Entity& entity, Event event)
	{
		switch (event)
		{
		case Event::DAMAGE:
		{
			if (!firstBlood)
			{
				std::cout << "First Blood!\n" << entity.name;
				firstBlood = true;
			}
		}
		break;
		}
	}
};

#endif