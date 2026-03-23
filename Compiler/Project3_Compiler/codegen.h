#ifndef CODEGEN_H
#define CODEGEN_H

#include <stdio.h>

extern FILE *out;

void init_codegen();
void finalize_codegen(const char *classname);

void init_codegen_file(const char *filename);
void close_codegen_file();

void emit_global_field(const char *varname, const char *type, int init_value);
void emit_main_prologue();
void emit_main_epilogue();

void emit_push_constant(int value);
void emit_put_static(const char *varname, const char *type);
void emit_get_static(const char *varname, const char *type);
void emit_istore(int index);
void emit_iload(int index);

void emit_print(const char *type);
void emit_println(const char *type);

int new_label();
void emit_label(int label_id);
void emit_goto(int label_id);
void emit_if_eq_zero(int label_id);
void emit_if_gt(int label_id);

// New additions
void codegen_emit_integer(int value);
void codegen_emit_load_variable(const char *name);
void codegen_emit_store_variable(const char *name);
void codegen_emit_arith_op(const char *op);
void codegen_emit_relop(const char *op);
void codegen_emit_logic_op(const char *op);
void codegen_emit_return();
void codegen_emit_return_value();
void codegen_emit_function_prologue(const char *name);
void codegen_emit_function_epilogue();
void codegen_emit_function_call(const char *name, int argc, const char *ret_type);

void codegen_emit_print(const char *type, const char *literal);
void codegen_emit_println(const char *type, const char *literal);
void codegen_emit_if_eq_zero(int label_id);
void codegen_emit_goto(int label_id);
void codegen_emit_label(int label_id);
void codegen_emit_if_gt(int label_id);

void codegen_emit_string(const char* s);
void emit_function_start(const char *name, const char *ret_type, int param_count, int *param_types);

#endif
