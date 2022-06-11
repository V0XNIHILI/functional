#include <stdio.h>

typedef void (*DestroyDataCallback)(void *value);

typedef struct List List;

struct List {
  void *value;
  List *next;
};

typedef void *(*MapFunction)(void *value);

/**
 * @brief Create a list object
 *
 * @param value
 * @return List*
 */
List *create_list(void *value);

/**
 * @brief Insert a value at the beginning of a list
 *
 * @param list
 * @param value
 * @return List*
 */
List *insert(List *list, void *value);

/**
 * @brief Pop a value from a list (delete it)
 *
 * @param list
 * @param index
 * @param destroy_data
 * @return List*
 */
List *pop(List *list, size_t index, DestroyDataCallback destroy_data);

/**
 * @brief Append a value at the end of a list
 *
 * @param list
 * @param value
 * @return List*
 */
List *append(List *list, void *value);

/**
 * @brief Concatenate two lists, where the second list is appended to the first
 *
 * @param list_1
 * @param list_2
 * @return List*
 */
List *concatenate(List *list_1, List *list_2);

/**
 * @brief Delete a list
 *
 * @param list
 * @param destroy_data
 */
void delete_list(List **list, DestroyDataCallback destroy_data);

/**
 * @brief Get the length of a list
 *
 * @param list
 * @return size_t
 */
size_t get_list_length(List *list);

/**
 * @brief Get an item at a specific index in a list
 *
 * @param list
 * @param index
 * @return void*
 */
void *get_list_item(List *list, size_t index);
