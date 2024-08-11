#include "Pipe.hpp"
#include "DEFINITIONS.hpp"

#include <iostream>

namespace Sonar
{
	Pipe::Pipe(GameDataRef data) : _data(data)
	{
		_landHeight = this->_data->assets.GetTexture("Land").getSize().y;
		_pipeSpawnYOffset = 0;

		pipeMovementSpeed = PIPE_MOVEMENT_SPEED;
	}

	void Pipe::SpawnBottomPipe()
	{
		sf::Sprite sprite(this->_data->assets.GetTexture("Pipe Up"));

		sprite.setPosition(this->_data->window.getSize().x, this->_data->window.getSize().y - sprite.getLocalBounds().height - _pipeSpawnYOffset);

		pipeSprites.push_back(sprite);
	}

	void Pipe::SpawnTopPipe()
	{
		sf::Sprite sprite(this->_data->assets.GetTexture("Pipe Down"));

		sprite.setPosition(this->_data->window.getSize().x, -_pipeSpawnYOffset);

		pipeSprites.push_back(sprite);
	}

	void Pipe::SpawnInvisiblePipe()
	{
		sf::Sprite sprite(this->_data->assets.GetTexture("Pipe Down"));

		sprite.setPosition(this->_data->window.getSize().x, -_pipeSpawnYOffset);
		sprite.setColor(sf::Color(0, 0, 0, 0));

		pipeSprites.push_back(sprite);
	}

	void Pipe::SpawnScoringPipe()
	{
		sf::Sprite sprite(this->_data->assets.GetTexture("Scoring Pipe"));

		sprite.setPosition(this->_data->window.getSize().x, 0);

		scoringPipes.push_back(sprite);
	}

	void Pipe::MovePipes(float dt)
	{
		for (unsigned int i = 0; i < pipeSprites.size(); i++)
		{
			if (pipeSprites.at(i).getPosition().x < 0 - pipeSprites.at(i).getGlobalBounds().width)
			{
				pipeSprites.erase(pipeSprites.begin() + i);
			}
			else
			{
				float movement = pipeMovementSpeed * dt;
				pipeSprites.at(i).move(-movement, 0);
			}
		}

		// Cũng cần di chuyển các cột ghi điểm
		for (unsigned int i = 0; i < scoringPipes.size(); i++)
		{
			if (scoringPipes.at(i).getPosition().x < 0 - scoringPipes.at(i).getGlobalBounds().width)
			{
				scoringPipes.erase(scoringPipes.begin() + i);
			}
			else
			{
				float movement = pipeMovementSpeed * dt;
				scoringPipes.at(i).move(-movement, 0);
			}
		}
	}



	void Pipe::DrawPipes()
	{
		for (unsigned short int i = 0; i < pipeSprites.size(); i++)
		{
			this->_data->window.draw(pipeSprites.at(i));
		}
	}

	void Pipe::RandomisePipeOffset()
	{
		_pipeSpawnYOffset = rand() % (_landHeight + 1);
	}

	const std::vector<sf::Sprite>& Pipe::GetSprites() const
	{
		return pipeSprites;
	}

	std::vector<sf::Sprite>& Pipe::GetScoringSprites()
	{
		return scoringPipes;
	}
}