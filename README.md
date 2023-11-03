# 42_cub3d

## Description
This project consists of creating a graphic engine (ray casting) using a minimal graphic library, like it is mlx. We are asked to parse the map information from a .cub file and use it to draw a 3d maze on the screen using raycasting principles. This project is inspired by the game Wolfenstein 3D.

https://github.com/karisti/42_cub3d/assets/33479154/0649fe40-050c-450e-a249-b6e082ba63b5

## Prerequisites
- MacOS
- Mlx library

## Usage
1. `make`
2. Run `./cub3d ./maps/map4.cub` on a shell and leave it running

## Controls
| Key   | Action |
| ------------ | ------------ |
| `ESC` | exit game |
| `W` | move forward |
| `A` | move left |
| `S` | move backward |
| `D` | move right |
| `→` | turn camera to right |
| `←` | turn camera to left |

## Lessons
- Raycasting
- Mlx library
- Key hooks
- Parsing

## Resources
- [Lode's Computer Graphics Tutorial: Raycasting](https://lodev.org/cgtutor/raycasting.html "Lode's Computer Graphics Tutorial: Raycasting")
- [harm-smits MiniLibX](https://harm-smits.github.io/42docs/libs/minilibx "harm-smits MiniLibX")
- [ft_libgfx MiniLibX](https://qst0.github.io/ft_libgfx/man_mlx_loop.html "ft_libgfx MiniLibX")
- [Make Your Own Raycaster Part 1 (YouTube)](https://www.youtube.com/watch?v=gYRrGTC7GtA&ab_channel=3DSage "Make Your Own Raycaster Part 1 (YouTube)")
- [Make Your Own Raycaster Part 2 (YouTube)](https://www.youtube.com/watch?v=PC1RaETIx3Y&ab_channel=3DSage "Make Your Own Raycaster Part 2 (YouTube)")
- [Code-It-Yourself! First Person Shooter (YouTube)](https://www.youtube.com/watch?v=xW8skO7MFYw&t=1612s&ab_channel=javidx9 "Code-It-Yourself! First Person Shooter (YouTube)")
- [Radians](https://www.mathsisfun.com/geometry/images/circle-unit-radians.gif "Radians")
- [cub3D_leaks_maps_tester](https://github.com/mlaraki/cub3D_leaks_maps_tester "cub3D_leaks_maps_tester")
