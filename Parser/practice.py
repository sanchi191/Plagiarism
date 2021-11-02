# remove all numerics
numerics=['+','-','=','*','/','<','>',':','.','!','"','\'','&','|','^',]

def removenum(file,remove = False):
    new_str = " "
    w = set(file)
    for num in w:
        if num in numerics:
            if remove==True:
                fil = " "
            else:
                fil = " " + num + " "
            new_str = new_str+ fil
    return new_str
# remove keywords of c++
keywords = ['auto'	,'break','case',	'char',	'const',	'continue'	,'default',	'do',
'double','else'	,'enum'	,'extern',	'float'	,'for',	'goto',	'if',
'int',	'long',	'register',	'return',	'short',	'signed',	'sizeof',	'static',
'struct',	'switch','typedef', 	'union'	,'unsigned'	,'void'	,'volatile'	,'while']
def remkey(file):
    finalstr = ""
    for i in file:
        for j in i:
            if j in keywords:
                pass
            else:
                finalstr= finalstr+ " k "
    return finalstr
