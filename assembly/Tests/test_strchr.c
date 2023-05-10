/*
** EPITECH PROJECT, 2022
** asm
** File description:
** test_strchr.c
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <dlfcn.h>

static void *test_dl()
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    if (handle) {
        return handle;
    }
    fprintf(stderr, "%s\n", dlerror());
    exit(84);
}

static char *(*load_strchr(void *test_lib))(const char *str, const char c)
{
    char *(*strchr)(const char *str, const char c) = dlsym(test_lib, "strchr");
    if (!strchr) {
        fprintf(stderr, "%s\n", dlerror());
        exit(84);
    }
}

Test(strchr, test_strchr) {
    void *handle = test_dl();
    char *(*strchr)(const char *str, const char c) = load_strchr(handle);

    const char str[] = "Hello, world!";
    const char c = 'o';
    const char c2 = 'y';
    char *ouais = strchr(str, c2);
    char *test = strchr(str, c);

    cr_assert_eq(test - str, 4);
    cr_assert_neq(test - str, 5);
    cr_assert_neq(ouais - str, 4);

    dlclose(handle);
}