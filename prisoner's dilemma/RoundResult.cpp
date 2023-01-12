#include "DilemmaHeader.h"

//RoundResult::RoundResult(int achose, int bchose, int cchose) {
//	SetChoice(achose, bchose, cchose);
//	PrisonersPayoff(&player1choise, &player2choise, &player3choise);
//};
RoundResult::RoundResult(std::vector<char> simulationroundchoises) {
	if (simulationroundchoises.size() == 3) {
		//std::cout << "a";
	}
	SetChoice(simulationroundchoises[0], simulationroundchoises[1], simulationroundchoises[2]);
	SetPrisonersPayoff();
};
//RoundResult::RoundResult() {
//	std::cin >> player1choise >> player2choise >> player3choise;
//	PrisonersPayoff(&player1choise, &player2choise, &player3choise);
//	int at = player1choise;//t-temp
//	int bt = player2choise;
//	int ct = player3choise;
//};

void RoundResult::SetChoice(int player1_choise_input, int player2_choise_input, int player3_choise_input) {
	player1_choise = player1_choise_input;
	player2_choise = player2_choise_input;
	player3_choise = player3_choise_input;
};
void RoundResult::SetPrisonersPayoff() {
	if ((player1_choise == 'C') && (player2_choise == 'C') && (player3_choise == 'C')) { player1_pay_off = 7; player2_pay_off = 7; player3_pay_off = 7; }
	else if ((player1_choise == 'C') && (player2_choise == 'C') && (player3_choise == 'D')) { player1_pay_off = 3; player2_pay_off = 3; player3_pay_off = 9; }
	else if ((player1_choise == 'C') && (player2_choise == 'D') && (player3_choise == 'C')) { player1_pay_off = 3; player2_pay_off = 9; player3_pay_off = 3; }
	else if ((player1_choise == 'D') && (player2_choise == 'C') && (player3_choise == 'C')) { player1_pay_off = 9; player2_pay_off = 3; player3_pay_off = 3; }
	else if ((player1_choise == 'C') && (player2_choise == 'D') && (player3_choise == 'D')) { player1_pay_off = 0; player2_pay_off = 5; player3_pay_off = 5; }
	else if ((player1_choise == 'D') && (player2_choise == 'C') && (player3_choise == 'D')) { player1_pay_off = 5; player2_pay_off = 0; player3_pay_off = 5; }
	else if ((player1_choise == 'D') && (player2_choise == 'D') && (player3_choise == 'C')) { player1_pay_off = 5; player2_pay_off = 5; player3_pay_off = 0; }
	else if ((player1_choise == 'D') && (player2_choise == 'D') && (player3_choise == 'D')) { player1_pay_off = 1; player2_pay_off = 1; player3_pay_off = 1; }
};
std::vector<int> RoundResult::GetScore() {
	//std::cout << "gained points: " << int(a) << " " << int(b) << " " << int(c) << "\n";
	std::vector<int> _score(3);
	_score = { player1_choise,player2_choise,player3_choise };
	return _score;
};
bool PlayersOfNewRounde(int* players_of_this_rounde, int playerscount, int players_count_in_single_game)
{
	int k = players_count_in_single_game;
	for (int i = k - 1; i >= 0; --i)
		if (players_of_this_rounde[i] < playerscount - k + i + 1)
		{
			++players_of_this_rounde[i];
			for (int j = i + 1; j < k; ++j)
				/*players_of_new_rounde*/players_of_this_rounde[j] = players_of_this_rounde[j - 1] + 1;
			return true;
		}
	return false;
};
