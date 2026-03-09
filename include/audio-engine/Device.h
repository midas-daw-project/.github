#pragma once

#include <cstddef>
#include <cstdint>
#include "audio-engine/Transport.h"

namespace audio_engine {

struct DeviceConfig {
    std::uint32_t sampleRate = 48000;
    std::uint32_t bufferFrames = 128;
    std::uint32_t channels = 2;
};

struct BufferSpan {
    float* data = nullptr;
    std::size_t frames = 0;
    std::size_t channels = 0;
};

class AudioCallback {
public:
    virtual ~AudioCallback() = default;
    virtual void onProcess(const BufferSpan& buffer, const TransportState& transport) = 0;
};

class AudioDevice {
public:
    virtual ~AudioDevice() = default;
    virtual bool open(const DeviceConfig& config) = 0;
    virtual bool start() = 0;
    virtual void stop() = 0;
    virtual void close() = 0;
    virtual void setCallback(AudioCallback& callback) = 0;
};

} // namespace audio_engine
