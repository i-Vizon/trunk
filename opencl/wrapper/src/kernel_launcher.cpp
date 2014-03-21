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
*   FILENAME            : KernelLauncher.cpp
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
#include "kernel_launcher.h"
namespace iv {

KernelLauncher::KernelLauncher(cl_kernel *kernel, cl_command_queue *queue)
{
    cl_int status;
    this->_pKernel = kernel;
    this->_pQueue = queue;
    this->_dimensions = -1;
    _globalWorkSize[0] = _globalWorkSize[1] = _globalWorkSize[2] =
            _localWorkSize[0] = _localWorkSize[1] = _localWorkSize[2] = -1;

    //Finding number of arguments in given kernel and making an bool array to track its data
    //content
    status = clGetKernelInfo(*_pKernel, CL_KERNEL_NUM_ARGS, sizeof(cl_int), &_numArgs, NULL);
    DEBUG_CL(status);
    this->_argListData = (cl_bool*) malloc(_numArgs*sizeof(cl_bool));//new cl_bool[numArgs];
    for(int i=0; i<_numArgs; i++)
        this->_argListData[i] = false;
}

int KernelLauncher::countArgs()
{
    int ret=0;

    for(int i=0; i<_numArgs; i++)
        if(_argListData[i])
            ret++;

    return ret;
}

void KernelLauncher::run() {
    if (countArgs() != _numArgs) {
        std::cout << "You have not enqueued enough arguments" << std::endl;
        std::cout << "Missing arguments";
        for(int i=0; i<_numArgs; i++)
            if(!_argListData[i])
                std::cout << " " << i;
        std::cout << std::endl;
        exit(-1); ///!TODO: custom return code
    }
    cl_int status = clEnqueueNDRangeKernel(*_pQueue, *_pKernel, _dimensions, NULL, _globalWorkSize, _localWorkSize, 0, NULL, NULL);
     DEBUG_CL(status);
}
KernelLauncher& KernelLauncher::global(const int g) {
    if (_dimensions == -1) _dimensions = 1;
    else if (_dimensions != 1) {
        std::cout << "Work group dimension incoherence" << std::endl;
    }
    _globalWorkSize[0] = g;
    return *this;
}

KernelLauncher& KernelLauncher::global(const int gx, const int gy) {
    if (_dimensions == -1) _dimensions = 2;
    else if (_dimensions != 2) {
        std:: cout << "Work group dimension incoherence" << std::endl;
    }
    _globalWorkSize[0] = gx;
    _globalWorkSize[1] = gy;
    return *this;
}

KernelLauncher& KernelLauncher::global(const int gx, const int gy, const int gz) {
    if (_dimensions == -1) _dimensions = 3;
    else if (_dimensions != 3) {
        std::cout << "Work group dimension incoherence" << std::endl;
    }
    _globalWorkSize[0] = gx;
    _globalWorkSize[1] = gy;
    _globalWorkSize[2] = gz;
    return *this;
}

KernelLauncher& KernelLauncher::local(const int l) {
    if (_dimensions == -1) _dimensions = 1;
    else if (_dimensions != 1) {
        std::cout << "Work group dimension incoherence" << std::endl;
    }
    _localWorkSize[0] = l;
    return *this;
}

KernelLauncher& KernelLauncher::local(const int lx, const int ly) {
    if (_dimensions == -1) _dimensions = 2;
    else if (_dimensions != 2) {
        std::cout << "Work group dimension incoherence" << std::endl;
    }
    _localWorkSize[0] = lx;
    _localWorkSize[1] = ly;
    return *this;
}

KernelLauncher& KernelLauncher::local(const int lx, const int ly, const int lz) {
    if (_dimensions == -1) _dimensions = 3;
    else if (_dimensions != 3) {
        std::cout << "Work group dimension incoherence" << std::endl;
    }
    _localWorkSize[0] = lx;
    _localWorkSize[1] = ly;
    _localWorkSize[2] = lz;
    return *this;
}

//////////////////////////
KernelLauncher* KernelLauncher::pGlobal(const int g) {
    if (_dimensions == -1) _dimensions = 1;
    else if (_dimensions != 1) {
        std::cout << "Work group dimension incoherence" << std::endl;
    }
    _globalWorkSize[0] = g;
    return this;
}

KernelLauncher* KernelLauncher::pGlobal(const int gx, const int gy) {
    if (_dimensions == -1) _dimensions = 2;
    else if (_dimensions != 2) {
        std::cout << "Work group dimension incoherence" << std::endl;
    }
    _globalWorkSize[0] = gx;
    _globalWorkSize[1] = gy;
    return this;
}

KernelLauncher* KernelLauncher::pGlobal(const int gx, const int gy, const int gz) {
    if (_dimensions == -1) _dimensions = 3;
    else if (_dimensions != 3) {
        std::cout << "Work group dimension incoherence" << std::endl;
    }
    _globalWorkSize[0] = gx;
    _globalWorkSize[1] = gy;
    _globalWorkSize[2] = gz;
    return this;
}

KernelLauncher* KernelLauncher::pLocal(const int l) {
    if (_dimensions == -1) _dimensions = 1;
    else if (_dimensions != 1) {
        std::cout << "Work group dimension incoherence" << std::endl;
    }
    _localWorkSize[0] = l;
    return this;
}

KernelLauncher* KernelLauncher::pLocal(const int lx, const int ly) {
    if (_dimensions == -1) _dimensions = 2;
    else if (_dimensions != 2) {
        std::cout << "Work group dimension incoherence" << std::endl;
    }
    _localWorkSize[0] = lx;
    _localWorkSize[1] = ly;
    return this;
}

KernelLauncher* KernelLauncher::pLocal(const int lx, const int ly, const int lz) {
    if (_dimensions == -1) _dimensions = 3;
    else if (_dimensions != 3) {
        std::cout << "Work group dimension incoherence" << std::endl;
    }
    _localWorkSize[0] = lx;
    _localWorkSize[1] = ly;
    _localWorkSize[2] = lz;
    return this;
}

} //end of namespace iv
