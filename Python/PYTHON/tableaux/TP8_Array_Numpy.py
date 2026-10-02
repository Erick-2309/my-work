#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue May 1 09:14:09 2021
@author: rjennane
"""

#import array
#import random
import numpy as np

##--------------------------------------------------------------------
# Exo 1
# number of occurrences of a specified element in an array
array_num = np.array([1, 3, 5, 3, 7, 9, 3])
print("Original array: ",array_num)
print("Number of occurrences of the number 3 in the said array: ",np.count_nonzero(array_num==3))

# append items at the end of the array
array_num = np.array([1, 3, 5, 7, 9])
print("Original array: ",array_num)

array_num1 = np.array([2, 4, 6, 8, 10])
np.append(array_num1,array_num1)
print("Extended array: "+str(array_num))

# reverse the order of the items in the array
array_num = np.array([1, 3, 5, 3, 7, 1, 9, 3])
print("Original array: "+str(array_num))
array_num = array_num[::-1]
print("Reverse the order of the items:")
print(str(array_num))


# Append items from a specified list
num_list = [1, 2, 6, -8]
array_num = np.array([])
print("Items in the list: ", num_list)
print("Append items from the list: ")
array_num = np.array(num_list)
print("Items in the array: ",array_num)

# Insert a new item before the third element in an existing array
array_num = np.array([1, 3, 5, 7, 9])
print("Original array: "+str(array_num))
print("Insert new value 4 before 3:")
array_num = np.insert(array_num,2,4)
print("New array: ",array_num)

# Remove an element from an array with specified position
array_num = np.array([1, 3, 5, 7, 3, 1, 9, 3])
print("Original array: ",array_num)
print("Remove the first occurrence of 3 from the said array:")
array_num = np.delete(array_num,3)
print("New array: ",array_num)

# Convert an array to an ordinary list with the same items
array_num = np.array([1, 3, 5, 3, 7, 1, 9, 3])
print("Original array: "+str(array_num))
num_list = array_num.tolist()
print("Convert the said array to an ordinary list with the same items:")
print(num_list)

# find the first duplicate element in a given array of integers.
# Return -1 if there are no such elements.
def find_first_duplicate(nums):
    num_set = set()
    no_duplicate = -1

    for i in range(len(nums)):
        if nums[i] in num_set:
            return nums[i]
        else:
            num_set.add(nums[i])
    return no_duplicate

print(find_first_duplicate([1, 2, 3, 4, 4, 5]))
print(find_first_duplicate([1, 2, 3, 4]))
print(find_first_duplicate([1, 1, 2, 3, 3, 2, 2]))

##--------------------------------------------------------------------
# Exo 2
# generate n random integer values between a and b.
def random_int(a,b,n):
    liste_integer = [np.random.randint(a,b) for i in range(n)]
    tab_integer = np.random.randint(a,b,n) 
    tab_uniform = [np.random.uniform(0,1) for i in range(n)]
    return  liste_integer, tab_integer, tab_uniform

liste_integer, tab_integer, tab_uniform = random_int (0,10,5)

print("Random liste of integers: "+str(liste_integer))
print("Random array of integers: "+str(tab_integer))
print("Random liste of uniform distributed values: "+str(tab_uniform))

# generate n random gaussian values 
def random_gauss(n):
    tab_gaussian = np.random.randn(n)
    return tab_gaussian

tab_gaussian = random_gauss (5)

print("Gaussian array: "+str(tab_gaussian))
##--------------------------------------------------------------------
# Exo 3
# append items at the end of the array
array_num = np.array([1, 3, 5, 7, 9])
print("Original array: ",array_num)

array_num1 = np.array([2, 4, 6, 8, 10])
print("Second array: ",array_num1)
array_num2 = np.append(array_num,array_num1)
print("Extended array: ",array_num2)

##--------------------------------------------------------------------
# Exo 4
# generate nxm (matrix) uniform values between a and b
def random_gauss_mat(a,b,n,m):
    mat_gaussian = a + (b-a) * np.random.rand(n,m)
    return mat_gaussian

mat_gaussian = random_gauss_mat(0,10,3,4)

print("Gaussian matrix: "+str(mat_gaussian))
