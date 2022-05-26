#include "minisynth.h"

void read_file(char *file, t_song *song)
{
    char *line;
    int fd;

    song->tempo = 0;
    song->n_tracks = 0;
    song->instruments = NULL;
    fd = open(file, O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        exit(-1);
    }
    while (get_next_line(fd, &line) == 1)
    {
        if (*line != '#' && *line)
        {
            if (song->tempo != 0 && song->instruments == NULL)
            {
                char **temp = ft_strsplit(line, ' ');
                song->instruments = ft_strsplit(temp[1], ',');
                free(temp[0]);
                free(temp[1]);
                free(temp);
                song->n_tracks -= 1;
            }
            if (song->tempo == 0)
            {
                char **temp = ft_strsplit(line, ' ');
                song->tempo = ft_atoi(temp[1]);
                free(temp[0]);
                free(temp[1]);
                free(temp);
                song->n_tracks -= 1;
            }
            song->n_tracks += 1;
        }
        free(line);
    }
    // TEST PRINT----------------------
    close(fd);
    printf("%d\n", song->tempo);
    printf("%d\n", song->n_tracks);
    int i = 0;
    while (i < song->n_tracks)
    {
        printf("%s, ", song->instruments[i]);
        i++;
    }
    //---------------------------------
}