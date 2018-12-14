# KeyFinder

## :tophat: Introduction

Mahir earns money doing freelance jobs and keeps his money in piggy
banks. After some time, he realizes that he has a considerable
amount of money and becomes paranoid that someone might steal his money.
He starts putting his keys of piggy banks inside the piggy banks. One
day his roommate tells him about cryptocurrencies and he decides to invest
in Bitcoin. To do that he needs to open all piggy banks. Initially, Mahir
doesn’t have any key which is not inside a piggy bank. Your job is to decide
which piggy banks should be cracked so that Mahir can open all piggy banks
and the number of cracked piggy banks is minimized.

We should find the number of Strongly connected components in the created graph. 
In the mathematical theory of directed graphs, a graph is said to be strongly connected if every vertex is 
reachable from every other vertex. Therefore, if we can crack one member of SCC, we can crack all other members in that particular SCC.
Tarjan's algorithm is used to find the different SCC's. Afterwards we unite this SCC structure into one node in order to create a new tree
which includes all SCC's and has no cycles inside it. The number of required cracked piggy banks is the number of nodes in this new graph.


## :flashlight: How to compile

In a terminal, call commands:
```
>cmake CMakeLists.txt
>make

OR

>cmake CMakeLists.txt && make

```
Make sure the executable is produced.

Then you can test the project with the command:
```
>./KeyFinder inputFile.txt outputFile.txt
```

## :arrow_heading_up: Input Format
The first line of the input file holds an integer, N, showing the number
of piggy banks.


In the following N lines, information about a piggy bank is given, one per
line. Information includes a number K which indicates the number of keys
inside the piggy bank followed by key types separated by space.


## :arrow_heading_down: Output Format

In a single line print the number of piggy banks he should crack followed
by which ones he should crack.


## LICENCE
All Solutions licensed under [The MIT Licence](https://github.com/yilmazvolkan/KeyFinder/blob/master/LICENSE).

## COPYRIGHT
Copyright (c) 2018 [yilmazvolkan](https://github.com/yilmazvolkan).
