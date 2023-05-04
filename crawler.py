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
   print(root, dirs[0:2], files[0:2])
   for name in files:
      if name[-4:] == ".cpp":
          if(root.split('/')[1] in judges):
              with open(root + '/' + name) as f:
                  line_count = sum(1 for line in f if line.strip())
              tot_lines = tot_lines + line_count
              judges[root.split('/')[1]] = judges[root.split('/')[1]] + line_count
          #print(os.path.join(root, name))
          cnt = cnt + 1
          
print("Total of " + str(tot_lines) + " lines of C++ code written")
print("Judges:" )
for x in judges:
    print(x + ": " + str(judges[x]) + " lines of C++ code written")
    
