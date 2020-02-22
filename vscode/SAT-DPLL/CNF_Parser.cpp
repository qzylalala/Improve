#include "header.h"
#include<malloc.h>

int symbol_num;
int clause_num;
symbolCounter *symbol_times;

formulae FormulaInitial(string cnfPATH)  // 读取.cnf文件，初始化formula
{
	int dummyint;
	formulae T_formulae;
	fstream input_file("F:/Improve/vscode/SAT-DPLL/" + cnfPATH);  // 传入文件(.cnf文件)
	if (input_file.is_open()) {
		string Line;
		bool flag = true;
		while (flag) {
			getline(input_file, Line);
			if (Line[0] == 'c')
				;
			else if (Line[0] == 'p') {
				char *p = (char *)Line.c_str();
				sscanf(p, "p cnf %d %d", &symbol_num, &clause_num);
				flag = false;
			}
		}

		symbol_times = (symbolCounter *)malloc(sizeof(symbolCounter) * symbol_num);
		for (int i = 0; i < clause_num; ++i) {
			clause T_clause;
			while ((input_file >> dummyint) && dummyint != 0) {
				symbol T_symbol;
				T_symbol.name = abs(dummyint);
				T_symbol.assigned = false;
				T_symbol.pure = false;
				if (dummyint > 0) {
					T_symbol.sign = true;
					symbol_times[T_symbol.name - 1].trueTimes++;
				}
				else {
					T_symbol.sign = false;
					symbol_times[T_symbol.name - 1].falseTimes++;
				}

				symbol_times[T_symbol.name - 1].times++;
				T_clause.Clause.push_back(T_symbol);
			}

			T_formulae.Formulae.push_back(T_clause);
			T_formulae.satisfiable = true;
			T_formulae.result = true;
		}

		return T_formulae;
	}

	else {
		cout << "Couldn't read file!\nplease enter correct path";
		exit(0);
	}
}
