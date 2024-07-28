import pygame
import sys
from Chess_grapes import *


#intialize the pygame module
pygame.init()


WINDOW_SIZE = (512, 512)
screen = pygame.display.set_mode(WINDOW_SIZE)
pygame.display.set_caption("Chess pain")

WHITE = (255, 255, 255)
BLACK = (0, 0, 0)

def draw_board():
    for row in range(8):
        for col in range(8):
            if (row + col) % 2 == 0:
                pygame.draw.rect(screen, WHITE, (col * 64, row * 64, 64, 64))
            else:
                pygame.draw.rect(screen, BLACK, (col * 64, row * 64, 64, 64))
# Initialize the board
def initialize_board():
    board = [['' for _ in range(8)] for _ in range(8)]
    
    # Place pawns
    for col in range(8):
        board[1][col] = 'WP'  # White Pawn
        board[6][col] = 'BP'  # Black Pawn

    # Place other pieces
    board[0] = ['WR', 'WN', 'WB', 'WQ', 'WK', 'WB', 'WN', 'WR']  # White pieces
    board[7] = ['BR', 'BN', 'BB', 'BQ', 'BK', 'BB', 'BN', 'BR']  # Black pieces

    return board

def draw_pieces(board):
    font = pygame.font.Font(None, 74)
    for row in range(8):
        for col in range(8):
            piece = board[row][col]
            if piece:
                text = font.render(piece, True, (0, 0, 0))
                screen.blit(text, (col * 64, row * 64))

def valid_pawn_moves(board, row, col):
    moves = []
    direction = -1 if board[row][col][0] == 'W' else 1
    start_row = 6 if board[row][col][0] == 'W' else 1
    
    # Move forward
    if board[row + direction][col] == '':
        moves.append((row + direction, col))
        # Move two squares from starting position
        if row == start_row and board[row + 2 * direction][col] == '':
            moves.append((row + 2 * direction, col))

    # Capture diagonally
    for d_col in [-1, 1]:
        if 0 <= col + d_col < 8:
            if board[row + direction][col + d_col] and board[row + direction][col + d_col][0] != board[row][col][0]:
                moves.append((row + direction, col + d_col))

    return moves

def draw_board():
    for row in range(8):
        for col in range(8):
            color = (255, 206, 158) if (row + col) % 2 == 0 else (209, 139, 71)
            pygame.draw.rect(screen, color, (col * 64, row * 64, 64, 64))

def main():
    clock = pygame.time.Clock()
    board = initialize_board()
    current_turn = 'W'  # White starts

    # Initialize the display
    pygame.init()
    screen = pygame.display.set_mode((512, 512))



    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()

            # Handle piece selection and movement
            if event.type == pygame.MOUSEBUTTONDOWN:
                pos = pygame.mouse.get_pos()
                col = pos[0] // 64
                row = pos[1] // 64
                piece = board[row][col]

                if piece and piece[0] == current_turn:  # Check if it's the current player's piece
                    moves = []
                    if piece[1] == 'P':
                        moves = valid_pawn_moves(board, row, col)
                    # Add similar checks for other pieces

                    # Implement movement logic here (e.g., update the board)

        draw_board()
        draw_pieces(board)
        pygame.display.flip()
        clock.tick(60)

if __name__ == "__main__":
    main()