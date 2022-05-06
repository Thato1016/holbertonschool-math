#!/usr/bin/env python3

import numpy as np

def gradient(A, b, tol, epoch_max):
    """A must be a c matrix, b a vectorand tol a tiny number
    this alogorithm will solve the linear system A.T A x = b"""
    B = np.dot(A.T, A)
    n, m = np.shape(B)
    p = len(b)
    x = b.copy()
    assert p == n
    assert tol > 0
    r =np.dot(B, x) - b
    epoch = 0
    alpha = 1 / np.sum(np.abs(B))
    while (np.sum(np.abs(r)) > tol) and (epoch < epoch_max):
        x = x - alpha * r
        r =np.dot(B, x) - b
        epoch += 1
    assert epoch < epoch_max
    return x

