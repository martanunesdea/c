# c
Going back to basics with 30 days of programming in C. Starting off with the most elementary data structures and algorithms, then moving on to scheduler programs and cryptography!

## Repository structure
To perserve my sanity and follow a certain order, I'm currently following Skienna's "The Algorithm Design Manual" and Sedgwick's "Algorithms in C". Since the code introduced in the books is provided as loose code blocks, I have organised each topic in its own source file, with a corresponding header file so it can be ported to future algorithm implementations.
1. Data Structures:
This folder stores the implementations of the most common data structures: arrays, linked lists, stacks, queues, hash tables and trees. The folder of trees comprises binary search trees, balanced BSTs and heaps.
2. Sorting:
This folder contains a few popular sorting algorithms (mergesort, quicksort, etc.). 
3. Searching:
This folder contains common search algorithms (sequential search, binary search, etc).
3. Graph algorithms:
This folder is organised in the following structure:
    - *graphs.c* includes adjacency lists as implemented in Skiena's manual.
    - *traversal.c* includes BFS, DFS and some applications.
    - *minimum_spanning_trees.c* includes Prim's and Kruskal's algorithms. 
    - *shortest_path.c* includes Dijkstra's algorithm.

Two additional folders store less relevant material: the "Sedgewick" folder is the implementation of adjancacy matrices and lists as seen in Sedgewick "Algorithm in C". The "alternative" folder stores some other implementations I've seen online and wanted to test and compare.

Feel free to pull this repository and use it for your own practice, or to edit and contribute with additional implementations.
