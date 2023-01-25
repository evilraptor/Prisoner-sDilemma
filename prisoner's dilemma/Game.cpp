#include "DilemmaHeader.h"

int Game(short game_type, int players_count, std::map<int, IStrategy*> players, int game_steps_number, int pay_off_matrix[8][6]) {
    Score score;
    std::vector<std::vector<char>> roundschoices(game_steps_number);//вектор векторов ходов 
    if (game_type == 3) {//это с турниром 
        int* players_of_this_rounde = new int[players_count];
        for (int i = 0; i < players_count; i++)players_of_this_rounde[i] = i + 1;
        int players_count_in_single_game = 3;
        //Print(a, m); 
        for (int i = 0; i < players_count_in_single_game; i++) std::cout << players_of_this_rounde[i] << " ";
        std::cout << "\n";
        //return 0;
        score = Simulator(pay_off_matrix, game_steps_number, game_type, players_of_this_rounde[0], players_of_this_rounde[1], players_of_this_rounde[2], score, roundschoices, players);
        if (players_count >= players_count_in_single_game)
        {
            while (PlayersOfNewRounde(players_of_this_rounde, players_count, players_count_in_single_game)) {
                for (int i = 0; i < players_count_in_single_game; i++) std::cout << players_of_this_rounde[i] << " ";
                std::cout << "\n";
                score = Simulator(pay_off_matrix, game_steps_number, game_type, players_of_this_rounde[0], players_of_this_rounde[1], players_of_this_rounde[2], score, roundschoices, players);
                //score.MakeItZero();
            }
        }
        score.ShowBestGlobalScore();
        //delete[] pay_off_matrix;
        return 0;
    }
    else if ((game_type == 1) || (game_type == 2)) {//ну и без 
        std::cout << "do something\n";
        score = Simulator(pay_off_matrix, game_steps_number, game_type, 0, 1, 2, score, roundschoices, players);
        score.ShowBestGlobalScore();
        return 0;
    }
};
