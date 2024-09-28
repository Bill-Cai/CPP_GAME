#ifndef CHESS_HPP
#define CHESS_HPP

#include <iostream>
#include <vector>

#define CLI_PRINT 1
const int CHESSBOARD_SCALE = 13;
const int BLACK_CHESS = 1;
const int WHITE_CHESS = -1;

class Chess
{
private:
    int mat[CHESSBOARD_SCALE][CHESSBOARD_SCALE];
    int playerFlag = BLACK_CHESS;
    float blockSize = 50;

public:
    Chess()
    {
        for (int i = 0; i < CHESSBOARD_SCALE; i++)
        {
            for (int j = 0; j < CHESSBOARD_SCALE; j++)
            {
                mat[i][j] = 0;
            }
        }
    }
    std::vector<std::vector<int>> getMat()
    {
        std::vector<std::vector<int>> m(CHESSBOARD_SCALE, std::vector<int>(CHESSBOARD_SCALE));
        for (int i = 0; i < CHESSBOARD_SCALE; i++)
        {
            for (int j = 0; j < CHESSBOARD_SCALE; j++)
            {
                m[i][j] = mat[i][j];
            }
        }
        return m;
    }
    float getBlockSize()
    {
        return blockSize;
    }
    void printChessboard()
    {
        for (int j = 0; j < CHESSBOARD_SCALE; j++)
        {
            for (int i = 0; i < CHESSBOARD_SCALE; i++)
            {
                switch (mat[i][j])
                {
                case BLACK_CHESS:
                    if (CLI_PRINT)
                        std::cout << "x ";
                    break;
                case WHITE_CHESS:
                    if (CLI_PRINT)
                        std::cout << "o ";
                    break;
                default:
                    if (CLI_PRINT)
                        std::cout << ". ";
                    break;
                }
            }
            if (CLI_PRINT)
                std::cout << std::endl;
        }
    }
    void drawChessboard()
    {
        // 13*13的棋盘，中间有5个点位标识
        setbkcolor(LIGHTGRAY);
        cleardevice();
        setlinecolor(BLACK);
        for (int i = 0; i <= CHESSBOARD_SCALE; i++)
        {
            line(blockSize, blockSize * (i + 1), blockSize * 13, blockSize * (i + 1));
            line(blockSize * (i + 1), blockSize, blockSize * (i + 1), blockSize * 13);
        }
        // 画5个点位
        setfillcolor(BLACK);
        fillcircle(blockSize * 4, blockSize * 4, 5);
        fillcircle(blockSize * 4, blockSize * 10, 5);
        fillcircle(blockSize * 10, blockSize * 4, 5);
        fillcircle(blockSize * 10, blockSize * 10, 5);
        fillcircle(blockSize * 7, blockSize * 7, 5);

        for (int j = 0; j < CHESSBOARD_SCALE; j++)
        {
            for (int i = 0; i < CHESSBOARD_SCALE; i++)
            {
                switch (mat[i][j])
                {
                case BLACK_CHESS:
                    setfillcolor(BLACK);
                    fillcircle(blockSize * i, blockSize * j, blockSize / 2.3);
                    break;
                case WHITE_CHESS:
                    setfillcolor(WHITE);
                    fillcircle(blockSize * i, blockSize * j, blockSize / 2.3);
                    break;
                default:
                    break;
                }
            }
            if (CLI_PRINT)
                std::cout << std::endl;
        }
    }
    void move(int mx, int my)
    {
        if (mat[mx][my] == 0)
        {
            if (playerFlag == 1)
                mat[mx][my] = BLACK_CHESS;
            else
                mat[mx][my] = WHITE_CHESS;
            playerFlag *= -1;
        }
        else
            return;
    }
    int coord2mat(int x)
    {
        int k = x / blockSize;
        if (x > (k + 0.5) * blockSize)
        {
            return k + 1;
        }
        else
        {
            return k;
        }
    }
    int getPlayerFlag()
    {
        return playerFlag;
    }
    bool check()
    {
        // 检查是否有五子连珠
        for (int i = 0; i < CHESSBOARD_SCALE; i++)
        {
            for (int j = 0; j < CHESSBOARD_SCALE; j++)
            {
                if (mat[i][j] == 0)
                    continue;
                if ((i + 4 < CHESSBOARD_SCALE && mat[i][j] == mat[i + 1][j] && mat[i][j] == mat[i + 2][j] && mat[i][j] == mat[i + 3][j] && mat[i][j] == mat[i + 4][j]) || (j + 4 < CHESSBOARD_SCALE && mat[i][j] == mat[i][j + 1] && mat[i][j] == mat[i][j + 2] && mat[i][j] == mat[i][j + 3] && mat[i][j] == mat[i][j + 4]) || (i + 4 < CHESSBOARD_SCALE && j + 4 < CHESSBOARD_SCALE && mat[i][j] == mat[i + 1][j + 1] && mat[i][j] == mat[i + 2][j + 2] && mat[i][j] == mat[i + 3][j + 3] && mat[i][j] == mat[i + 4][j + 4]) || (i + 4 < CHESSBOARD_SCALE && j - 4 >= 0 && mat[i][j] == mat[i + 1][j - 1] && mat[i][j] == mat[i + 2][j - 2] && mat[i][j] == mat[i + 3][j - 3] && mat[i][j] == mat[i + 4][j - 4]))
                {
                    if (CLI_PRINT)
                        std::cout << "Player " << mat[i][j] << " wins!" << std::endl;
                    if (mat[i][j] == 1)
                    {
                        TCHAR s[] = _T("Black player wins!");
                        settextcolor(RED);
                        outtextxy(5, 5, s);
                    }
                    else
                    {
                        TCHAR s[] = _T("White player wins!");
                        settextcolor(RED);
                        outtextxy(5, 5, s);
                    }
                    return true;
                }
            }
        }
        // 检查棋局是否继续
        for (int i = 0; i < CHESSBOARD_SCALE; i++)
        {
            for (int j = 0; j < CHESSBOARD_SCALE; j++)
            {
                if (mat[i][j] == 0)
                    return false;
            }
        }
        if (CLI_PRINT)
            std::cout << "Draw!" << std::endl;
        TCHAR s[] = _T("Draw!");
        settextcolor(RED);
        outtextxy(5, 5, s);
        return true;
    }
};

#endif