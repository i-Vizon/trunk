/************************Using CLWrapper Class
 *  All CL programs needs to do some device and kernel specific
 *  things again and again to run an even a simple matrix addition or
 *  reduction algorithm. So I decided to write a wrapper class to minimize
 *  the work done in non-logic part of the code. And the classes are
 *  1. CLSetup Class
 *  2. Program Class
 *  3. Memory & Image Classes
 *  4. KernelLauncher Class
 *
 */
#include <CLWrapper.hpp>

#define ROWS 640
#define COLS 480
int main()
{
    iv::CLSetup         cl;
    iv::Program*        prog;
    iv::Buffer*         buff1d;
    iv::KernelLauncher* kl;


    std::vector<std::string> kernelFiles;
    kernelFiles.push_back("../../wrkGrpInfo.cl");
    float               res[ROWS * COLS];

    cl.Init();

    std::cout<<"Number of Platforms "<<cl.getNumberOfPlatforms()<<std::endl;

    cl.getDeviceName();

    std::cout<<"Number of Devices "<<cl.getNumberOfDevices()<<std::endl;
    std::cout<<"Number of Compute Units "<<cl.getNumberMaxComputeUnits()<<std::endl;

    prog = cl.createProgram(kernelFiles);
    prog->buildProgram();

    buff1d = cl.createBuffer(ROWS * COLS * sizeof(float), CL_MEM_WRITE_ONLY, NULL);

    kl = prog->createKernelLauncher("id_check");
    kl->pGlobal(ROWS,COLS)->pLocal(32,32);
    kl->pArg(buff1d->getmem());
    kl->run();

    buff1d->read(res, sizeof(float)* ROWS * COLS);

    std::cout<<"\n";
    for(int i=0; i< (ROWS * COLS); i++) {
        //              printf("%.2f     %.2f     %.2f     %.2f     %.2f     %.2f\n",
        //                 res[i], res[i+1], res[i+2], res[i+3], res[i+4], res[i+5]);
        printf("%.2f\n", res[i]);
    }

    std::cout<<"\n\nDone Testing OpenCL Wrappers!\n";
    return 0;
}

