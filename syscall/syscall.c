#ifdef __APPLE__
#ifdef __aarch64__
    #include "darwin_arm.c"
#else
    #include "darwin.c"
#endif
#else
    #include "linux.c"
#endif
