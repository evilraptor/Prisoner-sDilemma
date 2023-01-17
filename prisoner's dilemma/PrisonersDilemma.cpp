// prisoner's dilemma.cpp 
#include "DilemmaHeader.h" 

//class AbstractCreator
//{
//public:
//    //virtual fooCreator() {} 
//    virtual IStrategy* create() const = 0;
//    //virtual ~abstractFooCreator();
//};
//
//template <class C>
//class StrategyCreator : public AbstractCreator
//{
//public:
//    virtual IStrategy* create() const { return new C(); }
//};
//
//class StrategyFactory
//{
//protected:
//    typedef std::map<int, AbstractCreator*> FactoryMap;
//    FactoryMap _factory;
//
//public:
//    //FooFactory(); 
//    //~virtual FooFactory(); 
//
//    template <class C>
//    void add(const int& id)
//    {
//        typename FactoryMap::iterator it = _factory.find(id);
//        if (it == _factory.end())
//            _factory[id] = new StrategyCreator<C>();
//    }
//
//    IStrategy* create(const int& id)
//    {
//        typename FactoryMap::iterator it = _factory.find(id);
//        if (it != _factory.end())
//            return it->second->create();
//        return 0;
//    }
//    ~StrategyFactory() {
//
//    };
//};
//////////////////////////////////// 
int main(int argc, char* argv[])
{
    //std::ifstream in;
    //in.open("Matrix.txt"); // окрываем файл для чтения
    ////std::ifstream inf{ "Matrix.txt" };
    ////if (!inf)
    ////{
    ////    std::cerr << "Matrix.txt could not be opened" << std::endl;
    ////    return -1;
    ////}
    //int pay_off_matrix[8][6] = { 0 };
    //int lines_in_matrix = 0;

    //while (in)
    //{
    //    //for (int i = 0; i < 2; i++) {
    //        for (int j1 = 0; j1 < 3; j1++) {
    //            //std::string strInput;
    //            char a;
    //            in >> a;
    //            std::cout << a;
    //            //inf >> strInput;
    //            //pay_off_matrix[lines_in_matrix][j1] = std::stoi(strInput);
    //            //std::cout << strInput << '\n';
    //        }
    //        for (int j2 = 0; j2 < 3; j2++) {
    //            std::string strInput;
    //            in >> strInput;
    //            //pay_off_matrix[lines_in_matrix][j2] = std::stoi(strInput);
    //            //std::cout << strInput<< '\n';
    //        }
    //        lines_in_matrix++;
    //    //}
    //    //std::string strInput;
    //    //inf >> strInput;
    //    //std::cout << strInput << '\n';
    //}




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
    if (argc == 1) {
        std::cout << "choice players and game mode (D-detailed, F-fast, T-tournament, E-to exit)\n";
        while (game_type == 0) {
            char tmp[256];
            std::cin >> tmp;
            switch (tmp[0])
            {
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
                int tmp2 = atoi(tmp);
                //typename Players::iterator it = players.find(players_count);
                //if (it == players.end()) {
                //    players[players_count] = factory.create(tmp2);

                //}
                bool strategy_existence_flag = factory.check(tmp2);
                if (strategy_existence_flag == false) {
                    std::cout << "there is no such strategy\n";
                }
                else {
                    players[players_count] = factory.create(tmp2);
                    //game_type = 0;
                    players_count++;
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

        Score score;
        std::vector<std::vector<char>> roundschoices(game_steps_number);//вектор векторов ходов 
        if (game_type == 3) {//это с турниром 
            int* players_of_this_rounde = new int[players_count];
            for (int i = 0; i < players_count; i++)players_of_this_rounde[i] = i + 1;
            int players_count_in_single_game = 3;
            //Print(a, m); 
            for (int i = 0; i < players_count_in_single_game; i++) std::cout << players_of_this_rounde[i] << " ";
            std::cout << "\n";
            score = Simulator(game_steps_number, game_type, players_of_this_rounde[0], players_of_this_rounde[1], players_of_this_rounde[2], score, roundschoices, players);
            if (players_count >= players_count_in_single_game)
            {
                while (PlayersOfNewRounde(players_of_this_rounde, players_count, players_count_in_single_game)) {
                    for (int i = 0; i < players_count_in_single_game; i++) std::cout << players_of_this_rounde[i] << " ";
                    std::cout << "\n";
                    score = Simulator(game_steps_number, game_type, players_of_this_rounde[0], players_of_this_rounde[1], players_of_this_rounde[2], score, roundschoices, players);
                    //score.MakeItZero();
                }
            }
            score.ShowBestGlobalScore();
            return 0;
        }
        else if ((game_type == 1) || (game_type == 2)) {//ну и без 
            std::cout << "do something\n";
            score = Simulator(game_steps_number, game_type, 0, 1, 2, score, roundschoices, players);
            score.ShowBestGlobalScore();
            return 0;
        }
        return -1;
    }
    else {
        for (int i = 1; i < argc - 1; i++) {
            char tmp = *argv[i];
            //tmp = char(tmp);
            //std::cout << i;
            switch (tmp)
            {
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
                int tmp2 = atoi(&tmp);
                //int tmp2 = tmp;
                bool strategy_existence_flag = factory.check(tmp2);
                if (strategy_existence_flag == false) {
                    std::cout << "there is no such strategy\n";
                }
                else {
                    players[players_count] = factory.create(tmp2);
                    //game_type = 0;
                    players_count++;
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
        //}
        Score score;
        std::vector<std::vector<char>> roundschoices(game_steps_number);//вектор векторов ходов 
        if (game_type == 3) {//это с турниром 
            int* players_of_this_rounde = new int[players_count];
            for (int i = 0; i < players_count; i++)players_of_this_rounde[i] = i + 1;
            int players_count_in_single_game = 3;
            //Print(a, m); 
            for (int i = 0; i < players_count_in_single_game; i++) std::cout << players_of_this_rounde[i] << " ";
            std::cout << "\n";
            score = Simulator(game_steps_number, game_type, players_of_this_rounde[0], players_of_this_rounde[1], players_of_this_rounde[2], score, roundschoices, players);
            if (players_count >= players_count_in_single_game)
            {
                while (PlayersOfNewRounde(players_of_this_rounde, players_count, players_count_in_single_game)) {
                    for (int i = 0; i < players_count_in_single_game; i++) std::cout << players_of_this_rounde[i] << " ";
                    std::cout << "\n";
                    score = Simulator(game_steps_number, game_type, players_of_this_rounde[0], players_of_this_rounde[1], players_of_this_rounde[2], score, roundschoices, players);
                    //score.MakeItZero();
                }
            }
            score.ShowBestGlobalScore();
            return 0;
        }
        else if ((game_type == 1) || (game_type == 2)) {//ну и без 
            std::cout << "do something\n";
            score = Simulator(game_steps_number, game_type, 0, 1, 2, score, roundschoices, players);
            score.ShowBestGlobalScore();
            return 0;
        }
        return -1;
    }
}
