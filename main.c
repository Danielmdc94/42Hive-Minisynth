#include "minisynth.h"
#include <stdio.h>
#include <SDL.h>

void sin_wave(SDL_AudioDeviceID audio_device, t_note note)
{
    float x = 0;
    for (int i = 0; i < FREQ * note.duration; i++)
    {
        // SDL_QueueAudio expects a signed 16-bit value
        int16_t sample = sin(((float)i / (float)FREQ) * 2.0f * M_PI * note.pitch) * GAIN;
        SDL_QueueAudio(audio_device, &sample, SAMPLE_SIZE);
    }
}

void sqr_wave(SDL_AudioDeviceID audio_device, t_note note)
{
    float x = 0;
    for (int i = 0; i < FREQ * note.duration; i++)
    {
        // SDL_QueueAudio expects a signed 16-bit value
        int16_t sample = ((float)i / (float)FREQ) * 2.0f * M_PI * note.pitch * GAIN;
        SDL_QueueAudio(audio_device, &sample, SAMPLE_SIZE);
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("usage: ./minisynth <file_name>");
        exit(-1);
    }
    SDL_Init(SDL_INIT_AUDIO);

    char *file = argv[1];
    t_song song;
    read_file(file, &song);

    // the representation of our audio device in SDL:
    SDL_AudioDeviceID audio_device;

    // opening an audio device:
    SDL_AudioSpec audio_spec;
    SDL_zero(audio_spec);
    audio_spec.freq = FREQ;
    audio_spec.format = AUDIO_S16SYS;
    audio_spec.channels = 1;
    audio_spec.samples = 1024;
    audio_spec.callback = NULL;

    audio_device = SDL_OpenAudioDevice(
        NULL, 0, &audio_spec, NULL, 0);

    //-----------------------
    t_note note;
    note.duration = 0.5f;
    note.pitch = G * 16;
    t_note note2;
    note2.duration = 0.5f;
    note2.pitch = D * 16;
    t_note note3;
    note3.duration = 0.5f;
    note3.pitch = F * 16;
    t_note note4;
    note2.duration = 0.5f;
    note2.pitch = E * 16;

    sqr_wave(audio_device, note2);
    sin_wave(audio_device, note2);
    sin_wave(audio_device, note4);
    sqr_wave(audio_device, note2);
    sin_wave(audio_device, note);
    sin_wave(audio_device, note3);
    //-------------------------

    // unpausing the audio device (starts playing):
    SDL_PauseAudioDevice(audio_device, 0);

    SDL_Delay(3000);

    SDL_CloseAudioDevice(audio_device);
    SDL_Quit();

    return 0;
}
