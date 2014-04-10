#include <iostream>
#include <cl_wrapper.hpp>
#include <opencv/cv.h>
#include <opencv2/highgui/highgui.hpp>
#include<opencv2/core/core.hpp>

#define NO_CONVOLUTION
int main()
{
    std::cout << "Image Convolution Test!" << std::endl;

    //CL Variables
    iv::CLSetup cl;
    iv::Program* prog;
    iv::KernelLauncher* kl;
    std::vector<std::string> kernelFiles;
    std::string kernelFile = "image_convolution.cl";
    kernelFiles.push_back(kernelFile);

    cl.init();

    //Image Convolution Varaibles
    cv::Mat jpegFile;
    jpegFile = cv::imread("shiva.jpg");
    std::cout<<"Image Size :"<<jpegFile.size()<<"\n";
    cv::cvtColor(jpegFile, jpegFile, CV_BGR2GRAY);
    cv::imshow("GrayScale Image", jpegFile);
    std::cout<<"Total Pixels in File: "<<jpegFile.total()<<"\n";
    std::cout<<"Pixel Data Type :"<<jpegFile.type()<<"\n";
    std::cout<<"Step Value :"<<jpegFile.step<<"\n";
    std::cout<<"Element Size :"<<jpegFile.elemSize()<<"\n";
    std::cout<<"Num of Channels :"<<jpegFile.channels()<<"\n";
    std::cout<<"Num of cols (cols * channesl) :"<<jpegFile.cols * jpegFile.channels()<<"\n";
    cv::waitKey();

    // The image format describes how the data will be stored in memory
    cl_image_format format;
    format.image_channel_order     = CL_R;     // single channel
    format.image_channel_data_type = CL_UNORM_INT8; // UCHAR data type

    // Copy the source image to the device
    iv::Image2D* dSourceImage = cl.createImage2D(jpegFile.size().width,
                                                 jpegFile.size().height,
                                                 0, CL_MEM_READ_ONLY |
                                                 CL_MEM_COPY_HOST_PTR,
                                                 &format, jpegFile.data);
    // Offset within the image to copy from
    size_t origin[3] = {0, 0, 0};
    // Elements to per dimension
    size_t region[3] = {jpegFile.size().width, jpegFile.size().height, 1};

    //dSourceImage->write(jpegFile.data, region, origin);

    iv::Image2D* dOutputImage = cl.createImage2D(jpegFile.size().width,
                                                 jpegFile.size().height,
                                                 0, CL_MEM_WRITE_ONLY,
                                                 &format, NULL);

    // 45 degree motion blur
    int filter[49] =
    {0,      0,      0,      0,      0,      0,      0,
     0,      0,      0,      0,      0,      0,      0,
     0,      0,     -1,      0,      1,      0,      0,
     0,      0,     -2,      0,      2,      0,      0,
     0,      0,     -1,      0,      1,      0,      0,
     0,      0,      0,      0,      0,      0,      0,
     0,      0,      0,      0,      0,      0,      0};
    // The convolution filter is 7x7
    int filterWidth = 7;
    int filterSize  = filterWidth*filterWidth;  // Assume a square kernel
    iv::Buffer* dFilter = cl.createBuffer(filterSize * sizeof(int),
                                          CL_MEM_READ_ONLY |
                                          CL_MEM_COPY_HOST_PTR, filter);

    iv::Sampler* sampler = cl.createSampler(CL_FALSE,
                                            CL_ADDRESS_CLAMP_TO_EDGE,
                                            CL_FILTER_NEAREST);
    prog = cl.createProgram(kernelFiles);
    prog->buildProgram();

#ifdef NO_CONVOLUTION
    kl = prog->createKernelLauncher("imgRW");
    kl->pGlobal(jpegFile.size().width, jpegFile.size().height)
      ->pLocal(4,4);
    kl->pArg(dSourceImage->getMem())
      ->pArg(dOutputImage->getMem())
      ->pArg(sampler->getSampler());
#else if
    int height = jpegFile.size().height;
    int width = jpegFile.size().width;
    kl = prog->createKernelLauncher("convolution");
    kl->pGlobal(jpegFile.size().width, jpegFile.size().height)->pLocal(16,16);
    kl->pArg(dSourceImage->getMem())
            ->pArg(dOutputImage->getMem())
            ->pArg(height)
            ->pArg(width)
            ->pArg(dFilter->getMem())
            ->pArg(sampler->getSampler())
            ->pArg(filterSize);
#endif
    std::cout<<"ddddddddddd\n";
    kl->run();
    std::cout<<"ddddddddddd\n";

    cv::waitKey();
    dOutputImage->read(jpegFile.data, region, origin);
    cv::imshow("Final", jpegFile);
    cv::waitKey();

   //std::cout<<"After cl intDataPtr Data: "<<jpegFile<<"\n";

    delete dSourceImage;
    delete dOutputImage;
    return 0;
}

//// FLOAT
///
//float* pixelData = new float[jpegFile.total() * jpegFile.channels()];
////uchar* pixelData = (uchar*)malloc(jpegFile.total() * sizeof(uchar));
//int c = 0;
//for (int y = 0; y < jpegFile.rows; ++y)
//{
//  for (int x = 0; x < (jpegFile.cols * jpegFile.channels() ); ++x)
//  {
//          pixelData[y * (jpegFile.cols * jpegFile.channels())+ x ] = jpegFile.data[y * (jpegFile.cols * jpegFile.channels())+ x ];
//          printf("%d, ",  pixelData[y * (jpegFile.cols * jpegFile.channels())+ x ]);
//          ++c;
//  }
//  printf("\n");
//}
//std::cout<<"\n\n\n0. Done: Number of Pixels: "<<c<<": \n\n\n\n\n";
//// return 0;

//cv::Mat intDataPtr(jpegFile.size(), CV_32FC4, pixelData, jpegFile.step);
//std::cout<<"Type: "<<intDataPtr.type()<<"\n";
//// std::cout<<"intDataPtr Data: "<<intDataPtr<<"\n";
//cv::imshow("intDataPtr", intDataPtr);
//cv::waitKey();



//    uchar* pixelData = new uchar[jpegFile.total() * jpegFile.channels()];
//    //uchar* pixelData = (uchar*)malloc(jpegFile.total() * sizeof(uchar));

//    for (int y = 0; y < jpegFile.rows; ++y)
//      for (int x = 0; x < (jpegFile.cols * jpegFile.channels() ); ++x)
//      {
//              pixelData[y * (jpegFile.cols * jpegFile.channels())+ x ] = jpegFile.data[y * (jpegFile.cols * jpegFile.channels())+ x ];
//             // printf("%d ", jpegFile.data[y * jpegFile.cols + x ]);
//      }
//   // std::cout<<"\n\n\n0. Done\n\n\n\n\n";
//   // return 0;

//    cv::Mat intDataPtr(jpegFile.size(), CV_8UC4, pixelData, jpegFile.step);
//    std::cout<<"Type: "<<intDataPtr.type()<<"\n";
//   // std::cout<<"intDataPtr Data: "<<intDataPtr<<"\n";
//    cv::imshow("intDataPtr", intDataPtr);
//    cv::waitKey();
