import pygame
import sys

# Initialize Pygame
pygame.init()


font = pygame.font.SysFont(None, 36)

# Screen dimensions
WIDTH, HEIGHT = 800, 900
SCREEN = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Chess")

# Colors
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)

# Load images
PIECES = {
    "wP": pygame.image.load("white-pawn.png"),
    "wR": pygame.image.load("white-rook.png"),
    "wN": pygame.image.load("white-knight.png"),
    "wB": pygame.image.load("white-bishop.png"),
    "wQ": pygame.image.load("white-queen.png"),
    "wK": pygame.image.load("white-king.png"),
    "bP": pygame.image.load("black-pawn.png"),
    "bR": pygame.image.load("black-rook.png"),
    "bN": pygame.image.load("black-Knight.png"),
    "bB": pygame.image.load("black-bishop.png"),
    "bQ": pygame.image.load("black-queen.png"),
    "bK": pygame.image.load("black-king.png"),
}

# Board setup
board = [
    ["bR", "bN", "bB", "bQ", "bK", "bB", "bN", "bR"],
    ["bP", "bP", "bP", "bP", "bP", "bP", "bP", "bP"],
    ["--", "--", "--", "--", "--", "--", "--", "--"],
    ["--", "--", "--", "--", "--", "--", "--", "--"],
    ["--", "--", "--", "--", "--", "--", "--", "--"],
    ["--", "--", "--", "--", "--", "--", "--", "--"],
    ["wP", "wP", "wP", "wP", "wP", "wP", "wP", "wP"],
    ["wR", "wN", "wB", "wQ", "wK", "wB", "wN", "wR"]
]

# Draw the board
def draw_board(screen):
    colors = [pygame.Color("white"), pygame.Color("gray")]
    for r in range(8):
        for c in range(8):
            color = colors[(r + c) % 2]
            pygame.draw.rect(screen, color, pygame.Rect(c*100, r*100, 100, 100))

# Draw the pieces
def draw_pieces(screen, board):
    for r in range(8):
        for c in range(8):
            piece = board[r][c]
            if piece != "--":
                screen.blit(PIECES[piece], pygame.Rect(c*95, r*95, 10, 100))

# Piece movement rules
def is_valid_move(piece, start_pos, end_pos):
    start_row, start_col = start_pos
    end_row, end_col = end_pos
    if piece[1] == 'P':  # Pawn
        return is_valid_pawn_move(piece, start_pos, end_pos)
    elif piece[1] == 'R':  # Rook
        return is_valid_rook_move(start_pos, end_pos)
    elif piece[1] == 'N':  # Knight
        return is_valid_knight_move(start_pos, end_pos)
    elif piece[1] == 'B':  # Bishop
        return is_valid_bishop_move(start_pos, end_pos)
    elif piece[1] == 'Q':  # Queen
        return is_valid_queen_move(start_pos, end_pos)
    elif piece[1] == 'K':  # King
        return is_valid_king_move(start_pos, end_pos)
    return False

def is_valid_pawn_move(piece, start_pos, end_pos):
    start_row, start_col = start_pos
    end_row, end_col = end_pos
    direction = -1 if piece[0] == 'w' else 1
    if start_col == end_col and board[end_row][end_col] == "--":
        if start_row + direction == end_row:
            return True
        if (start_row == 6 and piece[0] == 'w') or (start_row == 1 and piece[0] == 'b'):
            if start_row + 2 * direction == end_row and board[start_row + direction][start_col] == "--":
                return True
    if abs(start_col - end_col) == 1 and start_row + direction == end_row and board[end_row][end_col] != "--":
        return True
    return False

def is_valid_rook_move(start_pos, end_pos):
    start_row, start_col = start_pos
    end_row, end_col = end_pos
    if start_row == end_row or start_col == end_col:
        if not any(board[r][c] != "--" for r in range(min(start_row, end_row) + 1, max(start_row, end_row))
                   for c in range(min(start_col, end_col) + 1, max(start_col, end_col))):
            return True
    return False

def is_valid_knight_move(start_pos, end_pos):
    start_row, start_col = start_pos
    end_row, end_col = end_pos
    return (abs(start_row - end_row), abs(start_col - end_col)) in [(2, 1), (1, 2)]

def is_valid_bishop_move(start_pos, end_pos):
    start_row, start_col = start_pos
    end_row, end_col = end_pos
    if abs(start_row - end_row) == abs(start_col - end_col):
        if not any(board[start_row + i * (end_row - start_row) // abs(end_row - start_row)]
                   [start_col + i * (end_col - start_col) // abs(end_col - start_col)] != "--"
                   for i in range(1, abs(end_row - start_row))):
            return True
    return False

def is_valid_queen_move(start_pos, end_pos):
    return is_valid_rook_move(start_pos, end_pos) or is_valid_bishop_move(start_pos, end_pos)

def is_valid_king_move(start_pos, end_pos):
    start_row, start_col = start_pos
    end_row, end_col = end_pos
    return max(abs(start_row - end_row), abs(start_col - end_col)) == 1

# Draw the board
def draw_board(screen):
    screen.fill(BLACK)
    colors = [pygame.Color("white"), pygame.Color("gray")]
    for r in range(8):
        for c in range(8):
            color = colors[(r + c) % 2]
            pygame.draw.rect(screen, color, pygame.Rect(c*100, r*100, 100, 100))


def draw_turn(screen, player_turn):
    text = font.render(f"Turn: {'white' if player_turn == "w" else 'black'}", True, WHITE)
    screen.blit(text, (100, 850))


# Main game loop
def main():
    running = True
    selected_piece = None
    player_turn = "w"  # White starts

    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            elif event.type == pygame.MOUSEBUTTONDOWN:
                pos = pygame.mouse.get_pos()
                col = pos[0] // 100
                row = pos[1] // 100
                if selected_piece:
                    if is_valid_move(selected_piece, selected_piece_pos, (row, col)):
                        board[row][col] = selected_piece
                        board[selected_piece_pos[0]][selected_piece_pos[1]] = "--"
                        selected_piece = None
                        player_turn = "b" if player_turn == "w" else "w"
                else:
                    if board[row][col][0] == player_turn:
                        selected_piece = board[row][col]
                        selected_piece_pos = (row, col)

        draw_board(SCREEN)
        draw_pieces(SCREEN, board)
        draw_turn(SCREEN, player_turn)
        pygame.display.flip()
        

    pygame.quit()
    sys.exit()


if __name__ == "__main__":
    main()
