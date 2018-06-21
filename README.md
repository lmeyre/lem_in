# lem_in
Algorithm project where a certain amount of ants should find the best path through a labyrinth, but cannot take the same path at the same time. The algorithm should find all the best path, and split the ants in them.

**Usage**

To build:

```bash
$ make
```

To execute:

$ ./lem_in < map

A map example is displayed inside maps/ , it look like this :

15                **-> number of ants**
##start           **-> commentary used to tell wich room is the starting room of the ants**
1 23 3            **-> the name of the room, then it's x and y position ( wich is has no impact )**
2 16 7
#commentaire      **-> a simple commentary**
3 16 3
4 16 5
5 9 3
6 1 5
7 4 8
##end             **-> the end room**
0 9 5
0-4
0-6
1-3
4-3
5-2
3-5
#autre commentaire
4-2                **-> the link between rooms, there must be a path from start to end**
2-1
7-6
7-2
7-4
6-5

Output:

The output will look like this

L1-3 L2-2
L1-4 L2-5 L3-3 L4-2
L1-0 L2-6 L3-4 L4-5 L5-3 L6-2
L2-0 L3-0 L4-6 L5-4 L6-5 L7-3 L8-2
L4-0 L5-0 L6-6 L7-4 L8-5 L9-3 L10-2
L6-0 L7-0 L8-6 L9-4 L10-5 L11-3 L12-2
L8-0 L9-0 L10-6 L11-4 L12-5 L13-3 L14-2
L10-0 L11-0 L12-6 L13-4 L14-5 L15-3
L12-0 L13-0 L14-6 L15-4
L14-0 L15-0

L + number stand to say wich ant is moving, and the number N in L1-N tell wich room the ant had move into.
Each ant can only move once per round, and only to an adjacent room.
A path between two rooms can only be took by one ant at a time.

Options:

-e : Add verbosity to explain the reasons of the errors, or why the input is invalid.

$ ./lem_in -e < map

-k : Add color to ants to show the differents path they are taking

-p : Show all the differents path between start and end rooms.

-c : Show how many ants took each path. The ant aren't split equally between each path to optimize the best path avalaible.

Options can be stacked like this : $ ./lem_in -evk < map 

Note :

If executed without any map, the programm will wait for input, you can write the map yourself after launching the programm with your input.
 
 
