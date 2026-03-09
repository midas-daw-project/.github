#pragma once

#include <cstdint>
#include "shared-contracts/Primitives.h"

namespace mixer_engine {

struct ChannelState {
    shared_contracts::ContractId id = 0;
    float gain = 1.0f;
    float pan = 0.0f;
    bool mute = false;
    bool solo = false;
};

struct BusState {
    shared_contracts::ContractId id = 0;
    float gain = 1.0f;
};

struct Route {
    shared_contracts::ContractId sourceId = 0;
    shared_contracts::ContractId destinationId = 0;
    float gain = 1.0f;
};

struct InsertSlot {
    std::uint32_t index = 0;
    shared_contracts::ContractId processorId = 0;
};

enum class MeterType : std::uint8_t {
    Peak,
    RMS
};

struct MeterSource {
    shared_contracts::ContractId id = 0;
    MeterType type = MeterType::Peak;
};

} // namespace mixer_engine
