# written report
****
## Algorithms
### BFS
Our BFS function is used to find the shortest paths to all other points with a given points. We created small, medium, large testcases to test the correctness and efficiency of this function. We calculate a lot of paths by hand and test whether the algorithm can find the correct shortest paths. There are several examples in the testcases. We check its correctness by finding the number of vertices in shortest path to several other vertices. 
<img width="579" alt="381fa4e4cda6a2f2369bd2fdac34c2d" src="https://user-images.githubusercontent.com/90986475/207244276-5ba71e72-ef7c-4f20-b545-c4977605266b.png">

### Closeness Centrality
The goal of this algorithm is to find get the importance(centrality value) of each vertex in the graph. We calculate the centrality value by adding up the reciprocal of shortest distance from the vertex to all other vertices in the same component. We implement the algorithm in the BFS function using the parameter name "centrality". In test case, we calculate and print out the top ten vertices and their centrality after quick sort. 

### Quick Sort
We use quick sort algorithm to sort all vertices from largest to smallest by centrality value. In test case, we calculate and print out the top ten vertices as well as their centrality in the graph.  

****
## Conclusion
Our leading question for this project is How to get and visualize the Gnutella peer-to-peer graph/network with the most important host list. Now, with the functions and algorithms we implemented, we can successfully find the most important point from a graph database and visualize it. During this process, we encountered two problems: the first one is that our original way to determine the most important point is too slow, so we change our algorithm and implement it in a different way. Another problem is the visualization because drawing all the points in a database on one canvas and drawing lines between points are very difficult, so we only draw the top 100 points and visualize them with different colors based on their level of importance. For the problem of drawing a line, we calculate the line between two points based on their x-axis and y-axis and then paint all the pixels white on that line. For further improvements, we will find more efficient algorithms to find the most important points and better ways to visualize all the points and add point infomation on the picture.
