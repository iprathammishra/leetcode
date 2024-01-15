// 22. **Langton's Ant:** An ant is sitting on an infinite grid of white and black sqaures. It initially faces right. At each step, it does the following:

// (1) At a white square, flip the color of the square, turn 90 degrees right (clockwise), and move forward one unit.
// (2) At a black square, flip the color of the square, turn 90 degrees left (counter-clockwise), and move forward one unit.

// Write a program to stimulate the first k moves that the ant makes and print the final board as grid. Note that you are not provided with the data structure to represent the grid. This is something you must design yourself. The only input to your method is K. You should print the final grid and return nothing. The method signature might be something like void printKMovies(int K).
#include <iostream>
#include <vector>

class LangtonsAnt
{
private:
    std::vector<std::vector<bool>> grid;
    int antX, antY, antDirection;
    // antDirection: 0: right, 1: down, 2: left, 3: up
public:
    LangtonsAnt(int size) : grid(size, std::vector<bool>(size, false)), antX(size / 2), antY(size / 2), antDirection(0) {}

    void printKMovies(int K)
    {
        for (int i = 0; i < K; ++i)
            move();
        printGrid();
    }

private:
    void move()
    {
        if (grid[antY][antX])                      // On a black sqaure
            antDirection = (antDirection + 3) % 4; // 90 Deg to left
        else
            antDirection = (antDirection + 1) % 4; // 90 Deg to right

        grid[antY][antX] = !grid[antY][antX];

        switch (antDirection)
        {
        case 0:
            antX++;
            break; // right
        case 1:
            antY++;
            break; // down
        case 2:
            antX--;
            break; // left
        case 3:
            antY--;
            break; // up}
        }
        adjustGridSize();
    }

    void adjustGridSize()
    {
        int size = grid.size();
        if (antX < 0 || antX >= size || antY < 0 || antY >= size)
        {
            int newSize = size * 2;
            grid.resize(newSize, std::vector<bool>(newSize, false));

            antX += newSize / 4;
            antY += newSize / 4;
        }
    }

    void printGrid() const
    {
        for (const auto &row : grid)
        {
            for (bool cell : row)
                std::cout << (cell ? '1' : '0'); // # for black and ' ' for white
            std::cout << std::endl;
        }
    }
};

int main()
{
    LangtonsAnt ant(11);
    ant.printKMovies(5);
    return 0;
}