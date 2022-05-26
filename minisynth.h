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

/*-------SONG------*/
typedef struct s_song
{
    int tempo;
    int n_tracks;
    char **instruments;
    char **tracks;
    float length;
    int16_t sample;

} t_song;

/*-------NOTE------*/
typedef struct s_note
{
    float pitch;
    int octave;
    float duration;
    int alteration;
} t_note;

void read_file(char *file, t_song *song);

void build_track(SDL_AudioDeviceID audio_device, t_song *song);

void sin_wave(SDL_AudioDeviceID audio_device, t_song *song, t_note note);
void sqr_wave(SDL_AudioDeviceID audio_device, t_song *song, t_note note);
void tri_wave(SDL_AudioDeviceID audio_device, t_song *song, t_note note);
void saw_wave(SDL_AudioDeviceID audio_device, t_song *song, t_note note);

#endif
