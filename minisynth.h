#ifndef MINISYNTH_H
#define MINISYNTH_H

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

/*-------NOTE------*/
typedef struct s_note
{
    float pitch;
    int octave;
    float duration;

} t_note;

#endif
