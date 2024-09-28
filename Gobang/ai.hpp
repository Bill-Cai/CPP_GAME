#ifndef AI_HPP
#define AI_HPP

#include <vector>

class AI4Gobang
{
private:
public:
    std::vector<int> move(std::vector<std::vector<int>> mat, int playerFlag)
    {
        std::vector<int> move_xy;

        // AI算法

        std::vector<std::vector<int>> score;
        for (int i = 0; i < mat.size(); i++)
        {
            std::vector<int> row;
            for (int j = 0; j < mat[i].size(); j++)
            {
                row.push_back(0);
            }
            score.push_back(row);
        }
        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[i].size(); j++)
            {
                // 可以落点
                if (mat[i][j] == 0)
                {
                    move_xy.push_back(i);
                    move_xy.push_back(j);
                    for (int k = 0; k < 5; k++)
                    {
                        // (i,j-k) ~ (i,j+4-k)
                        if (j - k >= 0 && j + 4 - k < mat.size())
                        {
                            std::vector<int> v;
                            for (int _ = 0; _ < 5; _++)
                                v.push_back(mat[i][j - k + _]);
                            score[i][j] += eval(v, playerFlag);
                        }
                        // (i-k,j) ~ (i+4-k,j)
                        if (i - k >= 0 && i + 4 - k < mat.size())
                        {
                            std::vector<int> v;
                            for (int _ = 0; _ < 5; _++)
                                v.push_back(mat[i - k + _][j]);
                            score[i][j] += eval(v, playerFlag);
                        }
                        // (i-k,j-k) ~ (i+4-k,j+4-k)
                        if (i - k >= 0 && j - k >= 0 && i + 4 - k < mat.size() && j + 4 - k < mat.size())
                        {
                            std::vector<int> v;
                            for (int _ = 0; _ < 5; _++)
                                v.push_back(mat[i - k + _][j - k + _]);
                            score[i][j] += eval(v, playerFlag);
                        }
                        // (i-k,j-k) ~ (i+4-k,j-4+k)
                        if (i - k >= 0 && j + k >= 0 && i + 4 - k < mat.size() && j - 4 + k < mat.size())
                        {
                            std::vector<int> v;
                            for (int _ = 0; _ < 5; _++)
                                v.push_back(mat[i - k + _][j + k - _]);
                            score[i][j] += eval(v, playerFlag);
                        }
                    }
                }
            }
        }
        for (int i = 0; i < score.size(); i++)
        {
            for (int j = 0; j < score[i].size(); j++)
            {
                if (score[i][j] > score[move_xy[0]][move_xy[1]])
                {
                    move_xy[0] = i;
                    move_xy[1] = j;
                }
            }
        }
        return move_xy;
    }
    int eval(std::vector<int> v, int playerFlag)
    {
        int g = 0, b = 0;
        for (int k = 0; k < v.size(); k++)
        {
            if (v[k] == playerFlag)
                g++;
            else if (v[k] == -playerFlag)
                b++;
        }
        if (g == 0 && b == 0)
            return 10;
        else if (g == 1 && b == 0)
            return 35;
        else if (g == 2 && b == 0)
            return 1500;
        else if (g == 3 && b == 0)
            return 18000;
        else if (g == 4 && b == 0)
            return 1000000;
        else if (g == 0 && b == 1)
            return 15;
        else if (g == 0 && b == 2)
            return 400;
        else if (g == 0 && b == 3)
            return 6000;
        else if (g == 0 && b == 4)
            return 150000;
        else if (g != 0 && b != 0)
            return 0;
        return 0;
    }
};

#endif