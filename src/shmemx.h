#ifndef OSHMPI_SHMEMX_H
#define OSHMPI_SHMEMX_H

#include "shmemconf.h"

 /* Portals extensions */
double shmem_wtime(void);
char* shmem_nodename(void);

#if EXTENSION_FINAL_ABORT
#warning TODO
#endif

#if EXTENSION_COUNTING_PUT
#warning TODO
typedef char * shmem_ct_t;

void shmem_putmem_ct(shmem_ct_t ct, void *target, const void *source, size_t len, int pe);
void shmem_ct_create(shmem_ct_t *ct);
void shmem_ct_free(shmem_ct_t *ct);
long shmem_ct_get(shmem_ct_t ct);
void shmem_ct_set(shmem_ct_t ct, long value);
void shmem_ct_wait(shmem_ct_t ct, long wait_for);
#endif

#if EXTENSION_INTEL_CONTEXTS
#warning TODO
typedef char * shmem_ctx_t;

shmem_ctx_create(int num_ctx, int hint, shmem_ctx_t ctx[]);
shmem_ctx_destroy(int num_ctx, shmem_ctx_t ctx[]);

hmem_ctx_fence(shmem_ctx_t ctx);
shmem_ctx_quiet(shmem_ctx_t ctx);
shmem_ctx_barrier_all(shmem_ctx_t ctx);
shmem_ctx_barrier(shmem_ctx_t ctx, int PE_start, int logPE_stride, int PE_size, long * pSync);

shmem_ctx_putmem(shmem_ctx_t ctx, void * target, const void * source, size_t len, int pe);
shmem_ctx_getmem(shmem_ctx_t ctx, void * target, const void * source, size_t len, int pe);
/* ...AND SO FORTH */
#endif

#if EXTENSION_CRAY_INIT
#warning TODO
#endif

#if EXTENSION_CRAY_THREADS
#warning TODO
#endif

#if EXTENSION_ORNL_ASET
#warning TODO
#endif

#if EXTENSION_ORNL_NBCOLL
#warning TODO
#endif

#if EXTENSION_ORNL_NBRMA
#warning TODO
#endif

#if EXTENSION_ARMCI_STRIDED
#warning TODO
#endif

#if EXTENSION_INIT_SUBCOMM
#warning TODO
#endif

#endif /* OSHMPI_SHMEMX_H */
