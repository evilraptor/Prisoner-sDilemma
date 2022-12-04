// prisoner's dilemma.cpp
#include "dilemma.h"

class IStrategy {
public:
	int score = 0;
	virtual char GetChoise(short f, int p, std::vector<int> _score, std::vector<std::vector<char>> _roundes, std::vector<char> _roundechoises) { return 0; }
	virtual char ShowChoise(short f) { return 0; }
	virtual void w1() {}
	virtual void w2() {}
	IStrategy(short f) {}
	IStrategy() { /*std::cout << "Strategy";*/ }
};

class Strategy1 :public IStrategy {
public:
	char GetChoise(short f, int p, std::vector<int> _score, std::vector<std::vector<char>> _roundes, std::vector<char> _roundechoises) override {
		char answer;
		srand(time(NULL));
		int tmp = rand() % 2;
		if (tmp == 0) {
			answer = 'C';
		}
		else
		{
			answer = 'D';
		}

		if (f == 1) {
			std::cout << answer<<" ";
			return	answer;
		}
		else {
			return	answer;
		}
	}
};
class Strategy2 :public IStrategy {
public:
	char GetChoise(short f, int p, std::vector<int> _score, std::vector<std::vector<char>> _roundes, std::vector<char> _roundechoises) override {
		char answer;
		answer = 'C';
		if (f == 1) {
			std::cout << answer << " ";
			return	answer;
		}
		else {
			return	answer;
		}
	}
};
class Strategy3 :public IStrategy {
public:
	char GetChoise(short f, int p, std::vector<int> _score, std::vector<std::vector<char>> _roundes, std::vector<char> _roundechoises) override {
		char answer;
		answer = 'D';
		if (f == 1) {
			std::cout << answer << " ";
			return	answer;
		}
		else {
			return	answer;
		}
	}
};

class Strategy4 :public IStrategy {
public:
	char GetChoise(short f, int p, std::vector<int> _score, std::vector<std::vector<char>> _roundes, std::vector<char> _roundechoises) override {
		int max = _score[0];
		if (max < _score[1])max = _score[1];
		if (max < _score[2])max = _score[2];
		int ownscore = _score[p];

		char answer;
		if (ownscore <= max)
			answer = 'D';
		else {
			Strategy1 strategy1;
			answer = strategy1.GetChoise(0, -1, _score, _roundes, _roundechoises);
		}
			
		if (f == 1) {
			std::cout << answer << " ";
			return	answer;
		}
		else {
			return	answer;
		}
	}
};

//CDCCCDDCDCDC	101110010101(4)(12)
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
	char GetChoise(short f, int p, std::vector<int> _score, std::vector<std::vector<char>> _roundes, std::vector<char> _roundechoises) override {
		char answer;

		if ((counter < 12)&&(f==-1)) {
			switch (counter)
			{
			case 0:
				answer = 'C';
			case 1:
				answer = 'D';
			case 2:
				answer = 'C';
			case 3:
				answer = 'C';
			case 4:
				answer = 'C';
			case 5:
				answer = 'D';
			case 6:
				answer = 'D';
			case 7:
				answer = 'C';
			case 8:
				answer = 'D';
			case 9:
				answer = 'C';
			case 10:
				answer = 'D';
			case 11:
				answer = 'C';
			}
		}
		else if((counter >= 12)&&(ff==-1)) {
			for (int i = 0; i < 12; i++) {
				std::vector<char> a = _roundes[i];
				acc0.push_back(a[0]);
				acc1.push_back(a[1]);
				acc2.push_back(a[2]);
			}
			v0v1 = (acc0 == acc1);
			v0v2 = (acc0 == acc2);
			v1v2 = (acc1 == acc2);
			if (v0v1 == true)f = 1;
			else if (v0v2 == true)f = 2;
			else if (v1v2 == true)f = 3;
			else
				f == 0;
		}

		if ((f > 0) && (f != -1)) {
			if (f == 1) {
				if (p == 0) {
					if (_score[0] >= _score[1]) answer = 'D';
					else answer = 'C';
				}
				if (p == 1) {
					if (_score[0] > _score[1]) answer = 'C';
					else answer = 'D';
				}
			}
			else if (f == 2) {
				if (p == 0) {
					if (_score[0] >= _score[2]) answer = 'D';
					else answer = 'C';
				}
				if (p == 2) {
					if (_score[0] > _score[2]) answer = 'C';
					else answer = 'D';
				}
			}
			else if (f == 3) {
				if (p == 1) {
					if (_score[1] >= _score[2]) answer = 'D';
					else answer = 'C';
				}
				if (p == 2) {
					if (_score[1] > _score[2]) answer = 'C';
					else answer = 'D';
				}
			}
		}
		else answer = 'D';


		counter++;
		return answer;
	}
};
class Strategy6 :public IStrategy {
public:
	char GetChoise(short f, int p, std::vector<int> _score, std::vector<std::vector<char>> _roundes, std::vector<char> _roundechoises) override {
		char answer;
		if (((_roundechoises[0] == 'D') && (p != 0)) || ((_roundechoises[1] == 'D') && (p != 1)) || ((_roundechoises[2] == 'D') && (p != 2))) {
			int tmp = rand() / 3;
			if (tmp == 2)
				answer = 'C';
			else
				answer = 'D';
		}
		return answer;
	}
};



////////////////////////////////////
class abstractFooCreator
{
public:
	//virtual fooCreator() {}
	virtual IStrategy* create() const = 0;
};

template <class C>
class fooCreator : public abstractFooCreator
{
public:
	virtual IStrategy* create() const { return new C(); }
};

class FooFactory
{
protected:
	typedef std::map<int, abstractFooCreator*> FactoryMap;
	FactoryMap _factory;

public:
	//FooFactory();
	//~virtual FooFactory();

	template <class C>
	void add(const int& id)
	{
		typename FactoryMap::iterator it = _factory.find(id);
		if (it == _factory.end())
			_factory[id] = new fooCreator<C>();
	}

	IStrategy* create(const int& id)
	{
		typename FactoryMap::iterator it = _factory.find(id);
		if (it != _factory.end())
			return it->second->create();
		return 0;
	}
};

////////////////////////////////////

class RoundResult {
public:
	char a, b, c;
	RoundResult(int achose, int bchose, int cchose) {
		//SetChoice(achose, bchose, cchose);
		//PrisonersPayoff1(&a, &b, &c);
	}
	RoundResult(std::vector<char> _roundechoises) {
		if (_roundechoises.size() == 3) {
			//std::cout << "a";
		}
		char a = _roundechoises[1];
		
	}
	RoundResult() {
		std::cin >> a >> b >> c;
		PrisonersPayoff1(&a, &b, &c);
		int at = a;//t-temp
		int bt = b;
		int ct = c;
	}

	void SetChoice(int achose, int bchose, int cchose) {
		a = achose;
		b = bchose;
		c = cchose;
	}
	void PrisonersPayoff1(char *a, char *b, char *c) {
		if ((*a == 'C') && (*b == 'C') && (*c == 'C')) { *a = 7; *b = 7; *c = 7; }
		else if ((*a == 'C') && (*b == 'C') && (*c == 'D')) { *a = 3; *b = 3; *c = 9; }
		else if ((*a == 'C') && (*b == 'D') && (*c == 'C')) { *a = 3; *b = 9; *c = 3; }
		else if ((*a == 'D') && (*b == 'C') && (*c == 'C')) { *a = 9; *b = 3; *c = 3; }
		else if ((*a == 'C') && (*b == 'D') && (*c == 'D')) { *a = 0; *b = 5; *c = 5; }
		else if ((*a == 'D') && (*b == 'C') && (*c == 'D')) { *a = 5; *b = 0; *c = 5; }
		else if ((*a == 'D') && (*b == 'D') && (*c == 'C')) { *a = 5; *b = 5; *c = 0; }
		else if ((*a == 'D') && (*b == 'D') && (*c == 'D')) { *a = 1; *b = 1; *c = 1; }
	};
	std::vector<int> GetScore() {
		//std::cout << "gained points: " << int(a) << " " << int(b) << " " << int(c) << "\n";
		std::vector<int> _score(3);
		_score = { a,b,c };
	}

};
class Score {
private:
	typedef std::map<int, int> Scores;//типа баллы, с неймингом то проблемы
	Scores _scores;
	int ascore, bscore, cscore;//типа (х2) игроки которые сейчас
public:
	Score() {
		ascore = 0;
		bscore = 0;
		cscore = 0;
	}
	void ChangeScore(int da, int pa, int db, int pb, int dc, int pc) {//d-delta	p-place
		ascore += da;
		bscore += db;
		cscore += dc;
		typename Scores::iterator it1 = _scores.find(pa);
		if (it1 == _scores.end())
			_scores[pa] = 0;
		typename Scores::iterator it2 = _scores.find(pb);
		if (it2 == _scores.end())
			_scores[pb] = 0;
		typename Scores::iterator it3 = _scores.find(pc);
		if (it3 == _scores.end())
			_scores[pc] = 0;
		_scores[pa] += ascore;
		_scores[pb] += bscore;
		_scores[pc] += cscore;
	};
	std::vector<int> GetScore() {
		//std::cout << "score now:" << ascore << " " << bscore << " " << cscore << "\n";
		std::vector<int> _score(3);
		_score = { ascore,bscore,cscore };
		return _score;
	};
	std::map<int, int> GetGlobalScore() {
		return _scores;
	}
	int GetBest() {
		int tmp = ascore;
		if (tmp < bscore)tmp = bscore;
		if (tmp < cscore)tmp = cscore;
		return tmp;
	}
	void MakeItZero() {
		ascore = 0;
		bscore = 0;
		cscore = 0;
	}
};

void simulator(int n,short f, int strategy1p, int strategy2p, int strategy3p, Score score, std::vector<int> _score, std::vector<std::vector<char>> _roundes,std::map<int, IStrategy*>_stratagies) {
	std::cin.get();
	for (int i = 0; i < n; i++) {
		std::vector<char>_roundechoises(3);
		for (int j = 0; j < 3; j++) {
			_roundechoises[j] = _stratagies[j]->GetChoise(f, _score[j], _score, _roundes, _roundechoises);
			_roundes[i].push_back(_roundechoises[j]);
		}
		if (f == 1) {
			std::cout << "\n";
		}
		//std::cout << "\ninput: ";

		char a, b, c;
		a = _roundechoises[0];
		b = _roundechoises[1];
		c = _roundechoises[2];

		RoundResult roundresult(_roundechoises);
		roundresult.SetChoice(a, b, c);
		//score.ChangeScore(roundresult.a, roundresult.b, roundresult.c);
		_score = score.GetScore();
		_roundes.push_back(_roundechoises);
		std::cout << "do something...\n";
		std::cin.get();
	}
	score.MakeItZero();
}

//из Н по М эл
bool next(int* a, int n, int m)
{
	int k = m;
	for (int i = k - 1; i >= 0; --i)
		if (a[i] < n - k + i + 1)
		{
			++a[i];
			for (int j = i + 1; j < k; ++j)
				a[j] = a[j - 1] + 1;
			return true;
		}
	return false;
}

//void Print(int* a, int n)
//{
//	static int num = 1;
//	std::cout.width(3);
//	std::cout << num++ << ": ";
//	for (int i = 0; i < n; i++)
//		std::cout << a[i] << " ";
//	std::cout << std::endl;
//}

int main()
{
	FooFactory factory;
	factory.add<Strategy1>(1);
	factory.add<Strategy2>(2);
	factory.add<Strategy3>(3);
	factory.add<Strategy4>(4);
	factory.add<Strategy5>(5);
	factory.add<Strategy6>(6);
	//IStrategy* strategy1 = factory.create(1);
	//IStrategy* strategy2 = factory.create(2);
	// 
	//std::cout << "Prisoner's dilemma.\ncount of players:";
	int playerscount = 0;
	//std::cout << "Prisoner's dilemma.\ncount of players:";
	//std::cin >> playerscount;
	short f = 0;
	typedef std::map<int, IStrategy*> stratagies;//1ое число номер игрока	2ое номер стратегии
	stratagies _stratagies;//стратегии
	std::cout << "choise players and game mode (D-detailed, F-fast, T-tournament, E-to exit)\n";
		while (f == 0) {
			//std::cout << "\nchoise player "<<i<<": ";
			char tmp[256];
			std::cin >> tmp;
			/*typename stratagies::iterator it = _stratagies.find(i);
			if (it == _stratagies.end())
				_stratagies[i] = factory.create(tmp);*/
				//char tmp2 = char(tmp);
			switch (tmp[0])
			{
			case 'D'://68
				f = 1;
				break;
			case 'F'://70
				f = 2;
				break;
			case 'T'://84
				f = 3;
				break;
			case 'E'://69
				return 0;
			default:
				int tmp2 = atoi(tmp);
				typename stratagies::iterator it = _stratagies.find(playerscount);
				if (it == _stratagies.end())
					_stratagies[playerscount] = factory.create(tmp2);
				f = 0;
				playerscount++;
				//стратегии идут в мапе от нуля
			}
		}
	std::cout << "steps count: ";
	int n;
	std::cin >> n;
	
	//std::cout << "директива с матрицей но ее пока нет";

	Score score;
	//typedef std::map<int, char> roundechoises;//1ое число номер игрока	2ое номер стратегии
	//roundechoises _roundechoises;
	std::vector<std::vector<char>> _roundes(n);//вектор векторов ходов
	std::vector<int> _score(3);

	if(f==3){//это с турниром
		int *a = new int[playerscount];
		for (int i = 0; i < playerscount; i++)
			a[i] = i;
		int m = 3;
		//Print(a, m);
		simulator(n, f, 0, 1, 2, score, _score, _roundes, _stratagies);
		if (playerscount >= m)
		{
			while (next(a, playerscount, m))
				//Print(a, m);
				simulator(n, f, a[0], a[1], a[2], score, _score, _roundes, _stratagies);
		}
		return 0;
	}
	else if((f == 1) || (f == 2)) {//ну и без
		simulator(n, f, 0, 1, 2, score, _score, _roundes, _stratagies);
		return 0;
	}

	return -1;
}

