# Shapes Blackboard

## Description

This project implements a console-based system for drawing geometric figures such as circles, rectangles, triangles, and lines using a blackboard. It allows users to interact with the system through a command-line interface (CLI), providing commands to draw figures, clear the blackboard, and perform undo/redo actions. The `Blackboard` class handles figure drawing, while each shape is represented as a class inheriting from the `Figure` base class. The system supports user interaction with figures through commands and displays the drawn shapes on the blackboard.

## Changes

### Figure.cpp:
- Created a base class `Figure` for handling general properties of figures like position, drawing, and management.
- Implemented virtual functions for derived shapes to override specific drawing behavior.

### Line.cpp:
- Implemented the `Line` class for drawing straight lines of different slopes using Bresenham's algorithm.

### Circle.cpp:
- Implemented the `Circle` class inheriting from `Figure`, representing circles on the blackboard.

### Rectangle.cpp:
- Implemented the `Rectangle` class for drawing axis-aligned rectangles.
  
### Triangle.cpp:
- Implemented the `Triangle` class for drawing triangles with three points on the grid.

### Blackboard.cpp:
- Implemented functionality for drawing, adding, listing, clearing, undoing figures on the blackboard and saving/loading blackboard.
- Added support for storing and managing different figures using `std::vector<std::unique_ptr<Figure>> currentFigures`.
- Managed grid drawing operations and display of shapes on the blackboard.

### BresenhamAlgorithm.cpp:
- Implemented Bresenham's algorithm for drawing lines and circles with pixel-level accuracy.

### CLI.cpp:
- Implemented the command-line interface for interacting with the blackboard.
- Provided user input validation and error handling for commands.

### Main.cpp:
- Created the entry point for the program, setting up the CLI and initializing the blackboard.
- Processed user inputs and passed them to the CLI for command execution.

## How to Test

1. Draw the blackboard:
```
draw
```
*Description: Draws the blackboard to the console, showing the ASCII representation of all shapes or an empty board if no shapes are added.*

2. List all added shapes:
```
list
```
*Description: Prints all added shapes with their IDs and parameters (e.g., shape type, coordinates, etc.).*

3. List available shapes:
```
shapes
```
*Description: Displays a list of all available shapes and the required parameters for each shape.*

4. Add a shape:
```
add
<shape>
<parameters>
```
*Description: Adds a shape to the blackboard with the specified parameters.*

5. Undo the last added shape:
```
undo
```
*Description: Removes the last added shape from the blackboard.*

6. Clear all shapes from the blackboard:
```
clear
```
*Description: Removes all shapes from the blackboard.*

8. Save the blackboard to a file:
```
save
<file-path>
```
*Description: Saves the current state of the blackboard to the specified file.*

9. Load a blackboard from a file:
```
load
<file-path>
```
*Description: Loads a previously saved blackboard from the specified file, replacing the current state.*


### Program structure
<img width="1427" alt="Screenshot 2024-10-06 at 18 08 14" src="https://github.com/user-attachments/assets/32413e07-7b3b-494f-be28-6325a2be7a42">

