/* Author   : Sreelekha
    Topic     :  Cricket in App
 */

#include "game.h"
using namespace std;

void pressEnterTo(string, Game);

int main() {
	Game g;

	g.greetUsers();

	pressEnterTo("continue", g);
	g.displayAllPlayers();

	pressEnterTo("select players", g);
	g.selectPlayers();

	g.clearInputBuffer();
	pressEnterTo("display teams", g);
	g.displayBothTeams();

	pressEnterTo("to toss", g);
	g.toss();

	g.clearInputBuffer();
	pressEnterTo("to continue", g);
	g.firstInnings();

	g.clearInputBuffer();
	pressEnterTo("to continue", g);
	g.secondInnings();
	sleep(2);
	g.decideWinner();

	pressEnterTo("to show match insights", g);
	g.matchScoreCard();

	return 0;
}


void pressEnterTo(string str, Game g){
	std::cout << "Press enter to " << str << std::endl;

	if (std::cin.get() != '\n'){
		std::cout << "Invalid Input. ";
	    g.clearInputBuffer();
		pressEnterTo(str, g);
	}
}
