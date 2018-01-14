/* { dg-do compile } */
/* { dg-options "-O2 -mno-indirect-branch-register -mfunction-return=keep -mindirect-branch=thunk-extern -fno-pic" } */

extern void (*bar) (void);

__attribute__ ((function_return("thunk-inline")))
int
foo (void)
{
  bar ();
  return 0;
}

/* { dg-final { scan-assembler-times {\tlfence} 1 } } */
/* { dg-final { scan-assembler-not "jmp\[ \t\]*__x86_return_thunk" } } */
/* { dg-final { scan-assembler "jmp\[ \t\]*\.LIND" } } */
/* { dg-final { scan-assembler "call\[ \t\]*\.LIND" } } */
/* { dg-final { scan-assembler "push(?:l|q)\[ \t\]*_?bar" { target { ! x32 } } } } */
/* { dg-final { scan-assembler "jmp\[ \t\]*__x86_indirect_thunk" { target { ! x32 } } } } */
/* { dg-final { scan-assembler "call\[ \t\]*__x86_indirect_thunk_(r|e)ax" { target { x32 } }  } } */
/* { dg-final { scan-assembler-not "pushq\[ \t\]%rax" { target x32 } } } */
