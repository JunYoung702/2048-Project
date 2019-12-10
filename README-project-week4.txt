# How to use lib.c

Download `lib-cross.c` and `lib-cross.h`
and move it to same derectory with your codes

## In your code

copy this code at the top of your code

```
#include "./lib-cross.h"
```

## Compiling

gcc your-code.c lib-cross.c -o program

test it with `lib-test.c`

# Caution for using

I didn't test the library in Windows