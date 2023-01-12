#include "DilemmaHeader.h"

//void Score::ChangeScore(int da, int pa, int db, int pb, int dc, int pc) {
//	ascore += da;
//	bscore += db;
//	cscore += dc;
//	typename Scores::iterator it1 = _scores.find(pa);
//	if (it1 == _scores.end())
//		_scores[pa] = 0;
//	typename Scores::iterator it2 = _scores.find(pb);
//	if (it2 == _scores.end())
//		_scores[pb] = 0;
//	typename Scores::iterator it3 = _scores.find(pc);
//	if (it3 == _scores.end())
//		_scores[pc] = 0;
//	_scores[pa] += ascore;
//	_scores[pb] += bscore;
//	_scores[pc] += cscore;
//};

void Score::ChangeRoundScore(int player1pointsroundchange, int player2pointsroundchange, int player3pointsroundchange) {
	player1gamepoints += player1pointsroundchange;
	player2gamepoints += player2pointsroundchange;
	player3gamepoints += player3pointsroundchange;
};
void Score::ChangeGlobalScore(int player1_place, int player2_place, int player3_place) {
	typename Playersglobalscore::iterator it1 = playersglobalscore.find(player1_place);
		if (it1 == playersglobalscore.end())
			playersglobalscore[player1_place] = 0;
		typename Playersglobalscore::iterator it2 = playersglobalscore.find(player2_place);
		if (it2 == playersglobalscore.end())
			playersglobalscore[player2_place] = 0;
		typename Playersglobalscore::iterator it3 = playersglobalscore.find(player3_place);
		if (it3 == playersglobalscore.end())
			playersglobalscore[player3_place] = 0;
		playersglobalscore[player1_place] += player1gamepoints;
		playersglobalscore[player2_place] += player2gamepoints;
		playersglobalscore[player3_place] += player3gamepoints;
};

void Score::ShowGameScore(int player1_place, int player2_place, int player3_place, int game_type) {
	if (game_type != 2) {
		std::cout << "score in this game changed by: " << "player" << player1_place << ": " << player1gamepoints << ", " << "player" << player2_place << ": " << player2gamepoints << ",  " << "player" << player3_place << ": " << player3gamepoints << "\n";
	}
};

std::vector<int> Score::GetRoundScore(int player1_place, int player2_place, int player3_place) {
	std::vector<int> _score(3);
	_score = { player1gamepoints,player2gamepoints,player3gamepoints };
	return _score;
};

void Score::ShowGlobalScore() {
	std::cout << "global score now: ";
	for (const auto& playersglobalscore : playersglobalscore) {
		std::cout <<"player"<< playersglobalscore.first << ": "<< playersglobalscore.second<<"; ";
	}
};
void Score::ShowBestGlobalScore() {
	int element_place = 0;
	int tmp = playersglobalscore[element_place];
	for (int i = 0; i < playersglobalscore.size(); i++)
		if (tmp < playersglobalscore[i]) {
			tmp = playersglobalscore[i];
			element_place = i;
		}
	std::cout << "best player(s):";
	for (int i = 0; i < playersglobalscore.size(); i++) {
		if (playersglobalscore[i] == tmp) {
			element_place = i;
			std::cout << "player" << element_place << " score: " << tmp << "; ";
		}
	}
};

void Score::MakeItZero() {
	player1gamepoints = 0;
	player2gamepoints = 0;
	player3gamepoints = 0;
};
