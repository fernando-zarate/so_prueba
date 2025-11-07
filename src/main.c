/**
 * @file main.c
 * @brief Imprime el JSON por stdout.
 */
#include "profile.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  char *json = create_profile_json();
  if (!json) {
    fprintf(stderr, "Error: no se pudo crear el JSON.\n");
    return 1;
  }
  printf("%s\n", json);
  free(json);
  return 0;
}
