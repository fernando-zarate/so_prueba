/**
 * @file main.c
 * @author fernando zarate
 * @brief this is a test code for TuxLab
 * @version 0.1
 * @date 2025-10-22
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <cjson/cJSON.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Main entry point for the application.
 *
 * @return int
 */
int main(void)
{
    /// @brief Create a JSON object representing a user profile
    cJSON *profile = cJSON_CreateObject();

    cJSON_AddStringToObject(profile, "name", "Fernando Zarate");
    cJSON_AddNumberToObject(profile, "age", 25);
    cJSON_AddBoolToObject(profile, "is_student", 1);

    /// @brief Add an array of hobbies to the profile
    cJSON *hobbies = cJSON_CreateArray();

    cJSON_AddItemToArray(hobbies, cJSON_CreateString("Reading"));
    cJSON_AddItemToArray(hobbies, cJSON_CreateString("Gaming"));

    cJSON_AddItemToObject(profile, "hobbies", hobbies);

    char *json_string = cJSON_Print(profile);
    printf("%s\n", json_string);

    cJSON_Delete(profile);
    free(json_string);

    return 0;
}
