
#include <test.hpp>
using namespace std;
int main()

{
    // Board board(7, 8);
    // Snake snake(4, 6);
    Game game(4, 5, 10, 11, 3, 2);

    game.snake->mark_snake(game.board->mark_board);
    game.mark_star(game.board->mark_board);
    game.board->mark_block(11, 10, game.board->mark_board);

    game.board->print_board(game.snake->head->x, game.snake->head->y);

    while (true)
    {

        game.get_order();
        game.check_result();
        game.board->mark(game.snake->head->x, game.snake->head->y, SNAKE);

        game.board->print_board(game.snake->head->x, game.snake->head->y);
    }
}
