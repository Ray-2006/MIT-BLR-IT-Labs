/* 1.
Write a program to perform following string operations without using string handling functions:
a.) len of the string
b.) string concatenation
c.) string comparison
d.) to insert a sub string
e.) to delete a substring
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define size 100

void getString(char print[], char str[], int maxSize) {
    printf("%s", print);
    fgets(str, maxSize, stdin);
    str[strcspn(str, "\n")] = 0;
}

int strLen(char str[]) {
    int len = 0;
    while (str[len] != '\0') { len++; }
    return len;
}

void strConcat(char str1[], char str2[]) {
    int i = 0, j = 0;
    while (str1[i] != '\0') { i++; }
    while (str2[j] != '\0') {
        str1[i++] = str2[j++];
    }
    str1[i] = '\0';
}

bool strCompare(char str1[], char str2[]) {
    bool flag = true;
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return flag = false;
        }
        i++;
    }
    return (flag);
}

void insertSubString(char str[], char subStr[], int pos) {
    int lenStr = strLen(str);
    int lenSub = strLen(subStr);
    if (pos < 0 || pos  > lenStr) {
        printf(" > Invalid position for insertion.\n");
        return;
    }
    for (int i = lenStr; i >= pos; i--) {
        str[i + lenSub] = str[i];
    }
    for (int i = 0; i < lenSub; i++) {
        str[pos + i] = subStr[i];
    }
    str[lenStr + lenSub] = '\0';
}

void deleteSubString(char str[], char subStr[]) {
    int lenStr = strLen(str);
    int lenSub = strLen(subStr);
    for (int i = 0; i <= lenStr - lenSub; i++) {
        if (strCompare(&str[i], subStr)) {
            for (int j = i; j <= lenStr - lenSub; j++) {
                str[j] = str[j + lenSub];
            }
            return;
        }
    }
    printf(" > Substring not found.\n");
}

int main() {
    char str[size], subStr[size];
    int pos;

    getString("1. Enter the first string: ", str, size);
    printf(" > Length of the string: %d\n", strLen(str));

    getString("2. Enter the second string to concatenate: ", subStr, size);
    strConcat(str, subStr);
    printf(" > Concatenated string: %s\n", str);

    getString("3. Enter another string to compare: ", subStr, size);
    if (strCompare(str, subStr)) {
        printf(" > Strings are equal.\n");
    } else {
        printf(" > Strings are not equal.\n");
    }

    getString("4. Enter a substring to insert: ", subStr, size);
    printf(" > Enter position to insert the substring: ");
    scanf("%d", &pos);
    while (getchar() != '\n');
    insertSubString(str, subStr, pos);
    printf(" > String after insertion: %s\n", str);

    getString("5. Enter a substring to delete: ", subStr, size);
    deleteSubString(str, subStr);
    printf(" > String after deletion: %s\n", str);

    return 0;
}