#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
  printf("Input your postal code\n");
  int zip;
  if (!scanf("%d", &zip) || zip < 101000 || zip > 800999) {
    printf("Invalid input");
    exit(0);
  } else {
    char track[14] = {'0'};
    for (int i = 5; i >= 0; i--) {
      track[i] = (char)(zip % 10) + '0';
      zip /= 10;
    }
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int y = 2000;
    int two = 1;
    while (y < tm.tm_year + 1900) {
      int m = 1;
      while (m <= 12) {
        if (two < 99)
          two++;
        else
          two = 1;
        m++;
      }
      y++;
    }
    two += tm.tm_mon - 1;
    track[6] = (char)(two / 10) + '0';
    track[7] = (char)(two % 10) + '0';
    for (int j = 1; j < 99999; j++) {
      int three = j;
      for (int i = 12; i >= 8; i--) {
        track[i] = (char)(three % 10) + '0';
        three /= 10;
      }
      int four = 0;
      for (int i = 0; i < 13; i += 2) four += (track[i] - '0');
      four *= 3;
      for (int i = 1; i < 13; i += 2) four += (track[i] - '0');
      if (four % 10 == 0)
        four = 0;
      else
        four = 10 - (four % 10);
      track[13] = (char)four + '0';
      printf("%s\n", track);
      //   char link[65] = "open -a firefox -g https://www.pochta.ru/tracking#";
      //   strcat(link, track);
      //   system(link);
    }
  }
  return 0;
}
