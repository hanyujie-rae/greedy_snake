#include <test.hpp>
using namespace std;

Board::Board(int w, int h)
{
    this->height = h;
    this->width = w;
    mark_board = new cell *[height];
    for (size_t i = 0; i < height; i++)
    {
        mark_board[i] = new cell[width];
        for (size_t j = 0; j < width; j++)
        {
            mark_board[i][j] = SPACE;
            /* code */
        }
        /* code */
    }
}

void Board::unmark(int col, int row)
{

    mark_board[col][row] = SPACE;
}

void Board::mark(int col, int row, cell c)
{
    mark_board[col][row] = c;
}
// void Board::head_marker(direction d)
// {

//     switch (d)
//     {

//     case UP:
//         marker = "^";
//         break;
//     case DOWN:
//         marker = "v";
//         break;
//     case LEFT:
//         marker = "<";
//         break;
//     case RIGHT:
//         marker = ">";
//         break;

//     default:
//         break;
//     }
// }
void Board::print_line(int row, int head_x, int head_y)
{
    for (size_t i = 0; i < width; i++)
    {
        cout << "|";

        if (mark_board[row][i] == SNAKE)
        {
            if (row == head_x && i == head_y)
            {

                cout << "o";
            }

            else
            {
                cout << "*";
            }
        }

        else if (mark_board[row][i] == STAR)
        {
            cout << "@";
        }
        else if (mark_board[row][i] == SPACE)
        {
            cout << " ";
        }
        else if (mark_board[row][i] == BLOCK)
        {
            cout << "#";
        }
    }
    cout << "|" << endl;
}
void Board::mark_block(int height, int width, cell **mark_board)
{
    int h;
    int w;
    h = height - 1;
    w = width - 1;
    for (size_t i = 0; i < width; i++)
    {
        mark_board[0][i] = BLOCK;
    }
    for (size_t i = 0; i < width; i++)
    {
        mark_board[h][i] = BLOCK;
    }

    for (size_t j = 0; j < height; j++)
    {
        mark_board[j][0] = BLOCK;

        // board->mark(0, 0, BLOCK);
    }
    for (size_t j = 0; j < height; j++)
    {
        mark_board[j][w] = BLOCK;
    }
}
void Board::print_board(int head_x, int head_y)
{
    for (size_t i = 0; i < height; i++)
    {
        print_line(i, head_x, head_y);
    }
    cout << endl;
};

Snake::Snake(int x, int y)
{
    head = new Body(x + 2, y);
    body = new Body(x + 1, y);
    tail = new Body(x, y);
    // nextpose = new Body(0, 0);
    tail->next = body;
    body->next = head;
    length = 3;
}
void Snake::get_direction(direction d)
{
    this->head_direction = d;
}
Body Snake::mark_snake(cell **mark_board)
{
    mark_board[head->x][head->y] = SNAKE;
    mark_board[body->x][body->y] = SNAKE;
    mark_board[tail->x][tail->y] = SNAKE;
}
void Snake::get_nextpos(direction d)
{
    // get_direction(direction d);
    switch (d)
    {
    case DOWN:
        this->nextpose = new Body(head->x + 1, head->y);
        // this->nextpose->x = head->x + 1;
        // this->nextpose->y = head->y;
        break;
    case UP:
        this->nextpose = new Body(head->x - 1, head->y);
        break;
    case LEFT:
        // cout << head->y << endl;
        this->nextpose = new Body(head->x, head->y - 1);
        // cout << head->y << endl;
        break;
    case RIGHT:
        this->nextpose = new Body(head->x, head->y + 1);
        break;
    default:
        cout << "unknown Input";
        break;
    }
    // head->x = next_x;
    // head->= next_y;
}
void Snake::move()

{
    // get_direction(head_direction);

    //     get_direction(direction );

    // mark_board[head->x][head->y] = SNAKE;

    Body *temp = tail;
    tail = tail->next;
    delete temp;

    head->next = nextpose;
    head = nextpose;
}

void Snake::grow(cell **mark_board)
{
    head->next = nextpose;
    head = nextpose;
    length = length++;
}
Game::Game(int x, int y, int width, int height, int a, int b)
{
    this->snake = new Snake(x, y);
    this->board = new Board(width, height);
    this->star = new Body(a, b);
}
void Game::get_order()
{
    string order;
    // order = "a";
    sleep(1);
    cin >> order;
    if (order == "w")

    {

        snake->get_nextpos(UP);
        // board->print_board();

        // board->print_board();

        // board->mark(snake->head->x, snake->head->y, SNAKE);
        // // board->print_board();
    }

    if (order == "s")
    {

        snake->get_nextpos(DOWN);

        // board->mark(snake->head->x, snake->head->y, SNAKE);
    }

    if (order == "a")
    {

        snake->get_nextpos(LEFT);
        // board->print_board();

        // board->print_board();

        // board->mark(snake->head->x, snake->head->y, SNAKE);
        // board->print_board();
    }

    if (order == "d")
    {

        snake->get_nextpos(RIGHT);

        // board->mark(snake->head->x, snake->head->y, SNAKE);
    }
    // board->unmark(snake->tail->x, snake->tail->y);
    // board->print_board();
    // snake->move();
    // cout << snake->head->x << " " << snake->head->y << endl;
    // cout << snake->body->x << " " << snake->body->y << endl;
    // cout << snake->tail->x << " " << snake->tail->y << endl;
}

void Game::check_result()
{
    if (board->mark_board[snake->nextpose->x][snake->nextpose->y] == SPACE)

    {
        board->unmark(snake->tail->x, snake->tail->y);
        snake->move();
    }
    if (board->mark_board[snake->nextpose->x][snake->nextpose->y] == SNAKE)
    {

        cout << "lose" << endl;
    }
    if (board->mark_board[snake->nextpose->x][snake->nextpose->y] == BLOCK)
    {

        cout << "lose" << endl;
    }
    if (board->mark_board[snake->nextpose->x][snake->nextpose->y] == STAR)
    {
        snake->grow(board->mark_board);

        set_food(board->width, board->height, board->mark_board);
        mark_star(board->mark_board);
        // board->print_board();

        // board->unmark(snake->tail->x, snake->tail->y);
    }
}
void Game::mark_star(cell **mark_board)
{
    mark_board[star->x][star->y] = STAR;
}

void Game::set_food(int width, int height, cell **mark_board)
{
    int w;
    int h;
    w = width - 2;
    h = height - 2;
    star->x = rand() % (w - 1) + 1;
    star->y = rand() % (h - 1) + 1;
    if (mark_board[star->x][star->y] == SNAKE)
    {
        set_food(board->width, board->height, board->mark_board);
    }
}