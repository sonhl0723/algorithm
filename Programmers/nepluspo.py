def solution(absolutes, signs):
    for idx, sign in enumerate(signs):
        if not sign: absolutes[idx] *= -1
    return sum(absolutes)