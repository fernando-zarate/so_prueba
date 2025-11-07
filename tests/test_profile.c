#include "profile.h"
#include <cjson/cJSON.h>
#include <stdlib.h>
#include <unity.h>

void setUp(void) {}    // opcional (corre antes de cada test)
void tearDown(void) {} // opcional (corre después de cada test)

static void test_profile_json_content(void)
{
  char *json = create_profile_json();
  TEST_ASSERT_NOT_NULL(json);

  cJSON *root = cJSON_Parse(json);
  TEST_ASSERT_NOT_NULL(root);

  const cJSON *name = cJSON_GetObjectItemCaseSensitive(root, "name");
  TEST_ASSERT_NOT_NULL(name);
  TEST_ASSERT_TRUE(cJSON_IsString(name));
  TEST_ASSERT_EQUAL_STRING("Fernando Zarate", name->valuestring);

  const cJSON *age = cJSON_GetObjectItemCaseSensitive(root, "age");
  TEST_ASSERT_NOT_NULL(age);
  TEST_ASSERT_TRUE(cJSON_IsNumber(age));
  TEST_ASSERT_EQUAL_INT(25, age->valueint);

  const cJSON *is_student = cJSON_GetObjectItemCaseSensitive(root, "is_student");
  TEST_ASSERT_NOT_NULL(is_student);
  TEST_ASSERT_TRUE(cJSON_IsBool(is_student));
  TEST_ASSERT_TRUE(cJSON_IsTrue(is_student)); // true esperado

  const cJSON *hobbies = cJSON_GetObjectItemCaseSensitive(root, "hobbies");
  TEST_ASSERT_NOT_NULL(hobbies);
  TEST_ASSERT_TRUE(cJSON_IsArray(hobbies));
  TEST_ASSERT_EQUAL(2, cJSON_GetArraySize(hobbies));

  const cJSON *h0 = cJSON_GetArrayItem(hobbies, 0);
  const cJSON *h1 = cJSON_GetArrayItem(hobbies, 1);
  TEST_ASSERT_TRUE(cJSON_IsString(h0));
  TEST_ASSERT_TRUE(cJSON_IsString(h1));
  TEST_ASSERT_EQUAL_STRING("Reading", h0->valuestring);
  TEST_ASSERT_EQUAL_STRING("Gaming",  h1->valuestring);

  cJSON_Delete(root);
  free(json);
}

int main(void)
{
  UNITY_BEGIN();
  RUN_TEST(test_profile_json_content);
  return UNITY_END();
}
