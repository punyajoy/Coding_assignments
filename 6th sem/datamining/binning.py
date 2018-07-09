# -*- coding: utf-8 -*-
"""
Created on Fri Feb  9 02:00:19 2018

@author: Punyajoy Saha
"""

import pandas as pd
from scipy import stats
import matplotlib.pyplot as plt
import matplotlib.mlab as mlab
from sklearn import linear_model,datasets


import numpy as np
import math


df=pd.read_excel('data_stock.xlsx',header=None)
X=df[1].as_matrix()
X=np.reshape(X,(len(X),1))
X=np.sort(X,axis=0)

nofbins=int(input('give the number of bins:'))
"""keeping equal depth"""
depth=float((X[535]-X[0])/nofbins)
list1=[]
for i in range(1,nofbins+1):
    list1.append(float(X[0]+i*depth))
    
bineqdepth=[]
j=0
temp=[]
for ele in X:
    if(ele<list1[j]):
        temp.append(float(ele))
    else:
        bineqdepth.append(temp)
        temp=[]
        temp.append(float(ele))
        j=j+1
      
bineqdepth.append(temp)
   

"""keeping equal width"""
width=float(X.shape[0]/nofbins)
    
bineqwidth=[]
j=0
temp=[]
count=0
for ele in X:
    if(count<=width):
        temp.append(float(ele))
        count=count+1
    else:
        bineqwidth.append(temp)
        temp=[]
        count=0
        temp.append(float(ele))
        count=count+1

bineqwidth.append(temp)




"""removing noise by mean"""
"""
for ele in bineqwidth:
    temp_array=np.asarray(ele)
    mean = np.mean(temp_array)
    for i in range(0,len(ele)):
        ele[i]=mean
        

for ele in bineqdepth:
    temp_array=np.asarray(ele)
    mean = np.mean(temp_array)
    for i in range(0,len(ele)):
        ele[i]=mean
"""
"""removing noise by median"""
"""
for ele in bineqwidth:
    temp_array=np.asarray(ele)
    median = np.median(temp_array)
    for i in range(0,len(ele)):
        ele[i]=median
        

for ele in bineqdepth:
    temp_array=np.asarray(ele)
    median = np.median(temp_array)
    for i in range(0,len(ele)):
        ele[i]=median

"""
"""removing noise by boundary values"""

for ele in bineqwidth:
    for i in range(0,len(ele)):
        if((ele[i]-ele[0])>(ele[i]-ele[len(ele)-1])):
            ele[i]=ele[len(ele)-1]
        else:
            ele[i]=ele[0]

        
        

for ele in bineqdepth:
    for i in range(0,len(ele)):
        if((ele[i]-ele[0])>(ele[len(ele)-1]-ele[i])):
            ele[i]=ele[len(ele)-1]
        else:
            ele[i]=ele[0]




