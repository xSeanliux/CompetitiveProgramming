#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Feb 17 21:55:34 2020

@author: liusean
"""

import os

cnt = 0
tot_lines = 0
judges = {"UVa": 0, "CF": 0, "TIOJ": 0, "AtCoder": 0, "0J": 0, "SPOJ": 0}


def lines(fname):
        with open(fname) as f:
                for i, l in enumerate(f):
                        pass
        return i + 1

for root, dirs, files in os.walk(".", topdown=False):
   for name in files:
      if name[-4:] == ".cpp":
          if(root.split('/')[1] in judges):
              judges[root.split('/')[1]] = judges[root.split('/')[1]] + lines(os.path.join(root, name))
          #print(os.path.join(root, name))
          tot_lines = tot_lines + lines(os.path.join(root, name))
          cnt = cnt + 1
          
print("Total of " + str(tot_lines) + " lines of C++ code written")
print("Judges:" )
for x in judges:
    print(x + ": " + str(judges[x]) + " lines of C++ code written")
    