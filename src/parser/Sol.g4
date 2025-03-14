grammar Sol;

program : procedure*? ;

procedure : 'procedure' IDENT args (':' 'int')? '{' returnStatement '}' ;
args : '(' (arg (',' arg)*)? ')' ;
arg : IDENT ':' 'int' ;

returnStatement : 'return' expression ';' ;

expression 
    : INT                                              # IntExpr
    | IDENT                                            # IdentExpr
    | IDENT '(' (expression (',' expression)*)? ')'    # CallExpr
    | expression op='*' expression                     # BinopExpr
    | expression op='/' expression                     # BinopExpr
    | expression op='-' expression                     # BinopExpr
    | expression op='+' expression                     # BinopExpr
    ;

IDENT : [A-Za-z_][A-Za-z_0-9]* ;
INT : [0-9]+ ;

LF : '\r'? '\n' -> skip ;

BLOCK_COMMENT : '/*' .*? '*/' -> skip ;
LINE_COMMENT : '//' .*? LF -> skip ;

WS : [ \t\n\r]+ -> skip ;
