def remComm(prgm):
    n = len(prgm)
    res = ""
    s_cmt = False
    m_cmt = False
    #Traversethe given program
    i=0
    while(i<n):
        # Ifsinglelinecomment
        if (s_cmt == True and prgm[i] == '\n'):
            s_cmt = False
            i+=1
            # If multiple line comment is on, then check for end of it
        elif (m_cmt == True and prgm[i] == '*' and prgm[i + 1] == '/'):
            m_cmt = False
            i+=2

        # If this character is in a comment, ignore it
        elif (s_cmt or m_cmt):
            i+=1
            continue

        # Check for beginning of comments and set the approproate flags
        elif (prgm[i] == '/' and prgm[i + 1] == '/'):
            s_cmt = True
            i+=1
        elif (prgm[i] == '/' and prgm[i + 1] == '*'):
            m_cmt = True
            i+=1

        # If current character is a non-comment character, append it to res
        else:
            res += prgm[i]
            i+=1

    return res


f = open("subtree.cpp", 'r')
prgm = f.read()
f.close()
w = remComm(prgm)
wr = open("main1.cpp", 'w')
wr.write(w)
wr.close()
#print(w)


file = open('subtree.cpp','r')
f_read = file.read()
w = list(f_read)
numerics=['+','-','=','*','/','<','>',':','.','!','"','\'','&','|','^','#',';','{','}','(',')']
keywords = ['auto'	,'break','case',	'char',	'const',	'continue'	,'default',	'do',
'double','else'	,'enum'	,'extern',	'float'	,'for',	'goto',	'if',
'int',	'long',	'register',	'return',	'short',	'signed',	'sizeof',	'static',
'struct',	'switch','typedef', 	'union'	,'unsigned'	,'void'	,'volatile'	,'while']
new_str = " "
remove = False
for num in w:
    if num in numerics:
        if remove==True:
            fil = " "
        else:
            fil = " " + num + " "
        new_str = new_str + fil
    else:
        new_str+=num
finalstr = ""
for j in new_str.split():
    # print(j)
    # for j in i:
    if j in keywords or j in numerics:
        finalstr += (" " + j + " ")
        # pass
    else:
        finalstr= finalstr+ " k "


def k_gram(finalstr,k):
    result = set()
    for line in range(len(finalstr)-k):
        #print(line)
        kgram_string = ""
        for word in range(k):
            #print(word)
            kgram_string = kgram_string + finalstr[line+word]
            #print(kgram_string)
            #break
        result.add(kgram_string)
    return result
wis = k_gram(finalstr,5)
print(wis)
