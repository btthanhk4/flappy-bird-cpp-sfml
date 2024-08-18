#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "Game.hpp"

namespace Sonar
{
    class HUD
    {
    public:
        HUD(GameDataRef data);
        ~HUD();

        void Draw();
        void UpdateScore(int score);
        void UpdateShieldCount(int count); // Thêm phương thức để cập nhật số lượng khiên

    private:
        GameDataRef _data;

        sf::Text _scoreText;
        sf::Text _shieldText; // Thêm biến để hiển thị số lượng khiên
    };
}
