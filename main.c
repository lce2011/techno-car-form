#define _CRT_SECURE_NO_WARNINGS

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// f(x) = -0.5 * (|x| ± x)
// -> -0.5 * (|x| + x)
// -> -0.5 * (|x| - x)
int standard_control(int direction, int speed) {
  if (-100 > direction || direction > 100) goto not_in_bound;
  if (-100 > speed || speed > 100) goto not_in_bound;

  int x = direction + speed;
  int y;

  if (x < 0) {
    y = -0.5 * (abs(x) - x) + 100;
  } else if (x >= 0) {
    y = -0.5 * (abs(x) + x) + 100;
  } else {
    assert(0 && "unreachable");
    exit(1);
  }

  return y;

not_in_bound:
  fprintf(stderr, "ERROR: either direction or speed are not in-bounds\nBound is: -100 < x < 100\n");
  exit(1);
}

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "ERROR: missing file path\n");
    exit(1);
  }
  char *file_path = argv[1];

  FILE *f = fopen(file_path, "w");
  if (f == NULL) goto error;

  for (int direction = -100; direction <= 100; direction += 10) {
    for (int speed = -100; speed <= 100; speed += 10) {
      fprintf(f, "direction = %d; speed = %d => %d\n", direction, speed, standard_control(direction, speed));
    }
  }

  fclose(f);

  return 0;

error:
  if (f) fclose(f);

  fprintf(stderr, "ERROR: something went wrong in main()\n");
  exit(1);
}
