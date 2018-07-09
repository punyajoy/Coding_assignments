# -*- coding: utf-8 -*-
"""
Created on Thu Feb 22 21:35:38 2018

@author: Punyajoy Saha
"""

import math
import numpy as np
 
values = range(1, 209)
probs = [1.0 / 208] * 208
 
for idx, prob in enumerate(probs):
    if idx > 80 and idx < 90:
        probs[idx] = probs[idx] * (1 + math.log(idx + 1))
    if idx > 90 and idx < 100:
        probs[idx] = probs[idx] * (1 + math.log((100 - idx) + 1))
 
probs = [p / sum(probs) for p in probs]
sample =  np.random.choice(values, 1000, p=probs)
 
import matplotlib
#matplotlib.use('TkAgg')
import matplotlib.pyplot as plt
 
binwidth = 2
plt.hist(sample, bins=np.arange(min(sample), max(sample) + binwidth, binwidth))
plt.xlim([0, max(sample)])

plt.show()

plt.show()