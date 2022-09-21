/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.minesweeper;

/**
 *
 * @author Travis
 */
import java.lang.Math;

public class Grid {

    // initializes a constant for the number of mines per game
    public static final int NUM_OF_MINES = 10;

    // randomly places however many mines are in the above constant, into the game board
    public void randomFillGrid(int gridHeight, int gridWidth, int[][] boardPlay, int[][] boardData) {
        double r = 0.0;
        double c = 0.0;
        int row = 0;
        int col = 0;
        // chooses a random location on the grid, and places a mine in it
        for (int a = 0; a < NUM_OF_MINES; a++) {
            r = Math.random() * gridWidth;
            row = (int) r;
            c = Math.random() * gridHeight;
            col = (int) c;
            // determines if the chosen cell already has a mine in it or not
            if (boardData[col][row] != 9) {
                boardData[col][row] = 9;
                boardPlay[col][row] = 9;
            } else {
                // if cell already has mine, lowers count to try again
                a -= 1;
            }
        }
    }

    // fills every cell in the hidden "data" board with the number of adjacent mines
    public void numbersFillGrid(int gridHeight, int gridWidth, int[][] boardData) {
        // loops through every cell on the board
        for (int a = 0; a < gridHeight; a++) {
            for (int b = 0; b < gridWidth; b++) {
                Game adjacentMines = new Game();
                // calls the numberOfMines method to discover the number of adjacent mines
                int adjMines = adjacentMines.numberOfMines(b, a, boardData, gridHeight, gridWidth);
                if (boardData[a][b] != 9) {
                    boardData[a][b] = adjMines;
                }
            }
        }
    }

    // goes through every cell on the board and if it has adjacent mines
    // set self to be considered explored so the clearBlanks method doesnt explore it 
    public void exploredFillGrid(int gridHeight, int gridWidth, int[][] boardData, boolean[][] boardExplored) {
        for (int a = 0; a < gridHeight; a++) {
            for (int b = 0; b < gridWidth; b++) {
                if (boardData[a][b] != 0) {
                    boardExplored[a][b] = true;
                }
            }
        }
    }

    /* 
    copies the visible "play" board to a string array, and changes values to the correct
    hidden spaces (asterisk), clear spaces (blank space) or number in string form
    then formats the array into a table to display to the user to read
     */
    public void displayGrid(int[][] boardPlay, int gridHeight, int gridWidth) {
        // creates an array to be used for the top row so the user can choose a column
        int[] topRow = new int[gridWidth];
        int rowCounter = 1;
        int colCounter = 1;
        // fills the above array with numbers equal to the grid size
        for (int a = 0; a < gridWidth; a++) {
            topRow[a] = rowCounter;
            rowCounter++;
        }
        //prints words for the user to read
        System.out.print("There are a total of " + NUM_OF_MINES + " mines in the mine field" + "\n");
        System.out.print("\t");
        // prints the top row
        for (int a : topRow) {
            System.out.print(a + " ");
        }
        System.out.print("\n" + "\n" + "\n");
        // initializes the string array that will be displayed to the user
        String[][] boardString = new String[gridHeight][gridWidth];
        // fills the above array with the data of the "play" board and converts it to string
        for (int a = 0; a < gridHeight; a++) {
            for (int b = 0; b < gridWidth; b++) {
                boardString[a][b] = String.valueOf(boardPlay[a][b]);
            }
        }
        /*
        changes zeroes on the board to empty spaces (no adjacent mines)
        integer numbers to string numbers (num of adjacent mines)
        and unexplored cells and/or mines to asterisks
         */
        for (int a = 0; a < gridHeight; a++) {
            for (int b = 0; b < gridHeight; b++) {
                if (boardPlay[a][b] == 0) {
                    boardString[a][b] = " ";
                }
                if (boardPlay[a][b] == 1) {
                    boardString[a][b] = "1";
                }
                if (boardPlay[a][b] == 2) {
                    boardString[a][b] = "2";
                }
                if (boardPlay[a][b] == 3) {
                    boardString[a][b] = "3";
                }
                if (boardPlay[a][b] == 4) {
                    boardString[a][b] = "4";
                }
                if (boardPlay[a][b] == 5) {
                    boardString[a][b] = "5";
                }
                if (boardPlay[a][b] == 6) {
                    boardString[a][b] = "6";
                }
                if (boardPlay[a][b] == 7) {
                    boardString[a][b] = "7";
                }
                if (boardPlay[a][b] == 8) {
                    boardString[a][b] = "*";
                }
                if (boardPlay[a][b] == 9) {
                    boardString[a][b] = "*";
                }
            }
        }
        // prints the above array formatted correctly for the user
        for (String[] a : boardString) {
            // prints a column of numbers on the left to help user choose their row
            System.out.print(colCounter + "\t");
            colCounter++;
            // prints the actual game board array
            for (String b : a) {
                System.out.print(b + " ");
            }
            System.out.println("");
        }
    }

    /* calls the displayGrid method, but passes it the hidden "data" board
    instead of the play board to reveal the location of all mines on the board
    used in game over or victory screen
     */
    public void displayGridData(int[][] boardData, int gridHeight, int gridWidth) {
        // passes displayGrid the data board instead of the usual play board
        displayGrid(boardData, gridHeight, gridWidth);
    }

    // determines if the user has cleared every non mine cell, winning the game
    public static boolean allClear(int[][] boardPlay, int gridHeight, int gridWidth) {
        // creates a tally of spaces left to be cleared
        int spacesLeft = 0;
        // counts the remaining spaces left to be cleared
        for (int a = 0; a < gridHeight; a++) {
            for (int b = 0; b < gridWidth; b++) {
                if (boardPlay[a][b] == 8) {
                    spacesLeft++;
                }
            }
        }
        // if uncleared spaces are left, returns true otherwise returns false
        if (spacesLeft > 0) {
            return false;
        } else {
            return true;
        }
    }
}
