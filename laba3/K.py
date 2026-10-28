data = list(map(int, input().split()))
h = data[1:]

import sys

def main():
    data = sys.stdin.buffer.read().split()
    n = int(data[0])
    h = list(map(int, data[1:1+n])) + [0]   # фиктивный 0 закрывает всё в конце

    best = 0
    st = []
    for i, cur in enumerate(h):
        while st and h[st[-1]] > cur:
            height = h[st.pop()]
            left = st[-1] if st else -1
            best = max(best, height * (i - left - 1))
        st.append(i)

    print(best)

main()

