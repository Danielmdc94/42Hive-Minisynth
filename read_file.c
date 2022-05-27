#include "minisynth.h"

static void fill_tracks(char *file, t_song *song);

void read_file(char *file, t_song *song)
{
    char *line;
    int fd;

    song->tempo = 0;
    song->n_tracks = 0;
    song->instruments = NULL;
    song->tracks = NULL;
    song->length = 0.0;
    song->sample = 0.0;
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
            }
            if (song->tempo == 0)
            {
                char **temp = ft_strsplit(line, ' ');
                song->tempo = ft_atoi(temp[1]);
                free(temp[0]);
                free(temp[1]);
                free(temp);
            }
            if (ft_atoi(line) > song->n_tracks)
                song->n_tracks = ft_atoi(line);
        }
        free(line);
    }
    fill_tracks(file, song);
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
    while (get_next_line(fd, &line) == 1)
    {
        int cur_track = ft_atoi(line) - 1;
        if (cur_track > -1 && *line != '#' && *line)
        {
            if (!song->tracks[cur_track])
                song->tracks[cur_track] = ft_strdup(line);
            else
            {
                char *temp = ft_strjoin(song->tracks[cur_track], &((line)[2]));
                free(song->tracks[cur_track]);
                song->tracks[cur_track] = temp;
            }
        }
        free(line);
    }
}
