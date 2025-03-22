# Sudoku Solving Algorithm

## Overview
This repository contains a Sudoku-solving algorithm that supports 9x9, 16x16, and 25x25 Sudoku grids. The solver is implemented using an **enhanced Dancing Links (DLX) algorithm**, optimized with a custom data structure featuring `up`, `down`, `left`, and `right` pointers to improve execution speed.

This was a **first-year project** for the **Introduction to Data Structures and Algorithms** course.

## Features
- **Supports multiple grid sizes**: 
  - 9x9 Sudoku (standard)
  - 16x16 Sudoku
  - 25x25 Sudoku
- **Optimized with a custom data structure**:
  - Uses linked nodes with `up`, `down`, `left`, and `right` pointers to enhance speed.
  - Implements the Dancing Links algorithm to efficiently solve Sudoku puzzles.
- **Handles empty spaces with `0`s**.
- **Symbol representation**:
  - **9x9 Sudoku**: Uses digits `1-9`.
  - **16x16 Sudoku**: Uses digits `1-9` and letters `A-F`.
  - **25x25 Sudoku**: Uses digits `1-9` and letters `A-P`.


