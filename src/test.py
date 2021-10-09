import os

cnt = 0
fail_list=[]
for i in range(1,13):
    print('%d ----------------' %i)
    os.system('mkdir -p ../test/out/')
    os.system('../bin/splc ../test/stage1/test_1_r%02d.spl > ../test/out/%d' % (i,i))
    if os.system('diff ../test/stage1/test_1_r%02d.out ../test/out/%d' % (i,i)):
        fail_list.append(i)
    else:
        cnt=cnt+1   
print('Passed %d of 12' % cnt)
print('Failed test cases: ')
print(fail_list)