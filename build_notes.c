#include "minisynth.h"

build_note(t_song *song)
{
    t_note note;
    int t = 0;
    int i = 0;
    //    while (t < song->n_tracks)
    //    {
    //
    //    }
    note.duration = 0.5;
    note.octave = 4;
    while (tracks[t][i] != '\0')
    {
        if (tracks[t][i] == 'c')
        {
            note.pitch = C * (pow(2, note.octave));
        }
    }
}