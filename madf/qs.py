# Sorting a List using Quicksort in Python
# 2011-05-16

def quickSort(toSort):
	if len(toSort) <= 1:
		return toSort

	end = len(toSort) - 1
	pivot = toSort[end]

	low = []
	high = []

	for num in toSort[:end]:
		if num <= pivot:
			low.append(num)
		else:
			high.append(num)
			
	sortedList = quickSort(low)
	sortedList.append(pivot)
	sortedList.extend(quickSort(high))

	return sortedList

def main():
	l = [187,62,155,343,184,958,365,427,78,121,388]
	sortedList = quickSort(l)
	print sortedList

if __name__ == '__main__':
	main()
