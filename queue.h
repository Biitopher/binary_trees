#ifndef QUEUE_H
#define QUEUE_H

#include <stddef.h>
#include <stdlib.h>

typedef struct queue_node_s
{
	void *data;
	struct queue_node_s *next;
} queue_node_t;

typedef struct
{
	queue_node_t *front;
	queue_node_t *rear;
} queue_t;

queue_t *queue_create(void);
void queue_push(queue_t *queue, void *data);
void *queue_pop(queue_t *queue);
size_t queue_size(const queue_t *queue);
int queue_is_empty(const queue_t *queue);
void queue_delete(queue_t *queue);

/**
 * queue_create - Creates a queue
 * Return: Pointer to the queue
 */
queue_t *queue_create(void)
{
	queue_t *queue = (queue_t *)malloc(sizeof(queue_t));
	if (queue == NULL)
		return (NULL);

	queue->front = NULL;
	queue->rear = NULL;
	return (queue);
}

/**
 * queue_push - Pushes data to queue
 * @queue: The queue
 * @data: The data to push
 * Return: Nothing
 */
void queue_push(queue_t *queue, void *data)
{
	queue_node_t *new_node;

	if (queue == NULL)
		return;

	new_node = (queue_node_t *)malloc(sizeof(queue_node_t));
	if (new_node == NULL)
		return;

	new_node->data = data;
	new_node->next = NULL;

	if (queue->rear == NULL)
	{
		queue->front = new_node;
		queue->rear = new_node;
	}
	else
	{
		queue->rear->next = new_node;
		queue->rear = new_node;
	}
}

/**
 * queue_pop - Pos data from queue
 * @queue: The queue
 * Return: Nothing
 */
void *queue_pop(queue_t *queue)
{
	queue_node_t *temp;
	void *data;

	if (queue == NULL || queue->front == NULL)
		return (NULL);

	temp = queue->front;
	data = temp->data;

	queue->front = queue->front->next;
	if (queue->front == NULL)
		queue->rear = NULL;

	free(temp);
	return (data);
}

/**
 * queue_size - Get size of queue
 * @queue: The queue
 * Return: Returns size of queue
 */
size_t queue_size(const queue_t *queue)
{
	size_t count;
	queue_node_t *current;

	if (queue == NULL)
		return (0);

	count = 0;
	current = queue->front;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return (count);
}

/**
 * queue_is_empty - Checks if queue is empty
 * @queue: The queue
 * Return: 1 or 0
 */
int queue_is_empty(const queue_t *queue)
{
	return (queue == NULL || queue->front == NULL);
}

/**
 * queue_delete - Deletes the queue
 * @queue: The queue
 * Return: Nothing
 */
void queue_delete(queue_t *queue)
{
	if (queue == NULL)
		return;

	while (!queue_is_empty(queue))
		queue_pop(queue);

	free(queue);
}

#endif
