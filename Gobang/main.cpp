#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <vector>
#include "chess.hpp"
#include "ai.hpp"

int main()
{

    Chess chess;
    AI4Gobang ai;
    int blockSize = chess.getBlockSize();
    initgraph(14 * blockSize, 14 * blockSize);
    while (1)
    {
        if (CLI_PRINT)
            chess.printChessboard();
        chess.drawChessboard();
        if (chess.check())
            break;
        int playerFlag = chess.getPlayerFlag();
        if (playerFlag == 1)
        {
            while (1)
            {
                ExMessage msg = getmessage(EX_MOUSE);
                if (msg.message == WM_LBUTTONDOWN)
                {
                    int x, y;
                    x = chess.coord2mat(msg.x);
                    y = chess.coord2mat(msg.y);
                    chess.move(x, y);
                    break;
                }
            }
        }
        else
        {
            std::vector<int> ai_mov_xy = ai.move(chess.getMat(), playerFlag);
            chess.move(ai_mov_xy[0], ai_mov_xy[1]);
        }
    }
    _getch();
    closegraph();
    return 0;
}