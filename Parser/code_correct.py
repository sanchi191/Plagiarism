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


if __name__ == '__main__':
    file = open("subtree.cpp","r")
    prgm = file.read()
    file.close()
    res = remComm(prgm)
    file_write = open("subtree_remComm.cpp","w")
    file_write.write(res)
    file_write.close()