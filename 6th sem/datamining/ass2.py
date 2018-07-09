# -*- coding: utf-8 -*-
"""
Created on Fri Feb  2 13:01:50 2018

@author: Punyajoy Saha
"""

import pandas as pd
from scipy.stats import expon
from scipy.stats import norm
from scipy.stats import skewnorm

from scipy import stats
import matplotlib.pyplot as plt
import matplotlib.mlab as mlab
from sklearn import linear_model
import numpy as np
import math
plt.figure(1)

"""symmetric dataset"""
mu = 0
variance = 1
sigma = math.sqrt(variance)
sym_data = np.linspace(mu - 3*sigma, mu + 3*sigma, 100)
sym_density=mlab.normpdf(sym_data, mu, sigma)
sym_mode=stats.mode(sym_density)
sym_mean=np.mean(sym_density)
sym_median=np.median(sym_density)

plt.subplot(221)
"""
plt.vlines(sym_mean, 0, 0.7, colors='k')
plt.vlines(sym_median, 0, 0.7, colors='g')
plt.vlines(sym_mode[0], 0, 0.7, colors='m')
"""
plt.plot(sym_data, sym_density,'r-', label='skewnorm pdf')


#mean, var, skew, kurt = skewnorm.stats(a, moments='mvsk')
"""positively skewed dataset"""
a=2
pos_skewed = np.linspace(skewnorm.ppf(0.1, a),skewnorm.ppf(0.99, a), 100)
#pos_skewed = np.random.exponential(size=100)
#pos_density =expon.pdf(pos_skewed)
pos_density=skewnorm.pdf(pos_skewed, a)
pos_mode=stats.mode(pos_density)
pos_mean=np.mean(pos_density)
pos_median=np.median(pos_density)
plt.subplot(222)
"""
plt.vlines(pos_mean, 0, 0.7, colors='k')
plt.vlines(pos_median, 0, 0.7, colors='g')
plt.vlines(pos_mode[0], 0, 0.7, colors='m')
"""
plt.plot(pos_skewed, pos_density,'r-', label='skewnorm pdf')
"""negatively skewed dataset"""
a=-4
neg_skewed = np.linspace(skewnorm.ppf(0.1, a),skewnorm.ppf(0.99, a), 100)
neg_density=skewnorm.pdf(neg_skewed, a)
neg_mode=stats.mode(neg_density)
neg_mean=np.mean(neg_density)
neg_median=np.median(neg_density)
plt.subplot(223)
"""
plt.vlines(neg_mean, 0, 0.7, colors='k')
plt.vlines(neg_median, 0, 0.7, colors='g')
plt.vlines(neg_mode[0], 0, 0.7, colors='m')
"""
plt.plot(neg_skewed, neg_density,'r-',label='skewnorm pdf')






"""
vals = skewnorm.ppf([0.001, 0.5, 0.999], a)
np.allclose([0.001, 0.5, 0.999], skewnorm.cdf(vals, a))
r = skewnorm.rvs(a, size=1000)

ax.hist(r, normed=True, histtype='stepfilled', alpha=0.2)
"""
plt.show()