#ifndef NETWORKING_H
#define NETWORKING_H

#include "SFML/Network.hpp"
#include <list>
#include <iostream>

struct Client
{
	std::unique_ptr<sf::TcpSocket> socket;
	//sf::TcpSocket* socket;
	sf::Packet packetRx;
};

class Server
{
	sf::TcpListener listener;
	std::list<Client> clients;
	//sf::SocketSelector selector;

public:

	Server()
	{
		listener.setBlocking(false);
		listener.listen(5000);
		//cout << listener.listen(2000) << "\n";
	}

	void update(float fElapsedTime)
	{
		{
			Client newClient;
			//newClient.socket = new sf::TcpSocket;

			//if (listener.accept(*newClient.socket) == sf::Socket::Done)
			//{
			//	newClient.socket->setBlocking(false);
			//	clients.push_back(std::move(newClient));
			//}
		}

		//auto potentialClientIter = clients.emplace_back();

		//if (listener.accept(potentialClientIter->socket) == sf::Socket::Done)
		//{
		//	potentialClientIter.socket->setBlocking(false);
		//}
		//else
		//{
		//	clients.erase(potentialClientIter);
		//}


		for (auto& client : clients)
		{
			auto receive_status = client.socket->receive(client.packetRx);

			if (receive_status == sf::Socket::Status::Done)
			{
				uint8_t identifier;
				client.packetRx >> identifier;

				//std::cout << identifier << "\n";

				//switch (identifier)
				//{
				//case Cmd::ping:
				//{
				//	float timeReceive = currentTime;
				//	timeDelta = timeReceive - timeLast;

				//	//std::cout << timeDelta * 1000 << "us\n";
				//}
				//break;
				//}
			}
		}
	}
};

#endif 
