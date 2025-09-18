/*
** EPITECH PROJECT, 2025
** unit_test
** File description:
** 1
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

int valid_number(const char *str);
void redirect_all_stdout(void)
{
        cr_redirect_stdout();
        cr_redirect_stderr();
}

Test(valid_number, test_1, .init=redirect_all_stdout)
{
    int a = valid_number("12");
        cr_assert_eq(a, 1);
}

Test(valid_number, test_2, .init=redirect_all_stdout)
{
    int a = valid_number("12.3.4");
	cr_assert_eq(a, 0);
}

Test(valid_number, test_3, .init=redirect_all_stdout)
{
    int a = valid_number("-12df5");
	cr_assert_eq(a, 0);
}

Test(valid_number, test_4, .init=redirect_all_stdout)
{
    int a = valid_number("+135");
        cr_assert_eq(a, 1);
}

Test(valid_number, test_5, .init=redirect_all_stdout)
{
    int a = valid_number("\n");
	cr_assert_eq(a, 1);
}
