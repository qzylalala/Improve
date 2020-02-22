#include "./CNF_Parser.cpp"
#include "./Solver.cpp"
#include "./header.h"
#include <time.h>
// #include "SUDOKU.h"


int main() {
	int option = 1;
	char ch;
	while (option) {
		system("cls");
		printf("\n\n");
		printf("-------------SAT-solver based on DPLL and the implement of SUBOKU------------\n");
		printf("                           1.SAT-DPLL_solver\n");
		printf("                           2.SUDOKU\n");
		printf("    	                   0. Exit\n");
		printf("-----------------------------------------------------------------------------\n");
		printf("Please choose your option: ");
		scanf("%d", &option);
		switch (option) {
		case 1: {
			vector<symbol> model;
			formulae T_formulae;
			printf("Please input the file path: ");
			string cnfpath;   //用于存储cnf路径或名称
			cin.ignore();
			getline(cin, cnfpath);
			clock_t t1 = clock();
			T_formulae = FormulaInitial(cnfpath);
			initModel(model);
			
			while (T_formulae.satisfiable) {
				model = deleteUnitClause(T_formulae, model);
			}
			
			ofstream result;
			result.open(cnfpath + ".res");
			result << "s 求解结果: ";
			if (Dpll(T_formulae, model)) {
				clock_t t2 = clock();
				result << "1" << endl;
				result << "t " << t2 - t1 << endl;
				result << "v ";
				for (int i = 0; i < final_model.size(); i++) {
					if (final_model[i].sign == true && final_model[i].assigned == true) {
						cout << i + 1 << " ";
						result << i + 1 << " ";
					}
					else if (final_model[i].sign == false && final_model[i].assigned == true) {
						cout << "-" << i + 1 << " ";
						result << "-" << i + 1 << " ";
					}
					else
						;
				}
				cout << "\n用时" << t2 - t1 << "ms" << endl;
				
			}
			else {
				clock_t t3 = clock();
				result << "0" << endl;
				result << "t " << t3 - t1;
				cout << "It seems there is no fit arrangement." << endl;
			}
		}

		case 2: {

		}

		case 0: {
			break;
		}
		}
		system("pause");
	}

	system("pause");
	return 0;
}