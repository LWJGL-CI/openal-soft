#include <stddef.h>

void *old_memcpy(void *, const void *, size_t);

#if defined(__aarch64__)
  __asm__(".symver old_memcpy,memcpy@GLIBC_2.17");
#elif defined(__arm__)
  __asm__(".symver old_memcpy,memcpy@GLIBC_2.4");
#else
  __asm__(".symver old_memcpy,memcpy@GLIBC_2.2.5");
#endif

void *__wrap_memcpy(void *dest, const void *src, size_t n) {
	return old_memcpy(dest, src, n);
}
