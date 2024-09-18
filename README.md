# **Maze**

Table of content
- Intrduction
- Prerequisites
- Installation
- Usage
- Related projects

## Introduction
this is the default project for ALX SE programme. The project is all about creating a maze video game just like old game called “wolfenstien”. The project is built basically on SDL2 library. This project should be compiled using gcc and will be running on linux ubuntu 16 platform.


Authors: Mohammed Amer
E-mail: loard.amer.2010@gmail.com
Linkedin: ![The Maze](https://www.linkedin.com/pulse/maze-mohammed-amer-zfpef/)

## Prerequisites

You should install the SDL2 library to be able to build this game to do that follow this tutorial [HELLO! SDL2](https://lazyfoo.net/tutorials/SDL/01_hello_SDL/index.php)

## Installation
Run `make all` to generate the maze file this command will also remove object file after the compiling and linking

Run `make debug` to create maze file that have debug information for debuggin, 
>**NOTE** this command requires you to run `make clean` after using it in case you want to remove object files

Run `make re` if something went wrong during the compilation process and you needed to rebuild your project. In most cases run re is just like run all but it’s safer to run re if you have a problem.


## Usage
To start the game type `PATH/maze` in the terminal, that will open a window of the maze. 
W: to move forward
S: to move backward
A:  to move left
D: to move right
Right arrow: to rotate with clockwise
Left arrow: to rotate counter clockwise
To exit the game use the 'x' button of the window or you could send `SIGTERM` from the terminal that open it.


## Related projects:
All other projects related to ALX SE is found in my github account prefixed with 'alx'
