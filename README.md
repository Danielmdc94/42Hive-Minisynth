# 42Hive-Minisynth

Dependencies:
- SDL Library

Instructions:
- Install SDL2 library (can be done with brew: ```brew install sdl2```.
- Change the path of the SDL library and includes in the Makefile to match yours.
    *If installed with brew, use ```sdl2-config --cflags``` and ```sdl2-config --libs``` to find them.*
- ```make```
- Run with ```./minisynth <filename>```. Valid files are provided in the directory "examples"

Disclaimer:
Currently the program only plays one track at a time. You can choose the track to play changit the value of 't' in
the build_notes.c file, line 6.
