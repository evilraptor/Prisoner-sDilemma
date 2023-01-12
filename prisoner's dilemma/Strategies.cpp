#include "DilemmaHeader.h" 

char IStrategy::GetChoise(short game_type, int p, std::vector<int> _score, std::vector<std::vector<char>> _roundes, std::vector<char> _roundechoises) { return 0; };
char Strategy1::GetChoise(short game_type, int p, std::vector<int> _score, std::vector<std::vector<char>> _roundes, std::vector<char> _roundechoises) {
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
char Strategy2::GetChoise(short game_type, int p, std::vector<int> _score, std::vector<std::vector<char>> _roundes, std::vector<char> _roundechoises) {
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
char Strategy3::GetChoise(short game_type, int p, std::vector<int> _score, std::vector<std::vector<char>> _roundes, std::vector<char> _roundechoises) {
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
char Strategy4::GetChoise(short game_type, int p, std::vector<int> _score, std::vector<std::vector<char>> _roundes, std::vector<char> _roundechoises) {
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

    if (game_type == 1) {
        std::cout << answer << " ";
        return answer;
    }
    else {
        return answer;
    }
};
char Strategy5::GetChoise(short game_type, int p, std::vector<int> _score, std::vector<std::vector<char>> _roundes, std::vector<char> _roundechoises) {
    char answer = 0;

    if ((counter < 12) && (game_type == -1)) {
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
        if (v0v1 == true)game_type = 1;
        else if (v0v2 == true)game_type = 2;
        else if (v1v2 == true)game_type = 3;
        else
            game_type = 0;
    }

    if ((game_type > 0) && (game_type != -1)) {
        if (game_type == 1) {
            if (p == 0) {
                if (_score[0] >= _score[1]) answer = 'D';
                else answer = 'C';
            }
            if (p == 1) {
                if (_score[0] > _score[1]) answer = 'C';
                else answer = 'D';
            }
        }
        else if (game_type == 2) {
            if (p == 0) {
                if (_score[0] >= _score[2]) answer = 'D';
                else answer = 'C';
            }
            if (p == 2) {
                if (_score[0] > _score[2]) answer = 'C';
                else answer = 'D';
            }
        }
        else if (game_type == 3) {
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
};
char Strategy6::GetChoise(short game_type, int p, std::vector<int> _score, std::vector<std::vector<char>> _roundes, std::vector<char> _roundechoises) {
    char answer = 0;
    if (((_roundechoises[0] == 'D') && (p != 0)) || ((_roundechoises[1] == 'D') && (p != 1)) || ((_roundechoises[2] == 'D') && (p != 2))) {
        int tmp = rand() / 3;
        if (tmp == 2)
            answer = 'C';
        else
            answer = 'D';
    }
    return answer;
};
