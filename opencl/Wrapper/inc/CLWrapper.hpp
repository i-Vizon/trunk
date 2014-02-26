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

#define DEBUG_CL(err) \
            std::cout<<"line number: "<<__LINE__<<" function :"<<__func__<<"Error Name:" \
            <<get_error_string(err) \
            <<std::endl;

#define NUMBER_OF_PLATFORMS     5
#define NUMBER_OF_DEVICES       5
class CLSetup
{
public:
    void Init();
    void getPlatformID();
    void getDeviceID();
protected:
private:
    cl_int _status;
    char  *_vendorName;
    size_t _vendorNameSize;

    cl_uint _numPlatforms;
    cl_platform_id *_platformID;

    cl_uint _numDevices;
    cl_device_id *_deviceID;


    cl_context _context;

};

const char * get_error_string(cl_int err);
