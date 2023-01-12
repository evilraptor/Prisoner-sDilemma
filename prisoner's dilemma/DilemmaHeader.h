#pragma once 
#include <iostream> 
#include <sstream> 
#include <string> 
#include <iomanip> 
#include <ctime> 
#include <map> 
#include <vector> 

class IStrategy {
public:
	//int score = 0; 
	virtual char GetChoise(short f, int p, std::vector<int> _score, std::vector<std::vector<char>> _roundes, std::vector<char> _roundechoises);
	virtual ~IStrategy();
};
class Strategy1 :public IStrategy {
public:
	char GetChoise(short f, int p, std::vector<int> _score, std::vector<std::vector<char>> _roundes, std::vector<char> _roundechoises) override;
};
class Strategy2 :public IStrategy {
public:
	char GetChoise(short f, int p, std::vector<int> _score, std::vector<std::vector<char>> _roundes, std::vector<char> _roundechoises) override;
};
class Strategy3 :public IStrategy {
public:
	char GetChoise(short f, int p, std::vector<int> _score, std::vector<std::vector<char>> _roundes, std::vector<char> _roundechoises) override;
};
class Strategy4 :public IStrategy {
public:
	char GetChoise(short f, int p, std::vector<int> _score, std::vector<std::vector<char>> _roundes, std::vector<char> _roundechoises) override;
};
class Strategy5 :public IStrategy {
private:
	int counter = 0;
	int ff = -1;
	int fp = 0;
	std::vector<char> acc0;
	std::vector<char> acc1;
	std::vector<char> acc2;
	bool v0v1 = 0;
	bool v0v2 = 0;
	bool v1v2 = 0;
public:
	char GetChoise(short f, int p, std::vector<int> _score, std::vector<std::vector<char>> _roundes, std::vector<char> _roundechoises) override;
};
class Strategy6 :public IStrategy {
public:
	char GetChoise(short f, int p, std::vector<int> _score, std::vector<std::vector<char>> _roundes, std::vector<char> _roundechoises) override;
};


class Score {
protected:
	typedef std::map<int, int> Playersglobalscore;//типа баллы, с неймингом то проблемы 
	Playersglobalscore playersglobalscore;
	int player1gamepoints = 0, player2gamepoints = 0, player3gamepoints = 0;//типа (х2) игроки которые сейчас 
public:
	//Score(); 
	//void ChangeScore(int, int, int, int, int, int);
	void ShowGameScore(int, int, int, int);
	std::vector<int> GetRoundScore(int, int, int);
	/*std::vector<int>*/void ShowGlobalScore();
	void ShowBestGlobalScore();
	void MakeItZero();
	void ChangeRoundScore(int, int, int);
	void ChangeGlobalScore(int, int, int);
	//void ShowGlobalScore();
};

class RoundResult {
public:
	int player1_pay_off = 0, player2_pay_off = 0, player3_pay_off = 0;
	char player1_choise = 0, player2_choise = 0, player3_choise = 0;
	RoundResult(int, int, int);
	RoundResult(std::vector<char>);
	RoundResult();

	void SetChoice(int, int, int);
	void SetPrisonersPayoff();
	std::vector<int> GetScore();
};
bool PlayersOfNewRounde(int*, int, int);

Score Simulator(int, short, int, int, int, Score, std::vector<std::vector<char>>, std::map<int, IStrategy*>);
