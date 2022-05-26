#include "minisynth.h"

void sin_wave(SDL_AudioDeviceID audio_device, t_song *song, t_note note)
{
    for (int i = 0; i < FREQ * note.duration; i++)
    {
        song->sample = sin(((float)i / (float)FREQ) * 2.0f * M_PI * note.pitch) * GAIN;
        SDL_QueueAudio(audio_device, &song->sample, SAMPLE_SIZE);
    }
}

void sqr_wave(SDL_AudioDeviceID audio_device, t_song *song, t_note note)
{
    for (int i = 0; i < FREQ * note.duration; i++)
    {
        song->sample = sin(((float)i / (float)FREQ) * 2.0f * M_PI * note.pitch) * GAIN;
        song->sample += 1.0 / 3.0 * sin((((float)i / (float)FREQ) * 3) * 2 * M_PI * note.pitch) * GAIN;
        song->sample += 1.0 / 5.0 * sin((((float)i / (float)FREQ) * 5) * 2 * M_PI * note.pitch) * GAIN;
        song->sample += 1.0 / 7.0 * sin((((float)i / (float)FREQ) * 7) * 2 * M_PI * note.pitch) * GAIN;
        song->sample += 1.0 / 9.0 * sin((((float)i / (float)FREQ) * 9) * 2 * M_PI * note.pitch) * GAIN;
        song->sample += 1.0 / 11.0 * sin((((float)i / (float)FREQ) * 11) * 2 * M_PI * note.pitch) * GAIN;
        SDL_QueueAudio(audio_device, &song->sample, SAMPLE_SIZE);
    }
}
void tri_wave(SDL_AudioDeviceID audio_device, t_song *song, t_note note)
{
    for (int i = 0; i < FREQ * note.duration; i++)
    {
        song->sample = (sin(((float)i / (float)FREQ) * 2.0f * M_PI * note.pitch) + 4) * GAIN;
        song->sample += (pow(3, -2) * (-sin(((float)i / (float)FREQ) * 3))) * GAIN;
        song->sample += (pow(5, -2) * (-sin(((float)i / (float)FREQ) * 5))) * GAIN;
        song->sample += (pow(7, -2) * (-sin(((float)i / (float)FREQ) * 7))) * GAIN;
        song->sample += (pow(9, -2) * (-sin(((float)i / (float)FREQ) * 9))) * GAIN;
        song->sample += (pow(11, -2) * (-sin(((float)i / (float)FREQ) * 11))) * GAIN;
        SDL_QueueAudio(audio_device, &song->sample, SAMPLE_SIZE);
    }
}
void saw_wave(SDL_AudioDeviceID audio_device, t_song *song, t_note note)
{
    for (int i = 0; i < FREQ * note.duration; i++)
    {
        song->sample = (-((1.5 * GAIN) / M_PI) * (tan(-(note.pitch * ((float)i / (float)FREQ)))));
        SDL_QueueAudio(audio_device, &song->sample, SAMPLE_SIZE);
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("usage: ./minisynth <file_name>");
        exit(-1);
    }
    char *file = argv[1];
    t_song song;
    read_file(file, &song);

    SDL_Init(SDL_INIT_AUDIO);
    SDL_AudioDeviceID audio_device;

    SDL_AudioSpec audio_spec;
    SDL_zero(audio_spec);
    audio_spec.freq = FREQ;
    audio_spec.format = AUDIO_S16SYS;
    audio_spec.channels = 1;
    audio_spec.samples = 1024;
    audio_spec.callback = NULL;

    audio_device = SDL_OpenAudioDevice(
        NULL, 0, &audio_spec, NULL, 0);

    build_track(audio_device, &song);

    SDL_PauseAudioDevice(audio_device, 0);

    SDL_Delay(song.length * 1000);

    SDL_CloseAudioDevice(audio_device);
    SDL_Quit();

    int i = 0;
    while (i < song.n_tracks)
    {
        free(song.instruments[i]);
        free(song.tracks[i]);
        i++;
    }
    free(song.instruments);
    free(song.tracks);

    return 0;
}
