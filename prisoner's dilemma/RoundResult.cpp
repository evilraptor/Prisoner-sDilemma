#include "DilemmaHeader.h"

//RoundResult::RoundResult(int achose, int bchose, int cchose) {
//	SetChoice(achose, bchose, cchose);
//	PrisonersPayoff(&player1choise, &player2choise, &player3choise);
//};
RoundResult::RoundResult(std::vector<char> simulationroundchoises, int pay_off_matrix[8][6]) {
	if (simulationroundchoises.size() == 3) {
		//std::cout << "a";
	}
	SetChoice(simulationroundchoises[0], simulationroundchoises[1], simulationroundchoises[2]);
	SetPrisonersPayoff(pay_off_matrix);
};
//RoundResult::RoundResult() {
//	std::cin >> player1choise >> player2choise >> player3choise;
//	PrisonersPayoff(&player1choise, &player2choise, &player3choise);
//	int at = player1choise;//t-temp
//	int bt = player2choise;
//	int ct = player3choise;
//};

void RoundResult::SetChoice(int player1_choice_input, int player2_choice_input, int player3_choice_input) {
	player1_choice = player1_choice_input;
	player2_choice = player2_choice_input;
	player3_choice = player3_choice_input;
};
void RoundResult::SetPrisonersPayoff() {
	if ((player1_choice == 'C') && (player2_choice == 'C') && (player3_choice == 'C')) { player1_pay_off = 7; player2_pay_off = 7; player3_pay_off = 7; }
	else if ((player1_choice == 'C') && (player2_choice == 'C') && (player3_choice == 'D')) { player1_pay_off = 3; player2_pay_off = 3; player3_pay_off = 9; }
	else if ((player1_choice == 'C') && (player2_choice == 'D') && (player3_choice == 'C')) { player1_pay_off = 3; player2_pay_off = 9; player3_pay_off = 3; }
	else if ((player1_choice == 'D') && (player2_choice == 'C') && (player3_choice == 'C')) { player1_pay_off = 9; player2_pay_off = 3; player3_pay_off = 3; }
	else if ((player1_choice == 'C') && (player2_choice == 'D') && (player3_choice == 'D')) { player1_pay_off = 0; player2_pay_off = 5; player3_pay_off = 5; }
	else if ((player1_choice == 'D') && (player2_choice == 'C') && (player3_choice == 'D')) { player1_pay_off = 5; player2_pay_off = 0; player3_pay_off = 5; }
	else if ((player1_choice == 'D') && (player2_choice == 'D') && (player3_choice == 'C')) { player1_pay_off = 5; player2_pay_off = 5; player3_pay_off = 0; }
	else if ((player1_choice == 'D') && (player2_choice == 'D') && (player3_choice == 'D')) { player1_pay_off = 1; player2_pay_off = 1; player3_pay_off = 1; }
};

void RoundResult::SetPrisonersPayoff(int pay_off_matrix[8][6]) {
	int tmp[3] = { 0 };
	if (player1_choice == 'D') {
		tmp[0] = 1;
	}
	else if (player1_choice == 'C') {
		tmp[0] = 0;
	}

	if (player2_choice == 'D') {
		tmp[1] = 1;
	}
	else if (player2_choice == 'C') {
		tmp[1] = 0;
	}

	if (player3_choice == 'D') {
		tmp[2] = 1;
	}
	else if (player3_choice == 'C') {
		tmp[2] = 0;
	}

	for (int i = 0;i < 8;i++) {
		if ((pay_off_matrix[i][0] == tmp[0]) && (pay_off_matrix[i][1] == tmp[1]) && (pay_off_matrix[i][2] == tmp[2])) {
			player1_pay_off = pay_off_matrix[i][3];
			player2_pay_off = pay_off_matrix[i][4];
			player3_pay_off = pay_off_matrix[i][5];
		}
	}
};

std::vector<int> RoundResult::GetScore() {
	//std::cout << "gained points: " << int(a) << " " << int(b) << " " << int(c) << "\n";
	std::vector<int> _score(3);
	_score = { player1_choice,player2_choice,player3_choice };
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
