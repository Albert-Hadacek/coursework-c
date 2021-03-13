# SET08122 Coursework Report

###### Author: *Albert Hadacek **(40446686)***

---

### Project Description

For this coursework I was assigned to build a working command line interface (CLI) application allowing two players to play a classic board game called Connect 4. It was required to use appropriate data structures to represent the elements of the game and efficient algorithms to determine the winner.

In my case, I decided to take things a bit further to provide a bit more exciting experience for the players and also to dive deeper in the world of C and studied topics of this module. Beside the core functionality, I managed to implement two major features and several smaller tweaks that improve the gameplay. 

The first major feature is the option to play against the computer itself. I managed to implement an AI using the Minimax algorithm **#FINISH AI DESCRIPTION**

The second major feature allows the player to record their games as the move history can be saved (a player picks this option during the game setup) into a text file that is created after the game ends. Then, using the same CLI interface, the player can select to review the game and the history of the moves is displayed, so it can be used for analysis.

The third feature provides the option to set the size of the board. The player can play on boards of size 4 to 10. The shape of the board can be either rectangual or square.

The last feature that is worth mentioning is the option to rewind the game, this feature is available both in singleplayer and multiplayer. It is possible to undo moves one by one allowing the player to get basically back to the start.

---

### Design

The code for the program is written in a single file called main.c. The majority of logic is extracted into separate functions that are declared on top of the file. The flow of the program is responding based on the choices the player makes during the initial setups. 

At the start of the program the player can determine, if he or she wants to play the actual game or go through some of the previous games that are saved in the same folder as the main.c file. If the player decides to play the game, we are branching to the gameplay part of the code, which is then branched again based on the game mode - multiplyer or singleplayer against AI. **#FLOW DIAGRAM**

The logic of the gameplay is encapsulated in functions, the data structures are then gathered in two main structs, namely *gameOption* and *game*. The game options structure contains the settings that the player picked. 

The *mode* and *recordGame* flags are stored as simple characters. The reasoning behind this decision is that if I decided to add more than two modes or options for game recording, it would be possible. The bool data type would allow only two options. I discarded the use of integers as they are less semantic. The numbers of *rows* and *columns* are stored as integers.

In the second struct I stored the data representing the game itself. For the *currentPlayer* I am using an integer (1 or 2) to keep track of the person currently playing, the *move* is represented as a Struct that holds coordinates *y* and *x* as well as the *player* who performed the move - all of the mentioned bindings are stored as integeres. That struct then forms the *board* itself which is a dynamically allocated 2D array (based on the data from *gameOptions*) filled with the *move* structs. 

Lastly we have the *gameHistory*, stored as a doubly linked list filled with *move* structs. The reasoning is simple - we dont know how long our move sequence is gonna be, we need to pop the last elements from the list in case of rewinding and also we need to be able to access the game from start as we are recording it. Queue or stack would not be optimal in this case as each of them allows only one of the mentioned actions. Using an array that would be set dynamically using our board game size to determine the maximum amount of moves would also be an option, yet its determined size would be redundant in the case the game ends earlier and as the insertion times for appending are O(1) for both mentioned structures I picked the double linked list


---

### Critical Evaluation



---

### Resources

---


