#include <stdio.h>
#include <cuda_runtime.h>

__global__ void calc_pi(double *sum, int N)
{
    int i = blockIdx.x * blockDim.x + threadIdx.x;

    if (i < N) {
        double x = (i + 0.5) / N;
        double value = 4.0 / (1.0 + x*x);

        atomicAdd(sum, value);
    }
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
    int blocks = (N + threadsPerBlock - 1) / threadsPerBlock;

    // Launch kernel
    calc_pi<<<blocks, threadsPerBlock>>>(d_sum, N);

    // Wait until all preceding GPU work completes - redundant, cudaMemcpy works as barrier
    cudaDeviceSynchronize();

    // Copy result back to CPU
    cudaMemcpy(&h_sum, d_sum,
               sizeof(double), cudaMemcpyDeviceToHost);

    printf("Pi = %.15f\n", h_sum / N);

    cudaFree(d_sum);
    return 0;
}
