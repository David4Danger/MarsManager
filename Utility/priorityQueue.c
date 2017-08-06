#include <stdio.h>
#include <stdlib.h>
#include "priorityQueue.h"

void pq_insert (priority_queue_t *pq, 
                int priority, 
                marsTask newTask)
/**************************************************************/
/*                                                            */
/* pq_insert: See header                                      */
/*                                                            */
/* Params:                                                    */
/*    pq - priority queue to be inserted into                 */
/*    priority - the priority of the new node                 */
/*    newTask - pointer to the a marsTask function            */
/*                                                            */
/* Returns: Nothing                                           */
/*                                                            */
/**************************************************************/
{
  if ((pq->len +1) >= pq->maxNodes) {
    if (!pq->maxNodes) {
      pq->maxNodes = 2;//room for empty A[0] and root node
    } else {
      pq->maxNodes = pq->maxNodes * 2;
    }
    pq->nodes = (node_t*)realloc(pq->nodes, pq->maxNodes * sizeof(node_t));
  }

  // For 'heap' array, let A[1] be the root and continue level by level
  // from left to right. This produces the following rules:
  // The left child (if it exists) of any node A[i] is at A[2i]
  // The right child (if it exists) of any node A[i] is at A[2i+1]
  // The parent (if it exists) of any node A[i] is at A[floor((i-1)/2)]
  
  int i = pq->len + 1;//Start at bottom right most position in heap
  int j = i / 2;//Index of A[i] parent
  while ((i > 1) && priority < pq->nodes[j].priority) {
    pq->nodes[i] = pq->nodes[j];
    i = j;
    j = i / 2;
  }
  
  pq->nodes[i].priority = priority;
  pq->nodes[i].data = newTask;
  pq->len += 1;
}

int pq_deleteMax (priority_queue_t *pq)
/**************************************************************/
/*                                                            */
/* pq_deleteMax: See header                                   */
/*                                                            */
/* Params:                                                    */
/*    pq - priority queue to remove the maximum node from     */
/*                                                            */
/* Returns: Function pointer to the highest priority task.    */
/*                                                            */
/**************************************************************/
{
  if (!pq->len) {
    printf("Tried to pop from an empty priority queue!\n");
    return 0;
  }

  int max = pq->nodes[1].priority;
  pq->nodes[1] = pq->nodes[pq->len];//move last node to top of the heap
  pq->len -= 1;

  int i = 1;//current index
  int j, childInd;//index to swap with i after each iteration

  while (1) {
    j = i;
    childInd = i * 2;
    if ((childInd <= pq->len) && (pq->nodes[childInd].priority < pq->nodes[j].priority)) {
      j = childInd;
    }

    if ((childInd + 1 <= pq->len) && (pq->nodes[childInd + 1].priority < pq->nodes[j].priority)) {
      j = childInd + 1;
    }
  
    if (j == i) {//no swaps left, bubble down complete
      break;
    } else {//perform the swap, no temp needed as the moving val is still in len+1
      pq->nodes[i] = pq->nodes[j];
      pq->nodes[j] = pq->nodes[pq->len+1];
      i = j;
    }
  }
  return max;
}

void samplefunc () {
  ;
}

int main () {
  priority_queue_t *taskQ = (priority_queue_t*)calloc(1,sizeof(priority_queue_t));
  taskQ->len = 0;
  taskQ->maxNodes = 0;
  pq_insert(taskQ, 5, &samplefunc);
  pq_insert(taskQ, 4, &samplefunc);
  pq_insert(taskQ, 8, &samplefunc);
  pq_insert(taskQ, 2, &samplefunc);
  pq_insert(taskQ, 6, &samplefunc);
  pq_insert(taskQ, 3, &samplefunc);
  pq_insert(taskQ, 1, &samplefunc);
  pq_insert(taskQ, 9, &samplefunc);
  int i, j;
  for (i = 1; i < 9; i++) {
    printf("%d ", taskQ->nodes[i].priority);
  }
  printf("\n");
  for (i = 1; i < 9; i++) {
    pq_deleteMax(taskQ);
    for (j = 1; j < (9 - i); j++) {
      printf("%d ", taskQ->nodes[j].priority);
    }
    printf("\n");
  }
  return 0;
}
