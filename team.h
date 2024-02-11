#include "player.h" // <string>
#include <vector>
#include <iostream>


class Team{

	public:
		Team();
		std::string name;
		int totalRunsScored;
		int totalWicketsLost;
		int totalBallsBowled;
		std::vector <Player> teamPlayers;

		void displayTeam(int, std::string);
};

