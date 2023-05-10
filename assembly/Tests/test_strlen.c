/*
** EPITECH PROJECT, 2022
** asm
** File description:
** test_strlen.c
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

static unsigned int(*load_strlen(void *test_lib))(const char *str)
{
    unsigned int(*strlen)(const char *str) = dlsym(test_lib, "strlen");
    if (!strlen) {
        fprintf(stderr, "%s\n", dlerror());
        exit(84);
    }
}

Test(strlen, rtest_length) {
    void *handle = test_dl();
    unsigned int(*mstrlen)(const char *str) = load_strlen(handle);

    const char *str = "Hello, world!";
    size_t len = strlen(str);

    cr_assert_eq(len, 13, "Expected length 13, got %lu", len);

    dlclose(handle);
}