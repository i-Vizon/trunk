/*
****************************************************************************
BSD License
Copyright (c) 2014, i-Vizon
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.
3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the i-Vizon.
4. Neither the name of the i-Vizon nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY Mageswaran.D ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL Mageswaran.D BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

****************************************************************************
*/
/*
* =============================================================================
*
*
*   FILENAME            : CLWrapper.h
*
*   DESCRIPTION         : A wrapper library for OpenCL and its native counter part
*                         intialization. With boost thread support.
*
*   AUTHOR              : Mageswaran D
*
*
*   CHANGE HISTORY      :
*
*   DATE                : 22th Feb 2014
*
*   File Created.
*
* =============================================================================
*/

/**
 * Enable CL_INFO_PRINT macro to see OpenCL Device and Kernel Info
 *
 */
#include <Common.h>
#include <CL/cl.h>
#include <CL/cl.hpp>

#include "Program.h"
#include "Buffer.h"

namespace iv
{


#define NUMBER_OF_PLATFORMS     5
#define NUMBER_OF_DEVICES       5
class CLSetup
{
public:
    void Init();
    void getPlatformID();
    void getDeviceID();
    void getContextnQueue();
    Program* createProgram(std::vector<std::string> &kernelFilePath);
    Buffer* createBuffer(const size_t size, const cl_mem_flags flags, void* hostMem);
    //>>>>>>>>>>>>>>>>>Get Info
    int getNumberOfPlatforms()
    {
        return _numPlatforms;
    }
    void getDeviceName()
    {
        //        clGetPlatformInfo(_platformID,CL_PLATFORM_NAME, NULL, NULL, &_infoCLSize);
        //        _infoName = (char*)malloc(sizeof(char)*_infoCLSize);
        //        clGetPlatformInfo(_platformID,CL_PLATFORM_NAME, sizeof(char) * _infoCLSize, _infoName, NULL );
        //        std::cout<<"CL_PLATFORM_NAME          : "<<_infoName<<std::endl;
        //        free(_infoName);

    }
    int getNumberOfDevices()
    {
        return _numDevices;
    }

    cl_ulong getNumberMaxComputeUnits()
    {
        return _maxComputeUnits;
    }
    size_t getPerferredWorkGroupSize()
    {
        return _perferredWrkGrpSize;
    }

protected:
private:
    //>>>>>>>>>>>>>>>>>Info Members
    cl_int          _status;
    cl_long         _infoValue;
    char*           _infoName;
    size_t          _infoCLSize;


    //>>>>>>>>>>>>>>>>>Platform Members
    cl_uint         _numPlatforms;
    cl_platform_id  _platformID;
    /**
     * @brief _platformIDsVector
     *        _platformIDsVector[interestedPlatformNum]
     */
    std::vector<cl_platform_id> _platformIDsVector; //!TODO:

    //>>>>>>>>>>>>>>>>>Device Members
    cl_uint         _numDevices;
    cl_device_id    _deviceID;
    cl_ulong        _maxComputeUnits;
    cl_ulong        _maxWorkGroupSize;
    cl_ulong        _maxMemAllocSize;
    cl_ulong        _globalMemSize;
    cl_ulong        _constMemSize;
    cl_ulong        _localMemSize;

    //>>>>>>>>>>>>>>>>>Context Members
    cl_context      _context;

    //>>>>>>>>>>>>>>>>>Queue Members
    cl_command_queue      _queue;

    //>>>>>>>>>>>>>>>>>Program Members
    cl_program      _program;

    //>>>>>>>>>>>>>>>>>Kernel Members
    cl_kernel   _kernel;
    size_t      _compileWrkGrpSize;
    size_t      _wrkGrpSize;
    size_t      _perferredWrkGrpSize;
    cl_ulong    _localMem;
    cl_ulong    _privateMem;


};

//const char * get_error_string(cl_int err);

}
/*
 *#if CL_INFO_PRINT
    {
        clGetPlatformInfo(_platformID[0],CL_PLATFORM_NAME, NULL, NULL, &_infoCLSize);
        _infoName = (char*)malloc(sizeof(char)*_infoCLSize);
        clGetPlatformInfo(_platformID[0],CL_PLATFORM_NAME, sizeof(char) * _infoCLSize, _infoName, NULL );
        std::cout<<"CL_PLATFORM_NAME          : "<<_infoName<<std::endl;

        clGetPlatformInfo(_platformID[0],CL_PLATFORM_VENDOR, NULL, NULL, &_infoCLSize);
        _infoName = (char*)malloc(sizeof(char)*_infoCLSize);
        clGetPlatformInfo(_platformID[0],CL_PLATFORM_VENDOR, sizeof(char) * _infoCLSize, _infoName, NULL );
        std::cout<<"CL_PLATFORM_info        : "<<_infoName<<std::endl;


        clGetPlatformInfo(_platformID[0],CL_PLATFORM_VERSION, NULL, NULL, &_infoCLSize);
        _infoName = (char*)malloc(sizeof(char)*_infoCLSize);
        clGetPlatformInfo(_platformID[0],CL_PLATFORM_VERSION, sizeof(char) * _infoCLSize, _infoName, NULL );
        std::cout<<"CL_PLATFORM_VERSION            : "<<_infoName<<std::endl;

        clGetPlatformInfo(_platformID[0],CL_PLATFORM_PROFILE, NULL, NULL, &_infoCLSize);
        _infoName = (char*)malloc(sizeof(char)*_infoCLSize);
        clGetPlatformInfo(_platformID[0],CL_PLATFORM_PROFILE, sizeof(char) * _infoCLSize, _infoName, NULL );
        std::cout<<"CL_PLATFORM_PROFILE            : "<<_infoName<<std::endl;

        clGetPlatformInfo(_platformID[0],CL_PLATFORM_EXTENSIONS, NULL, NULL, &_infoCLSize);
        _infoName = (char*)malloc(sizeof(char)*_infoCLSize);
        clGetPlatformInfo(_platformID[0],CL_PLATFORM_EXTENSIONS, sizeof(char) * _infoCLSize, _infoName, NULL );
        std::cout<<"CL_PLATFORM_EXTENSIONS         : "<<_infoName<<std::endl;
    }

//#if CL_INFO_PRINT
//    {
//        clGetDeviceInfo(_deviceID[0],CL_DEVICE_TYPE, NULL, NULL, &_infoCLSize);
//        _infoValue = (cl_long*)malloc(sizeof(cl_long) * _infoCLSize);
//        clGetDeviceInfo(_deviceID[0],CL_DEVICE_TYPE, sizeof(cl_long) * _infoCLSize, (cl_long*)_infoValue, NULL );
//        //std::cout<<"CL_DEVICE_TYPE          : "<<*_infoValue<<std::endl;
//        printf("CL_DEVICE_TYPE : %ld\n", *_infoValue);

//        clGetDeviceInfo((cl_device_id)_deviceID,CL_DEVICE_NAME, NULL, NULL, &_infoCLSize);
//        _infoName = (char*)malloc(sizeof(char)*_infoCLSize);
//        clGetDeviceInfo((cl_device_id)_deviceID,CL_DEVICE_NAME, sizeof(char) * _infoCLSize, _infoName, NULL );
//        std::cout<<"CL_DEVICE_NAME        : "<<_infoName<<std::endl;


//        clGetDeviceInfo((cl_device_id)_deviceID,CL_DEVICE_VENDOR_ID, NULL, NULL, &_infoCLSize);
//        _infoName = (char*)malloc(sizeof(char)*_infoCLSize);
//        clGetDeviceInfo((cl_device_id)_deviceID,CL_DEVICE_VENDOR_ID, sizeof(char) * _infoCLSize, _infoName, NULL );
//        std::cout<<"CL_DEVICE_VENDOR_ID            : "<<_infoName<<std::endl;

//        clGetDeviceInfo((cl_device_id)_deviceID,CL_DEVICE_MAX_COMPUTE_UNITS, NULL, NULL, &_infoCLSize);
//        _infoName = (char*)malloc(sizeof(char)*_infoCLSize);
//        clGetDeviceInfo((cl_device_id)_deviceID,CL_PLATFORM_PROFILE, sizeof(char) * _infoCLSize, _infoName, NULL );
//        std::cout<<"CL_DEVICE_MAX_COMPUTE_UNITS            : "<<_infoName<<std::endl;

//        clGetDeviceInfo((cl_device_id)_deviceID,CL_PLATFORM_EXTENSIONS, NULL, NULL, &_infoCLSize);
//        _infoName = (char*)malloc(sizeof(char)*_infoCLSize);
//        clGetDeviceInfo(*_deviceID,CL_PLATFORM_EXTENSIONS, sizeof(char) * _infoCLSize, _infoName, NULL );
//        std::cout<<"CL_PLATFORM_EXTENSIONS         : "<<_infoName<<std::endl;
//    }
//#endif
*/
