def ext_gcd(a, b):
    if b == 0:
        return 1, 0, a
    else:
        x_, y, gcd_ = ext_gcd(b, a % b)
        x_, y = y, (x_ - (a // b) * y)
        return x_, y, gcd_


if __name__ == '__main__':
    n = eval(input())
    r = []
    s = []
    for i in range(0, n):
        ln = input()
        lns = ln.split(' ')
        r.append(eval(lns[0]))
        s.append(eval(lns[1]))
    eps = 1
    sm = 0
    for i in r:
        eps = eps * i
    for i in range(0, n):
        d = ext_gcd(eps // r[i], r[i])
        x = d[0]
        y = (x % r[i] + r[i]) % r[i]
        sm = sm + s[i] * y * eps // r[i]
    print(sm % eps)
