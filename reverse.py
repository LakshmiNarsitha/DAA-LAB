#https://leetcode.com/problems/reverse-words-in-a-string/description/
def reverseWords(s):
    l=[]
    l.extend(s.split(" "))
    t=''
    for i in range(0,len(l)):
        j=len(l)-i-1
        t=t+" "+l[j]
    k=t.lstrip()
    k=k.rstrip()
    p=' '.join(k.split())
    return p
s="a good   example"
n=reverseWords(s)
print(n)
