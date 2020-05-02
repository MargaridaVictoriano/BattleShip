# Battleship
A C99 implementation of the strategic game Battleship.

## Getting Started
You can download or clone the project on our [GitHub repository](https://github.com/MargaridaVictoriano/BattleShip).

## Prerequisites
First, you need to have installed **gcc** and **makefile**.
You can install both of them using the following terminal command: `sudo apt-get install build-essential`.
To compile the program you simply need to run the following terminal comand: `make`.
Then, to run the program you need to run the following terminal comand: `./battleship`.

## How to Play
This is a two player game.
You will be prompted with a menu with three options. If you press `1` you will start the game imediately, if you press  `2` the rules will be shown and if you press `3` you will quit the program.

If it's your first time playing the game,  we advise you to press `2` to read the rules since they explain in detail on how to play the game.

This version of the game is slightly different from the original Battleship since you can choose the board size and how many boats you want from each type. We also added a different type of boat. It is a L shapped boat and, just like in the others, you can choose how many types you want to play with. Please be aware that all the input is checked to assure it makes sense so you may have to respect some stated limits.

You can place your boats on the board or you can choose to place them randomly.

When the game begins the players take turns attacking each other and they can view their own map and their attack map whenever they want.

The first player to guess the location of all ships wins!

## Code Structure
Our program is divided in several different modules. We decided to divide the project into its main components and create a new module for each one of them.

### Board Module

The _Board_ module contains the _Cell_ and the _Board_ structures definition, the matrix limits and it also contains some auxiliary funtions to manipulate the board.

#### Board Module Functions
The usage and description of the functions of the Board module are specified in the documentation.

### 

## Authors
Ana Margarida Victoriano, up201704476

Eduardo Santos, up201805449

