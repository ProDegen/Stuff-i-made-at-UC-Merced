/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Project/Maven2/JavaApp/src/main/java/${packagePath}/${mainClassName}.java to edit this template
 */
package com.mycompany.minesweeper;

/**
 *
 * @author Travis
 */
public class MineSweeper {

    public static void main(String[] args) {
        System.out.println("=== WELCOME TO MINESWEEPER ===");
        Game play = new Game();
        // calls the game for the first time
        play.start();
    }
}
