/* { dg-do compile } */
/* { dg-options "-O2 -mfunction-return=thunk" } */

void
foo (void)
{
}

/* { dg-final { scan-assembler "jmp\[ \t\]*__x86_return_thunk" } } */
/* { dg-final { scan-assembler "jmp\[ \t\]*\.LIND" } } */
/* { dg-final { scan-assembler "call\[ \t\]*\.LIND" } } */
/* { dg-final { scan-assembler {\tlfence} } } */
