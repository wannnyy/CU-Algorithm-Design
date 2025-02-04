cur <= b)
        return max(solve(l, mid), solve(mid + 1, r));
    else
        return solve(l, m