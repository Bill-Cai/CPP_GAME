#include <iostream>
#include <graphics.h>
#include <conio.h>
#include "chess.hpp"

int main()
{

    Chess chess;
    int blockSize = chess.getBlockSize();
    initgraph(14 * blockSize, 14 * blockSize);
    while (1)
    {
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
    }
    _getch();
    closegraph();
    return 0;
}