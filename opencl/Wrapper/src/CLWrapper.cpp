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

#include <CLWrapper.hpp>

void CLSetup::Init()
{
    getPlatformID();
    getDeviceID();

}

void CLSetup::getPlatformID()
{
    _status = clGetPlatformIDs(NUMBER_OF_PLATFORMS, NULL, &_numPlatforms);
    DEBUG_CL(_status);
    _platformID = (cl_platform_id *)malloc(sizeof(cl_platform_id) * _numPlatforms);
    clGetPlatformIDs(_numPlatforms, _platformID, NULL);
#if CL_INFO_PRINT
    clGetPlatformInfo(_platformID[0],CL_PLATFORM_NAME, NULL, NULL, &_vendorNameSize);
    _vendorName = (char*)malloc(sizeof(char)*_vendorNameSize);
    clGetPlatformInfo(_platformID[0],CL_PLATFORM_NAME, sizeof(char) * _vendorNameSize, _vendorName, NULL );
    std::cout<<"Platform Vendor Name Size   : "<<_vendorName<<std::endl;

    clGetPlatformInfo(_platformID[0],CL_PLATFORM_VERSION, NULL, NULL, &_vendorNameSize);
    _vendorName = (char*)malloc(sizeof(char)*_vendorNameSize);
    clGetPlatformInfo(_platformID[0],CL_PLATFORM_VERSION, sizeof(char) * _vendorNameSize, _vendorName, NULL );
    std::cout<<"Platform Version            : "<<_vendorName<<std::endl;

    clGetPlatformInfo(_platformID[0],CL_PLATFORM_PROFILE, NULL, NULL, &_vendorNameSize);
    _vendorName = (char*)malloc(sizeof(char)*_vendorNameSize);
    clGetPlatformInfo(_platformID[0],CL_PLATFORM_PROFILE, sizeof(char) * _vendorNameSize, _vendorName, NULL );
    std::cout<<"Platform Profile            : "<<_vendorName<<std::endl;

    clGetPlatformInfo(_platformID[0],CL_PLATFORM_EXTENSIONS, NULL, NULL, &_vendorNameSize);
    _vendorName = (char*)malloc(sizeof(char)*_vendorNameSize);
    clGetPlatformInfo(_platformID[0],CL_PLATFORM_EXTENSIONS, sizeof(char) * _vendorNameSize, _vendorName, NULL );
    std::cout<<"Platform Extensions         : "<<_vendorName<<std::endl;
#endif

}

void CLSetup::getDeviceID()
{
    clGetDeviceIDs(_platformID[0],CL_DEVICE_TYPE_GPU, 5, NULL, &_numPlatforms);
    std::cout<<"Number of devices available:"<<_numPlatforms<<std::endl;
    _deviceID = (cl_device_id*)malloc(sizeof(cl_device_id) * _numDevices);
    clGetDeviceIDs(_platformID[0], CL_DEVICE_TYPE_GPU, _numDevices, _deviceID, NULL);
}


const char * get_error_string(cl_int err)
{
    F_LOG;
    switch(err)
    {
    case 0: return "CL_SUCCESS";
    case -1: return "CL_DEVICE_NOT_FOUND";
    case -2: return "CL_DEVICE_NOT_AVAILABLE";
    case -3: return "CL_COMPILER_NOT_AVAILABLE";
    case -4: return "CL_MEM_OBJECT_ALLOCATION_FAILURE";
    case -5: return "CL_OUT_OF_RESOURCES";
    case -6: return "CL_OUT_OF_HOST_MEMORY";
    case -7: return "CL_PROFILING_INFO_NOT_AVAILABLE";
    case -8: return "CL_MEM_COPY_OVERLAP";
    case -9: return "CL_IMAGE_FORMAT_MISMATCH";
    case -10: return "CL_IMAGE_FORMAT_NOT_SUPPORTED";
    case -11: return "CL_BUILD_Program_FAILURE";
    case -12: return "CL_MAP_FAILURE";

    case -30: return "CL_INVALID_VALUE";
    case -31: return "CL_INVALID_DEVICE_TYPE";
    case -32: return "CL_INVALID_PLATFORM";
    case -33: return "CL_INVALID_DEVICE";
    case -34: return "CL_INVALID_mContext";
    case -35: return "CL_INVALID_mQueue_PROPERTIES";
    case -36: return "CL_INVALID_COMMAND_mQueue";
    case -37: return "CL_INVALID_HOST_PTR";
    case -38: return "CL_INVALID_MEM_OBJECT";
    case -39: return "CL_INVALID_mIMAGE_FORMAT_DESCRIPTOR";
    case -40: return "CL_INVALID_mIMAGE_SIZE";
    case -41: return "CL_INVALID_SAMPLER";
    case -42: return "CL_INVALID_BINARY";
    case -43: return "CL_INVALID_BUILD_OPTIONS";
    case -44: return "CL_INVALID_mProgram";
    case -45: return "CL_INVALID_mProgram_EXECUTABLE";
    case -46: return "CL_INVALID_KERNEL_NAME";
    case -47: return "CL_INVALID_KERNEL_DEFINITION";
    case -48: return "CL_INVALID_KERNEL";
    case -49: return "CL_INVALID_ARG_mINDEX";
    case -50: return "CL_INVALID_ARG_VALUE";
    case -51: return "CL_INVALID_ARG_SIZE";
    case -52: return "CL_INVALID_KERNEL_ARGS";
    case -53: return "CL_INVALID_WORK_DIMENSION";
    case -54: return "CL_INVALID_WORK_GROUP_SIZE";
    case -55: return "CL_INVALID_WORK_mITEM_SIZE";
    case -56: return "CL_INVALID_GLOBAL_OFFSET";
    case -57: return "CL_INVALID_EVENT_WAIT_LIST";
    case -58: return "CL_INVALID_EVENT";
    case -59: return "CL_INVALID_OPERATION";
    case -60: return "CL_INVALID_GL_OBJECT";
    case -61: return "CL_INVALID_mBuffer_SIZE";
    case -62: return "CL_INVALID_MIP_LEVEL";
    case -63: return "CL_INVALID_GLOBAL_WORK_SIZE";
    default: return "Unknown OpenCL error";
    }
}
