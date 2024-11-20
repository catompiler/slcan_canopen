#ifndef CO_DOMAIN_H
#define CO_DOMAIN_H

#include <stddef.h>
#include "301/CO_ODinterface.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _S_CO_Domain {
	OD_extension_t extension; //!< Расширение CON.
	void* data; //!< Указатель на данные.
	size_t size; //!< Размер данных.
} co_domain_t;


CO_ReturnError_t co_domain_init(co_domain_t* dom, void* data, size_t size, OD_entry_t *domainEntry, uint32_t *errInfo);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CO_DOMAIN_H */
