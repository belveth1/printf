#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...) {
	va_list args;
    va_start(args, format);
    
    int char_count = 0;
    while (*format) {
        if (*format == '%') {
            format++;
            switch (*format) {
                case 'c': {
                    int c = va_arg(args, int);
                    putchar(c);
                    char_count++;
                    break;
                }
                case 's': {
                    const char* s = va_arg(args, const char*);
                    while (*s) {
                        putchar(*s);
                        s++;
                        char_count++;
                    }
                    break;
                }
                case '%': {
                    putchar('%');
                    char_count++;
                    break;
                }
                default: {
                    // Ignore unsupported format specifiers
                    break;
                }
            }
        } else {
            putchar(*format);
            char_count++;
        }
        format++;
    }

    va_end(args);
    return char_count;
}
