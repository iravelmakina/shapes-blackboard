#include "BresenhamAlgorithm.h"

#include <iostream>


namespace BresenhamAlgorithm {
    void drawLine(std::vector<std::vector<char> > &grid, int x1, int y1, const int x2, const int y2) {
        const int dx = abs(x2 - x1);
        const int dy = abs(y2 - y1);
        const int sx = (x1 < x2) ? 1 : -1;
        const int sy = (y1 < y2) ? 1 : -1;
        int err = dx - dy;

        while (true) {
            if (x1 >= 0 && x1 < grid[0].size() && y1 >= 0 && y1 < grid.size()) {
                grid[y1][x1] = '*';
            }

            if (x1 == x2 && y1 == y2) break;

            const int e2 = 2 * err;
            if (e2 > -dy) {
                err -= dy;
                x1 += sx;
            }
            if (e2 < dx) {
                err += dx;
                y1 += sy;
            }
        }
    }


    void drawCircle(std::vector<std::vector<char> > &grid, const int xCenter, const int yCenter, const int radius) {
        int x = 0;
        int y = radius;
        int d = 3 - 2 * radius;

        plotCirclePoints(grid, xCenter, yCenter, x, y);

        while (x <= y) {
            x++;
            if (d > 0) {
                y--;
                d = d + 4 * (x - y) + 10;
            } else {
                d = d + 4 * x + 6;
            }
            plotCirclePoints(grid, xCenter, yCenter, x, y);
        }
    }


    void plotCirclePoints(std::vector<std::vector<char> > &grid, const int xCenter, const int yCenter, const int x,
                          const int y) {
        if (xCenter + x < grid[0].size() && yCenter + y < grid.size()) grid[yCenter + y][xCenter + x] = '#';
        if (xCenter - x >= 0 && yCenter + y < grid.size()) grid[yCenter + y][xCenter - x] = '#';
        if (xCenter + x < grid[0].size() && yCenter - y >= 0) grid[yCenter - y][xCenter + x] = '#';
        if (xCenter - x >= 0 && yCenter - y >= 0) grid[yCenter - y][xCenter - x] = '#';
        if (xCenter + y < grid[0].size() && yCenter + x < grid.size()) grid[yCenter + x][xCenter + y] = '#';
        if (xCenter - y >= 0 && yCenter + x < grid.size()) grid[yCenter + x][xCenter - y] = '#';
        if (xCenter + y < grid[0].size() && yCenter - x >= 0) grid[yCenter - x][xCenter + y] = '#';
        if (xCenter - y >= 0 && yCenter - x >= 0) grid[yCenter - x][xCenter - y] = '#';
    }
}
