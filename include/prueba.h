/**
 * @file prueba.h
 * @brief API mínima del proyecto TuxLab.
 */

#ifndef TUXLAB_H
#define TUXLAB_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

    /**
     * @brief Códigos de estado básicos.
     *
     */
    typedef enum
    {
        TUXLAB_OK = 0,  ///< Operación exitosa.
        TUXLAB_ERR = -1 ///< Error en la operación.
    } tuxlab_status_t;

    /**
     * @brief Inicializa el módulo principal.
     * @return TUXLAB_OK si fue correcto, TUXLAB_ERR si falló.
     */
    tuxlab_status_t tuxlab_init(void);

    /** @brief Libera recursos del módulo. */
    void tuxlab_shutdown(void);

#ifdef __cplusplus
}
#endif

#endif /* TUXLAB_H */
