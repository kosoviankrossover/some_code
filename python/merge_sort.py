def merge(x,y):
	'''
	merge two sorted arrays
	'''
	# lengths 
	lenX = len(x)
	lenY = len(y)
	
	# outout array
	out = []
	
	# array positions 
	# - start at beginning ie 0
	indX = 0
	indY = 0
	
	# indicators for having reached end of array
	endX = False
	endY = False
	
	# loop until end of an array is reached 
	while not endX and not endY:
		# possible values to add to output arrays 
		xp = x[indX]
		yp = y[indY]
		
		# add the smaller of the two values
		# increment appropriate position indicator
		# if end of array is reached, update boolean
		if xp < yp:
			out.append(xp)
			indX += 1
			if indX == lenX:
				endX = True
		else:
			out.append(yp)
			indY += 1
			if indY == lenY:
				endY = True
	
	# if end of one array is reached, appemd the other
	if endX:
		out.extend(y[indY:])
	else:
		out.extend(x[indX:])
	
	return(out)

a = [1,4,5,9,14]
b = [2,3,6,16]
#print(merge(a,b))

def sort(s):
	'''sort an array of numbers in increasing order'''
	
	# grab length 
	n = len(s)
	
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
	
s = [5,8,3,1,9,15,4]

print(sort(s))
	
