
# 不会做

def ans(q: str):

    t1 = list(map(lambda x: x.lower() if x != 'I' else x,
                  filter(lambda x: len(x) != 0,
                         q.strip().split(' '))))

    t2 = ''
    for w in t1:
        if w[0].isalpha() or w[0].isnumeric():
            t2 += ' '+w
        else:
            t2 += w
    t2 = t2.strip()

    t3 = t2.replace('I ', 'you ').replace(
        ' I ', ' you ').replace(' me', ' you')
    t4 = t3.replace('can you', 'I can').replace('could you', 'I could')

    t5 = t4.replace('?', '!')
    return t5


N = int(input())
for _ in range(N):
    q = input()
    print(q)
    a = ans(q)
    print(f'AI: {a}')
