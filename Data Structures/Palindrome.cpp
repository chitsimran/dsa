bool isPalindrome(string &s)
{
    for (int i = 0; i < (int) s.length() / 2; i++)
        if (s[i] != s[s.length() - 1 - i])
            return false;
    return true;
}
