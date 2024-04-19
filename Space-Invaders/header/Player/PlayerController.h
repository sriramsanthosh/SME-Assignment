#pragma once
#include <SFML/Graphics.hpp>
#include "../Collision/ICollider.h"
#include "../../header/Powerup/PowerupConfig.h"
#include "../../header/Player/PlayerModel.h"
#include "../../header/UI/UIElement/ImageView.h"

namespace Player
{
    class PlayerView
    {
    private:
        const sf::String player_texture_path = "assets/textures/player_ship.png";

    	const float player_sprite_width = 60.f;
        const float player_sprite_height = 60.f;

        PlayerController* player_controller;
        UI::UIElement::ImageView* player_image;

        void createUIElements();
        void initializeImage();

        void destroy();

    public:
        PlayerView();
        ~PlayerView();

        void initialize(PlayerController* controller);
        void update();
        void render();

        void setPlayerHighlight(bool b_highlight);
        const sf::Sprite& getPlayerSprite();
    };
    

    class PlayerController : public Collision::ICollider
    {
    private:
        float elapsed_shield_duration;
        float elapsed_rapid_fire_duration;
        float elapsed_tripple_laser_duration;

        float elapsed_fire_duration;
        float elapsed_freez_duration;

        PlayerView* player_view;
        PlayerModel* player_model;

        void processPlayerInput();
        void moveLeft();
        void moveRight();

        bool processPowerupCollision(ICollider* other_collider);
        bool processEnemyCollision(ICollider* other_collider);
        void updateFreezDuration();
        void freezPlayer();
        void updatePowerupDuration();
       
        void disableShield();   
        void disableRapidFire();    
        void disableTrippleLaser();

        void saveHighScore();

    public:
        PlayerController();
        ~PlayerController();

        void initialize();
        void update();
        void render();

        void reset();

        void decreasePlayerLive();
        inline void increaseScore(int val) { PlayerModel::player_score += val; }
        inline void decreaseScore(int val) { PlayerModel::player_score -= val; }
        inline void increaseEnemiesKilled(int val) { PlayerModel::enemies_killed += val; }
        inline void increaseBulletsFired(int val) { PlayerModel::bullets_fired += val; }
        
        void enableShield();
        void enableRapidFire();
        void enableTrippleLaser();
        void processBulletFire();

        sf::Vector2f getPlayerPosition();
        PlayerState getPlayerState();

        const sf::Sprite& getColliderSprite() override;
        void onCollision(ICollider* other_collider) override;
    };
}