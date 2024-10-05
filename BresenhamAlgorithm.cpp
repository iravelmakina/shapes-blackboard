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


    void drawCircle(std::vector<std::vector<char> > &grid, const int x_center, const int y_center, const int radius) {
        int x = 0;
        int y = radius;
        int d = 3 - 2 * radius;

        plotCirclePoints(grid, x_center, y_center, x, y);

        while (x <= y) {
            x++;
            if (d > 0) {
                y--;
                d = d + 4 * (x - y) + 10;
            } else {
                d = d + 4 * x + 6;
            }
            plotCirclePoints(grid, x_center, y_center, x, y);
        }
    }


    void plotCirclePoints(std::vector<std::vector<char> > &grid, const int x_center, const int y_center, const int x,
                          const int y) {
        if (x_center + x < grid[0].size() && y_center + y < grid.size()) grid[y_center + y][x_center + x] = '#';
        if (x_center - x >= 0 && y_center + y < grid.size()) grid[y_center + y][x_center - x] = '#';
        if (x_center + x < grid[0].size() && y_center - y >= 0) grid[y_center - y][x_center + x] = '#';
        if (x_center - x >= 0 && y_center - y >= 0) grid[y_center - y][x_center - x] = '#';
        if (x_center + y < grid[0].size() && y_center + x < grid.size()) grid[y_center + x][x_center + y] = '#';
        if (x_center - y >= 0 && y_center + x < grid.size()) grid[y_center + x][x_center - y] = '#';
        if (x_center + y < grid[0].size() && y_center - x >= 0) grid[y_center - x][x_center + y] = '#';
        if (x_center - y >= 0 && y_center - x >= 0) grid[y_center - x][x_center - y] = '#';
    }
}
