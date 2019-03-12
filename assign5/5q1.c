#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef enum {
	start, stop, invalid,
	build_id, identifier,
	build_num, number,
	build_str, strconst,
	build_op, assignment_operator, equality_operator, dereference_operator, division_operator,
	build_comment, build_slcomment, slcomment, build_mlcomment, build_mlcommentend, mlcomment,
	lbrace, rbrace, lparen, rparen, semicolon, comma
} state;

state transition(state current, char currentchar, FILE* output, int* lookahead) {
	int alpha = isalpha(currentchar);
	int digit = isdigit(currentchar);
	int underscore = (currentchar == '_');
	int period = (currentchar == '.');
	int whitespace = (currentchar == '\n') || (currentchar == '\t') || (currentchar == ' ');
	int printchar = 1;
	state nextstate;
	switch(current) {
case start:
			if (alpha) {
				nextstate = build_id;
			entchar == '&' || currentchar == '%') {
				nextstate = dereference_operator;
			} else if (currentchar == '=') {
				nextstate = build_op;
			} else if (currentchar == '/') {
				nextstate = build_comment;
			} else {
				nextstate = invalid;
			}whitespace) {
				printchar;
		break;
		case build_id:
			if (alpha || digit || currentchar == '_') {
				nextstate = build_id;
			} else if ( currentchar == 0);
				nextstate = identifier;
			} else if (currentchar == '(' || currentchar == ';' || currentchar == ')') {
				*lookahead = 1;
				printchar = 0;
			} else if (digit) {
				nextstate = build_num;
			} else if (whitespace) {
				printchar = 0;
				nextstate = start;
			} else if (period) {
				nextstate = stop;
			} else if (currentchar == '(') {
				nextstate = lparen;+
			} else if (currentchar == ')') {
				nextstate = rparen;
			} else if (currentchar == '{') {
				nextstate = lbrace;
			} else if (currentchar == '}') {
				nextstate = rbrace;
			} else if (currentchar == ';') {
				nextstate = semicolon;
			} else if (currentchar == '\"') {
				nextstate = build_str;
			} else if (currentchar == ',') {
				nextstate = comma;
			} else if (curr	nextstate = identifier;
			} else {
				nextstate = invalid;
			}
		break;
		case build_num:
			if (digit) {
				nextstate = build_num;
			} else if (whitespace) {
				printchar = 0;
				nextstate = number;
			} else if (currentchar == ')' || currentchar == ';') {
				*lookahead = 1;
				printchar = 0;
				nextstate = number;
			} else {
				nextstate = invalid;
			}
		break;
		case build_str:
			if (currentchar == '\"') {
				nextstate = strconst;
			} else {
				nextstate = build_str;
			}
		break;
		case build_op:
			if (currentchar == '=') {
				nextstate = equality_operator;
			} else {
				*lookahead = 1;
				printchar = 0;
				nextstate = assignment_operator;
			}
		break;
		case build_comment:
			if (currentchar == '/') {
				nextstate = build_slcomment;
			} else if (currentchar == '*') {
				nextstate = build_mlcomment;
			} else {
				*lookahead = 1;
				printchar = 0;
				nextstate = division_operator;
			}
		break;
		case build_slcomment:
			if (currentchar == '\n') {
				printchar = 0;
				nextstate = slcomment;
			} else {
				nextstate = build_slcomment;
			}
		break;
		case build_mlcomment:
			if (currentchar == '*') {
				nextstate = build_mlcommentend;
			} else {
				nextstate = build_mlcomment;
			}
		break;
		case build_mlcommentend:
			if (currentchar == '/') {
				nextstate = mlcomment;
			} else if (currentchar == '*'){
				nextstate = build_mlcommentend;
			}
		break;
		case invalid:
			if (whitespace) {
				printchar = 0;
				fprintf(output, " => Invalid\n");
				nextstate = start;
			} else {
				nextstate = invalid;
			}
		break;
	}
	if (printchar)
		fprintf(output, "%c", currentchar);
	return nextstate;
}
void main() {
	FILE *input, *output;
	state current;
	char currentchar;
	int status;
	int lookahead;

	printf("Reading input.txt...\n");
	input = fopen("input.txt", "r");
	if (input == NULL) {
		printf("Error in opening input.txt!\n");
		exit(0);
	}
	output = fopen("output.txt", "w");
	if (output == NULL) {
		printf("Error in opening output.txt!\n");
		exit(0);
	}

	lookahead = 0;
	current = start;
	status = fscanf(input, "%c", &currentchar);
	do {
		current = transition(current, currentchar, output, &lookahead);
		if (lookahead == 0) {
			status = fscanf(input, "%c", &currentchar);
		} else {
			lookahead = 0;
		}
		switch(current) {
			case number:
				fprintf(output, " => Number\n");
				current = start;
			break;
			case identifier:
				fprintf(output, " => Identifier\n");
				current = start;
			break;
			case strconst:
				fprintf(output, " => String constant\n");
				current = start;
			break;
			case lparen:
				fprintf(output, " => Left Parenthesis\n");
				current = start;
			break;
			case rparen:
				fprintf(output, " => Right Parenthesis\n");
				current = start;
			break;
			case lbrace:
				fprintf(output, " => Left Brace\n");
				current = start;
			break;
			case rbrace:
				fprintf(output, " => Right Brace\n");
				current = start;
			break;
			case semicolon:
				fprintf(output, " => Semicolon\n");
				current = start;
			break;
			case comma:
				fprintf(output, " => Comma\n");
				current = start;
			break;
			case assignment_operator:
				fprintf(output, " => Assignment Operator\n");
				current = start;
			break;
			case equality_operator:
				fprintf(output, " => Equality Operator\n");
				current = start;
			break;
			case dereference_operator:
				fprintf(output, " => Dereference Operator\n");
				current = start;
			break;
			case division_operator:
				fprintf(output, " => Division Operator\n");
				current = start;
			se slcomment:
				fprintf(output, " => Singleline Comment\n");
				current = start;
			break;
			case mlcomment:
				fprintf(output, " => Multiline Comment\n");
				current = start;
			break;
		}
	} while(status != EOF);
	printf("Wrote output into output.txt\n");
}	break;
		
