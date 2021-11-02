def remComm(prgm):
    n = len(prgm)
    res = str(res)
    bool(s_cmt)
    bool(m_cmt)
    #Traversethe given program

while(i<n):
        # Ifsinglelinecomment
        if (s_cmt == true and prgm[i] == '\n'):
            s_cmt = false
            # If multiple line comment is on, then check for end of it
        elif (m_cmt == true and prgm[i] == '*' and prgm[i + 1] == '/'):
            m_cmt = false
            i++

        # If this character is in a comment, ignore it
        elif (s_cmt || m_cmt):
            continue

        # Check for beginning of comments and set the approproate flags
        elif (prgm[i] == '/' and prgm[i + 1] == '/'):
            s_cmt = true
            i++
        elif (prgm[i] == '/' and prgm[i + 1] == '*'):
            m_cmt = true
            i++

        # If current character is a non-comment character, append it to res
        else:
            res += prgm[i]

    return res

