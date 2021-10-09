import os

cnt = 0
fail_list=[]
for i in range(1,13):
    print('%d ----------------' %i)
    os.system('mkdir -p ../tests/out/')
    os.system('../bin/splc ../tests/stage1/test_1_r%02d.spl > ../tests/out/%d' % (i,i))
    if os.system('diff ../tests/stage1/test_1_r%02d.out ../tests/out/%d' % (i,i)):
        fail_list.append(i)
    else:
        cnt=cnt+1   
print('Passed %d of 12' % cnt)
print('Failed test cases: ')
print(fail_list)