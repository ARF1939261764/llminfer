#include <stdio.h>

__device__ void myKernel(){
    printf("Hello, world from the device!\n");
}

__global__ void llama_gemv(){
  myKernel();
}

int main_cu()
{
    llama_gemv<<<4,4>>>();
    cudaError_t cudaError = cudaGetLastError();
    if (cudaError != cudaSuccess) {
        printf("CUDA error: %s\n", cudaGetErrorString(cudaError));
        return 1;
        }
        else {
            printf("No CUDA error\n");
            }
     cudaDeviceSynchronize();
     return 0;
}
