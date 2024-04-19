#pragma once
#include "../../header/Player/PlayerController.h"

namespace Player
{
	

	class PlayerService
	{
	private:
		PlayerController* player_controller;

	public:
		PlayerService();
		virtual ~PlayerService();

		void initialize();
		void update();
		void render();

		void increaseScore(int val);
		void decreaseScore(int val);
		void increaseEnemiesKilled(int val);
		
		void enableShield();
		void enableRapidFire();
		void enableTrippleLaser();
		void processBulletFire();

		void reset();
	};
}