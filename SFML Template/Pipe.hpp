#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <vector>

namespace Sonar
{
	class Pipe
	{
	public:
		Pipe(GameDataRef data);

		void SpawnBottomPipe();
		void SpawnTopPipe();
		void SpawnInvisiblePipe();
		void SpawnScoringPipe();
		void MovePipes(float dt);
		void DrawPipes();
		void RandomisePipeOffset();
		float pipeMovementSpeed;
		float pipeVerticalSpeed = 50.0f;  // Tốc độ di chuyển theo chiều dọc của cột
		bool movingUp = true;             // Trạng thái di chuyển lên/xuống của cột


		const std::vector<sf::Sprite>& GetSprites() const;
		std::vector<sf::Sprite>& GetScoringSprites();

	private:
		GameDataRef _data;
		std::vector<sf::Sprite> pipeSprites;
		std::vector<sf::Sprite> scoringPipes;

		int _landHeight;
		int _pipeSpawnYOffset;

	};
}