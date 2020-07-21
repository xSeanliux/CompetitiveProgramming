#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Jul  8 19:28:11 2020

@author: liusean
"""

 # Import libraries
import seaborn as sns
import numpy as np
import matplotlib.pyplot as plt

# Exponential decay function

with open("./in.txt") as f:
    inp = f.read().split()

N = inp[0]
print("N = " + N)
K = inp[1]
y = []
x = []
for i in range(2, 2 + int(N)):
    #if(inp[2 + int(N)][i - 2] == 'T'):
    #    print(str(i - 2) + " is a T: " + inp[i]) 
    y.append(int(inp[i]) / 15000)
    x.append(i - 1)
        

print(len(y))
print("|x| = " + str(len(x)) + ", |y| = " + str(len(y)))

print("Now drawing")
plt.plot(x, y)

y = []
x = []

for i in range(2, 2 + int(N)):
    if(inp[2 + int(N)][i - 2] == 'T'):
        print(str(i - 1) + " is a T: " + inp[i]) 
        y.append(int(inp[i]) / 15000)
        x.append(i - 1)

print("Now drawing")
plt.plot(x, y, color='red', marker='o')

plt.plot(122044, int(inp[122044 + 1]) / 15000, marker = 'o')

print(inp[122044 + 1])

plt.show()

