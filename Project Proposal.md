## Leading Question 

How to get the most important node in a given graph  (positively weighted / unweighted graph)?

How to get the shortest path between two nodes?

How to visualize a graph in 2-D plane? 

**Application Example:**  	

  Visualizing World’s Major Hub Airports

  Visualizing Internet peer-to-peer networks

  Find the most influential people in social networks
  
…

## Dataset Acquisition

## Data Format

These data sets can be found here: http://snap.stanford.edu/data/p2p-Gnutella08.html

The input format of dataset should be txt., each line containing three parameters (From Node ID, To Node ID, Weight) separated by space. 

We will use all of the data. There are about 6000 nodes and 20000 edges in this graph. 

## Data Correction

If the graph is unweighted we will treat it as a weighted graph with each edge weighing 1.


## Data Storage

  We will use positively weighted graph to store data. Specifically, the whole network is stored as a graph and nodes are individual units(can be a person, a computer, or a social account).
  
 An estimate of total storage for betweenness centrality is at most O(n^3).


## Algorithm 


**Algorithm finding the shortest path between vertices(e.g. Dijkstra's )**

Expected input: Graph & start node

Output: Two vectors whose indexes represent nodes. The first vector stores the shortest distance and the other vector stores the previous node. 

Optimal Big O: O(nlog(n)+m)

**Betweenness Centrality: to get the most important vertex in a graph**

Expected input: Graph

Output: A vector of nodes sorting by its importance in the graph

Optimal Big O: O(n^2) to O(n^3)


**Other potential algorithms:**

  Graphic Output of Graph: Visualizing a graph in 2-D plane

  BFS in graphs



## Timeline

Before mid-project checkin(week 3): Basic environment setup(Makefile etc.). Complete basic functions for shortest paths finding & betweenness centrality.

Week 4: Complete data-processing functions and choose datasets to plug in.

Week 5&6: Visualize graphs and output images.
