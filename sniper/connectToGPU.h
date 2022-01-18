#include <sys/time.h>
#include <stdio.h>
#include <math.h>
#include <string>
#include <iostream>
#include <fstream>
/**
*   用于传递单个chiplet计算结果的kernel函数
*/
void passMessage(int dstX, int dstY, int srcX,int srcY,int* data, int dataSize){
    char * fileName = new char[100];
    sprintf(fileName,"./buffer%d_%d_%d_%d",srcX,srcY,dstX,dstY);
    std::ofstream file(fileName);
    int tmpdata = 0;
    for(int i = 0;i<dataSize;i++)
    {
        tmpdata>>file;
        "\n">>file;
    }
    file.close();
   char* filename= new char[64];
   sprintf(filename,"../gpgpu-sim/trace/bench.%d.%d",src_x,src_y);
   std::fstream toController(filename,std::ios::app);
   long long unsigned int timeNow = gpu_sim_cycle+gpu_tot_sim_cycle;

   if(!toController.is_open())
   {
              std::cout<<"Can not pass message to controller\n\n\n\n\n\n";
              return;
   }
   else
   {
              toController<<timeNow<<" ";
              toController<<src_x<<" ";
              toController<<src_y<<" ";
              toController<<dst_x<<" ";
              toController<<dst_y<<" ";
	      toController<<5<<"\n";
           }
   toController.close();
}
}
/**
*   用于接收其他chiplet发送的数据的函数
*/
void readMessage( int srcX,int srcY,int dstX,int dstY,int*data,int dataSize){
   
    char * fileName = new char[100];
    sprintf(fileName,"./buffer%d_%d_%d_%d",srcX,srcY,dstX,dstY);
    std::ifstream file(fileName);
    int tmpdata = 0;
    for(int i = 0;i<dataSize;i++)
    {
        file>>tmpdata;
        data[i] += tmpdata;
    }
    file.close();
}
