#include <unistd.h>
#include "iostream"
#include "pthread.h"
#include <termio.h>
#include <stdlib.h>
using namespace std;
#define random() (rand() % x)

enum cell
{
    SPACE,
    SNAKE,
    STAR,
    BLOCK
};
enum direction
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Board
{
private:
    // int width;
    // int height;

public:
    int width;
    int height;
    string marker;
    direction head_direction;

    Board(int width, int height);
    void mark(int row, int col, cell c);
    void unmark(int row, int col);
    cell **mark_board;
    void print_line(int row, int head_x, int head_y);
    void print_board(int head_x, int head_y);
    void mark_block(int height, int width, cell **mark_board);
    // void head_marker(direction d);
};

struct Body
{
    Body *next;
    int x;
    int y;
    Body(int X, int Y)
    {
        this->x = X;
        this->y = Y;
    }
    /* data */
};

class Snake

{

public:
    Snake(int x, int y);
    Body *body;
    Body *head;
    Body *tail;
    Body *nextpose;

    int length;
    void get_nextpos(direction head_direction);
    Body mark_snake(cell **mark_board);

    void move();
    void grow(cell **mark_board);
    direction head_direction;
    void get_direction(direction d);
};

class Game
{
private:
    Body *star;

public:
    Game(int x, int y, int width, int height, int a, int b);
    Board *board;
    Snake *snake;
    direction head_direction;

    void get_order();
    void check_result();
    void mark_star(cell **mark_board);

    void set_food(int width, int height, cell **mark_board);
};