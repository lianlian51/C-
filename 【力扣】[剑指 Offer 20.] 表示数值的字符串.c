// 处理连续的数字
bool scanUnsignedInt(char** ps)
{
    const char * before = *ps;

    while(**ps != '\0' && **ps >= '0' && **ps <= '9'){
        ++(*ps);
    }

    return *ps > before;
}

// 处理+-的情况
bool scanInt(char** s)
{
    if(**s == '+' || **s == '-')
        ++(*s);
    return scanUnsignedInt(s);
}

bool isNumber(char* s){
    if(s == NULL)
        return false;
    // 前空格
    while(*s == ' ')
        ++s;

    bool numeric = scanInt(&s);

	// 。
    if(*s == '.')
    {
        ++s;
        numeric = scanUnsignedInt(&s) || numeric;
    }
	// E,e
    if(*s == 'e' || *s == 'E')
    {
        ++s;
        numeric = numeric && scanInt(&s);
    }
	// 后空格
    while(*s == ' ')
        ++s;
	// 保证numeric真，并且s一定走到了末尾
    return numeric && *s == '\0';
}
