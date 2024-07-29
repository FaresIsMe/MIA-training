Chess Game Documentation
# 1. Initialize Pygame
The Pygame library is initialized to set up the environment for the game. This includes setting up the display and preparing the game window.

# 2. Screen Dimensions and Setup
The dimensions of the game window are defined, and the display is set up with a specific width and height. The window is also given a title, “Chess”.

# 3. Colors
Colors used in the game are defined, specifically white and black, which are used for the chessboard and text.

# 4. Load Images
Images for each chess piece are loaded from specified file paths. These images represent the different pieces (Pawn, Rook, Knight, Bishop, Queen, King) for both white and black players.

# 5. Board Setup
The chessboard is initialized with the starting positions of all the pieces. This setup includes two rows of pawns and the back rows with the major pieces for both players.

# 6. Piece Movement Rules
Movement rules for each type of piece are defined. This includes specific functions to validate the moves for pawns, rooks, knights, bishops, queens, and kings. Each function checks if a move is valid based on the rules of chess.

# 7. Draw the Board
A function is created to draw the chessboard. The board is drawn with alternating colors to represent the squares, using a nested loop to fill the board with the appropriate colors.

# 8. Draw the Pieces
A function is created to draw the pieces on the board. This function iterates through the board and places each piece image at the correct position on the screen.

# 9. Draw the Current Player’s Turn
A function is created to display the current player’s turn on the screen. This function uses Pygame’s text rendering capabilities to create a text surface that shows whether it is White’s or Black’s turn and then draws this text on the screen.

# 10. Main Game Loop
The main game loop handles the core functionality of the game. It includes event handling for quitting the game and mouse clicks for selecting and moving pieces. The loop also manages the switching of turns between players. The board and pieces are redrawn in each iteration of the loop, and the current player’s turn is displayed.