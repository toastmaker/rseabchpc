#include <stdio.h>
#include <cuda_runtime.h>


__global__ void calc_pi(double *sum, int N)
{
    int tid = blockIdx.x * blockDim.x + threadIdx.x;
    int stride = blockDim.x * gridDim.x;
    double local_sum = 0.0;
    for (int i = tid; i < N; i += stride) {
        double x = (i + 0.5) / N;
        local_sum += 4.0 / (1.0 + x*x);
    }
    atomicAdd(sum, local_sum);
}

int main()
{
    int N = 1000000;

    double *d_sum;
    double h_sum = 0.0;

    // Allocate GPU memory
    cudaMalloc(&d_sum, sizeof(double));
    cudaMemset(d_sum, 0, sizeof(double));

    // Configure CUDA execution

    int threadsPerBlock = 256;
    int blocks = 128;

    // Launch kernel
    calc_pi<<<blocks, threadsPerBlock>>>(d_sum, N);

    // Wait until all preceding GPU work completes (redundant cudaMemcpy works as barrier here)
    cudaDeviceSynchronize();

    // Copy result back to CPU
    cudaMemcpy(&h_sum, d_sum,
               sizeof(double), cudaMemcpyDeviceToHost);

    printf("Pi = %.15f\n", h_sum / N);

    cudaFree(d_sum);
    return 0;
}
