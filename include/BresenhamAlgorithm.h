#pragma once

#include <vector>


namespace BresenhamAlgorithm {
    void drawLine(std::vector<std::vector<char> > &grid, int x1, int y1, int x2, int y2);

    void drawCircle(std::vector<std::vector<char> > &grid, int xCenter, int yCenter, int radius);

    void plotCirclePoints(std::vector<std::vector<char> > &grid, int xCenter, int yCenter, int x, int y);
}
