# lem_in
Algorithm project where a certain amount of ants should find the best path through a labyrinth, but cannot take the same path at the same time. The algorithm should find all the best path, and split the ants in them.

**Usage**
To build:

$ make
To execute:

$ ./tetrigen [option 1] [option 2] [number]
Example:

$ ./tetrigen -v -f 26
The output of this example will be a valid file of 26 tetriminos saved in test.fillit.

Options
[options #1]

-v: valid map
-i: invalid map
[options #2]

-f: write the map in a file (test.fillit)
-s: send the map directly to the stdin
[number]

Select between 1 and 26 tetriminos per file.
Credits
hqro
License
This work is published under the terms of 42 Unlicense.

