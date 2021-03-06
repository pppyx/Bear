// REQUIRES: preload, c_api_system
// RUN: %{compile} -o %t %s
// RUN: %{intercept} --verbose --output %t.sqlite3 -- %t
// RUN: assert_intercepted %t.sqlite3 count -ge 2
// RUN: assert_intercepted %t.sqlite3 contains -program %t
// RUN: assert_intercepted %t.sqlite3 contains -arguments ls -l

#include <stdlib.h>

int main () {
    char *const command = "ls -l";

    system(command);

    return EXIT_SUCCESS;
}
