# CPP_GAME

本项目为 Cpp + EasyX 实现的五子棋人机对战应用。

在实现思路上参考了：[happysnaker/Gobang: 大一课设，一款AI五子棋项目，C++新手项目实践 — 智能人机五子棋对战。](https://github.com/happysnaker/Gobang)

但比该项目更加简洁，便于初学者学习。

## 项目运行

推荐使用 VSCode 作为项目的编程环境：

1. 参考 [EnvSetup.md](./docs/EnvSetup.md) 完成 VSCode 中 Cpp + EasyX 环境的配置。
2. 打开 `main.cpp` 文件，直接运行生成 `main.exe` 文件，即可运行该项目。

如果您喜欢使用命令行编译，则可以（以 Windows 系统为例）：

```bash
cd Gobang
# 直接使用 g++ 编译
g++ main.cpp -o main.exe -leasyx
# 运行程序
main.exe
```

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
