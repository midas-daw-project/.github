#pragma once

#include "shared-contracts/Primitives.h"

namespace midas_core {

struct CommandPayload {
    // Placeholder for future command data.
};

struct StateQuery {
    // Placeholder for future query parameters.
};

class SubsystemInterface {
public:
    virtual ~SubsystemInterface() = default;
    virtual void initialize() = 0;
};

class EventListener {
public:
    virtual ~EventListener() = default;
    virtual void onEvent(shared_contracts::EventType event, const shared_contracts::Result& result) = 0;
};

class Facade {
public:
    virtual ~Facade() = default;
    virtual void registerSubsystem(shared_contracts::SubsystemId id, SubsystemInterface& subsystem) = 0;
    virtual bool submitCommand(shared_contracts::CommandType command, const CommandPayload& payload) = 0;
    virtual bool subscribe(shared_contracts::EventType event, EventListener& listener) = 0;
    virtual shared_contracts::Result queryState(const StateQuery& query) = 0;
};

} // namespace midas_core
