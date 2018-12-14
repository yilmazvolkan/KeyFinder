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

Before you go you should increase your stack limit.
Write on the terminal
```
ulimit -s 65536

```
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

## :mushroom: Examples 


<p align="center">
<a href = "https://github.com/yilmazvolkan/KeyFinder/blob/master"><img 
<img src="https://github.com/yilmazvolkan/KeyFinder/blob/master/sample1.png" width="150" height="250"></a>
</p>

• The first piggy bank has 2 keys inside it, key 1 and key 2.
• The second piggy bank doesn’t have any keys in it.
• The third piggy bank has 2 keys inside it, key 2 and key 5.
• The fourth piggy bank doesn’t have any keys in it.
• The fifth piggy bank has one key inside it, key 4.


Mahir can open all piggy banks by cracking the first and the third
piggy banks. When he cracks the first piggy bank he will have key to
the second piggy bank(key to the first piggy bank is useless because
we already cracked it). When he crakcs the third piggy bank he will
have keys to the second and the fifth piggy bank. He can open the fifth
piggy bank with the key and get the key to the fourth piggy bank.


<p align="center">
<a href = "https://github.com/yilmazvolkan/KeyFinder/blob/master"><img 
<img src="https://github.com/yilmazvolkan/KeyFinder/blob/master/sample2.png" width="150" height="250"></a>
</p>

Explanation
Every piggy bank contain the key to the next piggy bank. Mahir can
crack any of them to open all the piggy banks. As stated in the output
format any answer which satisfies the minimum number to open all
piggy banks is accepted.

## LICENCE
All Solutions licensed under [The MIT Licence](https://github.com/yilmazvolkan/KeyFinder/blob/master/LICENSE).

## COPYRIGHT
Copyright (c) 2018 [yilmazvolkan](https://github.com/yilmazvolkan).
