PISANO_PERIOD = 1500000000
MOD = 1000000000
'''
def fib_diff(n1,n2,n):
    n3 = n1 - n2
    while n > 1:
        n //= 2
        n1,n2,n3 = (n1*n1 + n2*n2) % MOD, (n1 + n3) * n2 % MOD, (n3*n3 + n2*n2) % MOD
        if n % 2 == 1: n1,n2,n3 = n1+n2,n1,n2
    return n2 % MOD
        

a,b,n = map(int,input().split())
n = n % PISANO_PERIOD
print(fib_diff(a,b,n))
'''
def fib(n):
    v1, v2, v3 = 2,1,1    # initialise a matrix [[1,1],[1,0]]
    for rec in bin(n)[3:]:  # perform fast exponentiation of the matrix (quickly raise it to the nth power)
        calc = v2*v2
        v1, v2, v3 = v1*v1+calc, (v1+v3)*v2, calc+v3*v3
        if rec=='1':    v1, v2, v3 = v1+v2, v1, v2
    return v2
print(fib(1),fib(2),fib(3),fib(4))
