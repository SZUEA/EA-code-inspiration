def ext_gcd(a, b):
    if b == 0:
        return 1, 0, a
    else:
        x_, y, gcd_ = ext_gcd(b, a % b)  # 递归直至余数等于0(需多递归一层用来判断)
        x_, y = y, (x_ - (a // b) * y)  # 辗转相除法反向推导每层a、b的因子使得gcd(a,b)=ax+by成立
        return x_, y, gcd_


if __name__ == '__main__':
    p = input()
    if p[0] == '0':
        p = p[1:]
    a = eval(p)
    b = eval(input())
    d = ext_gcd(b, 19260817)
    x = d[0]
    gcd = d[2]
    ans = a // gcd * x
    print(ans % 19260817)
