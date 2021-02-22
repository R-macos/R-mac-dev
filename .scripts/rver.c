#include <stdio.h>
#include "rver.h"

int main(int ac, char **av) {
  /* this is a work-around for broken R_SVN_REVISION in most recent (unreleased) R */
#if R_VERSION > R_Version(2,12,1)
  char buf[16], *rev;
  if (sizeof(R_SVN_REVISION) < 6) {
    snprintf(buf, sizeof(buf), "%d", (int)(long)R_SVN_REVISION);
    rev = buf;
  } else rev = (char*)R_SVN_REVISION;
  printf("%s%s)\n", R_MAJOR "." R_MINOR " " R_STATUS "<br>(" R_YEAR "/" R_MONTH "/" R_DAY ", r", rev);
#else
  /* this is how it should be */
  puts(R_MAJOR "." R_MINOR " " R_STATUS "<br>(" R_YEAR "/" R_MONTH "/" R_DAY ", r" R_SVN_REVISION ")");
#endif
    return 0;
}
