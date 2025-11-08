int xorfrom1tillN(int N)
{
    if (N % 4 == 0)
        return N;
    if (N % 4 == 1)
        return 1;
    if (N % 4 == 2)
        return N + 1;
    return 0;
}

int xorInRange(int L, int R)
{
    return xorfrom1tillN(R) ^ xorfrom1tillN(L - 1);
}