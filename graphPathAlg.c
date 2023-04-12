#include "graph.h"
#include "graphPathAlg.h"


/* printName
 * input: none
 * output: none
 *
 * Prints the name of the student who worked on this solution
 */
void printName( )
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
Graph* buildGraph( array2D* maze, Point2D* point,Point2D start,Point2D finish /* and other parameters you find helpful */  )
{
     //OPTIONAL TODO: Translate the given maze into a graph.  'X' represents impassable locations.  Only moves of up, down, left, and right are allowed. 
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
pathResult hasPath(array2D *maze )
{
  double value;
  int numRows = maze->length;
  int numCols = maze->width;
  int i;
  int j;
  double dist;
  int path;

  Point2D start;
  Point2D finish;
  Point2D left;
  Point2D right;
  Point2D up;
  Point2D down;

  Graph *g = createGraph(numRows * numCols);

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
      setEdge(g,start,finish,500);
    }
    if (maze->array2D[i][j] != 'X' )
    {
      left = createPoint(i + 1, j);
      right = createPoint(i - 1, j);
      up = createPoint(i , j + 1);
      down = createPoint(i, j - 1);

      setEdge(g, start, left, 1);
      setEdge(g, start, right, 1);
      setEdge(g, start, down, 1);
     setEdge(g,start,up,1);
      
    }
}
}
  

 dijkstrasAlg(g,start);

  dist=getDistance(g,start,finish);
  printf("%d \n",dist);
if (dist==INT_MAX){
path=PATH_IMPOSSIBLE;
}
else if(dist<INT_MAX){
  path=PATH_FOUND;
}
else
{
  path=PATH_UNKNOWN;
}
freeGraph(g);
    //TODO: Complete this function
    /* HINT 1: To solve this, my solution used the functions createGraph, freeGraph, setEdge, dijkstrasAlg, getDistance from graph.c */
    /* HINT 2: My solution also used createPoint from point2D.c */
    /* HINT 3: You might also consider using the new helper function buildGraph to build the graph representing maze. */
    

    return path; /* TODO: Replace with PATH_FOUND or PATH_IMPOSSIBLE based on whether a path exists */
}

/* findNearestFinish
 * input: an array2D pointer to a maze, a pointer to an int
 * output: pathResult
 *
 * The maze contains one 'S' and multiple 'F's (1 or more).  'X' marks impassable regions.
 * Find the length of the shortest path to any 'F' from 'S' and return it in spDist.
 * If no 'F' is reachable set spDist to INT_MAX.
 */
pathResult findNearestFinish( array2D *maze, int *spDist )
{

    //TODO: Complete this function
    /* HINT 1: To solve this, my solution used the functions createGraph, freeGraph, setEdge, dijkstrasAlg, getDistance from graph.c */
    /* HINT 2: My solution also used createPoint from point2D.c */
    /* HINT 3: You might also consider using the new helper function buildGraph to build the graph representing maze. */
    double value;
    int numRows = maze->length;
    int numCols = maze->width;
    int i;
    int j;
    double dist;
    int path;

    Point2D start;
    Point2D finish;
    Point2D left;
    Point2D right;
    Point2D up;
    Point2D down;

    Graph *g = createGraph(numRows * numCols);

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
        setEdge(g, start, finish, 1);
      }
      if (maze->array2D[i][j] != 'X')
      {
        left = createPoint(i + 1, j);
        right = createPoint(i - 1, j);
        up = createPoint(i, j + 1);
        down = createPoint(i, j - 1);

        setEdge(g, start, left, 1);
        setEdge(g, start, right, 1);
        setEdge(g, start, down, 1);
        setEdge(g, start, up, 1);
      
      }
    }
    }
    dijkstrasAlg(g, start);
    dist = getDistance(g, start, finish);
    if (dist >= INT_MAX)
    {
    // (*spDist) = INT_MAX;
    path=PATH_IMPOSSIBLE;
    }
    else
    {
    //  (*spDist) =dist;
    path=PATH_FOUND;
    }
freeGraph(g);
   // ; /* TODO: This returns your shortest path distance to any 'F' from the 'S'.  Set it to INT_MAX if no path exists. */
    
    return path; /* TODO: Replace with PATH_FOUND or PATH_IMPOSSIBLE based on whether a path exists */
}

/* findTunnelRoute
 * input: an array2D pointer to a maze, an int representing the number X's you can travel through
 * output: pathResult
 *
 * Detects whether a path exists from 'S' to 'F' in the graph where you pass through at most k 'X' symbols.
 */
pathResult findTunnelRoute( array2D *maze, int k )
{
    //TODO: Complete this function
    /* HINT 1: To solve this, my solution used the functions createGraph, freeGraph, setEdge, dijkstrasAlg, getDistance from graph.c */
    /* HINT 2: My solution also used createPoint from point2D.c */
    /* HINT 3: You might also consider using the new helper function buildGraph to build the graph representing maze. */
    double value;
    int numRows = maze->length;
    int numCols = maze->width;
    int i;
    int j;
    double dist;
    int path;

    Point2D start;
    Point2D finish;
    Point2D left;
    Point2D right;
    Point2D up;
    Point2D down;

    Graph *g = createGraph(numRows * numCols);

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
        setEdge(g,start,finish,1);
      }
      if (maze->array2D[i][j] != 'X')
      {
        left = createPoint(i + 1, j);
        right = createPoint(i - 1, j);
        up = createPoint(i, j + 1);
        down = createPoint(i, j - 1);

        setEdge(g, start, left, 1);
        setEdge(g, start, right, 1);
        setEdge(g, start, down, 1);
        setEdge(g, start, up, 1);
   
      }
    }
    }
    dijkstrasAlg(g, start);
    dist = getDistance(g, start, finish);
    if (dist == INT_MAX)
    {
      path = PATH_IMPOSSIBLE;
    }
    else
    {
      path = PATH_FOUND;
    }
freeGraph(g);
    return path; /* TODO: Replace with PATH_FOUND or PATH_IMPOSSIBLE based on whether a path exists */
}
