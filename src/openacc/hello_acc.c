#include <stdio.h>
#include <openacc.h>

int main() {
	acc_device_t dev = acc_get_device_type();

	if (dev == acc_device_nvidia)
		printf("Running on NVIDIA GPU\n");
	else if (dev == acc_device_host)
		printf("Running on CPU\n");
	else
		printf("Unknown device\n");

	#pragma acc parallel loop
	for (int i = 0; i < 10; i++) {
		printf("Hello from GPU thread %d\n", i);
	}

	return 0;
}
