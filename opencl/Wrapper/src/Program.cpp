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
*   FILENAME            : Program.cpp
*
*   DESCRIPTION         : A wrapper library for OpenCL and its native counter part
*                         intialization. With boost thread support.
*
*   AUTHOR              : Mageswaran D
*
*
*   CHANGE HISTORY      :
*
*   DATE                : 17th Mar 2014
*
*   File Created.
*
* =============================================================================
*/
#include "Program.h"
namespace iv {

Program::Program(std::vector<std::string> &kernelFilePath, cl_context *context, cl_command_queue *queue, cl_device_id *device)
{
    this->_pContext     = context;
    this->_pQueue       = queue;
    this->_pDeviceID    = device;

    std::ifstream programFile(kernelFilePath[0].c_str());
    std::string programBuffer(std::istreambuf_iterator<char>(programFile),
                              (std::istreambuf_iterator<char>()));
    if(programBuffer.empty())
    {
        std::cout<<"Kernel File Not Found in specified location!"<<std::endl;
    }
    size_t   programSize = programBuffer.size();
    _program = clCreateProgramWithSource((*_pContext), 1,(const char **)&programBuffer, &programSize, &_status);
    DEBUG_CL(_status);
}

void Program::buildProgram()
{
    char *programLog;
    size_t programLogSize;
    const char options[] = "-cl-std=CL1.1 -cl-mad-enable -Werror";
    _status= clBuildProgram(_program, 1, _pDeviceID, options, NULL, NULL);
    DEBUG_CL(_status);
    if(_status<0)
    {
        clGetProgramBuildInfo(_program, *_pDeviceID, CL_PROGRAM_BUILD_LOG, 0, NULL, &programLogSize );
        programLog = (char*)malloc(sizeof(char)*programLogSize+1);
        clGetProgramBuildInfo(_program, *_pDeviceID, CL_PROGRAM_BUILD_LOG, programLogSize+1, programLog, NULL);
        printf("\nBuild Log :%s\n",programLog);
        free(programLog);
    }

    //    _kernel = clCreateKernel(_program, kernelName.c_str(), &_status);
    //    DEBUG_CL(_status);
    // Creates the kernels
    // Needs to verify if the file compiled is actually a kernel
    _status = clCreateKernelsInProgram(_program, 0, NULL, (cl_uint*)&(_numKernels));
    cl_kernel* k = new cl_kernel[_numKernels];
    _status = clCreateKernelsInProgram(_program, _numKernels, k, NULL);
    DEBUG_CL(_status);

    // Creates the hash with the kernels
    for (int i = 0; i < _numKernels; i++) {
        char name[256];
        _status = clGetKernelInfo(k[i], CL_KERNEL_FUNCTION_NAME, sizeof(char)*256, (void*) name, NULL);
        DEBUG_CL(_status);
        _kernels[name] = k[i];
        std::cout<<"Kernel No :"<<i+1<<" Name :"<<name; ///!TODO: Remove this
    }

}

KernelLauncher* Program::createKernelLauncher(std::string kernelName)
{
    ///@tips Always use a pointer to an variable that needs to be returned
    KernelLauncher *kl = new KernelLauncher(&_kernels[kernelName], _pQueue);
    return kl;
}

void Program::createKernels(std::string kernelName)
{


    //    _status = clGetKernelWorkGroupInfo(_kernel, _pDeviceID, CL_KERNEL_PREFERRED_WORK_GROUP_SIZE_MULTIPLE,
    //                                       sizeof(_perferredWrkGrpSize), &_perferredWrkGrpSize, NULL);
    //    size_t      _compileWrkGrpSize;
    //    size_t      _wrkGrpSize;
    //    cl_ulong    _localMem;
    //    cl_ulong    _privateMem;


    //    _status = clGetKernelWorkGroupInfo(_kernel, _deviceID, CL_KERNEL_WORK_GROUP_SIZE,
    //                                       sizeof(_wrkGrpSize), &_wrkGrpSize, NULL);

    //    DEBUG_CL(_status);
    //    _status = clGetKernelWorkGroupInfo(_kernel, _deviceID, CL_KERNEL_LOCAL_MEM_SIZE,
    //                                       sizeof(_localMem), &_localMem, NULL);

    //    DEBUG_CL(_status);
    //    _status = clGetKernelWorkGroupInfo(_kernel, _deviceID, CL_KERNEL_PRIVATE_MEM_SIZE,
    //                                       sizeof(_privateMem), &_privateMem, NULL);
    //    DEBUG_CL(_status);
    //    _status = clGetKernelWorkGroupInfo(_kernel, _deviceID, CL_KERNEL_COMPILE_WORK_GROUP_SIZE,
    //                                       sizeof(_compileWrkGrpSize), &_compileWrkGrpSize, NULL);
    //    DEBUG_CL(_status);

}

} //end namespace iv

