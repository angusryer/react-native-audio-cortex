#include "react-native-audio-cortex.h"
#include <oboe/Oboe.h>

namespace audiocortex
{
	double multiply(double a, double b)
	{
		return a * b;
	}

	class AudioInputCallback : public oboe::AudioStreamCallback
	{
	public:
		oboe::DataCallbackResult onAudioReady(oboe::AudioStream *oboeStream, void *audioData, int32_t numFrames) override
		{
			// Process the audio data here
			return oboe::DataCallbackResult::Continue;
		}

		void onErrorBeforeClose(oboe::AudioStream *oboeStream, oboe::Result error) override
		{
			// Handle errors here
		}

		void onErrorAfterClose(oboe::AudioStream *oboeStream, oboe::Result error) override
		{
			// Handle errors here
		}
	};

	std::unique_ptr<oboe::AudioStream> audioStream;
	AudioInputCallback audioInputCallback;

	void setupAudioStream()
	{
		oboe::AudioStreamBuilder builder;
		builder.setDirection(oboe::Direction::Input);
		builder.setPerformanceMode(oboe::PerformanceMode::LowLatency);
		builder.setInputPreset(oboe::InputPreset::VoiceRecognition);
		builder.setSampleRate(48000);
		builder.setChannelCount(1);
		builder.setFormat(oboe::AudioFormat::Float);
		builder.setCallback(&audioInputCallback);

        oboe::AudioStream *tempStream;
        oboe::Result result = builder.openStream(&tempStream);
        if (result != oboe::Result::OK) {
            // Handle errors
            return;
        }
        audioStream.reset(tempStream);

		// Start the audio stream
		audioStream->requestStart();
	}

}
