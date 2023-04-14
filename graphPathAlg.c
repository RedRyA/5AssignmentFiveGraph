#include "graph.h"
#include "graphPathAlg.h"

/* printName
 * input: none
 * output: none
 *
 * Prints the name of the student who worked on this solution
 */
void printName()
{
  /* TODO : Fill in your names */
  printf("This solution was completed by:\n");
  printf("<Ryan Reddoch>\n");
}

/* OPTIONAL HELPER FUNCTION
 * buildGraph
 *
 * IMPORTANT NOTE: This is an entirely optional helper function which is only called by student implemented functions.
 * Creates a new graph to represent the given maze.
 */
Graph *buildGraph(array2D *maze, Point2D *point, Point2D start, Point2D finish /* and other parameters you find helpful */)
{
  // OPTIONAL TODO: Translate the given maze into a graph.  'X' represents impassable locations.  Only moves of up, down, left, and right are allowed.
  /* With the right parameters this can be used by all three functions below to build the graph representing their different maze problems. */
  /* HINT 1: To solve this, my solution used the functions createGraph and setEdge from graph.c */
  /* HINT 2: My solution also used createPoint from point2D.c */

  /* TODO: Replace with your graph representing maze */
}
/* hasPath
 * input: an array2D pointer to a maze
 * output: pathResult
 *
 * Detects whether a path exists from 'S' to 'F' in the graph. 'X' marks impassable regions.
 */
pathResult hasPath(array2D *maze)
{ /* hasPath
   * input: an array2D pointer to a maze
   * output: pathResult
   *
   * Detects whether a path exists from 'S' to 'F' in the graph. 'X' marks impassable regions.
   */
  int numRows = maze->length;
  int numCols = maze->width;
  int i, j;
  double dist;
  double weight = 1.0;
  Graph *g = createGraph(numRows * numCols);

  Point2D start;
  Point2D finish;
  Point2D cell;
  Point2D left;
  Point2D right;
  Point2D up;
  Point2D down;

  // loop through cells in array maze
  for (i = 0; i < numRows; i++)
  {
    for (j = 0; j < numCols; j++)
    {

      if (maze->array2D[i][j] == 'S')
      {
        start = createPoint(i, j);
      }

      if (maze->array2D[i][j] == 'F')
      {
        finish = createPoint(i, j);
      }

      if (maze->array2D[i][j] != 'X')
      {
        cell = createPoint(i, j);
        left = createPoint(i, j - 1);
        right = createPoint(i, j + 1);
        up = createPoint(i - 1, j);
        down = createPoint(i + 1, j);

        setEdge(g, cell, left, weight);
        setEdge(g, cell, right, weight);
        setEdge(g, cell, up, weight);
        setEdge(g, cell, down, weight);
      }
    }
  }

  printf(" S to F %lf \n", getEdge(g, start, finish));
  dijkstrasAlg(g, start);

  dist = getDistance(g, start, finish);

  freeGraph(g);

  if (dist == INT_MAX)
  {
    return PATH_IMPOSSIBLE;
  }
  else
  {
    return PATH_FOUND;
  }

  // TODO: Complete this function
  /* HINT 1: To solve this, my solution used the functions createGraph, freeGraph, setEdge, dijkstrasAlg, getDistance from graph.c */
  /* HINT 2: My solution also used createPoint from point2D.c */
  /* HINT 3: You might also consider using the new helper function buildGraph to build the graph representing maze. */

  /* TODO: Replace with PATH_FOUND or PATH_IMPOSSIBLE based on whether a path exists */
}

/* findNearestFinish
 * input: an array2D pointer to a maze, a pointer to an int
 * output: pathResult
 *
 * The maze contains one 'S' and multiple 'F's (1 or more).  'X' marks impassable regions.
 * Find the length of the shortest path to any 'F' from 'S' and return it in spDist.
 * If no 'F' is reachable set spDist to INT_MAX.
 */
pathResult findNearestFinish(array2D *maze, int *spDist)
{
  int numRows = maze->length;
  int numCols = maze->width;
  int i, j;
  int k = 0;
  double dist;
  double dist2;

  double weight = 1.0;
  Graph *g = createGraph(numRows * numCols);

  Point2D start;
  Point2D finish;
  Point2D cell;
  Point2D left;
  Point2D right;
  Point2D up;
  Point2D down;

  // loop through cells in array maze
  for (i = 0; i < numRows; i++)
  {
    for (j = 0; j < numCols; j++)
    {

      if (maze->array2D[i][j] == 'S')
      {
        start = createPoint(i, j);
      }

      if (maze->array2D[i][j] == 'F')
      {

        finish = createPoint(i, j);
      }

      if (maze->array2D[i][j] != 'X')
      {
        cell = createPoint(i, j);
        left = createPoint(i, j - 1);
        right = createPoint(i, j + 1);
        up = createPoint(i - 1, j);
        down = createPoint(i + 1, j);

        setEdge(g, cell, left, weight);
        setEdge(g, cell, right, weight);
        setEdge(g, cell, up, weight);
        setEdge(g, cell, down, weight);
      }
    }
  }

  dijkstrasAlg(g, start);

  // iterate through array and find f's

  for (i = 0; i < numRows; i++)
  {
    for (j = 0; j < numCols; j++)
    {
      if (maze->array2D[i][j] == 'F')
      {

        finish = createPoint(i, j);
        dist = getDistance(g, start, finish);
        printf("dissst %lf \n", dist);
        if (k == 0)
        {
          dist2 = dist;
        }
        else if (k > 0)
        {
          if (dist < dist2)
            dist2 = dist;
        }
        k++;
      }
    }
  }

  // loop through 'F' points to find shortest distance

  freeGraph(g);

  printf("dist %lf \n", dist2);
  if (dist2 == INT_MAX)
  {
    *spDist = INT_MAX;
    return PATH_IMPOSSIBLE;
  }
  else
  {
    *spDist = (int)dist2;
    return PATH_FOUND;
  }
}

// TODO: Complete this function
/* HINT 1: To solve this, my solution used the functions createGraph, freeGraph, setEdge, dijkstrasAlg, getDistance from graph.c */
/* HINT 2: My solution also used createPoint from point2D.c */
/* HINT 3: You might also consider using the new helper function buildGraph to build the graph representing maze. */
/* TODO: Replace with PATH_FOUND or PATH_IMPOSSIBLE based on whether a path exists */

/* findTunnelRoute
 * input: an array2D pointer to a maze, an int representing the number X's you can travel through
 * output: pathResult
 *
 * Detects whether a path exists from 'S' to 'F' in the graph where you pass through at most k 'X' symbols.
 */
pathResult findTunnelRoute(array2D *maze, int k)
{
  // TODO: Complete this function
  /* HINT 1: To solve this, my solution used the functions createGraph, freeGraph, setEdge, dijkstrasAlg, getDistance from graph.c */
  /* HINT 2: My solution also used createPoint from point2D.c */
  /* HINT 3: You might also consider using the new helper function buildGraph to build the graph representing maze. */


    // Calculate the number of vertices in the graph
    int numRows = maze->length;
    int numCols = maze->width;
    int numVertices = numRows * numCols;
    Point2D start;
    Point2D finish;
    Point2D cell;
    Point2D left ;
    Point2D right ;
    Point2D up;
    Point2D down;
    Point2D cellx;
    Point2D leftx;
    Point2D rightx;
    Point2D upx;
    Point2D downx;
    // Create the graph
    Graph *g = createGraph(numVertices);

    // Tunnel through k number of 'X's
    int count = 0;
    int kCount=k;
    int spaceCount=0;
    int i, j;
    printf("kCou %d \n",kCount);
    for (i = 0; i < numRows; i++)
    {
      for (j = 0; j < numCols; j++)
      {

      if (maze->array2D[i][j] == 'S')
      {
        start = createPoint(i, j);
      }
      if (maze->array2D[i][j] == 'F')
      {
        finish = createPoint(i, j);
      }
      if (maze->array2D[i][j] != 'X')
      {
      spaceCount++;
        cell = createPoint(i, j);
        left = createPoint(i, j - 1);
        right = createPoint(i, j + 1);
        up = createPoint(i - 1, j);
        down = createPoint(i + 1, j);

        setEdge(g, left, right, 1.0);
        setEdge(g, right, left, 1.0);
        setEdge(g, up, down, 1.0);
        setEdge(g, down, up, 1.0);
      }
        if (maze->array2D[i][j] == 'X')
        {
          
          while(k>0){

         
            // Connect all adjacent cells to create a tunnel
            cellx = createPoint(i, j);
            leftx = createPoint(i, j - 1);
            rightx = createPoint(i, j + 1);
            upx = createPoint(i - 1, j);
            downx = createPoint(i + 1, j);

            setEdge(g, cellx, rightx, 1.0);
            setEdge(g, cellx, leftx, 1.0);
            setEdge(g, cellx, downx, 1.0);
            setEdge(g, cellx, upx, 1.0);

          k--;
         
          }
        }
      }
    }

    // Find the shortest path from start to finish
    
    dijkstrasAlg(g, start);
    double distance = getDistance(g, start, finish);
    printf("dist %lf count= %d space= %d \n ",distance, count,spaceCount);

    // Free the graph
    freeGraph(g);

    if (distance == INT_MAX)
    {
      return PATH_IMPOSSIBLE;
    }
    else
    {
      return PATH_FOUND;
    }
}


    /* TODO: Replace with PATH_FOUND or PATH_IMPOSSIBLE based on whether a path exists */
