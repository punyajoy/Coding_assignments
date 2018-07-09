# -*- coding: utf-8 -*-
"""
Created on Thu Feb 15 15:52:57 2018

@author: Punyajoy Saha
"""

import pandas as pd
from scipy import stats
import matplotlib.pyplot as plt
import matplotlib.mlab as mlab
from sklearn import linear_model,datasets
import pprint


import numpy as np
import math
x=[]
    
df=pd.read_excel('Cryotherapy.xlsx')
X=df['age'].as_matrix()
X=np.matrix(X,dtype='int')
X=np.reshape(X,(X.shape[1],1))
X=np.sort(X,axis=0)

#####histogram#####        
#l_hist=hist_into(X.copy())       
histogram=np.histogram(X,bins=10)
arr=histogram[0].astype('int')
sum1=0
for i in range(arr.shape[0]):
    sum1=sum1+arr[i]
    arr[i]=sum1
l_split=np.array_split(X,arr[1:(arr.shape[0]-1)])
        

#####discretization using 3-4-5 natural partitioning####
x=[]
x.append(X)
discrete=int(input('give the number of discrete values:'))
count=1    
while(1):
    len_x=len(x)
    flag=0
    temp_list=[]
    for i in range(0,len_x):
        temp_list.append(x[i])
        X_1=(np.floor(x[i].copy()/int(10))).astype(int)
        X_new=np.unique(X_1,axis=0) 
        if(X_new.shape[0]==3 or X_new.shape[0]==6 or X_new.shape[0]==9):
            print("the number of partition is 3")
            l=np.array_split(x[i],3)
            count=count+2
        elif(X_new.shape[0]==2 or X_new.shape[0]==4 or X_new.shape[0]==8):
            print("the number of partition is 4")
            l=np.array_split(x[i],4)    
            count=count+3
        elif(X_new.shape[0]==1 or X_new.shape[0]==5 or X_new.shape[0]==10):
            print("the number of partition is 5")
            l=np.array_split(x[i],5)
            count=count+4
        for i in range(len(l)):
            x.append(l[i])
        if((len(x)-len(temp_list))>discrete):
            flag=1
            break
    for j in temp_list:
        x.remove(j)
    if flag==1:
        break


#####discretization using entropy based#####
   
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
  
#X0=X[1:90][1]


#
#x_all=break_into(X)

#noflevels=int(input('give the number of level:'))
    


#plt.hist(X, bins='auto')  # arguments are passed to np.histogram
#plt.title("Histogram with 'auto' bins")
#plt.show()
