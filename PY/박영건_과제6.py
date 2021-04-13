def d2x(number, N):
    q, r = divmod(number, N)
    if q == 0:
        return str(r)
    else:
        return d2x(q, N) + str(r)

print(d2x(10, 2))
print(d2x(10, 3))
print(d2x(10, 8))