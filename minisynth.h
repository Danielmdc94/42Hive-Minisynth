#ifndef MINISYNTH_H
#define MINISYNTH_H

#include "libft/libft.h"
#include "get_next_line.h"
#include <math.h>
#include <fcntl.h>
#include <stdio.h>
#include <SDL.h>

#define SAMPLE_SIZE 2
#define FREQ 44100
#define GAIN 5000

#define C 16.35
#define D 18.35
#define E 20.60
#define F 21.83
#define G 24.50
#define A 27.50
#define B 30.87
#define SILENCE 0.0

typedef struct s_song
{
    int tempo;
    int n_tracks;
    char **instruments;
    char **tracks;

} t_song;

/*-------NOTE------*/
typedef struct s_note
{
    float pitch;
    int octave;
    float duration;
    void *next;

} t_note;

void read_file(char *file, t_song *song);

#endif
