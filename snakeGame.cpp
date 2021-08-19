#include <iostream>
#include <conio.h>
using namespace std;

bool gameOver;
const int width = 25;
const int height = 20;
int x, y;
int fruitX, fruitY;
int score;
enum edirection
{
  STOP,
  RIGHT,
  LEFT,
  UP,
  DOWN
};
edirection dir;
void setup()
{
  gameOver = false;
  x = width / 2;
  y = height / 2;
  fruitX = 1 + rand() % width;
  fruitY = 1 + rand() % height;
  score = 0;
}

void Draw()
{
  system("cls");
  for (int i = 0; i < height; i++)
  {
    if (i == 0 || i == height - 1)
    {
      for (int j = 0; j < width; j++)
        cout << "#";
    }
    else
    {
      for (int j = 0; j < width; j++)
        if (j == 0 || j == width - 1)
          cout << "#";
        else if (x == j && y == i)
          cout << "o";
        else if (fruitX == j && fruitY == i)
          cout << "F";
        else
          cout << " ";
    }
    cout << endl;
  }
  cout << "Score: " << score << endl;
}

void input()
{
  if (_kbhit())
  {
    switch (_getch())
    {
    case 'a':
      dir = LEFT;
      break;

    case 'd':
      dir = RIGHT;
      break;

    case 's':
      dir = DOWN;
      break;

    case 'w':
      dir = UP;
      break;
    case 'x':
      gameOver = true;
      break;
    }
  }
}

void logic()
{
  if (x == fruitX && y == fruitY)
  {
    fruitX = 1 + rand() % width;
    fruitY = 1 + rand() % height;
    score += 10;
  }
  switch (dir)
  {
  // case 0:
  //   gameOver = true;
  //   break;
  case 1:
    x++;
    break;
  case 2:
    x--;
    break;
  case 3:
    y--;
    break;
  case 4:
    y++;
    break;
  }
  if (x == 0 || x == width - 1 || y == 0 || y == height - 1)
  {
    gameOver = true;
    printf("GAME OVER!");
  }
}

int main()
{
  setup();
  while (!gameOver)
  {
    Draw();
    input();
    logic();
  }

  return 0;
}
