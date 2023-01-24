#include "DilemmaHeader.h" 

char IStrategy::Getchoice(short game_type, int p, std::vector<int> _score, std::vector<std::vector<char>> _roundes, std::vector<char> _roundechoices) { return 0; };
IStrategy::~IStrategy() {};
char StrategyRand::Getchoice(short game_type, int p, std::vector<int> _score, std::vector<std::vector<char>> _roundes, std::vector<char> _roundechoices) {
    char answer;
    srand(int(time(NULL)));
    int tmp = rand() % 2;
    if (tmp == 0) {
        answer = 'C';
    }
    else
    {
        answer = 'D';
    }

    if (game_type == 1) {
        std::cout << answer << " ";
        return answer;
    }
    else {
        return answer;
    }
};
char StrategyAlwaysC::Getchoice(short game_type, int p, std::vector<int> _score, std::vector<std::vector<char>> _roundes, std::vector<char> _roundechoices) {
    char answer;
    answer = 'C';
    if (game_type == 1) {
        std::cout << answer << " ";
        return answer;
    }
    else {
        return answer;
    }
};
char StrategyAlwaysD::Getchoice(short game_type, int p, std::vector<int> _score, std::vector<std::vector<char>> _roundes, std::vector<char> _roundechoices) {
    char answer;
    answer = 'D';
    if (game_type == 1) {
        std::cout << answer << " ";
        return answer;
    }
    else {
        return answer;
    }
};
char StrategyWinRound::Getchoice(short game_type, int p, std::vector<int> _score, std::vector<std::vector<char>> _roundes, std::vector<char> _roundechoices) {
    int max = 0;
    if ((max < _score[0]) && (p != 0))max = _score[0];;
    if ((max < _score[1]) && (p != 1))max = _score[1];
    if ((max < _score[2]) && (p != 2))max = _score[2];
    int ownscore = _score[p];

    char answer;
    if (ownscore <= max)
        answer = 'D';
    else {
        StrategyRand strategy1;
        answer = strategy1.Getchoice(0, -1, _score, _roundes, _roundechoices);
    }

    if (game_type == 1) {
        std::cout << answer << " ";
        return answer;
    }
    else {
        return answer;
    }
};
char StrategyTeamplay::Getchoice(short game_type, int p, std::vector<int> _score, std::vector<std::vector<char>> _roundes, std::vector<char> _roundechoices) {
    char answer = 0;
    int tmp = counter;
    if ((tmp < 12)/* && (game_type == -1)*/) {
        switch (tmp)
        {
        case 0:
            answer = 'C';
            break;
        case 1:
            answer = 'D';
            break;
        case 2:
            answer = 'C';
            break;
        case 3:
            answer = 'C';
            break;
        case 4:
            answer = 'C';
            break;
        case 5:
            answer = 'D';
            break;
        case 6:
            answer = 'D';
            break;
        case 7:
            answer = 'C';
            break;
        case 8:
            answer = 'D';
            break;
        case 9:
            answer = 'C';
            break;
        case 10:
            answer = 'D';
            break;
        case 11:
            answer = 'C';
            break;
        }
    }
    else if ((counter >= 12) && (ff == -1)) {
        for (int i = 0; i < 12; i++) {
            std::vector<char> a = _roundes[i];
            acc0.push_back(a[0]);
            acc1.push_back(a[1]);
            acc2.push_back(a[2]);
        }





        v0v1 = (acc0 == acc1);
        v0v2 = (acc0 == acc2);
        v1v2 = (acc1 == acc2);
        if (v0v1 == true)ff = 1;
        else if (v0v2 == true)ff = 2;
        else if (v1v2 == true)ff = 3;
        else
            ff = 0;
    }

    if ((ff > 0) && (ff != -1)) {
        if (ff == 1) {
            if (p == 0) {
                if (_score[0] >= _score[1]) answer = 'D';
                else answer = 'C';
            }
            if (p == 1) {
                if (_score[0] > _score[1]) answer = 'C';
                else answer = 'D';
            }
        }
        else if (ff == 2) {
            if (p == 0) {
                if (_score[0] >= _score[2]) answer = 'D';
                else answer = 'C';
            }
            if (p == 2) {
                if (_score[0] > _score[2]) answer = 'C';
                else answer = 'D';
            }
        }
        else if (ff == 3) {
            if (p == 1) {
                if (_score[1] >= _score[2]) answer = 'D';
                else answer = 'C';
            }
            if (p == 2) {
                if (_score[1] >= _score[2]) answer = 'C';
                else answer = 'D';
            }
        }
    }
    else if (ff == 0)answer = 'D';

    if (game_type==1)//||(game_type == 3))
    {
        std::cout<<answer<<" ";
    }
    counter++;
    return answer;
};
char StrategyRevengeful::Getchoice(short game_type, int p, std::vector<int> _score, std::vector<std::vector<char>> _roundes, std::vector<char> _roundechoices) {
    char answer = 0;
    if (((_roundechoices[0] == 'D') && (p != 0)) || ((_roundechoices[1] == 'D') && (p != 1)) || ((_roundechoices[2] == 'D') && (p != 2))) {
        int tmp = rand() % 3;
        if (tmp == 2)
            answer = 'C';
        else
            answer = 'D';
    }
    else
    {
        answer = 'C';
    }

    if (game_type == 1) //|| (game_type == 3))
    {
        std::cout << answer << " ";
    }
    return answer;
};
