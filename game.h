#include <ctime>
#include <cstdlib>
#include <limits>
#include "team.h" // <string> <vector> "player.h"
#include <algorithm>
#include <unistd.h>

class Game{
	public:
		Game();
		int playerPerTeam;
		int maxBalls;
		int totalPlayers;
		std::string players[11];

		bool isFirstInnings;
		Team teamA, teamB;
		Team *battingTeam, *bowlingTeam;
		Player *batsman, *bowler;

		std::vector<int> selectedPlayers;

		void greetUsers();
		void displayAllPlayers();

		void selectPlayers();
		int intSelectedPlayers();
		void displayBothTeams();

		void toss();
		bool choose(std::string);

		void firstInnings();
		void secondInnings();
		void initializePlayers();
		void playInning();
		int runsGenerator();
		void updateChart(int);

		void decideWinner();
		void matchScoreCard();
		void teamScoreCard(Team*, int);

		void clearInputBuffer();
};


