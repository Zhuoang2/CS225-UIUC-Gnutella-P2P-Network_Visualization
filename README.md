# CS225-Final-Project
> The repository for CS225 final project for group nslfcs
> 
> Contributors: Zhuoang Tao, Qi Wu, Aoyang Li, Jiayi Zhang
>
> ![image](https://user-images.githubusercontent.com/90300558/207221148-24970280-807f-4039-aa5e-017763746312.png)
> The red point is the most important point for [this database used for creating this picture](https://snap.stanford.edu/data/p2p-Gnutella08.html)


****

### Introduction

This is the CS225 final project repository for the group nslfcs, with members Zhuoang Tao, Qi Wu, Aoyang Li, and Jiayi Zhang. Our leading question for this project is How to get and visualize the Gnutella peer-to-peer graph/network with the most important host list. To answer this question, we decide to divide it into three parts. Firstly, we will use algorithms like Dijkstra's algorithm to find the shortest path between every two vertices. Then, we will use Betweenness Centrality to measure the centrality based on the shortest paths we get in the first step and get a sorted list that contains all the vertices arranged from the most important to the least important. At last, we will visualize the graph based on the sorted list we find in the second step.

The most important thing to our project is that what we are trying to create is a "template" that can be used by any kind of graph database no matter whether the graph database is unweighted, weighted, undirected, or directed. For example, if we input the flight database or the railway database, we could get the most important airports or train stations. We could also get pictures based on those databases.

****

### Github Organization
    .
    ├── Final_project                     The main folder for the final project which contains all the codes                        
    |   ├── entry                           The folder for main.cpp
    |   |   └── main.cpp                      The main function
    |   ├── lib                             The folder for the libraries, classes, and pictures needed
    |   |   ├── cs225 and lodepng             The libraries and classes from CS225
    |   |   └── canvas and spots              The canvas and spots used for visualization
    |   ├── src                             The folder for main programs
    |   |   ├── Image                         The implementation of Image
    |   |   ├── StickerSheet                  The implementation of StickerSheet used for visualization
    |   |   ├── Final_project                 The implementation of main functions for the final project
    |   |   ├── Graph                         The implementation of graph
    |   |   └── utils                         The helper functions from mp_schedule
    |   ├── tests                           The folder for tests
    |   |   ├── empty.txt                     The empty text
    |   |   ├── smallcase.txt                 The small-case text
    |   |   ├── smallcase2.txt                The second small-case text
    |   |   ├── smallcase.png                 The output visualization picture for the small-case text
    |   |   ├── email-Eu-core.txt             The medium-case text (https://snap.stanford.edu/data/email-Eu-core.html)
    |   |   ├── email-Eu-core.png             The output visualization picture for the medium-case text
    |   |   ├── p2p-Gnutella08.txt            The large-case text (https://snap.stanford.edu/data/p2p-Gnutella08.html)
    |   |   ├── p2p-Gnutella08.png            The output visualization picture for the large-case text
    |   |   └── tests_case.cpp                The test cases
    |   └── CMakeLists.txt                  The Cmake program for compiling
    ├── Presentation Video                The folder for Presentation Video
    |   └── Presentation Video              The Presentation Video
    ├── Git_instruction.md                The instructions for Git operations
    ├── Project_Proposal.md               The proposal for the final project
    ├── README.md                         The ReadMe file
    ├── Team_Contract.md                  The Team Contract for the team
    └── results.md                        The written report for the final project
    
****

### Running Instructions

Our project use the same container as the CS225 machine problems, so you can use exactly the same way to open, build, use, and test our codes as the CS225 machine problems. Here are the detailed instructions.

1. Clown or download our project

2. Put the whole folder into CS225 folder which contains the CS225 container.

3. Open our project under the environment of the CS225 container

4. Move to the  ```Final_project``` folder with the following command

```
cd Final_project
```
5. create the ```build``` folder and move to the ```build``` folder with the following command

```
Mkdir build
cd build
```
6. run Cmake with the following command
```
cmake ..
```
7. then you can use and test our codes

We have written test suite for all of the data structures, functions, and algorithms that we implemented. We have created small,medium, and large testcases for each data structure, function, and algorithm to check their correctness and efficiency. We have also created some special testcases to test some potential side problems. So you can run our testcases by the following instructions:

1. compile the tests with the following command
```
make test
```
2. The fourth step will create an executable named test which you can execute with the following command
```
./test
```
