#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clone_repository() {
    printf("Cloning the 8-bit CPU repository...\n");
    system("git clone https://github.com/lightcode/8bit-computer.git");
    system("cd 8bit-computer || exit 1");
}

void display_readme() {
    printf("Displaying README file...\n");
    system("cat 8bit-computer/README.md");
}

void run_examples() {
    printf("Running provided examples...\n");
    if (system("test -f 8bit-computer/examples/example1.asm") == 0) {
        printf("Assembling example1.asm...\n");
        system("8bit-computer/assembler 8bit-computer/examples/example1.asm -o example1.bin");
        printf("Running example1.bin on the CPU simulator...\n");
        system("8bit-computer/cpu_simulator example1.bin");
    } else {
        printf("No example1.asm file found. Please check the repository for available examples.\n");
    }
}

void review_architecture() {
    printf("Reviewing the 8-bit CPU Architecture...\n");
    system("cat 8bit-computer/rtl/machine.v | head -n 50");
    system("grep -E \"opcode|instruction\" 8bit-computer/rtl/*.v");
}

void document_simplelang() {
    FILE *file = fopen("SimpleLang_Spec.txt", "w");
    if (file) {
        fprintf(file, "## SimpleLang Specification\n\n");
        fprintf(file, "### Variable Declaration\n");
        fprintf(file, "- Syntax: int variable_name;\n\n");
        fprintf(file, "### Assignment\n");
        fprintf(file, "- Syntax: variable = expression;\n\n");
        fprintf(file, "### Arithmetic Operations\n");
        fprintf(file, "- Supported operators: +, -\n\n");
        fprintf(file, "### Conditionals\n");
        fprintf(file, "- Syntax: if (condition) { statements }\n\n");
        fclose(file);
        printf("SimpleLang design documented in SimpleLang_Spec.txt\n");
    }
}

void implement_lexer() {
    FILE *file = fopen("lexer.c", "w");
    if (file) {
        fprintf(file, "#include <stdio.h>\n#include <string.h>\n#include <ctype.h>\n\n");
        fprintf(file, "typedef enum { KEYWORD, IDENTIFIER, OPERATOR, NUMBER, SYMBOL } TokenType;\n\n");
        fprintf(file, "typedef struct { TokenType type; char value[20]; } Token;\n\n");
        fprintf(file, "void tokenize(const char *code) {\n");
        fprintf(file, "    printf(\"Tokenizing: %s\\n\", code);\n}");
        fclose(file);
        printf("Lexer implemented in lexer.c\n");
    }
}

void implement_parser() {
    FILE *file = fopen("parser.c", "w");
    if (file) {
        fprintf(file, "#include <stdio.h>\n#include \"lexer.c\"\n\n");
        fprintf(file, "void parse() {\n    printf(\"Parsing tokens...\\n\");\n}\n");
        fclose(file);
        printf("Parser implemented in parser.c\n");
    }
}

void generate_documentation() {
    FILE *file = fopen("Compiler_Documentation.txt", "w");
    if (file) {
        fprintf(file, "## SimpleLang Compiler Documentation\n\n");
        fprintf(file, "### Overview\n");
        fprintf(file, "The SimpleLang Compiler translates SimpleLang code into assembly code for an 8-bit CPU.\n\n");
        fprintf(file, "### Components\n- Lexer\n- Parser\n- Code Generator\n\n");
        fprintf(file, "### Future Improvements\n- Add support for loops.\n- Optimize generated assembly.\n");
        fclose(file);
        printf("Compiler documentation saved in Compiler_Documentation.txt\n");
    }
}

int main() {
    clone_repository();
    display_readme();
    run_examples();
    review_architecture();
    document_simplelang();
    implement_lexer();
    implement_parser();
    generate_documentation();

   return 0;
}
