#define _GNU_SOURCE
#include <dlfcn.h>
#include <sys/utsname.h>
#include <string.h>

typedef int (*uname_t)(struct utsname *);

int uname(struct utsname *buf) {
    static uname_t real_uname = NULL;
    if (!real_uname) {
        real_uname = (uname_t)dlsym(RTLD_NEXT, "uname");
        if (!real_uname) return -1;
    }
    int r = real_uname(buf);
    if (r == 0) {
        /* Replace the machine field with armv7l (armv7) */
        strncpy(buf->machine, "armv7l", sizeof(buf->machine) - 1);
        buf->machine[sizeof(buf->machine)-1] = '\0';
    }
    return r;
}
