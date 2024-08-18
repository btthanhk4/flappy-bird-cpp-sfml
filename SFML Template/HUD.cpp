#include "HUD.hpp"
#include <string>

namespace Sonar
{
    HUD::HUD(GameDataRef data) : _data(data)
    {
        // Khởi tạo văn bản hiển thị điểm số
        _scoreText.setFont(this->_data->assets.GetFont("Flappy Font"));
        _scoreText.setString("0");
        _scoreText.setCharacterSize(128);
        _scoreText.setFillColor(sf::Color::White);
        _scoreText.setOrigin(sf::Vector2f(_scoreText.getGlobalBounds().width / 2, _scoreText.getGlobalBounds().height / 2));
        _scoreText.setPosition(sf::Vector2f(_data->window.getSize().x / 2, _data->window.getSize().y / 5));

        // Khởi tạo văn bản hiển thị số lượng khiên
        _shieldText.setFont(this->_data->assets.GetFont("Flappy Font"));
        _shieldText.setString("Shields: 0");
        _shieldText.setCharacterSize(64);
        _shieldText.setFillColor(sf::Color::White);
        _shieldText.setPosition(sf::Vector2f(10, 100)); // Điều chỉnh vị trí hiển thị khiên
    }

    HUD::~HUD()
    {
    }

    void HUD::Draw()
    {
        _data->window.draw(_scoreText);
        _data->window.draw(_shieldText); // Vẽ số lượng khiên trên màn hình
    }

    void HUD::UpdateScore(int score)
    {
        _scoreText.setString(std::to_string(score));
    }

    void HUD::UpdateShieldCount(int count)
    {
        _shieldText.setString("Shields: " + std::to_string(count)); // Cập nhật văn bản hiển thị số lượng khiên
    }
}
