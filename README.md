# Project_Tic_Tac_Toe
# Console-Based Two-Player Tic-Tac-Toe Game with Score Tracking in C

## Team Members
**Section:** F | **Group:** C-11

| S.No | Name | Roll No. | Role / Contribution |
| :--- | :--- | :--- | :--- |
| 1 | Karnika | 26CSU244 | Board initialization & 3x3 grid display, main menu & play-again loop, scoreboard tracking/reset logic, and project documentation |
| 2 | Harshita Sehrawat | 26CSU233 | Player name input handling, move input & validation logic, win/draw detection (rows, columns, diagonals), and testing & screenshots |

---

## Short Description
This is a console-based Two-Player Tic-Tac-Toe game developed in C for the **FOCP-I (C Programming)** mini project. Two players enter their names, receive markers **`X`** and **`O`**, and take turns placing their marks on a 3×3 grid using cell numbers `1–9`. After each valid move, the program checks all rows, columns, and diagonals for a winner or declares a draw when all nine cells are filled. It also includes an interactive main menu and tracks cumulative wins and draws across multiple rounds.

---

## Features
- **Menu-Driven Interface:** Main menu with options to *Play Game*, *View Scoreboard*, *Reset Scores*, or *Exit*.
- **Custom Player Names:** Accepts both players' first names and personalizes turn prompts and scoreboard entries.
- **3×3 Console Game Board:** Displays numbered cells (`1–9`) initially and updates live with `X` and `O` after each move.
- **Input & Move Validation:** Validates that cell numbers are within `1–9` and prevents players from overwriting already occupied cells.
- **Win & Draw Detection:** Automatically checks all 3 rows, 3 columns, and 2 diagonals for a winning line, or detects a draw if all 9 cells fill up.
- **Multi-Round Scoreboard & Replay Loop:** Tracks cumulative wins for Player X, Player O, and Draws across rounds with a quick `y/n` play-again option.

---


│   └── result.png
└── docs/
    └── FOCP_I_Tic_Tac_Toe_Project_Report-v3.docx
