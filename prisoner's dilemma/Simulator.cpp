#include "DilemmaHeader.h"

Score Simulator(int game_steps_number, short game_type, int player1_place, int player2_place, int player3_place, Score score, std::vector<std::vector<char>> roundschoices, std::map<int, IStrategy*> players) {
	if (game_type != 2)std::cin.get();
	std::vector<int> _score(3);
	for (int i = 0; i < game_steps_number; i++) {
		_score = score.GetRoundScore(player1_place, player2_place, player3_place);
		std::vector<char>simulationroundchoices(3);
		for (int j = 0; j < 3; j++) {
			int tmp = _score[j];
			simulationroundchoices[j] = players[j]->Getchoice(game_type, j, _score, roundschoices, simulationroundchoices);
			roundschoices[i].push_back(simulationroundchoices[j]);
		}
		if (game_type == 1) {
			std::cout << "\n";
		}
		RoundResult roundresult(simulationroundchoices);
		//score.ChangeScore(roundresult.a, strategy1p, roundresult.b, strategy2p, roundresult.c, strategy3p);
		score.ChangeRoundScore(roundresult.player1_pay_off,roundresult.player2_pay_off,roundresult.player3_pay_off);
		/*_score = */score.ShowGameScore(player1_place, player2_place, player3_place, game_type);
		roundschoices.push_back(simulationroundchoices);
		if (game_type != 2)std::cout << "do something...\n";
		if (game_type != 2)std::cin.get();
	}
	score.ChangeGlobalScore(player1_place, player2_place, player3_place);
	score.ShowGlobalScore();
	std::cout << "\n";
	score.MakeItZero();
	return score;
}
