cnt = 0
def check(l1,l2,r1,r2):
    # print('---', l1,r1,l2,r2, l1 <= l2, l2, '<=', r1, l2 <= r1, (l1 <= l2) and (l2 <= r1))
    if (l1 == l2 and r1 == r2):
        return 1
    elif (l1 <= l2 and l2 <= r1):
        return 1
    elif (l2 <= l1 and l1 <= r2):
        return 1
    elif (r2 <= r1 and r2 >= l1):
        return 1
    elif (r1 <= r2 and r1 >= l2):
        return 1
    return 0

ans = 0
with open('filename.txt', 'r') as f:
    lines = f.readlines()
for inp in lines:
    st = inp.split(',')
    st1 = st[0].split('-')
    st2 = st[1].split('-')
    l1 = int(st1[0])
    r1 = int(st1[1])
    l2 = int(st2[0])
    r2 = int(st2[1])
    ans += check(l1,l2,r1,r2)
print(ans)

# while(True):
#     try:
#         st = input().split(',')
#         st1 = st[0].split('-')
#         st2 = st[1].split('-')
#         l1 = st1[0]
#         r1 = st1[1]
#         l2 = st2[0]
#         r2 = st2[1]
#         ans += check(l1,l2,r1,r2)
#         #print(ans)
#     except EOFError:
#         print(ans)
#         break

# 2-4,6-8
# 2-3,4-5
# 5-7,7-9
# 2-8,3-7
# 6-6,4-6
# 2-6,4-8