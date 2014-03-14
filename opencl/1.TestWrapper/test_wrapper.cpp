#include <CLWrapper.hpp>

int main()
{
    CLSetup ivcl;
    ivcl.Init();
    std::cout<<"Number of Platforms "<<ivcl.getNumberOfPlatforms()<<std::endl;
    ivcl.getDeviceName();
    std::cout<<"Number of Devices "<<ivcl.getNumberOfDevices()<<std::endl;
    std::cout<<"Number of Compute Units "<<ivcl.getNumberMaxComputeUnits()<<std::endl;
    ivcl.createProgram("../rotation.cl");
    ivcl.buildProgram();
    std::cout<<"Done!\n";
    return 0;
}

