'''
mergesort
'''

import numpy as np

def merge(x,y):
	'''merge two sorted arrays'''
	# lengths 
	lenX = x.shape[0]
	lenY = y.shape[0]
	
	# outout array
	out = np.zeros(lenX+lenY)
	
	# array positions 
	# - start at beginning ie 0
	indX = 0
	indY = 0
	i = 0
	
	# indicators for having reached end of array
	endX = False
	endY = False
	
	# loop until end of an array is reached 
	while not endX and not endY:
		# possible values to add to output arrays 
		xp = x[indX]
		yp = y[indY]
		
		# add the smaller of the two values
		# increment appropriate position indicators
		# if end of array is reached, update boolean
		if xp < yp:
			out[i] = xp
			indX += 1
			i += 1
			if indX == lenX:
				endX = True
		else:
			out[i] = yp
			indY += 1
			i += 1
			if indY == lenY:
				endY = True
	
	# if end of one array is reached, appemd the other
	if endX:
		out[i:] = y[indY:]
	else:
		out[i:] = x[indX:]
	
	# return output
	return(out)

def sort(s):
	'''sort an array of numbers in increasing order'''
	
	# convert array to numpy
	s = np.array(s)
	
	# grab length 
	n = s.shape[0]
	
	# trivial cases
	if n < 2:
		return(s)
	
	# find midpoimt 
	mid = n//2
	
	# sort the left half 
	left = sort(s[:mid])
	# sort the right half 
	right = sort(s[mid:])
	
	# merge the left and right halves
	out = merge(left,right)
	
	# return sorted array
	return(out)

# test case
s = [5,8,3,1,9,15,4,4]

print(sort(s))
