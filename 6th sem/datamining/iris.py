# -*- coding: utf-8 -*-
"""
Created on Fri Jan  5 14:25:24 2018

@author: Punyajoy Saha
"""

import csv
import pandas as pd
import numpy as np
from sklearn import datasets
import math 
import statistics

iris = datasets.load_iris()
iris_data=iris.data
#iris_data=np.zeros((150,4))

def normalize(data):
    data=(data-np.min(data))/(np.max(data)-np.min(data))
    return data

def make_clusters(dice_list,clusters):    
  count=0
  previous_length=0
  while(len(dice_list)>clusters):
    if(len(dice_list)==previous_length):
        break
    count=count+1
    #print(count)
    dice_mat_cluster=np.zeros((len(dice_list),len(dice_list)))
    for i in range(0,len(dice_list)):
      for j in range(0,len(dice_list)):
        dice_mat_cluster[i,j]=len(set(dice_list[i])&(set(dice_list[j])))/len(set(dice_list[i])|(set(dice_list[j])))

    
    dice_max_list=[]        
    dice_max_cluster=0   
    for i in range(0,dice_mat_cluster.shape[0]):
      for j in range(i+1,dice_mat_cluster.shape[1]):
          if(dice_mat_cluster[i][j]>dice_max_cluster):
              dice_max_cluster=dice_mat_cluster[i][j]
    
    for i in range(0,dice_mat_cluster.shape[0]):
      for j in range(i+1,dice_mat_cluster.shape[1]):
        if(dice_mat_cluster[i][j]==dice_max_cluster):
            new=list(set(dice_list[i])|set(dice_list[j]))
            dice_max_list.append(new)
    
    
    previous_length=len(dice_list)
    for i in range(0,len(dice_max_list)):
     temp_list=[]
     for j in range(0,len(dice_list)):
         if(set(dice_list[j]).issubset(set(dice_max_list[i]))):
            temp_list.append(j)
     dice_list = [x for i,x in enumerate(dice_list) if i not in temp_list]
     dice_list.append(dice_max_list[i])
    print("number of clusters at pass "+str(count)+":"+str(len(dice_list)))
  return dice_list


"""
with open('E:\\computerscience\\program\\6th sem\\datamining\\iris.csv', 'r') as csvfile:
    irisreader = csv.reader(csvfile, delimiter=',', quotechar='|')
    count=0
    for row in irisreader:
        iris_data[count][0]=row[0]
        iris_data[count][1]=row[1]
        iris_data[count][2]=row[2]
        iris_data[count][3]=row[3]
        count=count+1
"""     

   
for i in range(0,4):
   iris_data[:,i]=normalize(iris_data[:,i])


dice_mat=np.zeros((150,150))
jaccard_mat=np.zeros((150,150))
cosine_mat=np.zeros((150,150))
overlap_mat=np.zeros((150,150))
   
   
for i in range(0,150):
    for j in range(0,150):
        mult=np.sum(np.multiply(iris_data[i,:],iris_data[j,:]))
        sum1=np.sum(np.multiply(iris_data[i,:],iris_data[i,:]))
        sum2=np.sum(np.multiply(iris_data[j,:],iris_data[j,:]))
    
        if(sum1>sum2):
            min_sum=sum1
        if(sum1<=sum2):
            min_sum=sum2
            
        
        """if i==j:
            jaccard_mat[i,j]=1
            dice_mat[i,j]=1
            cosine_mat[i,j]=1
            overlap_mat[i,j]=1
        else:"""
        dice_mat[i,j]=2*mult/(sum1+sum2)
        jaccard_mat[i,j]=mult/(sum1+sum2-mult)
        cosine_mat[i,j]=mult/math.sqrt(sum1*sum2)
        overlap_mat[i,j]=mult/min_sum


dice_avg=np.zeros((150,1))
jaccard_avg=np.zeros((150,1))
cosine_avg=np.zeros((150,1))
overlap_avg=np.zeros((150,1))
for i in range(0,150):
    dice_avg[i]=np.mean(dice_mat[i])
    jaccard_avg[i]=np.mean(jaccard_mat[i])
    cosine_avg[i]=np.mean(cosine_mat[i])
    overlap_avg[i]=np.mean(overlap_mat[i])

dice_list=[]    
jaccard_list=[]
cosine_list=[]
overlap_list=[]    
    
    
for i in range(0,150):
    dice_row=[]    
    jaccard_row=[]
    cosine_row=[]
    overlap_row=[]    
    for j in range(0,150):
        if(dice_mat[i,j]>=dice_avg[i]):
            dice_row.append(j)
        if(jaccard_mat[i,j]>=jaccard_avg[i]):
            jaccard_row.append(j)        
        if(cosine_mat[i,j]>=cosine_avg[i]):
            cosine_row.append(j)
        if(overlap_mat[i,j]>=overlap_avg[i]):
            overlap_row.append(j)        
    dice_list.append(dice_row)
    jaccard_list.append(jaccard_row)
    cosine_list.append(cosine_row)
    overlap_list.append(overlap_row)


dice_mat_cluster=np.zeros((150,150))
jaccard_mat_cluster=np.zeros((150,150))
cosine_mat_cluster=np.zeros((150,150))
overlap_mat_cluster=np.zeros((150,150))
    
for i in range(0,150):
    for j in range(0,150):
        dice_mat_cluster[i,j]=len(set(dice_list[i])&(set(dice_list[j])))/len(set(dice_list[i])|(set(dice_list[j])))
        jaccard_mat_cluster[i,j]=len(set(jaccard_list[i])&(set(jaccard_list[j])))/len(set(jaccard_list[i])|(set(jaccard_list[j])))
        cosine_mat_cluster[i,j]=len(set(cosine_list[i])&(set(cosine_list[j])))/len(set(cosine_list[i])|(set(cosine_list[j])))
        overlap_mat_cluster[i,j]=len(set(overlap_list[i])&(set(overlap_list[j])))/len(set(overlap_list[i])|(set(overlap_list[j])))


dice_max_list=[]        
dice_max_cluster=np.max(np.max(dice_mat_cluster,axis=0),axis=0)   
for i in range(0,150):
    for j in range(i+1,150):
        if(dice_mat_cluster[i][j]==dice_max_cluster):
            new=list(set(dice_list[i])|set(dice_list[j]))
            dice_max_list.append(new)



clusters = int(input("give the number of clusters?"))

print("\nWith dice similarity\n")
final_dice_list=make_clusters(dice_list,clusters)

print("\nWith jaccard similarity\n")
final_jaccard_list=make_clusters(jaccard_list,clusters)

print("\nWith overlap similarity\n")
final_overlap_list=make_clusters(overlap_list,clusters)
print("\nWith cosine similarity\n")
final_cosine_list=make_clusters(cosine_list,clusters)
            
        



    