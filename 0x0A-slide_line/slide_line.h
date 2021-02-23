#ifndef SLIDE_LINE
#define SLIDE_LINE

#define SLIDE_LEFT 4
#define SLIDE_RIGHT 6

int slide_line(int *line, size_t size, int direction);

int lefty_doubler(int *line, size_t size);
int lefty_shifter(int *line, size_t size);
int righty_doubler(int *line, size_t size);
int righty_shifter(int *line, size_t size);

#endif /* SLIDE_LINE */
