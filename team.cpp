#include "team.h" // <string> <vector> "player.h"

Team::Team(){
	totalRunsScored = 0;
	totalWicketsLost = 0;
	totalBallsBowled = 0;
}


void Team :: displayTeam(int playerPerTeam, std::string teamName){

	std::cout << "------------------------" << std::endl;
	std::cout << "         "<< teamName << std::endl;
	std::cout << "------------------------" << std::endl;

	for ( int i=1 ; i <= playerPerTeam; i++ ){
		std::cout << "\t" << "[" << i << "] " << teamPlayers[i-1].name << std::endl;
	}

	std::cout << "------------------------\n" << std::endl;
}


