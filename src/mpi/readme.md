```bash
module load openmpi-5.0.8

python3 -m venv rsempi
source ~/rsempi/bin/activate
MPICC=$(which mpicc) python -m pip install --no-cache-dir --no-binary=mpi4py mpi4py
```
