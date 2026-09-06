first_word = input()
second_word = input()


def check_anagram(w1, w2):
    if len(w1) != len(w2):
        return 'NO'
    counts = {}
    for ch in w1:
        counts[ch] = counts.get(ch, 0) + 1
    for ch in w2:
        if ch not in counts:
            return 'NO'
        counts[ch] -= 1
        if counts[ch] < 0:
            return 'NO'
    return 'YES'


print(check_anagram(first_word, second_word))
