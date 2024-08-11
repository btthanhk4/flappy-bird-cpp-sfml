#pragma once

#include <sstream>
#include "DEFINITIONS.hpp"
#include "GameState.hpp"
#include "GameOverState.hpp"

#include <iostream>

namespace Sonar
{
	GameState::GameState(GameDataRef data) : _data(data)
	{

	}

	void GameState::Init()
	{
		if (!_hitSoundBuffer.loadFromFile(HIT_SOUND_FILEPATH))
		{
			std::cout << "Error Loading Hit Sound Effect" << std::endl;
		}

		if (!_wingSoundBuffer.loadFromFile(WING_SOUND_FILEPATH))
		{
			std::cout << "Error Loading Wing Sound Effect" << std::endl;
		}

		if (!_pointSoundBuffer.loadFromFile(POINT_SOUND_FILEPATH))
		{
			std::cout << "Error Loading Point Sound Effect" << std::endl;
		}

		_hitSound.setBuffer(_hitSoundBuffer);
		_wingSound.setBuffer(_wingSoundBuffer);
		_pointSound.setBuffer(_pointSoundBuffer);

		this->_data->assets.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH);
		this->_data->assets.LoadTexture("Pipe Up", PIPE_UP_FILEPATH);
		this->_data->assets.LoadTexture("Pipe Down", PIPE_DOWN_FILEPATH);
		this->_data->assets.LoadTexture("Land", LAND_FILEPATH);
		this->_data->assets.LoadTexture("Bird Frame 1", BIRD_FRAME_1_FILEPATH);
		this->_data->assets.LoadTexture("Bird Frame 2", BIRD_FRAME_2_FILEPATH);
		this->_data->assets.LoadTexture("Bird Frame 3", BIRD_FRAME_3_FILEPATH);
		this->_data->assets.LoadTexture("Bird Frame 4", BIRD_FRAME_4_FILEPATH);
		this->_data->assets.LoadTexture("Scoring Pipe", SCORING_PIPE_FILEPATH);
		this->_data->assets.LoadFont("Flappy Font", FLAPPY_FONT_FILEPATH);
		this->_data->assets.LoadTexture("Double Score Item", DOUBLE_SCORE_ITEM_FILEPATH);
		this->_data->assets.LoadTexture("Speed Up Item", SPEED_UP_ITEM_FILEPATH);

		doubleScoreItemSprite.setTexture(this->_data->assets.GetTexture("Double Score Item"));
		speedUpItemSprite.setTexture(this->_data->assets.GetTexture("Speed Up Item"));

		doubleScoreItemSprite.setPosition(-100, -100);
		speedUpItemSprite.setPosition(-100, -100);

        pipeMovementSpeed = PIPE_MOVEMENT_SPEED;
        pipeSpawnFrequency = PIPE_SPAWN_FREQUENCY;


		pipe = new Pipe(_data);
		land = new Land(_data);
		bird = new Bird(_data);
		flash = new Flash(_data);
		hud = new HUD(_data);

		_background.setTexture(this->_data->assets.GetTexture("Game Background"));

		_score = 0;
		hud->UpdateScore(_score);

		_gameState = GameStates::eReady;
	}

	void GameState::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}

			if (this->_data->input.IsSpriteClicked(this->_background, sf::Mouse::Left, this->_data->window))
			{
				if (GameStates::eGameOver != _gameState)
				{
					_gameState = GameStates::ePlaying;
					bird->Tap();

					_wingSound.play();
				}
			}
		}
	}

    void GameState::Update(float dt)
    {
        if (GameStates::eGameOver != _gameState)
        {
            bird->Animate(dt);
            land->MoveLand(dt);
        }

        if (GameStates::ePlaying == _gameState)
        {
            pipe->MovePipes(dt);

            if (clock.getElapsedTime().asSeconds() > pipeSpawnFrequency)
            {
                pipe->RandomisePipeOffset();

                pipe->SpawnInvisiblePipe();
                pipe->SpawnBottomPipe();
                pipe->SpawnTopPipe();
                pipe->SpawnScoringPipe();

                clock.restart();
            }

            bird->Update(dt);


            std::vector<sf::Sprite> landSprites = land->GetSprites();

            for (int i = 0; i < landSprites.size(); i++)
            {
                if (collision.CheckSpriteCollision(bird->GetSprite(), 0.7f, landSprites.at(i), 1.0f))
                {
                    _gameState = GameStates::eGameOver;

                    clock.restart();

                    _hitSound.play();
                }
            }

            std::vector<sf::Sprite> pipeSprites = pipe->GetSprites();

            for (int i = 0; i < pipeSprites.size(); i++)
            {
                if (collision.CheckSpriteCollision(bird->GetSprite(), 0.625f, pipeSprites.at(i), 1.0f))
                {
                    _gameState = GameStates::eGameOver;

                    clock.restart();

                    _hitSound.play();
                }
            }

            // Kiểm tra và chuyển giữa các chế độ
            if (_score > 140)
            {
                // Chuyển lại bản đồ máu
                ActivateLightMode();
                darkModeActivated = false;
            }
            else if (_score > 105 && _score < 140 && !darkModeActivated)
            {
                // Chuyển sang bản đồ tối
                ActivateDarkMode();
                darkModeActivated = true;
            }
            else if (_score > 70 && _score < 105)
            {
                // Chuyển lại bản đồ sáng
                ActivateLightMode();
                darkModeActivated = false;
            }
            else if (_score > 35 && !darkModeActivated)
            {
                // Chuyển sang bản đồ tối
                ActivateDarkMode();
                darkModeActivated = true;
            }

            // Vật phẩm xuất hiện ngẫu nhiên ở giữa màn hình
            if (std::rand() % 1000 < 5) // Tỷ lệ xuất hiện ngẫu nhiên
            {
                doubleScoreItemSprite.setPosition(SCREEN_WIDTH, std::rand() % (SCREEN_HEIGHT / 2) + (SCREEN_HEIGHT / 4));
            }

            if (std::rand() % 1000 < 5) // Tỷ lệ xuất hiện ngẫu nhiên
            {
                speedUpItemSprite.setPosition(SCREEN_WIDTH, std::rand() % (SCREEN_HEIGHT / 2) + (SCREEN_HEIGHT / 4));
            }

            // Di chuyển vật phẩm nếu chúng xuất hiện trên màn hình
            if (doubleScoreItemSprite.getPosition().x >= 0)
            {
                doubleScoreItemSprite.move(-PIPE_MOVEMENT_SPEED * dt, 0);
            }

            if (speedUpItemSprite.getPosition().x >= 0)
            {
                speedUpItemSprite.move(-PIPE_MOVEMENT_SPEED * dt, 0);
            }

            // Kiểm tra va chạm với vật phẩm tăng điểm
            if (collision.CheckSpriteCollision(bird->GetSprite(), 0.7f, doubleScoreItemSprite, 1.0f))
            {
                _score += 5;  // Cộng 5 điểm
                hud->UpdateScore(_score);
                doubleScoreItemSprite.setPosition(-100, -100);  // Ẩn vật phẩm sau khi ăn
            }

            // Kiểm tra va chạm với vật phẩm tăng tốc độ
            if (collision.CheckSpriteCollision(bird->GetSprite(), 0.7f, speedUpItemSprite, 1.0f))
            {
                pipe->pipeMovementSpeed *= 1.5f;  // Tăng tốc độ của cột
                pipeSpawnFrequency /= 1.4f;  // Giảm thời gian giữa các lần xuất hiện cột
                speedUpItemSprite.setPosition(-100, -100);  // Ẩn vật phẩm sau khi ăn
            }


            // Kiểm tra nếu vật phẩm đi qua màn hình mà không bị ăn
            if (doubleScoreItemSprite.getPosition().x + doubleScoreItemSprite.getGlobalBounds().width < 0)
            {
                doubleScoreItemSprite.setPosition(-100, -100);  // Ẩn vật phẩm
            }

            if (speedUpItemSprite.getPosition().x + speedUpItemSprite.getGlobalBounds().width < 0)
            {
                speedUpItemSprite.setPosition(-100, -100);  // Ẩn vật phẩm
            }

            if (GameStates::ePlaying == _gameState)
            {
                std::vector<sf::Sprite>& scoringSprites = pipe->GetScoringSprites();

                for (int i = 0; i < scoringSprites.size(); i++)
                {
                    if (collision.CheckSpriteCollision(bird->GetSprite(), 0.625f, scoringSprites.at(i), 1.0f))
                    {
                        _score++;

                        hud->UpdateScore(_score);

                        scoringSprites.erase(scoringSprites.begin() + i);

                        _pointSound.play();
                    }
                }
            }
        }

        if (GameStates::eGameOver == _gameState)
        {
            flash->Show(dt);

            if (clock.getElapsedTime().asSeconds() > TIME_BEFORE_GAME_OVER_APPEARS)
            {
                this->_data->machine.AddState(StateRef(new GameOverState(_data, _score)), true);
            }
        }
    }



    void GameState::Draw(float dt)
    {
        // Xóa màn hình với màu nền
        this->_data->window.clear(sf::Color::Red);

        // Vẽ hình nền
        this->_data->window.draw(this->_background);

        // Vẽ các đối tượng trò chơi khác
        pipe->DrawPipes();
        land->DrawLand();
        bird->Draw();

        // Vẽ hai vật phẩm nếu chúng xuất hiện trên màn hình
        this->_data->window.draw(doubleScoreItemSprite);
        this->_data->window.draw(speedUpItemSprite);

        // Vẽ hiệu ứng flash
        flash->Draw();

        // Vẽ HUD (điểm số, v.v.)
        hud->Draw();

        // Hiển thị các nội dung đã vẽ lên màn hình
        this->_data->window.display();
    }


    void GameState::ActivateDarkMode()
    {
        // Thay đổi hình nền sang bản đồ tối
        this->_data->assets.LoadTexture("Game Background", DARK_BACKGROUND_FILEPATH);
        _background.setTexture(this->_data->assets.GetTexture("Game Background"));
    }

    void GameState::ActivateLightMode()
    {
        // Thay đổi hình nền sang bản đồ sáng
        this->_data->assets.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH);
        _background.setTexture(this->_data->assets.GetTexture("Game Background"));
    }


}