#!/usr/bin/env python3

import numpy as np

def determinant(A):
    if np.isclose(np.sum(np.abs(A)), 0.0):
        return 0
    """A function that calculate the determinant 
    of a sqaure matrix A by the LU factorization"""
    #Get the number of rows
    n = A.shape[0]
    #Allocate space for P, L, and U
    U = A.astype(float).copy()
    L = np.eye(n, dtype=np.double)
    P = np.eye(n, dtype=np.double)
    #Loop over rows
    po = 0
    for i in range(n):
        #Permute rows if needed
        for k in range(i, n): 
            if not(np.isclose(U[i, i], 0.0)):
                break
            U[i, :], U[k+1, :] = U[k+1, :], U[i, :].copy()
            P[i, :], P[k+1, :] = P[k+1, :], P[i, :].copy() 
            po +=1
        #Eliminate entries below i with row 
        #operations on U and #reverse the row 
        #operations to manipulate L
        factor = U[i+1:, i] / U[i, i]
        L[i+1:, i] = factor
        U[i+1:] -= factor[:, np.newaxis] * U[i]
    return P, L, U, round(np.prod(np.diag(U)) * ((-1) ** po), 2)

