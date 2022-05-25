#include "minisynth.h"

void read_file(char *file, t_song *song)
{
    char *line;
    int fd;

    song->tracks = 0;
    fd = open(file, O_RDONLY);
    if (fd < 0)
    {
        perror("File not opened)");
        exit(-1);
    }
    while (get_next_line(fd, &line) == 1)
    {
        song->tracks += 1;
        free(line);
    }
    close(fd);
    printf("%d\n", song->tracks);
}