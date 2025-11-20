# FAKE armv7 in aarvh64

``` bash
root@host$ apk add build-base musl-dev # or apt-get install build-essential libc6-dev in "debian/ubuntu" NOT TESTED
root@host$ gcc -shared -fPIC -o libfakeuname.so fake_uname.c -ldl
root@host$ LD_PRELOAD=$PWD/libfakeuname.so /bin/uname -a
root@host$ Linux 002518F14C7A 5.10.209 # 1 SMP PREEMPT 2023-01-01T00:00:00+00:00 armv7l Linux
```

