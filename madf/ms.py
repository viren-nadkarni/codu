#!/bin/python 
# Sorting a List using Mergesort in Python
# 2011-05-16

def mergeSort(toSort):
	if len(toSort) <= 1:						#if single/no element, return
		return toSort

	mIndex = len(toSort) / 2					#find midpoint
	left = mergeSort(toSort[:mIndex])			#split into left
	right = mergeSort(toSort[mIndex:])			#and right array

	result = []
	while len(left) > 0 and len(right) > 0:
		if left[0] > right[0]:	
			result.append(right.pop(0))
		else:
			result.append(left.pop(0))
			
	if len(left) > 0:
		result.extend(mergeSort(left))
	else:
		result.extend(mergeSort(right))

	return result

def main():
	l = [187,62,155,343,184,958,365,427,78,121,388]
	sortedList = mergeSort(l)
	print sortedList

if __name__ == '__main__':
	main()
