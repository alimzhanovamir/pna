#include "hello.h"
#include <string.h>
#include <stdio.h>

const char removeNewLineChar(char name[20]) {
    return name[strcspn(name, "\n")] = 0;
}

int main() {
    char rawName[20], rawSurname[20], rawPatronymic[20];
    printf("Введите ваше имя\n");
    fgets(rawName, 20, stdin);
    printf("Введите вашу фамилию\n");
    fgets(rawSurname, 20, stdin);
    printf("Введите ваше отчество\n");
    fgets(rawPatronymic, 20, stdin);
    
    char text[60] = "";

    printf("%s %s %s\n", rawName, rawSurname, rawPatronymic);
    char name = removeNewLineChar(rawName);
    char surname = removeNewLineChar(rawSurname);
    char patronymic = removeNewLineChar(rawPatronymic);
    printf("%s %s %s\n", &name, &surname, &patronymic);

    if (strlen(&name) > 1) {
        strcat(text, &name);

        if (strlen(&surname) > 1) {
            strcat(text, " ");
            strcat(text, &surname);
        }

        if (strlen(&patronymic) > 1) {
            strcat(text, " ");
            strcat(text, &patronymic);
        }
    } else {
        strcat(text, "Незнакомец");
    }
    

    hello_message(text);
    return 0;
}