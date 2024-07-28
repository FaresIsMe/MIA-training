import time
import numpy as np
from Oranges import *

size = 1000000

list = list(range(size))
numpy_array = np.array(size)

start_time = time.time()
list = [list * 2 for list in list]
python_time = time.time() - start_time
print (f"Python execution time: {python_time: .3f}" )

start_time = time.time()
numpy_array *= 2
numpy_time = time.time() - start_time
print (f"Numpy execution time: {numpy_time: .3f}")


pineapple(6)
multiply_lists([1, 2, 3], [4, 5, 6])
