#include "profile.h"
#include <cjson/cJSON.h>
#include <stdlib.h>

char *create_profile_json(void)
{
  cJSON *profile = cJSON_CreateObject();
  if (!profile) return NULL;

  cJSON_AddStringToObject(profile, "name", "Fernando Zarate");
  cJSON_AddNumberToObject(profile, "age", 25);
  cJSON_AddBoolToObject(profile, "is_student", 1);

  cJSON *hobbies = cJSON_CreateArray();
  if (!hobbies) { cJSON_Delete(profile); return NULL; }

  cJSON_AddItemToArray(hobbies, cJSON_CreateString("Reading"));
  cJSON_AddItemToArray(hobbies, cJSON_CreateString("Gaming"));
  cJSON_AddItemToObject(profile, "hobbies", hobbies);

  char *json_string = cJSON_PrintUnformatted(profile);
  cJSON_Delete(profile);
  return json_string;
}
