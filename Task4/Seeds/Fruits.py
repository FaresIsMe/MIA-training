import pygame

import sys

import time


#intialize the pygame module
pygame.init()

SCREEN = pygame.display.set_mode((800, 600))

pygame.display.set_caption("Test")

RED = (255, 0, 0)
GRAY = (128, 128, 128)
BLUE = (0, 0, 255)


def draw_background(screen, pos):
    new_colour = (pos[0] % 256, pos[1] % 256, pos[1] % 256)

    screen.fill(new_colour)

def main():
    open = True
    pos = (0, 0, 0)

    while open:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                open = False
            elif event.type == pygame.MOUSEBUTTONDOWN:
                pos = pygame.mouse.get_pos()
                print("You clicked at ", pos)

        draw_background(SCREEN, pos)
        pygame.display.flip()  
    sys.exit()



if __name__ == "__main__":
    main()