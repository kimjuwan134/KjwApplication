#include <SFML/Graphics.hpp>

#include <time.h>
#include <iostream>

#define COL 16
#define ROW 16
#define BOMB_CNT 20

#define TILE_PIXCEL 16

#define BLANK 0
#define BOMB 9
#define BOOM 10
#define UNBLANK 11
#define FLAG 12
#define DONTKNOW 13

using namespace sf;
using namespace std;

int user_board[COL + 1][ROW + 1];
int board[COL + 1][ROW + 1];

int main()
{
    RenderWindow window(VideoMode(TILE_PIXCEL * COL, 600), "Minesweeper");

    srand(time(0));

    Texture img_tile;
    img_tile. loadFromFile("icon/tiles2.png");
    Sprite tile(img_tile);

    fill(&user_board[0][0], &user_board[COL][ROW + 1], UNBLANK);

    while (window.isOpen())
    {
        Event event;

        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case Event::Closed:
                    window.close();
                    break;
            default:
                    break;
            }
        }

        for (int i = 0; i < COL; i++)
        {
            for (int j = 0; j < ROW; j++)
            {
                tile.setTextureRect(IntRect(user_board[i][j] * TILE_PIXCEL, 0, TILE_PIXCEL, TILE_PIXCEL));
                tile.setPosition(i * TILE_PIXCEL, j * TILE_PIXCEL);
                window.draw(tile);
            }
        }
    }
    window.display();
}