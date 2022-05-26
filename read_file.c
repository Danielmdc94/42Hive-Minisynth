#include "minisynth.h"

static void fill_tracks(char *file, t_song *song);

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
    fill_tracks(file, song);
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
    i = 0;
    while (i < song->n_tracks)
    {
        printf("\n%s\n", song->tracks[i]);
        i++;
    }
    //---------------------------------
}

static void fill_tracks(char *file, t_song *song)
{
    char *line;
    int fd;

    fd = open(file, O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        exit(-1);
    }
    song->tracks = (char **)ft_memalloc(sizeof(char **) * song->n_tracks);
    int i = 0;
    while (get_next_line(fd, &line) == 1)
    {
        if (ft_atoi(line) > 0 && *line != '#' && *line)
        {
            song->tracks[i] = ft_strdup(line);
            i++;
        }
        free(line);
    }
}