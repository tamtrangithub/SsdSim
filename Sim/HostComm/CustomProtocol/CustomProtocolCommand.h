#ifndef __CustomProtocolCommand_h__
#define __CustomProtocolCommand_h__

#include "HostComm/BasicTypes.h"

class CustomProtocolInterface;

struct DownloadAndExecutePayload
{
    U8 CodeName[20];
};

union BenchmarkPayload
{
    struct
    {
        long long Duration;
        U32 NopCount;
    } Response;
};

struct SimpleFtlPayload
{
    U32 Lba;
    U32 SectorCount;
};

struct DeviceInfoPayload
{
    U32 LbaCount;
    U32 BytesPerSector;
};

union CustomProtocolCommandDescriptor
{
    DownloadAndExecutePayload DownloadAndExecute;
    BenchmarkPayload BenchmarkPayload;
    SimpleFtlPayload SimpleFtlPayload;
    DeviceInfoPayload DeviceInfoPayload;
};

typedef U32 CommandId;

struct CustomProtocolCommand
{
    enum Code
    {
        DownloadAndExecute,
        BenchmarkStart,
        BenchmarkEnd,
        Write,
        Read,
        GetDeviceInfo,
        Nop
    };

public:
    Code Command;
    CustomProtocolCommandDescriptor Descriptor;

private:
    CommandId CommandId;
    friend class CustomProtocolInterface;
};

#endif