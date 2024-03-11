package com.gameoflife;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class GameOfLifeTest {

    private GameOfLife game;

    @BeforeEach
    public void setUp() {
        game = new GameOfLife(5);
    }

    @Test
    public void testInitialPopulation() {
        boolean[][] board = game.getBoardOfCells();
        assertNotNull(board, "Board should not be null");
        assertEquals(5, board.length, "Board should have 5 rows");
        assertEquals(5, board[0].length, "Board should have 5 columns");
    }

    @Test
    public void testNextGeneration() {
        boolean[][] initialBoard = game.getBoardOfCells();
        boolean[][] nextGenBoard = game.populateNextGeneration();
        assertNotEquals(initialBoard, nextGenBoard, "Boards should not be the same after generation update");
    }

    @Test
    public void testUniqueConfigurations() {
        int initialUniqueConfigs = game.findUniqueBoardConfigurations();
        game.populateNextGeneration();
        int afterOneGenConfigs = game.findUniqueBoardConfigurations();
        assertTrue(afterOneGenConfigs > initialUniqueConfigs, "Unique configurations should increase after generation update");
    }
}