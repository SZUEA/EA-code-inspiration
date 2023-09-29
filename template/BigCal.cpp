#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
class BigInteger
{
public:
    BigInteger(string num);
    BigInteger(vector<int> num);
    BigInteger(int num);
    string printNum();
    friend ostream &operator<<(ostream &os, BigInteger num);

    BigInteger add(BigInteger plus);
    BigInteger operator+(BigInteger plus);
    BigInteger add(string plus);

    BigInteger subtract(BigInteger minus);
    BigInteger operator-(BigInteger minus);
    BigInteger subtract(string minus);
    BigInteger subtract(int minus);

    BigInteger multiply(BigInteger mul);
    BigInteger operator*(BigInteger mul);
    BigInteger multiply(string mul);
    BigInteger multiply(int mul);

    BigInteger divide(int div);
    BigInteger operator/(int div);

    bool equals(BigInteger num);
    bool equals(int num);
    bool equals(string num);

    vector<int> intArr;
    int neg;

private:
    BigInteger removeZero();
};

string BigInteger::printNum()
{
    string s = string();
    if (intArr.size() == 1 && intArr[0] == 0)
    {
        return "0";
    }
    s.append(neg ? "-" : "");
    for (int i = intArr.size() - 1; i >= 0; i--)
    {
        s.append(to_string(intArr[i]));
    }
    return s;
};

ostream &operator<<(ostream &os, BigInteger num)
{
    return os << num.printNum();
}

BigInteger BigInteger::operator+(BigInteger plus)
{
    return add(plus);
}

BigInteger BigInteger::operator-(BigInteger minus)
{
    return subtract(minus);
}

BigInteger BigInteger::operator*(BigInteger mul)
{
    return multiply(mul);
}

BigInteger BigInteger::operator/(int div)
{
    return divide(div);
}

BigInteger::BigInteger(string a)
{
    neg = a.at(0) == '-';
    for (int i = a.length() - 1; i >= neg; i--)
    {
        if (a.at(i) <= '9' && a.at(i) >= '0')
        {
            intArr.push_back(a.at(i) - '0');
        }
        else
        {
            cout << "You've input an invalid number.";
            exit(0);
        }
    }
    removeZero();
}

BigInteger BigInteger::add(BigInteger plus)
{
    if (neg ^ plus.neg)
    {
        if (neg)
        {
            neg = 0;
            return plus.subtract(*this);
        }
        else
        {
            plus.neg = 0;
            return subtract(plus);
        }
    }
    else
    {
        vector<int> result;

        while (intArr.size() != plus.intArr.size())
        {
            if (intArr.size() < plus.intArr.size())
            {
                intArr.push_back(0);
            }
            else
            {
                plus.intArr.push_back(0);
            }
        }

        int _add = 0;
        for (int i = 0; i < intArr.size(); i++)
        {
            result.push_back((_add + intArr[i] + plus.intArr[i]) % 10);
            _add = (_add + intArr[i] + plus.intArr[i]) / 10;
        }
        if (_add)
        {
            result.push_back(1);
        }
        BigInteger res = BigInteger(result);
        res.neg = neg;
        return res.removeZero();
    }
}

BigInteger BigInteger::add(string plus)
{
    return add(BigInteger(plus));
}

BigInteger BigInteger::subtract(BigInteger minus)
{

    if (neg ^ minus.neg)
    {
        if (neg)
        {
            minus.neg = 1;
            return add(minus);
        }
        else
        {
            minus.neg = 0;
            return add(minus);
        }
    }
    else
    {
        vector<int> result, former, latter;
        int resNeg;
        while (intArr.size() != minus.intArr.size())
        {
            if (intArr.size() < minus.intArr.size())
            {
                intArr.push_back(0);
            }
            else
            {
                minus.intArr.push_back(0);
            }
        }

        for (int i = intArr.size() - 1; i >= 0; --i)
        {
            if (intArr[i] > minus.intArr[i])
            {
                former = intArr;
                latter = minus.intArr;
                resNeg = 0;
                break;
            }
            else if (intArr[i] < minus.intArr[i])
            {
                latter = intArr;
                former = minus.intArr;
                resNeg = 1;
                break;
            }
            else if (i == 0)
            {
                return BigInteger("0");
            }
        }

        int _minus = 0;
        for (int i = 0; i < intArr.size(); i++)
        {
            if (_minus + former[i] - latter[i] < 0)
            {
                result.push_back(_minus + former[i] - latter[i] + 10);
                _minus = -1;
            }
            else
            {
                result.push_back(_minus + former[i] - latter[i]);
                _minus = 0;
            }
        }
        if (neg)
        {
            resNeg = !resNeg;
        }
        BigInteger res = BigInteger(result);
        res.neg = resNeg;
        return res.removeZero();
    }
}

BigInteger BigInteger::subtract(string minus)
{
    return subtract(BigInteger(minus));
}

BigInteger BigInteger::subtract(int minus)
{
    return subtract(BigInteger(minus));
}

BigInteger BigInteger::multiply(BigInteger mul)
{
    BigInteger res = BigInteger(0);
    int nega = mul.neg ^ neg;
    mul.neg = neg = 0;
    for (int i = 0; i < mul.intArr.size(); i++)
    {
        vector<int> unit;
        int m = mul.intArr[i];
        int _mul = 0;
        for (int i = 0; i < intArr.size(); i++)
        {
            unit.push_back((intArr[i] * m + _mul) % 10);
            _mul = (intArr[i] * m + _mul) / 10;
        }
        if (_mul)
        {
            unit.push_back(_mul);
        }

        int t = i;
        while (t--)
        {
            unit.emplace(unit.begin(), 0);
        }
        BigInteger _unit = BigInteger(unit);
        _unit.neg = 0;
        res = res.add(_unit);
    }
    res.neg = nega;
    return res;
}

BigInteger BigInteger::multiply(string mul)
{
    return multiply(BigInteger(mul));
}

BigInteger BigInteger::multiply(int mul)
{
    return multiply(BigInteger(mul));
}

BigInteger BigInteger::divide(int div)
{
    if (!div)
    {
        cout << "Cannot divide a number by 0.";
        exit(0);
    }
    vector<int> result;
    int nega = div < 0 ^ neg;
    div = abs(div);
    neg = 0;
    long long _div=0;
    for (int i = intArr.size() - 1 ; i >= 0; i--, _div *= 10)
    {
        result.emplace(result.begin(), (_div + intArr[i]) / div);
        _div = (_div + intArr[i]) % div;
    }
    BigInteger res = BigInteger(result);
    res.neg = nega;
    return res.removeZero();
}

BigInteger::BigInteger(vector<int> intArr)
{
    this->intArr = intArr;
}

BigInteger::BigInteger(int num)
{
    neg = num < 0;
    num = neg ? -1 * num : num;
    do
    {
        intArr.push_back(num % 10);
    } while (num /= 10);
}

bool BigInteger::equals(BigInteger num)
{
    return printNum().compare(num.printNum()) == 0;
}

bool BigInteger::equals(int num)
{
    return equals(BigInteger(num));
}

bool BigInteger::equals(string num)
{
    return equals(BigInteger(num));
}

BigInteger BigInteger::removeZero()
{
    while (intArr[intArr.size() - 1] == 0 && intArr.size() > 1)
    {
        intArr.pop_back();
    }
    return *this;
}

int main(){
            freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    string a;
    int b;
    cin>>a>>b;
    cout<<BigInteger(a).divide(b);
    return 0;
}