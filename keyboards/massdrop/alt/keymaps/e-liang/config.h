#define MK_3_SPEED
#define MK_MOMENTARY_ACCEL

#define MK_C_OFFSET_0 4
#define MK_C_INTERVAL_0 16
#define MK_C_OFFSET_UNMOD 10
#define MK_C_INTERVAL_UNMOD 16
#define MK_C_OFFSET_1 20
#define MK_C_INTERVAL_1 16
#define MK_C_OFFSET_2 50
#define MK_C_INTERVAL_2 16

#define MK_W_INTERVAL_0 120
#define MK_W_INTERVAL_UNMOD 30
#define MK_W_INTERVAL_1 10
#define MK_W_INTERVAL_2 2

// HACK: These are here just so that mousekeys.c compiles
#define MOUSEKEY_DELAY              0
#define MOUSEKEY_INTERVAL           16
#define MOUSEKEY_MAX_SPEED          2
#define MOUSEKEY_TIME_TO_MAX        0
#define MOUSEKEY_WHEEL_MAX_SPEED    1
#define MOUSEKEY_WHEEL_TIME_TO_MAX  0

#undef DEBOUNCE
#define DEBOUNCE 7
