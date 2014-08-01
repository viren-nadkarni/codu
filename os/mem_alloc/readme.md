## Memory Allocation Simulator ##
**mem\_alloc\_sim** can simulate memory blocks being allocated by the operating system. Currently it supports first-fit, best-fit and worst-fit schemes.

### Installing and running ###
mem\_alloc\_sim is written in C and uses the ncurses library. Make sure you have it installed and depending on your platform/distribution, you may need to change the header path in main.c.

    $ gcc *.c -lncurses -o mem_alloc_sim
    $ ./mem_alloc_sim