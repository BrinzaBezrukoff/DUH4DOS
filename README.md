# Game "DUH" (Spirit) for DOS

## Under develop
You can't find any stable release now.

## History part
33 years ago my father was learning programming.
His first computer was soviet "БК-0010" (BK-0010) and programing language there was Basic. He made a game, called "Дух" (Spirit). Main idea was to escape from the maze. Spirit on his way to exit had to pick up water jugs, avoid walls and collect coins. There was only 3 different levels, because of limited memory. Also game didn't have graphics. All my father could do in 1989 is pseudo-graphics in console.

3 years later he rewrote the game on Turbo Pascal (and on Turbo Basic) on MS-DOS. But I didn't find any sources or binaries. Seems they are completely lost. This is why I decided to recreate old game concept.

## Nowadays
In this repo you can find sources of recreated game "Spirit".
### Technical description
- Target platform: MS-DOS (but I use DOSBox emulator).
- Programming language: C/C++ (I use extension .CPP but code in C-style).
- Compiler: Turbo C++.
- Pseud-graphics in console (with conio.h support).
- Maps saving (folder LVLS) and editing (folder LEDIT).
### Technical TODO list
- Now, when something works fine, I want to start using OOP and rewrite C-style code on C++.
- With C++ styled code it will be easier to make this project cross-platform. In plans make this game working on Linux with ncurses library.
- 

## Gameplay
Main ideas:
1. Your main target is to escape from maze.
2. You should watch for watter balance (you will be able to collect water jugs to increase it).
3. You could collect coins to improve record.
4. I also want to make this an arcade game, so the plan is to make Spirit move all the time. WASD keys will only change direction. Walls are fatal for the hero.
