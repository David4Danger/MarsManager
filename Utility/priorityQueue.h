/**************************************************************/
/*                                                            */
/*                                                            */
/* priorityQueue.h                                            */
/*                                                            */
/* Defines operations for a priority queue in C using a heap  */
/*                                                            */
/* By David Skudra                                            */                
/*                                                            */
/*                                                            */
/**************************************************************/


// Function pointer for a marsTask func
typedef void (*marsTask)();

typedef struct {
  int priority;
  marsTask data;
} node_t;

// Manually malloc the pq then use methods from there.
typedef struct {
  int len;
  int maxNodes;
  node_t *nodes;
} priority_queue_t;


void pq_insert (priority_queue_t *pq, 
                int priority, 
                marsTask newTask);
/**************************************************************/
/*                                                            */
/* pq_insert: Inserts a node into a priority queue.           */
/*                                                            */
/* Params:                                                    */
/*    pq - priority queue to be inserted into                 */
/*    priority - the priority of the new node                 */
/*    newTask - pointer to the a marsTask function            */
/*                                                            */
/* Returns: Nothing                                           */
/*                                                            */
/* Runtime: Inserts the node at the end of the pq and then    */
/*          performs a bubble up on each level, hence runtime */
/*          O(height of heap) = O(logn)                       */
/*                                                            */
/**************************************************************/


int pq_deleteMax (priority_queue_t *pq);
/**************************************************************/
/*                                                            */
/* pq_deleteMax: Removes the highest priority task from the   */
/*               priority queue and returns the function      */
/*               pointer 'data'                               */
/*                                                            */
/* Params:                                                    */
/*    pq - priority queue to remove the maximum node from     */
/*                                                            */
/* Returns: Function pointer to the highest priority task.    */
/*                                                            */
/* Runtime: Deletes the node at the top of the heap and then  */
/*          performs a bubble down on each level, hence       */
/*          runtime O(height of heap) = O(logn)               */
/*                                                            */
/**************************************************************/
