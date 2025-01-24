grammar Sol;

program : top_level_statement*? ;
top_level_statement : import_statement | assignment | procedure;
import_statement : 'import' IDENT ';' ;

assignment : 'let' IDENT (':' IDENT)? '=' VALUE ';' ;
declaration : 'let' IDENT ':' IDENT ';' ;

statement : assignment ;

procedure : 'procedure' IDENT args (':' IDENT)? '{' statement* '}' ;
args : '(' (arg (',' arg)*)? ')' ;
arg : IDENT ':' IDENT ;

IDENT : [A-Za-z_][A-Za-z_0-9]* ;
VALUE : INT | FLOAT ;
FLOAT : [0-9]+ '.' [0-9]+ ;
INT : [0-9]+ ;

LF : '\r'? '\n' -> skip ;

BLOCK_COMMENT : '/*' .*? '*/' -> skip ;
LINE_COMMENT : '//' .*? LF -> skip ;

WS : [ \t\n\r]+ -> skip ;
