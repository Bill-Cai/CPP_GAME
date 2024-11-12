# CPP_GAME

本项目为 Cpp + EasyX 实现的五子棋人机对战应用。

在实现思路上参考了：[happysnaker/Gobang: 大一课设，一款AI五子棋项目，C++新手项目实践 — 智能人机五子棋对战。](https://github.com/happysnaker/Gobang)

## 代码解析

核心代码主要包含三个类：

1. `main.cpp`：游戏的主进程文件，通过一个 `while` 循环控制游戏进程。
2. `chess.hpp`：五子棋类，控制五子棋的状态和操作，以及 UI 界面绘制。
3. `ai.hpp`：AI类，通过 [评分法](https://blog.csdn.net/weixin_44342683/article/details/105586098) / 五元组法 实现的五子棋AI。

## Note

可以优化的方面

1. 界面交互：增加落子位置提示（考虑怎么刷新位置指示）等。
2. AI算法：可以采用博弈树策略，并比较哪种算法的效果更好。
3. 代码结构：优化代码OOP的编写风格，使其更优美。
