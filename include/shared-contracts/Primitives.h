#pragma once

#include <cstdint>
#include <string>

namespace shared_contracts {

using ContractId = std::uint32_t;
using SubsystemId = std::uint32_t;

enum class CommandType : std::uint8_t {
    Undefined = 0,
    Initialize,
    Shutdown,
    UserDefined
};

enum class EventType : std::uint8_t {
    Undefined = 0,
    StatusChanged,
    CommandResult
};

enum class ResultCode : std::int32_t {
    Ok = 0,
    Failed = 1,
    InvalidArgument = 2
};

struct Result {
    ResultCode code = ResultCode::Ok;
    std::string message;
};

enum class ParameterType : std::uint8_t {
    Float,
    Integer,
    Boolean,
    String
};

struct ParameterDescriptor {
    std::string name;
    ParameterType type = ParameterType::Float;
    std::string defaultValue;
    std::string minValue;
    std::string maxValue;
    std::string description;
};

} // namespace shared_contracts
