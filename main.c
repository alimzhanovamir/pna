#include "hello.h"
#include <string.h>
#include <stdio.h>

const char removeNewLineChar(char name[20]) {
    return name[strcspn(name, "\n")] = 0;
}

int main() {
    char name[20], surname[20], patronymic[20];
    char text[60] = "";
    printf("Введите ваше имя\n");
    fgets(name, 20, stdin);
    printf("Введите вашу фамилию\n");
    fgets(surname, 20, stdin);
    printf("Введите ваше отчество\n");
    fgets(patronymic, 20, stdin);
    
    removeNewLineChar(name);
    removeNewLineChar(surname);
    removeNewLineChar(patronymic);

    if (strlen(name) > 1) {
        strcat(text, name);

        if (strlen(surname) > 1 && strlen(patronymic) > 1) {
            strcat(text, " ");
            strcat(text, surname);
            strcat(text, " ");
            strcat(text, patronymic);
        }
    } else {
        strcat(text, "незнакомец");
    }
    

    hello_message(text);
    return 0;
}