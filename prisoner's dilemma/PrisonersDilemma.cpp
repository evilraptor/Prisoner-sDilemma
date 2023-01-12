// prisoner's dilemma.cpp 
#include "DilemmaHeader.h" 

class AbstractCreator
{
public:
    //virtual fooCreator() {} 
    virtual IStrategy* create() const = 0;
    //virtual ~abstractFooCreator();
};

template <class C>
class StrategyCreator : public AbstractCreator
{
public:
    virtual IStrategy* create() const { return new C(); }
};

class StrategyFactory
{
protected:
    typedef std::map<int, AbstractCreator*> FactoryMap;
    FactoryMap _factory;

public: 
    //FooFactory(); 
    //~virtual FooFactory(); 

    template <class C>
    void add(const int& id)
    {
        typename FactoryMap::iterator it = _factory.find(id);
        if (it == _factory.end())
            _factory[id] = new StrategyCreator<C>();
    }

    IStrategy* create(const int& id)
    {
        typename FactoryMap::iterator it = _factory.find(id);
        if (it != _factory.end())
            return it->second->create();
        return 0;
    }
    ~StrategyFactory() {

    };
};
//////////////////////////////////// 
int main(int argc, char* argv[])
{
    StrategyFactory factory;
    factory.add<StrategyRand>(1);
    factory.add<StrategyAlwaysC>(2);
    factory.add<StrategyAlwaysD>(3);
    factory.add<StrategyWinRound>(4);
    factory.add<StrategyTeamplay>(5);
    factory.add<StrategyRevengeful>(6);
    int playerscount = 0;
    short game_type = 0;
    typedef std::map<int, IStrategy*> Players;//1ое число номер игрока 2ое номер стратегии 
    Players players;//стратегии 
    int game_steps_number;
    if (argc == 1) {
        std::cout << "choise players and game mode (D-detailed, F-fast, T-tournament, E-to exit)\n";
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
                int tmp2 = atoi(tmp);
                typename Players::iterator it = players.find(playerscount);
                if (it == players.end())
                    players[playerscount] = factory.create(tmp2);
                game_type = 0;
                playerscount++;
            }
        }
        std::cout << "steps count: ";
        std::cin >> game_steps_number;
    }
    else {
        for (int i = 1;i < argc - 1;i++) {
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
                int tmp2 = atoi(&tmp);
                //int tmp2 = tmp;
                typename Players::iterator it = players.find(playerscount);
                if (it == players.end())
                    players[playerscount] = factory.create(tmp2);
                game_type = 0;
                playerscount++;
            }
        }
        game_steps_number = atoi(argv[argc-1]);
        //}
        Score score;
        std::vector<std::vector<char>> roundschoises(game_steps_number);//вектор векторов ходов 
        if (game_type == 3) {//это с турниром 
            int* players_of_this_rounde = new int[playerscount];
            for (int i = 0; i < playerscount; i++)players_of_this_rounde[i] = i + 1;
            int players_count_in_single_game = 3;
            //Print(a, m); 
            for (int i = 0; i < players_count_in_single_game; i++) std::cout << players_of_this_rounde[i] << " ";
            std::cout << "\n";
            score = Simulator(game_steps_number, game_type, players_of_this_rounde[0], players_of_this_rounde[1], players_of_this_rounde[2], score, roundschoises, players);
            if (playerscount >= players_count_in_single_game)
            {
                while (PlayersOfNewRounde(players_of_this_rounde, playerscount, players_count_in_single_game)) {
                    for (int i = 0; i < players_count_in_single_game; i++) std::cout << players_of_this_rounde[i] << " ";
                    std::cout << "\n";
                    score = Simulator(game_steps_number, game_type, players_of_this_rounde[0], players_of_this_rounde[1], players_of_this_rounde[2], score, roundschoises, players);
                    //score.MakeItZero();
                }
            }
            score.ShowBestGlobalScore();
            return 0;
        }
        else if ((game_type == 1) || (game_type == 2)) {//ну и без 
            std::cout << "do something";
            score = Simulator(game_steps_number, game_type, 0, 1, 2, score, roundschoises, players);
            score.ShowBestGlobalScore();
            return 0;
        }
        return -1;
    }///////
}
