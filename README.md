<div align="center">
<h1>42 - SO_LONG</h1>
<p><strong>And Thanks for All the Fish</strong></a></p>
<p><a href="https://github.com/MathysCogne/42_so_long/blob/main/subject/so_long.pdf"><strong>Subject</strong></a></p>
</br>
![Screen](textures/screenshots/main.gif)
</br>
</div>

## Features

Welcome to **So_Long**, a 2D game developed with MiniLibX as part of the 42 School projects! 🌟

Your mission? Collect all items before finding the exit... but beware of lurking monsters !

</br>

### Game Objectives (Mandatory part):

- **2D View**
- **Objective:** The player must collect all items on the map and escape via the shortest path.
- **Player Movement:** The player can move in four directions (up, down, left, right) and never through walls.
- **Movement Counter in shell** 

### Bonus Features:

- **Random Floor Pattern:** Ground textures are randomized, and external walls differ from the labyrinth walls inside the map.
- **Character and Monster Animation:** Both the player and monsters are animated during movement.
- **Monsters:** Monsters are programmed to pursue the player at all costs. If they encounter a wall blocking their path, they will attempt to find an alternative route to reach the player.
- **Health Management:** The player has three lives before dying.
- **Turn-Based Mechanics:** The player has as many moves per turn as remaining lives + 1, while monsters always have two moves.
- **User Interface (UI):** Displays move counter, item counter, lives remaining, and a turn banner indicating if it’s the player’s or monsters' turn.


</br>

### Key Hooks

| Key     | Description       |
|:--------|:-------------------
| ESC        | Quit the game  |
| W or ⬆️     | Move up        |
| S or ⬇️     | Move down      |
| A or ⬅️     | Move left      |
| D or ➡️     | Move right     |

</br>

### Map Structure `(.ber formar)`

Each map in .ber format should adhere to specific structural rules:
   - The map is rectangular and closed by walls on all edges.
   - Contains one 'P' (Start) and one 'E' (Exit).
   - Items ('C') must be collectible, with a path allowing the player to reach all items before accessing the Exit.
   - Only the characters shown in the table below are allowed:

| Character | Description   |
|:--------|:-----------------
| P       | Start point     |
| E       | Exit point      |
| C       | Item            |
| 0       | Void / Flat     |
| 1       | Wall            |
| M       | Monsters        |


</br>

## Project Structure

- **include/**
  -  Contains header files

- **src/**
   - [`main.c`](./src/main.c) - Entry point of the program
   - [`so_long.c`](./src/so_long.c) - Manages core game functions
      - [`game/`](./src/game/) - Contains gameplay logic, including player movement, item collection tracking,monster behavior, and win/loss conditions.
      - [`map/`](./src/map/) - Handles map-related functions, such as loading and validating .ber map files and checking paths for game elements like the exit and items.
      - [`mlx/`](./src/mlx/) - Manages the interface with the MiniLibX library, including creating windows, rendering textures, and updating the display.
      - [`utils/`](./src/utils/) - Utility functions

- **textures/**
   - Contains the game's textures, stored in .xpm format

- **map/**
   - Directory for .ber maps, including both valid and invalid configurations for testing.

- **librairies**
   -  [`MinilibX`](https://harm-smits.github.io/42docs/libs/minilibx) The graphical library provided by 42
   -  [`Libft`](https://github.com/MathysCogne/MyLibft_GNL_Printf) A custom implementation of the Libft library with essential functions



</br>

## Compilation and usage

**Dependencies**

- Libft: This project depends on Libft. Please clone [`Libft`](https://github.com/MathysCogne/MyLibft_GNL_Printf).

- MiniLibX: The MiniLibX library will be automatically downloaded and installed when you run the make command. Ensure you have the necessary [`prerequisites`](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html) on your machine.

1. To compile, simply run the `make` command:

```bash
make
```
``make bonus``
``make clean``
``make fclean``
``make re``

</br>
2. After compiling, run the game with the following command:
```bash
./so_long [path/to/map.ber]
```

</br>


## Disclaimer
> At 42 School, most projects must comply with the [Norm](https://github.com/42School/norminette/blob/master/pdf/en.norm.pdf).