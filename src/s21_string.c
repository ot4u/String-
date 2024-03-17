#include "s21_string.h"

#include "s21_sprintf.h"
// набросок

#if defined __linux__
#define MinCount 0
#define MaxCount 133
#define UnknownError "Unknown error %d"
static const char *ErrorsMas[] = {
    "Success",
    "Operation not permitted",
    "No such file or directory",
    "No such process",
    "Interrupted system call",
    "Input/output error",
    "No such device or address",
    "Argument list too long",
    "Exec format error",
    "Bad file descriptor",
    "No child processes",
    "Resource temporarily unavailable",
    "Cannot allocate memory",
    "Permission denied",
    "Bad address",
    "Block device required",
    "Device or resource busy",
    "File exists",
    "Invalid cross-device link",
    "No such device",
    "Not a directory",
    "Is a directory",
    "Invalid argument",
    "Too many open files in system",
    "Too many open files",
    "Inappropriate ioctl for device",
    "Text file busy",
    "File too large",
    "No space left on device",
    "Illegal seek",
    "Read-only file system",
    "Too many links",
    "Broken pipe",
    "Numerical argument out of domain",
    "Numerical result out of range",
    "Resource deadlock avoided",
    "File name too long",
    "No locks available",
    "Function not implemented",
    "Directory not empty",
    "Too many levels of symbolic links",
    "Unknown error 41",
    "No message of desired type",
    "Identifier removed",
    "Channel number out of range",
    "Level 2 not synchronized",
    "Level 3 halted",
    "Level 3 reset",
    "Link number out of range",
    "Protocol driver not attached",
    "No CSI structure available",
    "Level 2 halted",
    "Invalid exchange",
    "Invalid request descriptor",
    "Exchange full",
    "No anode",
    "Invalid request code",
    "Invalid slot",
    "Unknown error 58",
    "Bad font file format",
    "Device not a stream",
    "No data available",
    "Timer expired",
    "Out of streams resources",
    "Machine is not on the network",
    "Package not installed",
    "Object is remote",
    "Link has been severed",
    "Advertise error",
    "Srmount error",
    "Communication error on send",
    "Protocol error",
    "Multihop attempted",
    "RFS specific error",
    "Bad message",
    "Value too large for defined data type",
    "Name not unique on network",
    "File descriptor in bad state",
    "Remote address changed",
    "Can not access a needed shared library",
    "Accessing a corrupted shared library",
    ".lib section in a.out corrupted",
    "Attempting to link in too many shared libraries",
    "Cannot exec a shared library directly",
    "Invalid or incomplete multibyte or wide character",
    "Interrupted system call should be restarted",
    "Streams pipe error",
    "Too many users",
    "Socket operation on non-socket",
    "Destination address required",
    "Message too long",
    "Protocol wrong type for socket",
    "Protocol not available",
    "Protocol not supported",
    "Socket type not supported",
    "Operation not supported",
    "Protocol family not supported",
    "Address family not supported by protocol",
    "Address already in use",
    "Cannot assign requested address",
    "Network is down",
    "Network is unreachable",
    "Network dropped connection on reset",
    "Software caused connection abort",
    "Connection reset by peer",
    "No buffer space available",
    "Transport endpoint is already connected",
    "Transport endpoint is not connected",
    "Cannot send after transport endpoint shutdown",
    "Too many references: cannot splice",
    "Connection timed out",
    "Connection refused",
    "Host is down",
    "No route to host",
    "Operation already in progress",
    "Operation now in progress",
    "Stale file handle",
    "Structure needs cleaning",
    "Not a XENIX named type file",
    "No XENIX semaphores available",
    "Is a named type file",
    "Remote I/O error",
    "Disk quota exceeded",
    "No medium found",
    "Wrong medium type",
    "Operation canceled",
    "Required key not available",
    "Key has expired",
    "Key has been revoked",
    "Key was rejected by service",
    "Owner died",
    "State not recoverable",
    "Operation not possible due to RF-kill",
    "Memory page has hardware error"};

#elif defined __APPLE__
#define MinCount 0
#define MaxCount 106
#define UnknownError "Unknown error: %d"
static const char *ErrorsMas[] = {
    "Undefined error: 0",
    "Operation not permitted",
    "No such file or directory",
    "No such process",
    "Interrupted system call",
    "Input/output error",
    "Device not configured",
    "Argument list too long",
    "Exec format error",
    "Bad file descriptor",
    "No child processes",
    "Resource deadlock avoided",
    "Cannot allocate memory",
    "Permission denied",
    "Bad address",
    "Block device required",
    "Resource busy",
    "File exists",
    "Cross-device link",
    "Operation not supported by device",
    "Not a directory",
    "Is a directory",
    "Invalid argument",
    "Too many open files in system",
    "Too many open files",
    "Inappropriate ioctl for device",
    "Text file busy",
    "File too large",
    "No space left on device",
    "Illegal seek",
    "Read-only file system",
    "Too many links",
    "Broken pipe",
    "Numerical argument out of domain",
    "Result too large",
    "Resource temporarily unavailable",
    "Operation now in progress",
    "Operation already in progress",
    "Socket operation on non-socket",
    "Destination address required",
    "Message too long",
    "Protocol wrong type for socket",
    "Protocol not available",
    "Protocol not supported",
    "Socket type not supported",
    "Operation not supported",
    "Protocol family not supported",
    "Address family not supported by protocol family",
    "Address already in use",
    "Can't assign requested address",
    "Network is down",
    "Network is unreachable",
    "Network dropped connection on reset",
    "Software caused connection abort",
    "Connection reset by peer",
    "No buffer space available",
    "Socket is already connected",
    "Socket is not connected",
    "Can't send after socket shutdown",
    "Too many references: can't splice",
    "Operation timed out",
    "Connection refused",
    "Too many levels of symbolic links",
    "File name too long",
    "Host is down",
    "No route to host",
    "Directory not empty",
    "Too many processes",
    "Too many users",
    "Disc quota exceeded",
    "Stale NFS file handle",
    "Too many levels of remote in path",
    "RPC struct is bad",
    "RPC version wrong",
    "RPC prog. not avail",
    "Program version wrong",
    "Bad procedure for program",
    "No locks available",
    "Function not implemented",
    "Inappropriate file type or format",
    "Authentication error",
    "Need authenticator",
    "Device power is off",
    "Device error",
    "Value too large to be stored in data type",
    "Bad executable (or shared library)",
    "Bad CPU type in executable",
    "Shared library version mismatch",
    "Malformed Mach-o file",
    "Operation canceled",
    "Identifier removed",
    "No message of desired type",
    "Illegal byte sequence",
    "Attribute not found",
    "Bad message",
    "EMULTIHOP (Reserved)",
    "No message available on STREAM",
    "ENOLINK (Reserved)",
    "No STREAM resources",
    "Not a STREAM",
    "Protocol error",
    "STREAM ioctl timeout",
    "Operation not supported on socket",
    "Policy not found",
    "State not recoverable",
    "Previous owner died",
    "Interface output queue is full",
    "Unknown error"};
#endif

char *s21_strstr(const char *haystack, const char *needle) {
  const char *a;
  const char *b;

  b = needle;

  if (*b == 0) {
    return (char *)haystack;
  }

  for (; *haystack != 0; haystack += 1) {
    if (*haystack != *b) {
      continue;
    }

    a = haystack;
    while (1) {
      if (*b == 0) {
        return (char *)haystack;
      }
      if (*a++ != *b++) {
        break;
      }
    }
    b = needle;
  }

  return s21_NULL;
}

char *s21_strtok(char *str, const char *delim) {
  static int next_s21_null, tok;
  static size_t ind;
  static char *max_ptr;
  static char *addr;
  if (str) {
    tok = 1;
    ind = 0, next_s21_null = 0;
    addr = str + s21_strspn(str, delim);
    max_ptr = str + s21_strlen(str);
  }
  char *res = s21_NULL;
  if (!(addr >= max_ptr || next_s21_null)) {
    int non_delim = 1;
    for (int i = 0; addr[i]; i++) {
      size_t step = s21_strspn(addr + i, delim);
      if (step != 0) {
        non_delim = 0;
        for (size_t j = i; j < i + step; j++) addr[j] = '\0';
        ind = step + i;
        break;
      }
    }
    if (tok == 1 && non_delim) next_s21_null = 1;
    res = addr;
    addr += ind;
  }
  ++tok;
  return res;
}

void *s21_memchr(const void *str, int c, s21_size_t n) {
  unsigned char *p = (unsigned char *)str;
  unsigned char *isCharFind = s21_NULL;
  while ((str != s21_NULL) && (n--)) {
    if (*p != (unsigned char)c) {
      p++;
    } else {
      isCharFind = p;
      break;
    }
  }
  return isCharFind;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  char *pszDest = (char *)dest;
  const char *pszSource = (const char *)src;
  if ((pszDest != s21_NULL) && (pszSource != s21_NULL)) {
    while (n) {
      *(pszDest++) = *(pszSource++);
      --n;
    }
  }
  return dest;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  unsigned char *ptr1 = (unsigned char *)str1;
  unsigned char *ptr2 = (unsigned char *)str2;
  int flag_memcmp = 0, flag_of_end = 0;
  while (!flag_of_end && (n--) && ptr1 && ptr2) {
    if (*ptr1 != *ptr2) {
      flag_memcmp = (*ptr1) - (*ptr2);
      flag_of_end = 1;
    }
    ptr1++;
    ptr2++;
  }
  return flag_memcmp;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  char *s = (char *)str;
  for (s21_size_t i = 0; i < n; i++) {
    s[i] = c;
  }
  return str;
}

char *s21_strncat(char *str1, const char *src, s21_size_t n) {
  if ((str1 == s21_NULL) && (src == s21_NULL)) {
    return s21_NULL;
  }
  char *dest = str1;
  while (*dest != '\0') {
    dest++;
  }
  char *p = dest + s21_strlen(dest);
  while (*src != '\0' && n--) {
    *p++ = *src++;
  }
  *p = '\0';

  return str1;
}

char *s21_strchr(const char *str, int c) {
  char *isCharFind = s21_NULL;
  if (str != s21_NULL) {
    do {
      if (*str == (char)c) {
        isCharFind = (char *)str;
        break;
      }
    } while (*str++);
  }
  return isCharFind;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int result = 0;
  while (n--) {
    if (*str1 != *str2) {
      result = *str1 - *str2;
    } else {
      ++str1;
      ++str2;
    }
  }
  return result;
}

s21_size_t s21_strlen(const char *str) {
  const char *end = str;

  while (*end != '\0') {
    ++end;
  }

  return end - str;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  if (n != 0) {
    char *d = dest;
    const char *s = src;
    do {
      if ((*d++ = *s++) == 0) {
        while (--n > 0) *d++ = 0;

        break;
      }
    } while (--n > 0);
  }
  return dest;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  int len1 = s21_strlen(str2);
  int count = 0;
  int flag = 0;
  char *str11 = (char *)str1;
  while (*str11 != '\0') {
    for (int i = 0; i < len1; i++) {
      if ((*str11) == str2[i]) {
        flag = 1;
        break;
      }
    }
    if (flag == 1) break;
    str11++;
    count++;
  }

  return count;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  char *newMas = s21_NULL;
  int len2 = s21_strlen(str2);
  char *res = s21_NULL;
  if (str1 != s21_NULL && len2 > 0) {
    int flag = 0;
    newMas = (char *)str1;
    while (*newMas != '\0' && flag == 0) {
      for (int k = 0; k < len2; k++) {
        if ((*newMas) == str2[k]) {
          res = newMas;
          flag = 1;
        }
      }
      newMas++;
    }
  }
  return res;
}

char *s21_strerror(int errnum) {
  char *buf = s21_NULL;
  static char str[100] = {'\0'};
  if (errnum >= MinCount && errnum <= MaxCount) {
    buf = (char *)ErrorsMas[errnum];
  } else {
    s21_sprintf(str, UnknownError, errnum);
    buf = str;
  }
  return buf;
}

char *s21_strrchr(const char *str, int c) {
  char *res = s21_NULL;
  do {
    if (*str == (char)c) {
      res = (char *)str;
    }
  } while (*str++);
  return res;
}

s21_size_t s21_strspn(const char *str1, const char *str2) {
  char *newMas = (char *)str1;
  int len = s21_strlen(str2);
  int flag = 0;
  int count = 0;
  while (*newMas != '\0' && flag == 0) {
    int i = 0;
    while (i < len) {
      if ((*newMas) == str2[i]) {
        count++;
        break;
      }
      i++;
      if (i == len) {
        flag = 1;
      }
    }
    newMas++;
  }
  return count;
}

void *s21_to_lower(const char *str) {
  char *ch = s21_NULL;
  if (str) {
    ch = (char *)malloc((s21_strlen(str) + 1) * sizeof(char));  // s21_strlen
    if (ch) {
      s21_strncpy(ch, str, s21_strlen(str));              // s21_strcpy
      for (s21_size_t i = 0; i < s21_strlen(str); i++) {  // s21_strlen
        if (ch[i] >= 'A' && ch[i] <= 'Z') ch[i] += 32;
      }
      ch[s21_strlen(str)] = '\0';
    }
  }
  return ch;
}

void *s21_to_upper(const char *str) {
  char *ch = s21_NULL;
  if (str) {
    ch = (char *)malloc((s21_strlen(str) + 1) * sizeof(char));  // s21_strlen
    if (ch) {
      s21_strncpy(ch, str, s21_strlen(str));              // s21_strcpy
      for (s21_size_t i = 0; i < s21_strlen(str); i++) {  // s21_strlen
        if (ch[i] >= 'a' && ch[i] <= 'z') ch[i] -= 32;
      }
      ch[s21_strlen(str)] = '\0';
    }
  }
  return (void *)ch;
}

void *s21_insert(const char *src, const char *str, size_t start_index) {
  char *ch = s21_NULL;
  s21_size_t len = s21_strlen(str);  // s21_strlen
  if (start_index <= len && src) {
    len += s21_strlen(src);  // s21_strlen
    ch = (char *)malloc((len + 3) * sizeof(char));
    if (ch) {
      s21_size_t i = 0;
      s21_size_t j = 0;
      for (; i < start_index; i++) {
        ch[i] = src[i];
      }
      for (; j < s21_strlen(str); j++) {  // s21_strlen
        ch[i + j] = str[j];
      }
      for (i = start_index; i < len; i++) {
        ch[i + j] = src[i];
      }
      ch[len] = '\0';
    }
  }
  return ch;
}

void delete_first_letter(char *str) {
  s21_size_t counter = 0;
  while (str[counter]) {
    str[counter] = str[counter + 1];
    counter++;
  }
}

void rightpart(char *str, const char *trim_chars) {
  s21_size_t trim_lenght = s21_strlen(trim_chars);  // s21_strlen
  s21_size_t str_length = s21_strlen(str);          // s21_strlen
  for (int i = (int)str_length - 1; i >= 0; i--) {
    int is_break = 0;
    for (s21_size_t j = 0; j < trim_lenght; j++) {
      if (str[i] == trim_chars[j]) {
        str[i] = '\0';
        break;
      }
      if (j == trim_lenght - 1) {
        is_break = 1;
      }
    }
    if (is_break) break;
  }
}

void leftpart(char *str, const char *src, const char *trim_chars) {
  s21_size_t trim_lenght = s21_strlen(trim_chars);  // s21_strlen
  s21_size_t str_length = s21_strlen(src);          // s21_strlen
  for (s21_size_t i = 0; i < str_length; i++) {
    int is_break = 0;
    for (s21_size_t j = 0; j < trim_lenght; j++) {
      if (src[i] == trim_chars[j]) {
        delete_first_letter(str);
        break;
      }
      if (j == trim_lenght - 1) {
        is_break = 1;
      }
    }
    if (is_break) break;
  }
}

void *s21_trim(const char *src, const char *trim_chars) {
  char *str = s21_NULL;
  if (src && trim_chars) {
    str = (char *)malloc((s21_strlen(src) + 1) * sizeof(char));  // s21_strlen
    if (str) {
      char default_chars[10] = " \t\n\v\r\f\0";
      if (trim_chars == s21_NULL || s21_strlen(trim_chars) == 0)  // s21_strlen
        trim_chars = default_chars;
      s21_strncpy(str, (char *)src, s21_strlen((char *)src));  // s21_strcpy
      leftpart(str, src, trim_chars);
      rightpart(str, trim_chars);
    }
  }
  return str;
}
