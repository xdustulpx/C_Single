#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#define ROW 20 // 地图行数
#define COL 40 // 地图列数
#define SPEED 200 // 移动速度
struct Snake
{
    int x, y;
    struct Snake *next;
};
int map[ROW][COL]; // 地图
int score = 0; // 分数
int speed = SPEED; // 移动速度
int foodX, foodY; // 食物坐标
struct Snake *head, *tail; // 蛇头和蛇尾
void initMap();
void initSnake();
void drawMap();
void drawSnake();
void moveSnake();
void createFood();
void updateScore();
void gameOver();
int main()
{
    initMap();
    initSnake();
    drawMap();
    drawSnake();
    createFood();
    updateScore();
    while (1)
    {
        if (_kbhit())
        {
            char ch = _getch();
            if (ch == 27) // 按下 ESC 键，结束游戏
                break;
            else if (ch == 72 && head->x - 1 != tail->x) // 按下向上箭头键，向上移动
            {
                head->x--;
                moveSnake();
            }
            else if (ch == 80 && head->x + 1 != ROW - 1) // 按下向下箭头键，向下移动
            {
                head->x++;
                moveSnake();
            }
            else if (ch == 75 && head->y - 1 != tail->y) // 按下向左箭头键，向左移动
            {
                head->y--;
                moveSnake();
            }
            else if (ch == 77 && head->y + 1 != COL - 1) // 按下向右箭头键，向右移动
            {
                head->y++;
                moveSnake();
            }
        }
        else
        {
            moveSnake();
        }
        Sleep(speed); // 延迟一段时间，控制移动速度
    }
    return 0;
}
void initMap()
{
    int i, j;
    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            if (i == 0 || i == ROW - 1 || j == 0 || j == COL - 1)
                map[i][j] = -1; // 设置地图边界
            else
                map[i][j] = 0;
        }
    }
}
void initSnake()
{
    int x = ROW / 2, y = COL / 2;
    struct Snake *node = (struct Snake *)malloc(sizeof(struct Snake));
    node->x = x;
    node->y = y;
    node->next = NULL;
    head = node;
    tail = node;
    map[x][y] = 2;
}
void drawMap()
{
    int i, j;
    system("cls"); // 清屏
    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            if (map[i][j] == -1)
                printf("#"); // 绘制边界
            else if (map[i][j] == 0)
                printf(" "); // 绘制空白
            else if (map[i][j] == 1)
                printf("#"); // 绘制食物
        }
        printf("\n"); // 换行
    }
}
void drawSnake()
{
    struct Snake *p = head;
    while (p)
    {
        gotoxy(p->x, p->y);
        printf("*"); // 绘制蛇身
        p = p->next;
    }
}
void moveSnake()
{
    int x = head->x, y = head->y;
    if (map[x][y] == -1 || map[x][y] == 2) // 撞墙或者撞到自己，游戏结束
        gameOver();
    if (map[x][y] == 1) // 吃到食物，蛇变长
    {
        struct Snake *node = (struct Snake *)malloc(sizeof(struct Snake));
        node->x = foodX;
        node->y = foodY;
        node->next = NULL;
        tail->next = node;
        tail = node;
        map[foodX][foodY] = 2;
        createFood(); // 生成新的食物
        score += 10; // 分数加10
        if (score %!!(MISSING) (MISSING)== 0) // 每吃到50个食物，速度加快
            speed -= 20;
    }
    else
    {
        struct Snake *node = head;
        head = head->next;
        map[node->x][node->y] = 0;
        gotoxy(node->x, node->y);
        printf(" ");
        free(node);
    }
    map[x][y] = 2;
    gotoxy(x, y);
    printf("*");
}
void createFood()
{
    int i, j;
    do
    {
        srand((unsigned)time(NULL));
        foodX = rand() %!!(MISSING)((MISSING)ROW - 2) + 1;
        foodY = rand() %!!(MISSING)((MISSING)COL - 2) + 1;
    } while (map[foodX][foodY] != 0);
    map[foodX][foodY] = 1;
    gotoxy(foodX, foodY);
    printf("#");
}
void updateScore()
{
    gotoxy(ROW + 1, 0);
    printf("Score: %!!(MISSING)d(MISSING)", score);
}
void gameOver()
{
    system("cls");
    printf("Game Over!\n");
    printf("Your Score: %!!(MISSING)d(MISSING)\n", score);
    exit(0);
}
/*
这份代码使用了Windows API中的一些函数，包括 gotoxy()、SetConsoleCursorPosition()和 GetStdHandle()。
在这个程序中，我们使用了链表来存储蛇的身体。程序的基本思路是：绘制地图 -> 初始化蛇 -> 随机生成食物 -> 移动蛇 -> 
判断是否撞墙、撞到自己、吃到食物 -> 生成新的食物 -> 更新分数 -> 延迟一段时间 -> 接收键盘输入。如果按下 ESC 键，程序结束。
这份代码并不是最优的，它可能有一些问题需要改进。但是，它可以帮助初学者快速理解贪吃蛇的实现原理，
以及如何在Windows命令行绘制图案和操作光标。
*/