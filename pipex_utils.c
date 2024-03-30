//#include "pipex.h"

size_t ft_strlen(const char *s)
{
    size_t i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

void   ft_putstr_fd(char *s, int fd)
{
    write(fd, s, ft_strlen(s));
}

char **free_arr(char **arr, int i)
{
    while (i > 0)
    {
        free(arr[i]);
        i--;
    }
    free(arr);
    return (0);
}

char *ft_memcpy(char *dst, const char *src, size_t n)
{
    size_t i;

    i = 0;
    while (i < n)
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return (dst);
}

size_t word_count(char const *s, char c)
{
    size_t cnt;
    size_t i;
    int flag;

    flag = 1;
    cnt = 0;
    i = 1;
    while (s[i])
    {
        if ((s[i - 1] == c && s[i] != c) || (s[0] != c && flag == 1))
        {
            if (flag == 1)
                flag = 0;
            cnt++;
        }
        i++;
    }
    return (cnt);
}

size_t word_len(char const *s, char c)
{
    size_t i;

    i = 0;
    while (s[i] != c && s[i])
        i++;
    return (i);
}

char **ft_split(char const *s, char c)
{
    size_t cnt;
    size_t i;
    size_t arr_len;
    char **arr;

    if (!s)
        return (NULL);
    if (c == '\0')
        return (NULL);

    i = 0;
    cnt = 0;
    cnt = word_count(s, c);
    arr = (char **)malloc(sizeof(char *) * cnt + 1);
    if (arr == 0)
        return (0);
    while (cnt--)
    {
        while (*(s++) == c)
            ;
        arr_len = word_len(--s, c);
        arr[i] = (char *)malloc(sizeof(char) * (arr_len + 1));
        if (arr[i] == 0)
            return (free_arr(arr, cnt));
        arr[i] = ft_memcpy(arr[i], s, arr_len);
        s += arr_len;
        i++;
    }
    arr[i] = 0;
    return (arr);
}

char *ft_strdup(const char *s)
{
        char *ptr;
        size_t len;
        size_t i;

        len = ft_strlen(s);
        ptr = (char *)malloc(sizeof(char) * (len + 1));
        if (ptr == 0)
            return (0);
        i = 0;
        while (i < len)
        {
            ptr[i] = s[i];
            i++;
        }
        ptr[i] = '\0';
        return (ptr);
}

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;

    i = 0;
    while (i < n && s1[i] && s2[i])
    {
        if (s1[i] != s2[i])
            return ((unsigned char)s1[i] - (unsigned char)s2[i]);
        i++;
    }
    if (i == n)
        return (0);
    return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char *ft_strjoin(char const *s1, char const *s2)
{
    char *str;
    size_t len;

    if (!s1 || !s2)
        return (NULL);
    len = ft_strlen(s1) + ft_strlen(s2);
    str = (char *)malloc(sizeof(char) * (len + 1));
    if (!str)
        return (NULL);
    ft_strlcpy(str, s1, ft_strlen(s1) + 1);
    ft_strlcat(str, s2, len + 1);
    return (str);
}

size_t ft_strlcat(char *dst, const char *src, size_t size)
{
    size_t i;
    size_t j;
    size_t dst_len;
    size_t src_len;

    i = 0;
    j = 0;
    dst_len = ft_strlen(dst);
    src_len = ft_strlen(src);
    if (size <= dst_len)
        return (size + src_len); // 이만큼의 공간이 있어야 복사가 가능함을 알려주는 것
    while (dst[i])
        i++;
    while (src[j] && i + 1 < size)
        dst[i++] = src[j++];
    if (i < size)
        dst[i] = '\0';
    return (dst_len + src_len); // 복사를 성공했음
}

size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
    size_t i;

    i = 0;
    if (dstsize == 0)
        return (ft_strlen(src));
    while (src[i] && i < dstsize - 1)
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return (ft_strlen(src));
}