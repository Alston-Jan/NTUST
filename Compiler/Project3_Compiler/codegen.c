#include "codegen.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static char classname[256];

// --- Internal helpers ---
FILE *out;
static int label_counter = 0;

void init_codegen_file(const char *filename) {
    out = fopen(filename, "w");
    if (!out) {
        fprintf(stderr, "Cannot open output file: %s\n", filename);
        exit(1);
    }
}

void close_codegen_file() {
    if (out) fclose(out);
}

void init_codegen(const char* name) {
    strncpy(classname, name, sizeof(classname));
    classname[sizeof(classname)-1] = '\0';  // 保證 null-terminated
}

void finalize_codegen(const char *classname) {
    fprintf(out, "}\n");
}

void emit_global_field(const char *varname, const char *type, int init_value) {
    if (init_value >= 0)
        fprintf(out, "field static %s %s = %d\n", type, varname, init_value);
    else
        fprintf(out, "field static %s %s\n", type, varname);
}

void emit_main_prologue() {
    fprintf(out, "method public static void main(java.lang.String[])\n");
    fprintf(out, "max_stack 15\n");
    fprintf(out, "max_locals 15\n");
    fprintf(out, "{\n");
}

void emit_main_epilogue() {

}

void emit_push_constant(int value) {
    fprintf(out, "sipush %d\n", value);
}

void emit_put_static(const char *varname, const char *type) {
    fprintf(out, "putstatic %s example.%s\n", type, varname);
}

void emit_get_static(const char *varname, const char *type) {
    fprintf(out, "getstatic %s example.%s\n", type, varname);
}

void emit_istore(int index) {
    fprintf(out, "istore %d\n", index);
}

void emit_iload(int index) {
    fprintf(out, "iload %d\n", index);
}

void emit_print(const char *type) {
    fprintf(out, "getstatic java.io.PrintStream java.lang.System.out\n");
    fprintf(out, "invokevirtual void java.io.PrintStream.print(%s)\n", type);
}

void emit_println(const char *type) {
    fprintf(out, "getstatic java.io.PrintStream java.lang.System.out\n");
    fprintf(out, "invokevirtual void java.io.PrintStream.println(%s)\n", type);
}

int new_label() {
    return label_counter++;
}

void emit_label(int label_id) {
    fprintf(out, "L%d:\n", label_id);
}

void emit_goto(int label_id) {
    fprintf(out, "goto L%d\n", label_id);
}

void emit_if_eq_zero(int label_id) {
    fprintf(out, "ifeq L%d\n", label_id);
}

void emit_if_gt(int label_id) {
    fprintf(out, "ifgt L%d\n", label_id);
}

void emit_add() { fprintf(out, "iadd\n"); }
void emit_sub() { fprintf(out, "isub\n"); }
void emit_mul() { fprintf(out, "imul\n"); }
void emit_div() { fprintf(out, "idiv\n"); }
void emit_mod() { fprintf(out, "irem\n"); }
void emit_return() { fprintf(out, "return\n"); }
void emit_assign(const char* name) { emit_put_static(name, "int"); }

void emit_function_start(const char *name, const char *ret_type, int param_count, int *param_types) {
    fprintf(out, "method public static %s %s(", ret_type, name);
    for (int i = 0; i < param_count; i++) {
        const char *type_str = (param_types[i] == 0) ? "int" :
                               (param_types[i] == 1) ? "boolean" :
                               "int";  // default fallback
        fprintf(out, "%s", type_str);
        if (i < param_count - 1) fprintf(out, ", ");
    }
    fprintf(out, ")\nmax_stack 15\nmax_locals 15\n{\n");
}

void emit_function_end() {
    fprintf(out, "}\n");
}

// ==== Additional emit functions used by parser.y ====

void codegen_emit_integer(int value) {
    emit_push_constant(value);
}

void codegen_emit_store_variable(const char* name) {
    fprintf(out, "putstatic int %s.%s\n", classname, name);
}

void codegen_emit_load_variable(const char* name) {
    fprintf(out, "getstatic int %s.%s\n", classname, name);
}

void codegen_emit_arith_op(const char *op) {
    if (strcmp(op, "iadd") == 0) emit_add();
    else if (strcmp(op, "isub") == 0) emit_sub();
    else if (strcmp(op, "imul") == 0) emit_mul();
    else if (strcmp(op, "idiv") == 0) emit_div();
    else if (strcmp(op, "irem") == 0) emit_mod();
    else if (strcmp(op, "ineg") == 0) fprintf(out, "ineg\n");
}

void codegen_emit_relop(const char *op) {
    int label_true = new_label();
    int label_end = new_label();
    fprintf(out, "isub\n");
    if (strcmp(op, "<") == 0) fprintf(out, "iflt L%d\n", label_true);
    else if (strcmp(op, "<=") == 0) fprintf(out, "ifle L%d\n", label_true);
    else if (strcmp(op, "==") == 0) fprintf(out, "ifeq L%d\n", label_true);
    else if (strcmp(op, "!=") == 0) fprintf(out, "ifne L%d\n", label_true);
    else if (strcmp(op, ">=") == 0) fprintf(out, "ifge L%d\n", label_true);
    else if (strcmp(op, ">") == 0) fprintf(out, "ifgt L%d\n", label_true);
    fprintf(out, "iconst_0\n");
    fprintf(out, "goto L%d\n", label_end);
    fprintf(out, "L%d:\niconst_1\nL%d:\n", label_true, label_end);
}

void codegen_emit_logic_op(const char *op) {
    if (strcmp(op, "&&") == 0) fprintf(out, "iand\n");
    else if (strcmp(op, "||") == 0) fprintf(out, "ior\n");
    else if (strcmp(op, "!") == 0) {
        int label_true = new_label();
        int label_end = new_label();
        fprintf(out, "ifeq L%d\niconst_0\ngoto L%d\nL%d:\niconst_1\nL%d:\n", label_true, label_end, label_true, label_end);
    }
}

void codegen_emit_return() {
    emit_return();
}

void codegen_emit_return_value() {
    fprintf(out, "ireturn\n");
}

void codegen_emit_function_prologue(const char *func_name) {
    if (strcmp(func_name, "main") == 0)
        fprintf(out, "method public static void main(java.lang.String[])\n");
    else
        fprintf(out, "method public static int %s()\n", func_name); // or return_type
    fprintf(out, "max_stack 15\nmax_locals 15\n{\n");
}

void codegen_emit_function_epilogue() {
    emit_function_end();
}

void codegen_emit_function_call(const char *name, int argc, const char *ret_type) {
    fprintf(out, "invokestatic %s example.%s(", ret_type, name);
    for (int i = 0; i < argc; ++i) {
        fprintf(out, "int");
        if (i < argc - 1) fprintf(out, ", ");
    }
    fprintf(out, ")\n");
}

void codegen_emit_print(const char *type, const char *literal) {
    fprintf(out, "getstatic java.io.PrintStream java.lang.System.out\n");  // receiver
    if (literal != NULL)
        fprintf(out, "ldc \"%s\"\n", literal);                             // argument
    fprintf(out, "invokevirtual void java.io.PrintStream.print(%s)\n", type);
}

void codegen_emit_println(const char *type, const char *literal) {
    fprintf(out, "getstatic java.io.PrintStream java.lang.System.out\n");  // receiver
    if (literal != NULL)
        fprintf(out, "ldc \"%s\"\n", literal);                             // argument
    fprintf(out, "invokevirtual void java.io.PrintStream.println(%s)\n", type);
}

void codegen_emit_if_eq_zero(int label_id) {
    fprintf(out, "ifeq L%d\n", label_id);
}

void codegen_emit_goto(int label_id) {
    fprintf(out, "goto L%d\n", label_id);
}

void codegen_emit_label(int label_id) {
    fprintf(out, "L%d:\n", label_id);
}

void codegen_emit_string(const char* s) {
    fprintf(out, "ldc \"%s\"\n", s);
}

void codegen_emit_if_gt(int label_id) {
    fprintf(out, "ifgt L%d\n", label_id);
}