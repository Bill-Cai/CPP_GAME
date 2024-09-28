#include <iostream>
#include "chess.hpp"

int main()
{

    Chess chess;
    while (1)
    {
        chess.printChessboard();
        if (chess.check())
            break;
        int playerFlag = chess.showPlayerFlag();
        if (playerFlag == 1)
        {
            std::cout << "[BLACK]" << " Please enter the position of the next move: ";
            int x, y;
            std::cin >> x >> y;
            chess.move(x, y);
        }
        else
        {
            std::cout << "[WHITE]" << " Please enter the position of the next move: ";
            int x, y;
            std::cin >> x >> y;
            chess.move(x, y);
        }
    }
    return 0;
}