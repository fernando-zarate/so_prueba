#ifndef PROFILE_H
#define PROFILE_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Crea un JSON de perfil de usuario.
 * @note El caller debe liberar con free().
 * @return char* JSON NUL-terminado o NULL en error.
 */
char *create_profile_json(void);

#ifdef __cplusplus
}
#endif

#endif /* PROFILE_H */
