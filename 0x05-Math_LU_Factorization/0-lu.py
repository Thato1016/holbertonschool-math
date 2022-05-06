#!/usr/bin/env python3

import numpy as np

# **LU decomposition**
# your code here
def lu(A):
    """A must be a quare matrix, this algorithm will return 
    the lu factorization of the matrix A"""
    #Get the number of rows
    n = A.shape[0]
    #Initialization
    U = A.astype(float).copy()
    L = np.eye(n, dtype=np.double)
    #Loop over rows
    for i in range(n):
        #Eliminate entries below i with row operations 
        #on U and reverse the row operations to 
        #manipulate L
        assert not(np.isclose(U[i, i], 0.0))
        factor = U[i+1:, i] / U[i, i]
        L[i+1:, i] = factor.astype(float)
        U[i+1:] = U[i+1:] - factor[:, np.newaxis] * U[i]
        
    return L, U
    
