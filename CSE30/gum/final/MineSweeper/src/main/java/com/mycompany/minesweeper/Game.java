/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.minesweeper;

/**
 *
 * @author Travis
 */
import java.util.Scanner;

public class Game {

    // initializes a constant for the number of mines per game
    public static final int NUM_OF_MINES = 10;

    Scanner sc = new Scanner(System.in);

    // builds the game boards(s)
    public void start() {
        // get the dimensions of the grid from the user
        System.out.print("Enter the height of the grid: " + "\n");
        int gridHeight = sc.nextInt();
        System.out.print("Enter the width of the grid: " + "\n");
        int gridWidth = sc.nextInt();
        // ensures the height and width are equal, and large enough to hold 10 mines
        if (gridWidth > gridHeight || gridWidth < gridHeight || gridHeight < 4) {
            System.out.print("!!! Please make sure the height and width are equal and greater than 3 !!!" + "\n" + "\n");
            start();
        } else {
            /*
            initializes three arrays to be the game "board"
            one for the user to see with bombs hidden
            one for the program to read to calculate the user's guesses
            and one that determines whether or not a space has already been explored
            to prevent infinite recursions when uncovering empty cells
             */
            int[][] boardPlay = new int[gridHeight][gridWidth];
            int[][] boardData = new int[gridHeight][gridWidth];
            boolean[][] boardExplored = new boolean[gridHeight][gridWidth];
            // fills the arrays with junk data to be changed later in the program
            for (int a = 0; a < gridHeight; a++) {
                for (int b = 0; b < gridWidth; b++) {
                    boardPlay[a][b] = 8;
                    boardData[a][b] = 8;
                    boardExplored[a][b] = false;
                }
            }
            // creates an object of the Grid class to be able to build the game boards
            Grid placeBombs = new Grid();
            // places bombs in the visible "play" board and hidden "data" board
            placeBombs.randomFillGrid(gridHeight, gridWidth, boardPlay, boardData);
            // adds in numbers for all adjacent mines to "data" board only
            placeBombs.numbersFillGrid(gridHeight, gridWidth, boardData);
            // sets all non-zero cells to be "explored" so they will not be visited by clearBlanks method
            placeBombs.exploredFillGrid(gridHeight, gridWidth, boardData, boardExplored);
            // begins the actual game
            gameLoop(boardPlay, boardData, boardExplored, gridHeight, gridWidth);
        }
    }

    /* 
    runs a loop that asks the user for coordinates to check for mines
    and either repeats or gives a victory/fail state 
     */
    public void gameLoop(int boardPlay[][], int boardData[][], boolean boardExplored[][], int gridHeight, int gridWidth) {
        Grid showBoard = new Grid();
        // determines if the player uncovered all non-mine cells and won the game
        if (showBoard.allClear(boardPlay, gridHeight, gridWidth)) {
            System.out.print("Congratulations! You have won MineSweeper!" + "\n");
            showBoard.displayGridData(boardData, gridHeight, gridWidth);
            System.out.print("Play again? (Y/N)" + "\n");
            String playAgain = sc.next();
            // asks to play again
            if (playAgain.equalsIgnoreCase("y")) {
                start();
            } else {
                System.out.print("Thanks for Playing!");
                sc.close();
            }
        } else {
            // shows user the board, asks them to choose a spot to check for mines
            showBoard.displayGrid(boardPlay, gridHeight, gridWidth);
            System.out.print("Pick a spot to check for a mine." + "\n" + "First enter the row number then the column number: " + "\n");
            int row = sc.nextInt() - 1;
            int col = sc.nextInt() - 1;
            // begins calculating their choice
            if (inBounds(row, col, gridHeight, gridWidth)) {
                // checks if their choice is a mine
                if (checkLocation(row, col, boardData)) {
                    System.out.print("GameOver!" + "\n");
                    showBoard.displayGridData(boardData, gridHeight, gridWidth);
                    System.out.print("Play again? (Y/N)" + "\n");
                    String playAgain = sc.next();
                    // asks to play again
                    if (playAgain.equalsIgnoreCase("y")) {
                        start();
                    } else {
                        System.out.print("Thanks for Playing!");
                        sc.close();
                    }
                    // checks if their choice has any mines adjacent to it    
                } else if (boardData[col][row] != 0) {
                    boardPlay[col][row] = boardData[col][row];
                    // restarts loop asking user to choose another spot
                    gameLoop(boardPlay, boardData, boardExplored, gridHeight, gridWidth);
                } else {
                    boardPlay[col][row] = boardData[col][row];
                    clearBlanks(row, col, boardData, boardPlay, boardExplored, gridHeight, gridWidth);
                    // restarts loop asking user to choose another spot
                    gameLoop(boardPlay, boardData, boardExplored, gridHeight, gridWidth);
                }
            } else {
                // makes sure guess is valid
                System.out.print("!!! Please make sure your guess is within the game board !!!" + "\n");
                gameLoop(boardPlay, boardData, boardExplored, gridHeight, gridWidth);
            }
        }
    }

    // determines how many mines are adjacent to every cell of the grid minus mine squares
    public int numberOfMines(int row, int col, int boardData[][], int gridHeight, int gridWidth) {
        int adjMines = 0;
        /* 
        checks every adjacent cell of the given coordinate
        skipping if they are out of bounds and/or a mine cell
         */
        if (inBounds(row - 1, col - 1, gridHeight, gridWidth) == true) {
            if (boardData[col - 1][row - 1] == 9) {
                adjMines += 1;
            }
        }
        if (inBounds(row, col - 1, gridHeight, gridWidth) == true) {
            if (boardData[col - 1][row] == 9) {
                adjMines += 1;
            }
        }
        if (inBounds(row + 1, col - 1, gridHeight, gridWidth) == true) {
            if (boardData[col - 1][row + 1] == 9) {
                adjMines += 1;
            }
        }
        if (inBounds(row - 1, col, gridHeight, gridWidth) == true) {
            if (boardData[col][row - 1] == 9) {
                adjMines += 1;
            }
        }
        if (inBounds(row + 1, col, gridHeight, gridWidth) == true) {
            if (boardData[col][row + 1] == 9) {
                adjMines += 1;
            }
        }
        if (inBounds(row - 1, col + 1, gridHeight, gridWidth) == true) {
            if (boardData[col + 1][row - 1] == 9) {
                adjMines += 1;
            }
        }
        if (inBounds(row, col + 1, gridHeight, gridWidth) == true) {
            if (boardData[col + 1][row] == 9) {
                adjMines += 1;
            }
        }
        if (inBounds(row + 1, col + 1, gridHeight, gridWidth) == true) {
            if (boardData[col + 1][row + 1] == 9) {
                adjMines += 1;
            }
        }
        return adjMines;
    }

    // determines if the given cell is a mine
    public boolean checkLocation(int row, int col, int boardData[][]) {
        if (boardData[col][row] == 9) {
            return true;
        } else {
            return false;
        }
    }

    /* 
    reveals all adjacent cells to the user's choice, marking them with a zero/empty space
    or marking them the number of adjacent mines. if the adjacent cell is also empty
    recursively repeat the method until all adjacent empty cells are revealed and
    adjacent number cells have their number of adjacent mines displayed
     */
    public void clearBlanks(int row, int col, int boardData[][], int boardPlay[][], boolean boardExplored[][], int gridHeight, int gridWidth) {
        // checks that the given coordinate is in bounds of the grid
        if (inBounds(row, col, gridHeight, gridWidth)) {
            // checks if this coordinate of the board has already been explored
            if (!boardExplored[col][row]) {
                // sets current cell to be considered "explored" by this method's recursion
                boardExplored[col][row] = true;
                // reveals this cell
                boardPlay[col][row] = boardData[col][row];
                // reveals the four adjacent cells, if they are in bounds
                if (inBounds(row + 1, col, gridHeight, gridWidth)) {
                    boardPlay[col][row + 1] = boardData[col][row + 1];
                }
                if (inBounds(row - 1, col, gridHeight, gridWidth)) {
                    boardPlay[col][row - 1] = boardData[col][row - 1];
                }
                if (inBounds(row, col + 1, gridHeight, gridWidth)) {
                    boardPlay[col + 1][row] = boardData[col + 1][row];
                }
                if (inBounds(row, col - 1, gridHeight, gridWidth)) {
                    boardPlay[col - 1][row] = boardData[col - 1][row];
                }
                // repeats this method for adjacent cells if they have no adjacent mines as well
                clearBlanks(row + 1, col, boardData, boardPlay, boardExplored, gridHeight, gridWidth);
                clearBlanks(row - 1, col, boardData, boardPlay, boardExplored, gridHeight, gridWidth);
                clearBlanks(row, col + 1, boardData, boardPlay, boardExplored, gridHeight, gridWidth);
                clearBlanks(row, col - 1, boardData, boardPlay, boardExplored, gridHeight, gridWidth);
            }
        }

    }

    // determines if the coordinates given are in bounds of the game grid
    public static boolean inBounds(int row, int col, int gridHeight, int gridWidth) {
        return row >= 0 && col >= 0 && row < gridHeight && col < gridWidth;
    }
}
