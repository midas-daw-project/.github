#pragma once

#include <cstdint>

namespace audio_engine {

struct TransportState {
    double playbackPositionSeconds = 0.0;
    std::uint64_t framesProcessed = 0;
};

struct TimingConfig {
    std::uint32_t sampleRate = 48000;
    std::uint32_t bufferFrames = 128;
    std::uint32_t channels = 2;
};

} // namespace audio_engine
