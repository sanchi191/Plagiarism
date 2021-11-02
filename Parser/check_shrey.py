numerics=['+','-','=','*','/','<','>',':','.','!','"','\'','&','|','^','#',';','{','}','(',')']
file = open('subtree_remComm.cpp','r')
f_read = file.read()
w = list(f_read)

# for word in w:
#     print(word)

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

# print(new_str)
keywords = ['auto'	,'break','case',	'char',	'const',	'continue'	,'default',	'do',
'double','else'	,'enum'	,'extern',	'float'	,'for',	'goto',	'if',
'int',	'long',	'register',	'return',	'short',	'signed',	'sizeof',	'static',
'struct',	'switch','typedef', 	'union'	,'unsigned'	,'void'	,'volatile'	,'while']

finalstr = ""
for j in new_str.split():
    # print(j)
    # for j in i:
    if j in keywords or j in numerics:
        finalstr += (" " + j + " ")
        # pass
    else:
        finalstr= finalstr+ " k "


print(finalstr)

