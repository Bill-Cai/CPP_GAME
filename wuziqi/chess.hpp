#ifndef CHESS_HPP
#define CHESS_HPP

#include <iostream>

const int CHESSBOARD_SCALE = 13;
const int BLACK_CHESS = 1;
const int WHITE_CHESS = -1;

class Chess
{
private:
    int mat[CHESSBOARD_SCALE][CHESSBOARD_SCALE];
    int playerFlag = BLACK_CHESS;

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
    void printChessboard()
    {
        for (int j = 0; j < CHESSBOARD_SCALE; j++)
        {
            for (int i = 0; i < CHESSBOARD_SCALE; i++)
            {
                switch (mat[i][j])
                {
                case BLACK_CHESS:
                    std::cout << "x ";
                    break;
                case WHITE_CHESS:
                    std::cout << "o ";
                    break;
                default:
                    std::cout << ". ";
                    break;
                }
            }
            std::cout << std::endl;
        }
    }
    void move(int x, int y)
    {
        if (mat[x][y] == 0)
        {
            if (playerFlag == 1)
                mat[x][y] = BLACK_CHESS;
            else
                mat[x][y] = WHITE_CHESS;
            playerFlag *= -1;
        }
        else
            return;
    }
    int showPlayerFlag()
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
                if (i + 4 < CHESSBOARD_SCALE && mat[i][j] == mat[i + 1][j] && mat[i][j] == mat[i + 2][j] && mat[i][j] == mat[i + 3][j] && mat[i][j] == mat[i + 4][j])
                {
                    std::cout << "Player " << mat[i][j] << " wins!" << std::endl;
                    return true;
                }
                if (j + 4 < CHESSBOARD_SCALE && mat[i][j] == mat[i][j + 1] && mat[i][j] == mat[i][j + 2] && mat[i][j] == mat[i][j + 3] && mat[i][j] == mat[i][j + 4])
                {
                    std::cout << "Player " << mat[i][j] << " wins!" << std::endl;
                    return true;
                }
                if (i + 4 < CHESSBOARD_SCALE && j + 4 < CHESSBOARD_SCALE && mat[i][j] == mat[i + 1][j + 1] && mat[i][j] == mat[i + 2][j + 2] && mat[i][j] == mat[i + 3][j + 3] && mat[i][j] == mat[i + 4][j + 4])
                {
                    std::cout << "Player " << mat[i][j] << " wins!" << std::endl;
                    return true;
                }
                if (i + 4 < CHESSBOARD_SCALE && j - 4 >= 0 && mat[i][j] == mat[i + 1][j - 1] && mat[i][j] == mat[i + 2][j - 2] && mat[i][j] == mat[i + 3][j - 3] && mat[i][j] == mat[i + 4][j - 4])
                {
                    std::cout << "Player " << mat[i][j] << " wins!" << std::endl;
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
        std::cout << "Draw!" << std::endl;
        return true;
    }
};

#endif