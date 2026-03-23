import ply.lex as lex
import ply.yacc as yacc

# List of token names
tokens = [
    'ID', 'INT_CONST', 'REAL_CONST', 'BOOL_CONST',
    'PLUS', 'MINUS', 'TIMES', 'DIVIDE',
    'LPAREN', 'RPAREN', 'LBRACKET', 'RBRACKET', 'LBRACE', 'RBRACE',
    'COMMA', 'SEMICOLON', 'COLON',
    'ASSIGN', 'EQ', 'NEQ', 'GT', 'LT', 'GTE', 'LTE',
    'STRING_CONST',
    'NEWLINE'
]

# Regular expression rules for simple tokens
t_PLUS = r'\+'
t_MINUS = r'-'
t_TIMES = r'\*'
t_DIVIDE = r'/'
t_LPAREN = r'\('
t_RPAREN = r'\)'
t_LBRACKET = r'\['
t_RBRACKET = r'\]'
t_LBRACE = r'\{'
t_RBRACE = r'\}'
t_COMMA = r','
t_SEMICOLON = r';'
t_COLON = r':'
t_ASSIGN = r'='
t_EQ = r'=='
t_NEQ = r'!='
t_GT = r'>'
t_LT = r'<'
t_GTE = r'>='
t_LTE = r'<='
t_STRING_CONST = r'\".*?\"'
t_ignore = ' \t'

# Define a rule so we can track line numbers
def t_NEWLINE(t):
    r'\n+'
    t.lexer.lineno += len(t.value)

# A regular expression rule with some action code
def t_ID(t):
    r'[a-zA-Z_][a-zA-Z0-9_]*'
    t.type = 'ID' if t.value not in ['true', 'false'] else 'BOOL_CONST'
    return t

def t_REAL_CONST(t):
    r'\d+\.\d+'
    t.value = float(t.value)
    return t

def t_INT_CONST(t):
    r'\d+'
    t.value = int(t.value)
    return t

# Error handling rule
def t_error(t):
    print("Illegal character '%s'" % t.value[0])
    t.lexer.skip(1)

# Build the lexer
lexer = lex.lex()

# Define parsing rules
def p_statement_assign(p):
    'statement : ID ASSIGN expression SEMICOLON'
    p[0] = ('assign', p[1], p[3])

def p_expression_binop(p):
    '''expression : expression PLUS expression
                  | expression MINUS expression
                  | expression TIMES expression
                  | expression DIVIDE expression'''
    p[0] = ('binop', p[2], p[1], p[3])

def p_expression_group(p):
    'expression : LPAREN expression RPAREN'
    p[0] = p[2]

def p_expression_const(p):
    '''expression : INT_CONST
                  | REAL_CONST
                  | BOOL_CONST'''
    p[0] = ('const', p[1])

def p_error(p):
    print("Syntax error at '%s'" % p.value)

# Build the parser
parser = yacc.yacc()

# Test the parser
data = '''
x = 3 * (4 + 5);
y = x - 2;
'''
parser.parse(data)