# written report
****
### Algorithms


****
### Conclusion
Our leading question for this project is How to get and visualize the Gnutella peer-to-peer graph/network with the most important host list. Now, with the functions and algorithms we implemented, we can successfully find the most important point from a graph database and visualize it. During this process, we encountered two problems: the first one is that our original way to determine the most important point is too slow, so we change our algorithm and implement it in a different way. Another problem is the visualization because drawing all the points in a database on one canvas and drawing lines between points are very difficult, so we only draw the top 100 points and visualize them with different colors based on their level of importantness. To the problem of drawing line, we caluate the line between two points based on their x-axis and y-axis and then paint all the pixels white on that line. For the further improvements
