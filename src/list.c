#include "list.h"

#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

const size_t MAX_SIZE_T = (size_t)-1;

List *create_list(void *value) {
  List *list = malloc(sizeof *list);

  assert(list != NULL);

  list->value = value;
  list->next = NULL;

  return list;
}

List *insert(List *list, void *value) {
  assert(list != NULL);

  List *new_list = malloc(sizeof *new_list);

  assert(new_list != NULL);

  new_list->value = value;
  new_list->next = list;

  return new_list;
}

List *pop(List *list, size_t index, DestroyDataCallback destroy_data) {
  assert(list != NULL);

  size_t current_index = 0;

  List *previous_list = list;
  List *current_list = list->next;

  while (current_list != NULL) {
    if (current_index == index)
      break;

    current_index++;

    previous_list = current_list;
    current_list = current_list->next;
  }

  if (current_index != index) {
    fprintf(stderr, "List index out of range");
    exit(1);
  }

  // TODO: think about how to handle the case where the list only has one item
  previous_list->next = current_list->next;

  if (destroy_data != NULL)
    destroy_data(current_list->value);

  free(current_list);

  return list;
}

List *append(List *list, void *value) {
  assert(list != NULL);

  List *new_list = create_list(value);

  List *final_list = list;

  while (final_list->next != NULL) {
    final_list = final_list->next;
  }

  final_list->next = new_list;

  return list;
}

List *concatenate(List *list_1, List *list_2) {
  assert(list_1 != NULL);
  assert(list_2 != NULL);

  List *final_list = list_1;

  while (final_list->next != NULL) {
    final_list = final_list->next;
  }

  final_list->next = list_2;

  return list_1;
}

void delete_list(List **list, DestroyDataCallback destroy_data) {
  assert(*list != NULL);

  List *current_list = *list;

  while (current_list != NULL) {
    if (destroy_data != NULL)
      destroy_data(current_list->value);

    List *previous_list = current_list;
    current_list = current_list->next;

    free(previous_list);
  }

  *list = NULL;
}

size_t get_list_length(List *list) {
  assert(list != NULL);

  size_t length = 0;

  List *current_list = list;

  while (current_list != NULL) {
    length++;

    current_list = current_list->next;

    if (length == MAX_SIZE_T) {
      fprintf(stderr, "List length is larger than MAX_SIZE_T\n");
      exit(1);
    }
  }

  return length;
}

void *get_list_item(List *list, size_t index) {
  assert(list != NULL);

  size_t current_index = 0;

  List *current_list = list;

  while (current_list != NULL) {
    if (current_index == index)
      return current_list->value;

    current_index++;

    current_list = current_list->next;
  }

  fprintf(stderr, "List index out of range");
  exit(1);
}
