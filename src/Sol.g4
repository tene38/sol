grammar Sol;

program : procedure*? ;

procedure : 'procedure' IDENT args (':' 'int')? '{' return_statement '}' ;
args : '(' (arg (',' arg)*)? ')' ;
arg : IDENT ':' 'int' ;

return_statement : 'return' expression ';' ;

expression : INT
	   | IDENT
	   | func_call
	   | expression '*' expression
	   | expression '/' expression
	   | expression '-' expression
	   | expression '+' expression ;

func_call : IDENT '(' (expression (',' expression)*)? ')' ;

IDENT : [A-Za-z_][A-Za-z_0-9]* ;
INT : [0-9]+ ;

LF : '\r'? '\n' -> skip ;

BLOCK_COMMENT : '/*' .*? '*/' -> skip ;
LINE_COMMENT : '//' .*? LF -> skip ;

WS : [ \t\n\r]+ -> skip ;
