bool isMatchCore(char* s, char* p)
{
    // s，p都为空时，返回true
    if(*p == '\0' && *s == '\0')
        return true;
    // s不为空，p为空时返回true
    if(*s != '\0' && *p == '\0')
        return false;
    // p+1等于*时，两种匹配方式
    if(*(p + 1) == '*')
    {
        // 三种情况
        if(*p != *s && *p != '.')
            return isMatchCore(s, p + 2);
        if(*p == '.' && *s != '\0')
            return isMatchCore(s, p + 2) || isMatchCore(s + 1, p);
        else if(*p == '.' && *s =='\0')
            return isMatchCore(s, p + 2);
        if(*p ==*s)
            return isMatchCore(s + 1, p) || isMatchCore(s, p + 2);
    }

    // 对于s不为空，并且相等的情况
    if((*p == '.' && *s != '\0') || *p ==*s)
        return isMatchCore(s + 1, p + 1);
    return false;
}


bool isMatch(char* s, char* p){
    if(p == NULL && s == NULL)
        return false;
    return isMatchCore(s,p);
}
