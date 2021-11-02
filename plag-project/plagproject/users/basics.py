import numpy as np
import os
import matplotlib.pyplot as plt
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


# f = open("subtree.cpp", 'r')
# prgm = f.read()
# w = remComm(prgm)
# print(w)
# exit()

numerics=['+','-','=','*','/','<','>',':','.','!','"','\'','&','|','^','#',';','{','}','(',')']
keywords = ['auto'	,'break','case',	'char',	'const',	'continue'	,'default',	'do',
'double','else'	,'enum'	,'extern',	'float'	,'for',	'goto',	'if',
'int',	'long',	'register',	'return',	'short',	'signed',	'sizeof',	'static',
'struct',	'switch','typedef', 	'union'	,'unsigned'	,'void'	,'volatile'	,'while']
def specialchars(code):
    new_str = " "
    remove = False
    for num in code:
        if num in numerics:
            if remove==True:
                fil = " "
            else:
                fil = " " + num + " "
            new_str = new_str + fil
        else:
            new_str+=num
    return new_str
# f = open("subtree.cpp", 'r')
# prgm = f.read()
# w = remComm(prgm)
# w2 = specialchars(w)
# print(w2)
# exit()
def perform_all_funcs(files):
    finalstr = ""
    o1 = remComm(files)
    new_str= specialchars(o1)
    for i in new_str.split():
        # print(j)
        # for j in i:
        if i in keywords or i in numerics:
            finalstr += (" " + i + " ")
            # pass
        else:
            finalstr = finalstr + " k "
    #print(finalstr,"b")
    return finalstr
# f = open("subtree.cpp", 'r')
# prgm = f.read()
# w = perform_all_funcs(prgm)
# print(w)
# exit()
def k_gram(finalstr,k):
    #print(finalstr,"a")
    k=5
    result = set()
    finalstr = finalstr.split()
    for line in range(len(finalstr)-k+1):
        #print(line)
        kgram_string = ""
        for word in range(k):
            #print(word)
            kgram_string = kgram_string + finalstr[line+word]
            #print(kgram_string)
            #break
        result.add(kgram_string)

    return result
# f = open("subtree.cpp", 'r')
# prgm = f.read()
# w = perform_all_funcs(prgm)
# w= k_gram(w,5)
# print(w)
# exit()
def common (files_in_dir):
    files_in_directory = []
    l=0
    C=0
    Cv= []
    path = files_in_dir
    dir = os.listdir(path)
    dir = sorted(dir)
    for i in dir:
        files_in_directory.append(i)
    kgrams = []
    for x in range(len(files_in_directory)):
        f= open(path+"/"+files_in_directory[x],"r")

        kgrams.append(k_gram(perform_all_funcs(f.read()), 5))
    # print(files_in_directory)
    matrix = np.zeros((len(files_in_directory), len(files_in_directory)))
    for z in range(len(files_in_directory)):
        for w in range(z + 1, len(files_in_directory)):
            C=0
            for a in kgrams[z]:
                if a in kgrams[w]:
                    C += 1
            #print(C)
            l = min(len(kgrams[z]), len(kgrams[w]))
            Cv.append(C/l)
            matrix[z,w] = C/l
    return matrix

# path = '/home/oem/PycharmProjects/pythonProject1/Parser/Assignment_5'
# data = common(path)



# plt.imshow(data)
# plt.colorbar()
# plt.show()

