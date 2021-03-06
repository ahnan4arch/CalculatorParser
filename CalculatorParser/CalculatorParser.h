#pragma once
#include <cinttypes>

typedef int32_t uc32;

// runtime definition
typedef double TNumber;
typedef int TSmallInt;
typedef bool TBool;

#define OPERATOR_LIST(V) \
	V(ADD, "+", 10) \
	V(SUB, "-", 10) \
	V(MUL, "*", 11) \
	V(DIV, "/", 11) \
	V(MOD, "%", 12) \
	V(POW, "**", 13) \
	V(ILLEGAL_OP, "", 0)

#define TOKEN_LIST(V) \
	V(ILLEGAL) \
	V(LET) \
	V(IF) \
	V(ELSE) \
	V(WHILE) \
	V(DEF) \
	V(ASSIGN) \
	V(IDENTIFIER) \
	V(OPEN_PAREN) \
	V(CLOSE_PAREN) \
	V(NUMBER) \
	V(ENDFILE) 


#define E(NAME, STR, PRE) NAME,
	enum OperatorType
	{
		OPERATOR_LIST(E)
		OP_NUM
	};
#undef E


#define E(NAME, STR, PRE) PRE,
	const int OpreatorPrecedence[OperatorType::OP_NUM] = 
	{
		OPERATOR_LIST(E)
	};
#undef E

#define E(NAME, STR, PRE) #NAME ,
#define ET(NAME) #NAME ,
	const static char* TokenName[] =
	{
		OPERATOR_LIST(E)
		TOKEN_LIST(ET)
	};
#undef E
#undef ET

inline int getPrecedence(OperatorType ot)
{
	if (ot >= OperatorType::OP_NUM || ot < 0) return 0;
	return OpreatorPrecedence[ot];
}
