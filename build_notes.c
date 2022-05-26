#include "minisynth.h"

void build_track(SDL_AudioDeviceID audio_device, t_song *song)
{
    t_note note;
    int t = 0;
    int i = 0;

    //    while (t < song->n_tracks)
    //    {
    //
    //    }
    char *temp = ft_strdup(song->tracks[t]);
    note.duration = 1;
    note.octave = 4;
    while (song->tracks[t][i] != '\0')
    {
        if (song->tracks[t][i] == 'c')
        {
            i++;
            if (ft_isdigit(song->tracks[t][i]))
            {
                note.octave = song->tracks[t][i] - '0';
                i++;
            }
            note.pitch = C * (pow(2, note.octave));
            if (song->tracks[t][i] == '/')
            {
                i++;
                temp = temp + i;
                note.duration = atof(temp);
                temp = temp - i;
                printf("%f\n", note.duration);
            }
            sin_wave(audio_device, note);
        }
        if (song->tracks[t][i] == 'd')
        {
            i++;
            if (ft_isdigit(song->tracks[t][i]))
                note.octave = song->tracks[t][i] - '0';
            note.pitch = D * (pow(2, note.octave));
            sin_wave(audio_device, note);
        }
        if (song->tracks[t][i] == 'e')
        {
            i++;
            if (ft_isdigit(song->tracks[t][i]))
                note.octave = song->tracks[t][i] - '0';
            note.pitch = E * (pow(2, note.octave));
            sin_wave(audio_device, note);
        }
        if (song->tracks[t][i] == 'f')
        {
            i++;
            if (ft_isdigit(song->tracks[t][i]))
                note.octave = song->tracks[t][i] - '0';
            note.pitch = F * (pow(2, note.octave));
            sin_wave(audio_device, note);
        }
        if (song->tracks[t][i] == 'g')
        {
            i++;
            if (ft_isdigit(song->tracks[t][i]))
                note.octave = song->tracks[t][i] - '0';
            note.pitch = G * (pow(2, note.octave));
            sin_wave(audio_device, note);
        }
        if (song->tracks[t][i] == 'a')
        {
            i++;
            if (ft_isdigit(song->tracks[t][i]))
                note.octave = song->tracks[t][i] - '0';
            note.pitch = A * (pow(2, note.octave));
            sin_wave(audio_device, note);
        }
        if (song->tracks[t][i] == 'b')
        {
            i++;
            if (ft_isdigit(song->tracks[t][i]))
                note.octave = song->tracks[t][i] - '0';
            note.pitch = B * (pow(2, note.octave));
            sin_wave(audio_device, note);
        }
        if (song->tracks[t][i] == 'r')
        {
            note.pitch = SILENCE;
            sin_wave(audio_device, note);
        }
        i++;
    }
    // free(temp);
}
