#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "State.hpp"
#include "Game.hpp"
#include "Pipe.hpp"
#include "Land.hpp"
#include "Bird.hpp"
#include "Collision.hpp"
#include "Flash.hpp"
#include "HUD.hpp"

namespace Sonar
{
	class GameState : public State
	{
	public:
		GameState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);
		float pipeMovementSpeed;
		float pipeSpawnFrequency;

	private:
		GameDataRef _data;

		sf::Sprite _background;

		Pipe* pipe;
		Land* land;
		Bird* bird;
		Collision collision;
		Flash* flash;
		HUD* hud;

		sf::Clock clock;

		int _gameState;

		sf::RectangleShape _gameOverFlash;
		bool _flashOn;

		int _score;

		sf::SoundBuffer _hitSoundBuffer;
		sf::SoundBuffer _wingSoundBuffer;
		sf::SoundBuffer _pointSoundBuffer;

		sf::Sound _hitSound;
		sf::Sound _wingSound;
		sf::Sound _pointSound;

		sf::Sprite doubleScoreItemSprite;
		sf::Sprite speedUpItemSprite;
		sf::Sprite boomItemSprite;
		sf::Sprite shieldItemSprite;
		sf::Sprite nextTrackButton;
		sf::Sprite prevTrackButton;
		sf::Sprite stopMusicButton;


		void ActivateDarkMode();
		void ActivateLightMode();
		bool darkModeActivated = false;
		bool flag = false;

		// Các biến liên quan đến âm nhạc
		sf::Music backgroundMusic;
		std::vector<std::string> musicFiles;
		int currentTrack;

		bool musicPlaying;

		void NextTrack();
		void PrevTrack();
		void StopMusic();
		void PlayMusic();

		bool hasDoubleScore = false;
		bool hasSpeedUp = false;
		bool hasBoom = false;
		bool hasShield = false;

		float itemDisplayTime = 5.0f;  // Thời gian hiển thị vật phẩm trên màn hình
		sf::Clock itemClock;
		int shieldCount; // Đếm số lượng khiên đã ăn được


	};
}