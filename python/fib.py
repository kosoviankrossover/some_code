
# fibonacci sequence
# i       0 1 2 3 4 5 6 7  8  ...
# f(i) =  0 1 1 2 3 5 8 13 21 ...
# f(i) = f(i-1) + f(i-2(

# time the fib functions
import time

# recursive fib fun
def fib1(n):
    if n <= 0:
        return(0)
    elif n == 1:
        return(1)
    else:
        n1 = fib1(n-1)
        n2 = fib1(n-2)
        return (n1 + n2)


# fib fun using a dynamic loop
def fib2(n):
    if n < 0:
        return(-1)
    elif n == 0:
        return(0)
    elif n == 1 or n == 2:
        return(1)
    else:
        # print('this loop')
        out = 0
        two_before = 1
        one_before = 1
        # n=3 -> index=1 -> one loop
        index = n-2
        for i in range(index):
            # print('-'*15)
            # print(i)
            # print("one before {}, two before {}, out {}".format(one_before, two_before, out))
            out = one_before + two_before
            two_before = one_before
            one_before = out
            # print("change")
            # print("one before {}, two before {}, out {}".format(one_before, two_before, out))
            # print('-'*15)

        return(out)

# dynamic fib fun with dicts
fib_dict = dict()
fib_dict[0] = 0
fib_dict[1] = 1
fib_dict[2] = 1
def fib3(n):
    if n < 0:
        return(-1)
    else:
        if n in fib_dict:
            return(fib_dict[n])
        else:
            fib_dict[n] = fib3(n-1) + fib3(n-2)
            return(fib_dict[n])


    

n = int(input("give a number... "))

start = time.time()
print("the fib number is... {}".format(fib1(n)))
end = time.time()
print(round((end-start)*1e9))
print('-'*15)

start = time.time()
print("the fib number is... {}".format(fib2(n)))
end = time.time()
print(round((end-start)*1e9))
print('-'*15)

start = time.time()
print("the fib number is... {}".format(fib3(n)))
end = time.time()
print(round((end-start)*1e9))
print('-'*15)




