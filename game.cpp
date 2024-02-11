#include "game.h"

Game :: Game(){

	playerPerTeam = 4;
	maxBalls = 6;
	totalPlayers = 11;

	players[0] = "Ravi";
	players[1] = "Ram";
	players[2] = "Murali";
	players[3] = "Divakar";
	players[4] = "Saideep";
	players[5] = "Sandeep";
	players[6] = "Rajendra";
	players[7] = "Anil";
	players[8] = "Santosh";
	players[9] = "Ceaser";
	players[10] = "Jhonny";

	for (int i=1; i <=totalPlayers; i++){
		if (players[i-1].length() > 10){
			std::cout << "Internal Error !!!!" << std::endl;
			std::cout << "Name of the players should be max 10 characters." << std::endl;
			std::cout <<	"Please check the player "<< i << std::endl;
			exit(0);
		}


	}

	isFirstInnings = true;
	teamA.name = "Team-A";
	teamB.name = "Team-B";
}


// Code to greet the users
void Game :: greetUsers(){
	std::cout << "****************************************" << std::endl;
	std::cout << "\t\t\t CRIC-IN\n" << std::endl;
	std::cout << "\tWelcome to Virtual Cricket APP" << std::endl;
	std::cout << "****************************************\n\n" << std::endl;
	sleep(2);
	std::cout << "----------------------------------------------------------" << std::endl;
	std::cout << "Instructions :" << std::endl;
	std::cout << "1. Select 4 players for teams A & B from a pool\n   of 11 players." << std::endl;
	std::cout << "2. Lead the toss and decide the choice of play." << std::endl;
	std::cout << "3. Each innings will be 6 balls." << std::endl;
	std::cout << "----------------------------------------------------------\n" << std::endl;
}

//Code to display the list of players available
void Game :: displayAllPlayers(){
	std::cout << "----------------------------------------------------------" << std::endl;
	std::cout << "\t\t\tPlayers_List" << std::endl;
	std::cout << "----------------------------------------------------------\n" << std::endl;

	for( int i=0; i < totalPlayers; i++){
		std::cout << "\t[" << i+1<< "] " << players[i] << "\n";
	}
}


//Code to select players for teams
void Game :: selectPlayers(){

	std::cout << "----------------------------------------------------------" << std::endl;
	std::cout << "\t\tCreate Team-A & Team-B" << std::endl;
	std::cout << "----------------------------------------------------------\n" << std::endl;

	for( int i=1; i <= (playerPerTeam*2); i++){

			teamSelection:

			if ( i % 2 != 0 ){
				std::cout << "Select player " << i /2 + 1 << " for Team-A : ";
			}else{
				std::cout << "Select player " << i /2 << " for Team-B: ";
			}

			int input = intSelectedPlayers();

			if ( input == 1000){
				goto teamSelection;
			}else {
				selectedPlayers.push_back(input);
				Player player;
				player.index = input;
				player.name = players[input-1];
				if ( i % 2 != 0 ){
          				teamA.teamPlayers.push_back(player);
          			}else{
          				teamB.teamPlayers.push_back(player);
          			}
			 }
	}
}

//Code to store the list of players selected
int Game :: intSelectedPlayers(){
	int n=0;
	std :: cin >> n;

	if(n != 0){
		if (n>=1 && n<=11){
			 if ( find(selectedPlayers.begin(), selectedPlayers.end(), n) == selectedPlayers.end() ){
				 return n;
			 }else{
				 std::cout << "Player has been already selected. Please select other player" << std::endl;
				 return 1000;
			 }
		}else{
			std::cout << "Please select players from the list" << std::endl;
			return 1000;
	    }
	}else{
		std::cout << "Invalid entry. Please enter a number from the list" << std::endl;
		clearInputBuffer();
        return 1000;
	}
}

//Code to display teams
void Game :: displayBothTeams(){
	teamA.displayTeam(playerPerTeam, "Team-A");
	teamB.displayTeam(playerPerTeam, "Team-B");
}


//Code to perform toss
void Game :: toss(){
	std::string wonTeam;
	std::cout << "--------------------------------------------" << std::endl;
	std::cout << "                      Let's toss           " << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
	sleep(2);
	std::cout << "Tossing the coin......" << std::endl;
	sleep(5);

	srand(time(NULL));
	if ((rand() % 2) != 0)
		wonTeam = teamA.name;
	else
		wonTeam = teamB.name;

	std::cout << "Congratulations!... " << wonTeam << " won the toss" << std::endl;
	bool bat = choose(wonTeam);

	if (wonTeam == "Team-A"){
		if(bat){
			battingTeam = &teamA;
			bowlingTeam = &teamB;
		}else{
			battingTeam = &teamB;
			bowlingTeam = &teamA;
		}
	}else{
		if(bat){
				battingTeam = &teamB;
				bowlingTeam = &teamA;
		}else{
				battingTeam = &teamA;
				bowlingTeam = &teamB;
		}
	}
}

//Code to choose batting or bowling after toss
bool Game :: choose(std::string team){
	int num;
	chooseAgain:
	std::cout << "Enter 1 to bat or 2 to bowl first : " << std::endl;
	std::cout << "1. Bat \n" << "2. Bowl" << std::endl;
	std::cin >> num;

	if (num == 1){
		std::cout << team << " won the toss and elected to bat first" << std::endl;
		return 1;
	}
	else if (num == 2){
		std::cout << team << " won the toss and elected to bowl first" << std::endl;
		return 0;
	}else{
		std::cout << "Invalid Input. Please enter valid number." << std::endl;
		clearInputBuffer();
		goto chooseAgain;
	}
}


//To play first Innings
void Game :: firstInnings(){
	isFirstInnings = true;
	std::cout << "             ***** FIRST INNINGS STARTS*****" << std::endl;
	initializePlayers();
	playInning();
	sleep(1);
	std::cout << "             ***** FIRST INNINGS ENDS*****" << std::endl;
	sleep(2);
    std::cout << battingTeam->name << " " << battingTeam->totalRunsScored << " - " << battingTeam->totalWicketsLost;
    std::cout << " (" << bowlingTeam->totalBallsBowled << ") " <<std::endl;
    std::cout << bowlingTeam->name << " needs " << (battingTeam->totalRunsScored) + 1 << " runs to win the match" << std::endl;
 }

//To play second Innings
void Game :: secondInnings(){
	isFirstInnings = false;

	Team *temp = battingTeam; //swaping teams
	battingTeam = bowlingTeam;
	bowlingTeam = temp;

	std::cout << "             ***** SECOND INNINGS STARTS*****" << std::endl;
	initializePlayers();
    playInning();
}

//Code to initialize Players
void Game :: initializePlayers(){
	batsman = &battingTeam->teamPlayers[0];
	bowler = &bowlingTeam->teamPlayers[0];
	std::cout << battingTeam->name << " - " << batsman->name  << " is batting" << std::endl;
	std::cout << bowlingTeam->name << " - " << bowler->name  << " is bowling" << std::endl;
}

//Code to play the innings
void Game :: playInning(){
	for (int i=1; i<=maxBalls; i++){
          std::cout << "Press Enter to bowl";

          while(std::cin.get() !='\n'){
        	  clearInputBuffer();
        	  std::cout << "Invalid Input. Press Enter to bowl" << std::endl;
          }

          std::cout << "Bowling... " << std::endl;
          sleep(2);
          int runs = runsGenerator();

          if (runs == 0){
        	  std::cout << bowler->name << " to " << batsman->name << " OUT!" <<std::endl;
          }else {
        	  std::cout << bowler->name << " to " << batsman->name << " " << runs << " runs!" << std::endl;
          }

          updateChart(runs);

          if (battingTeam->totalWicketsLost == 4)
        	  break;

          if (runs == 0)
               batsman++;

          if (!isFirstInnings){
        	  int runsRequired = bowlingTeam->totalRunsScored - battingTeam->totalRunsScored + 1;
        	  int ballsRemaining = maxBalls - bowlingTeam->totalBallsBowled;

        	  if (runsRequired <= 0 || ballsRemaining ==0)
        		  break;
        	  else
        		  std :: cout << battingTeam->name << " needs " << runsRequired << " for " << ballsRemaining<<" balls to win the match." << std::endl;
          }
          std::cout << "\n";
	}
}

//Code to generate runs from 0 to 6
int Game :: runsGenerator(){
	srand(time(NULL));
	return rand() % 7;
}

//Code to update the chart data after each ball
void Game :: updateChart(int runs){
	 bowlingTeam->totalBallsBowled++;
	 battingTeam->totalRunsScored += runs;
	 bowler->ballsBowled++;
	 batsman->ballsPlayed++;
	 batsman->runScored += runs;
	 bowler->runsGiven += runs;

	 if (runs == 0){
		 battingTeam->totalWicketsLost++;
		 bowler->wicketsTaken++;
	 }

	 std::cout << "-----------------------------------------------------------------------------------------------" << std::endl;
	 std::cout << "\t\t" << battingTeam->name << "   " ;
	 std::cout << battingTeam->totalRunsScored << " - " << bowlingTeam->totalBallsBowled << " (" << battingTeam->totalWicketsLost << ")  | ";
	 std::cout << batsman->name << " " << batsman->runScored << " (" << batsman->ballsPlayed << ")" << "\t\t";
	 std::cout << bowler->name << " " << bowler->ballsBowled << " - " << bowler->runsGiven << " - " << bowler->wicketsTaken << std::endl;
	 std::cout << "-----------------------------------------------------------------------------------------------" << std::endl;
}


//Code to decide a winner of the game
void Game :: decideWinner(){
	int num = bowlingTeam->totalRunsScored - battingTeam->totalRunsScored;
	std::cout << "\n";
	if ( num == 0)
		std::cout << "IT'S A TIE MATCH" << std::endl;
	else if ( num > 0 )
		std::cout << bowlingTeam->name << " WON THE MATCH"<< std::endl;
	else
		std::cout << battingTeam->name << " WON THE MATCH"<< std::endl;

	std::cout << "CONGRATULATIONS!!!!!!!\n" << std::endl;
	std::cout << "              ****** MATCH ENDS ******\n" << std::endl;
}

//Code to display total match score card
void Game :: matchScoreCard(){
	teamScoreCard(&teamA, teamB.totalBallsBowled);
	std::cout << "\n";
	teamScoreCard(&teamB, teamA.totalBallsBowled);
}

void Game :: teamScoreCard(Team* t, int ballsPlayed){
    std::cout << t->name << "   " << t->totalRunsScored << " - " << t->totalWicketsLost << " (" << ballsPlayed << ")" << std::endl ;
    std::cout << "====================================================" << std::endl;
    std::cout << "PLAYER \t\tBATTING \t\t BOWLING" << std::endl;

    for (int i =1; i <=playerPerTeam; i++){
    	std::string player = t->teamPlayers[i-1].name;
    	int num = 10 - player.length();
    	std::string whiteSpaces(num, ' ');
    	player.append(whiteSpaces);

    	std::string runsScored = std::to_string (t->teamPlayers[i-1].runScored);
    	num = 2 - runsScored.length();
    	std::string ws(num, ' ');
    	runsScored.append(ws);


    	std::cout << "[" << i << "]"<< " " << player << "\t\t";

    	std::cout << runsScored << " (" << t->teamPlayers[i-1].ballsPlayed << ")"<<"\t\t\t";
    	std::cout << t->teamPlayers[i-1].ballsBowled << " - " << t->teamPlayers[i-1].runsGiven << " - " << t->teamPlayers[i-1].wicketsTaken << std::endl;
    }

    std::cout << "====================================================" << std::endl;
}

//Code to clear input buffer memory
void Game :: clearInputBuffer(){
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize> ::max(), '\n');
}

