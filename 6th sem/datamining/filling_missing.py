# -*- coding: utf-8 -*-
"""
Created on Thu Feb  8 19:48:52 2018

@author: Punyajoy Saha
"""
import pandas as pd
from scipy import stats
import matplotlib.pyplot as plt
import matplotlib.mlab as mlab
from sklearn import linear_model,datasets
import numpy as np
import math
import random
df=pd.read_csv('class-grades.csv',names=['Prefix','Assignment','Tutorial','Midterm','TakeHome','Final'],header=None)

new_df=df.dropna()
count=0
for iter1 in df:
    if count==0:
       k1=df[pd.isnull(df[iter1])]
    else:
       k1=k1.append(df[pd.isnull(df[iter1])])    
    count=count+1

h=new_df.as_matrix()

"""using linear regression to fill missing value"""
"""
corr_matrix = new_df.corr()

max1=0
for iter1 in corr_matrix:
    if(iter1!='Final'):
       if corr_matrix[iter1]['Final']>max1:
           max1=corr_matrix[iter1]['Final']
           key_max=iter1
           
X=new_df[key_max].as_matrix()
y=new_df['Final'].as_matrix()


X=np.reshape(X,(len(X),1))
y=np.reshape(y,(len(y),1))

reg1=linear_model.LinearRegression()
reg1.fit(X, y)

k_modi=k1.copy()
for i in k1.index.values:
    if(np.isnan(k1['Final'][i])):
        
        k_modi['Final'][i]=reg1.predict(k1[key_max][i])
""" 
"""using multiple linear regression to fill missing value"""
"""   
X_all=new_df.iloc[:,1:5].copy() 

reg2=linear_model.LinearRegression()
reg2.fit(X_all, y)

k_modi_1=k1.copy()
for enum,i in enumerate(k1.index.values):
    if(np.isnan(k1['Final'][i])):
        k_modi_1['Final'][i]=reg2.predict(k1.iloc[enum,1:5].reshape(1,4))
"""
"""using logistic regression to fill missing value"""

iris = datasets.load_iris()
iris_data=iris.data
iris_target=iris.target
df_label=pd.DataFrame(iris_data)
df_label[4] = pd.Series(iris_target, index=df_label.index,dtype='float')

ix = [(row, 4) for row in range(df_label.shape[0])]
for row,col in random.sample(ix, int(round(.1*len(ix)))):
    df_label.iat[row, col] = np.nan

new_df_label=df_label.dropna()
count=0
for iter1 in df_label:
    if count==0:
       k1_label=df_label[pd.isnull(df_label[iter1])]
    else:
       k1_label=k1_label.append(df_label[pd.isnull(df_label[iter1])])    
    count=count+1

h=new_df_label.as_matrix()
logreg = linear_model.LogisticRegression(C=1e5)

X_all=new_df_label.iloc[:,0:3].copy() 
y=new_df_label[4].as_matrix()
y=np.reshape(y,(len(y),1))
logreg.fit(X_all,y)


k_modi_1=k1_label.copy()
for enum,i in enumerate(k1_label.index.values):
    if(np.isnan(k1_label[4][i])):
        k_modi_1[4][i]=logreg.predict(k1_label.iloc[enum,0:3].reshape(1,3))

