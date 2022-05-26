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
    note.duration = 0.5;
    note.octave = 4;
    while (song->tracks[t][i] != '\0')
    {
        if (song->tracks[t][i] == 'c' || song->tracks[t][i] == 'd' || song->tracks[t][i] == 'e' || song->tracks[t][i] == 'f' || song->tracks[t][i] == 'g' || song->tracks[t][i] == 'a' || song->tracks[t][i] == 'b' || song->tracks[t][i] == 'r')
        {
            char name = song->tracks[t][i];
            i++;
            if (ft_isdigit(song->tracks[t][i]))
            {
                note.octave = song->tracks[t][i] - '0';
                i++;
            }
            if (name == 'c')
                note.pitch = C * (pow(2, note.octave));
            if (name == 'd')
                note.pitch = D * (pow(2, note.octave));
            if (name == 'e')
                note.pitch = E * (pow(2, note.octave));
            if (name == 'f')
                note.pitch = F * (pow(2, note.octave));
            if (name == 'g')
                note.pitch = G * (pow(2, note.octave));
            if (name == 'a')
                note.pitch = A * (pow(2, note.octave));
            if (name == 'b')
                note.pitch = B * (pow(2, note.octave));
            if (name == 'r')
                note.pitch = SILENCE;
            if (song->tracks[t][i] == '/')
            {
                i++;
                temp = temp + i;
                note.duration = atof(temp) * song->tempo / 60;
                song->length = song->length + note.duration;
                temp = temp - i;
            }
            if (ft_strcmp(song->instruments[t], "sine") == 0)
                sin_wave(audio_device, song, note);
            if (ft_strcmp(song->instruments[t], "square") == 0)
                sqr_wave(audio_device, song, note);
            if (ft_strcmp(song->instruments[t], "triangle") == 0)
                tri_wave(audio_device, song, note);
            if (ft_strcmp(song->instruments[t], "saw") == 0)
                saw_wave(audio_device, song, note);
            sin_wave(audio_device, song, note);
        }
        i++;
    }
    free(temp);
}
