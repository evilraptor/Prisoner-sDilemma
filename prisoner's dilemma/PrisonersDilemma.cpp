// prisoner's dilemma.cpp 
#include "DilemmaHeader.h" 

int main(int argc, char* argv[])
{
    std::ifstream in;
    in.open("Matrix.txt"); // окрываем файл для чтения
    if (!in)
    {
        std::cerr << "Matrix.txt could not be opened" << std::endl;
        return -1;
    }

    int pay_off_matrix[8][6] = { 0 };
    int lines_in_matrix = 0;
    int counter = 0;
    //return 0;
    while (!in.eof())// пробегаем пока не встретим конец файла eof
    {
        short f = 0;
        char tmp;
        in >> tmp;//в пустоту считываем из файла числа
        int tmp2 = (int)tmp;
        if ((tmp != 'C') && (tmp != 'D'))//67C
            tmp2 = (int)tmp - 48;
        //int tmp2 = atoi(tmp);
        if (counter > 5) {
            counter = 0;
            //lines_in_matrix++;
            f = 1;
        }
        pay_off_matrix[lines_in_matrix][counter] = tmp2;
        if (f == 1) {
            f = 0;
            lines_in_matrix++;
        }
        counter++;
        //std::cout << temp;
        //count++;// увеличиваем счетчик числа чисел
    }
    //return 0;
    CheckMatrix(pay_off_matrix);
    in.close();


    StrategyFactory factory;
    //factory.add<StrategyRand>(1);
    //factory.add<StrategyAlwaysC>(2);
    //factory.add<StrategyAlwaysD>(3);
    //factory.add<StrategyWinRound>(4);
    //factory.add<StrategyTeamplay>(5);
    //factory.add<StrategyRevengeful>(6);
    int players_count = 0;
    short game_type = 0;
    typedef std::map<int, IStrategy*> Players;//1ое число номер игрока 2ое номер стратегии 
    Players players;//стратегии 
    int game_steps_number;
    //return 0;
    if (argc == 1) {
        std::cout << "choice players and game mode (D-detailed, F-fast, T-tournament, H-help, E-to exit)\n";
        while (game_type == 0) {
            //char tmp[256];
            std::string tmp;
            std::cin >> tmp;
            switch (tmp[0])
            {
            case 'H':
                std::cout << "available strategies:\n" << "StrategyRand, StrategyAlwaysC, StrategyAlwaysD, StrategyWinRound, StrategyTeamplay, StrategyRevengeful\n" << "also 1st u put players then gamemode\n";
                break;
            case 'D'://68 
                game_type = 1;
                break;
            case 'F'://70 
                game_type = 2;
                break;
            case 'T'://84 
                game_type = 3;
                break;
            case 'E'://69 
                return 0;
            default:
                short wrong_input_flag = 1;
                //int tmp2 = atoi(tmp);
                //typename Players::iterator it = players.find(players_count);
                //if (it == players.end()) {
                //    players[players_count] = factory.create(tmp2);

                //}
                bool strategy_existence_flag = factory.check(tmp/*2*/);
                if (strategy_existence_flag == false) {
                    std::cout << "there is no such strategy\n";
                }
                else {
                    players[players_count] = factory.create(tmp/*2*/);
                    //game_type = 0;
                    players_count++;
                    std::cout << "players count now: " << players_count << "\n";
                }
            }
        }
        std::cout << "steps count: ";
        std::cin >> game_steps_number;
        if ((players_count < 3) || ((players_count != 3) && ((game_type == 1) || (game_type == 2)))) {
            std::cout << "wrong players count";
            return -1;
        }
        if (game_steps_number < 1) {
            std::cout << "wrong steps count";
            return -1;
        }
         
        int f;
        f = Game(game_type, players_count, players, game_steps_number, pay_off_matrix);
        if (f == 0) return 0;
        else return -1;
    }
    else {
        for (int i = 1; i < argc - 1; i++) {
            //char tmp = *argv[i];
            std::string tmp = argv[i];
            //tmp = char(tmp);
            //std::cout << i;
            switch (tmp[0])
            {
            case 'H':
                std::cout << "available strategies:\n" << "StrategyRand, StrategyAlwaysC, StrategyAlwaysD, StrategyWinRound, StrategyTeamplay, StrategyRevengeful\n" << "also 1st u put players then gamemode\n";
                break;
            case 'D'://68 
                game_type = 1;
                break;
            case 'F'://70 
                game_type = 2;
                break;
            case 'T'://84 
                game_type = 3;
                break;
            case 'E'://69 
                return 0;
            default:
                short wrong_input_flag = 1;
                //int tmp2 = atoi(&tmp);
                //int tmp2 = tmp;
                bool strategy_existence_flag = factory.check(tmp/*2*/);
                if (strategy_existence_flag == false) {
                    std::cout << "there is no such strategy\n";
                }
                else {
                    players[players_count] = factory.create(tmp/*2*/);
                    //game_type = 0;
                    players_count++;
                    std::cout << "players count now: " << players_count << "\n";
                }
            }
        }
        game_steps_number = atoi(argv[argc - 1]);
        if ((players_count < 3) || ((players_count != 3) && ((game_type == 1) || (game_type == 2)))) {
            std::cout << "wrong players count";
            return -1;
        }
        if (game_steps_number < 1) {
            std::cout << "wrong steps count";
            return -1;
        }

        int f;
        f = Game(game_type, players_count, players, game_steps_number, pay_off_matrix);
        if (f == 0) return 0;
        else return -1;
    }
}
