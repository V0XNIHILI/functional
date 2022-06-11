#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "../src/list.h"

void test_create_list() {
  List *list = create_list("entry 1");

  assert(list != NULL);
  assert(strcmp(list->value, "entry 1") == 0);
  assert(list->next == NULL);

  delete_list(&list, NULL);
}

void test_list_insert() {
  List *list = create_list("entry 1");

  list = insert(list, "entry 2");

  assert(list != NULL);
  assert(strcmp(list->value, "entry 2") == 0);
  assert(list->next != NULL);
  assert(strcmp(list->next->value, "entry 1") == 0);
  assert(list->next->next == NULL);

  delete_list(&list, NULL);
}

void test_list_append() {
  List *list = create_list("entry 1");

  list = append(list, "entry 2");

  assert(list != NULL);
  assert(strcmp(list->value, "entry 1") == 0);
  assert(list->next != NULL);
  assert(strcmp(list->next->value, "entry 2") == 0);
  assert(list->next->next == NULL);

  delete_list(&list, NULL);
}

void test_delete_list() {
  List *list = create_list("entry 1");

  list = insert(list, "entry 2");

  delete_list(&list, NULL);

  assert(list == NULL);
}

int main() {
  test_create_list();
  test_list_insert();
  test_delete_list();

  printf("All tests passed\n");

  return 0;
}
