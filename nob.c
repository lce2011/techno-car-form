#include <stdio.h>
#include <string.h>
#define NOB_IMPLEMENTATION
#include "nob.h"

int main(int argc, char **argv) {
  NOB_GO_REBUILD_URSELF(argc, argv);

  Cmd cmd = {0};

  nob_cc(&cmd);
  nob_cc_flags(&cmd);

  #ifdef _WIN32
    nob_cc_output(&cmd, "./main.exe");
  #else
    nob_cc_outupt(&cmd, "./main");
  #endif

  nob_cc_inputs(&cmd, "./main.c");
  if (!cmd_run_sync_and_reset(&cmd)) return 1;

  if (argc > 1) {
    if (strcmp(argv[1], "run") == 0) {
      if (argc != 3) {
        fprintf(stderr, "ERROR: missing filepath or more than one filepath given\n");
        return 1;
      } else {
        #ifdef _WIN32
          nob_cmd_append(&cmd, "./main.exe", argv[2]);
        #else
          nob_cmd_append(&cmd, "./main", argv[2]);
        #endif
        if (!cmd_run_sync_and_reset(&cmd)) return 1;
      }
    } else {
      fprintf(stderr, "ERROR: unknown subcommand: %s\n", argv[1]);
      return 1;
    }
  }

  return 0;
}
