%{
#include <stdio.h>
//flex with --case-insensitive
extern "C" int yywrap() { exit(0);}
bool isDoubleQuotes = false;
bool isSingleQuotes = false;
#define TOKEN(b) if(!isDoubleQuotes && !isSingleQuotes){printf(b);}else{printf(yytext);}
%}

%%
"'"			isSingleQuotes = isSingleQuotes?false:true;	
"\""		isDoubleQuotes = isDoubleQuotes?false:true;	
"glowna"			TOKEN("main")
"przerwij"			TOKEN("break")
"stan" 			TOKEN("case")
"znak" 			TOKEN("char")
"stala"			TOKEN("const")
"staly"			TOKEN("const")
"kontynuluj"			TOKEN("continue")
"domyslna"			TOKEN("default")
"domyslne"			TOKEN("default")
"domyslny"			TOKEN("default")
"rob"			TOKEN("do")
"podwojna" 			TOKEN("double")
"podwojny" 			TOKEN("double")
"inaczej" 			TOKEN("else")
"enumeracja"			TOKEN("enum")
"zewnetrzna" 			TOKEN("extern")		
"zewnetrzny" 			TOKEN("extern")
"pojedyncza" 			TOKEN("float")
"pojedynczy" 			TOKEN("float")
"dla" 			TOKEN("for")
"idzdo" 			TOKEN("goto")
"jezeli" 			TOKEN("if")
"calkowita" 			TOKEN("int")
"dlugi" 			TOKEN("long")
"dluga" 			TOKEN("long")
"rejestr" 			TOKEN("register")
"zwroc" 			TOKEN("return")
"krotki"			TOKEN("short")
"krotka" 			TOKEN("short")
"sygnowany"			TOKEN("signed")
"sygnowana"			TOKEN("signed")
"wielkosc"			TOKEN("sizeof")
"statyczna"			TOKEN("static")
"statyczny"			TOKEN("static")
"struktura"			TOKEN("struct")
"strukt"			TOKEN("struct")
"przelacz"			TOKEN("switch")
"definujtyp"			TOKEN("typedef")
"unia"			TOKEN("union")
"niesygnowany"			TOKEN("unsigned")
"niesygnowana"			TOKEN("unsigned")
"nicosc"			TOKEN("void")
"nic"			TOKEN("void")
"niewazny"			TOKEN("void")
"lotny"			TOKEN("volatile")
"dopoki"			TOKEN("while")
			
"#zalacz"			TOKEN("#include")
"#definiuj"			TOKEN("#define")
"#def"			TOKEN("#define")
"#oddefiniuj"			TOKEN("#undef")
"#oddef"			TOKEN("#undef")
"#jezeli"			TOKEN("#if")
"#inaczej"			TOKEN("#else")
"#koniecjezeli"			TOKEN("#endif")
"#konjez"			TOKEN("#endif")
"#injez"			TOKEN("#elif")
"#jezelizdefiniowany"			TOKEN("#ifdef")
"#jezdef"			TOKEN("#ifdef")
"#jezeliniezdefiniowany"			TOKEN("#ifndef")
"#jeznzdef"			TOKEN("#ifndef")
"#blad"			TOKEN("#error")
%%
int main(int argc, char **argv)
{
	return (yylex());
}