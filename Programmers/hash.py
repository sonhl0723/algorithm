from collections import Counter

def solution(participant, completion):
    answer = ''
    part = Counter(participant)
    comp = Counter(completion)

    for part_key, part_val in part.items():
        if part_key in comp and comp[part_key] == part_val: continue
        else:
            answer = part_key
            break

    return answer



print(solution(["marina", "josipa", "nikola", "vinko", "filipa"], ["josipa", "filipa", "marina", "nikola"]))