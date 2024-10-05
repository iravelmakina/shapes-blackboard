#include "BresenhamAlgorithm.h"

#include <iostream>


namespace BresenhamAlgorithm {
    void drawLine(std::vector<std::vector<char> > &grid, int  x1, int y1, const int x2, const int y2) {
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
}
