#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<cmath>
#include<ctgmath>

using namespace std;

struct symbol {
    char value;
    bool sign;
    bool pure;
    int name;
    bool assigned;
};

struct clause {
    bool value;
    bool assigned;
    vector<symbol> Clause;
};

struct formulae {
    bool satisfiable;
    bool assigned;
    int clause_num;
    int symbol_num;
    vector<clause> Formulae;
};

formulae FormulaeInitial()
{
    int dummyint;
    formulae T_formulae;
    fstream input_file("F:/Improve/vscode/SAT-DPLL/data.txt");  // 传入文件(.cnf文件)
    if(input_file.is_open()) {
        string Line;
        bool flag = true;
        while (flag) {
            getline(input_file, Line);
            if(Line[0] == 'c')
                ;
            else if(Line[0] == 'p') {
                char *p = (char *)Line.c_str();
                sscanf(p, "p cnf %d %d", &T_formulae.symbol_num, &T_formulae.clause_num);
                flag = false;
            }
        }
        for (int i = 0; i < T_formulae.clause_num; i++) {
            clause T_clause;
            while((input_file >> dummyint) && dummyint != 0) {
                symbol T_symbol;
                T_symbol.name = abs(dummyint);
                T_symbol.assigned = false;
                T_symbol.value = 'N';
                T_symbol.pure = false;
                if(T_symbol.name > 0) {
                    T_symbol.sign = true;
                }
                else {
                    T_symbol.sign = false;
                }

                T_clause.Clause.push_back(T_symbol);
            }

            T_clause.assigned = false;
            T_clause.value = 'N';

            T_formulae.Formulae.push_back(T_clause);
            T_formulae.satisfiable = false;
            T_formulae.assigned = false;
        }

        return T_formulae;
    }

    else {
        cout << "Couldn't read file!\nplease enter correct path";
        exit(0);
    }
}

bool check_unit_clause(formulae formulae)
{
	for (int i = 0; i < formulae.Formulae.size(); i++) {
		for (int j = 0; j < formulae.Formulae[i].Clause.size(); j++)
		{
			if (formulae.Formulae[i].Clause[j].assigned == false) {
				if (i == 0) {
					if (formulae.Formulae[i].Clause[j + 1].assigned == true && formulae.Formulae[i].Clause[j + 2].assigned == true && formulae.Formulae[i].Clause[j + 1].value == 'F' && formulae.Formulae[i].Clause[j + 2].value == 'F') {
						return true;
					}
				}
				if (i == 1) {
					if (formulae.Formulae[i].Clause[j - 1].assigned == true && formulae.Formulae[i].Clause[j + 1].assigned == true && formulae.Formulae[i].Clause[j - 1].value == 'F' && formulae.Formulae[i].Clause[j + 1].value == 'F') {
						return true;
					}
				}
				if (i == 2) {
					if (formulae.Formulae[i].Clause[j - 1].assigned == true && formulae.Formulae[i].Clause[j - 2].assigned == true && formulae.Formulae[i].Clause[j - 1].value == 'F' && formulae.Formulae[i].Clause[j - 2].value == 'F') {
						return true;
					}
				}
			}
		}
	}
	return false;
}

formulae unit_check_update(formulae formulae, vector<symbol>& model) {
	for (int i = 0; i < formulae.Formulae.size(); i++) {
		if (check_unit_clause(formulae) == true) {
			for (int j = 0; j < formulae.Formulae[i].Clause.size(); j++) {
				if (formulae.Formulae[i].Clause[j].assigned == false) {
					formulae.Formulae[i].Clause[j].value = 'T';
					formulae.Formulae[i].value = 'T';
					model.push_back(formulae.Formulae[i].Clause[j]);
				}
			}
		}
	}

    return formulae;
}

bool check_pure_symbol(formulae formulae, symbol symbol)
{
	for (int i = 0; i < formulae.Formulae.size(); i++) // number of clauses
	{
		for (int j = 0; j < formulae.Formulae[i].Clause.size(); j++) // number of variables of each clause
		{
			if (formulae.Formulae[i].Clause[j].name == symbol.name && formulae.Formulae[i].Clause[j].sign == symbol.sign) {
                return true;
            }
		}
	}
    
	return false;
}

formulae Delete_pure_symbol(formulae formulae, symbol symbol) 
{
	for (int i = 0; i < formulae.Formulae.size(); i++){
		for (int j = 0; j < formulae.Formulae[i].Clause.size(); j++) {
			if (formulae.Formulae[i].Clause[j].name == symbol.name && formulae.Formulae[i].Clause[j].sign == symbol.sign) {
				formulae.Formulae[i].Clause.erase(formulae.Formulae[i].Clause.begin() + j); //Deletes the jth element 
			}
		}
	}
	return formulae;
}

bool check_empty_clause(formulae formulae) 
{
	for (int i = 0; i < formulae.Formulae.size(); i++) // number of clauses
	{
		//If the set of clauses is empty, it returns true
		if (formulae.Formulae[i].Clause.empty()) {
			return true;
		}
	}

    return false;
}

vector<symbol> selection_symbol(formulae formulae, vector<symbol>& model)
{
	for (int i = 0; i < formulae.Formulae.size(); i++) {
		for (int j = 0; j < formulae.Formulae[i].Clause.size(); j++) {
			if (formulae.Formulae[i].Clause[j].assigned == false) {
				model.push_back(formulae.Formulae[i].Clause[j]);
				model.back().value = 'T';
				model.back().assigned = true;
			}
		}
	}
	return model;
}

vector<symbol> selection_opposite_simbol(formulae formulae, vector<symbol>& model)
{
	for (int i = 0; i < formulae.Formulae.size(); i++) {
		for (int j = 0; j < formulae.Formulae[i].Clause.size(); j++) {
			if (formulae.Formulae[i].Clause[j].assigned == false) {
				model.push_back(formulae.Formulae[i].Clause[j]);
				model.back().value = 'F';
				model.back().assigned = true;
			}
		}
	}
	return model;
}

formulae update_formulae(formulae formulae, vector<symbol>& model)
{
	for (int i = 0; i < model.size(); i++) {
		for (int j = 0; j < formulae.Formulae.size(); j++) {
			for (int k = 0; k < formulae.Formulae[i].Clause.size(); k++) {
				if (formulae.Formulae[j].Clause[k].name == model[i].name && formulae.Formulae[j].Clause[k].sign == model[i].sign ) {
					formulae.Formulae[j].Clause[k].value = model[i].value;
					formulae.Formulae[j].Clause[k].assigned = true;
				}
				if (formulae.Formulae[j].Clause[k].name == model[i].name && formulae.Formulae[j].Clause[k].sign != model[i].sign) {
					formulae.Formulae[j].Clause[k].value = !(model[i].value);
					formulae.Formulae[j].Clause[k].assigned = true;
				}
			}
		}
	}

	return formulae;
}

void check_satisfiability_formulae(formulae formulae)
{
	formulae.assigned = false;
	int count = 0;
	for (int i = 0; i < formulae.Formulae.size(); i++)
	{
		if (formulae.Formulae[i].assigned)
		{
			count++;
			if (formulae.Formulae[i].value == false)
			{
				formulae.assigned = true;
				formulae.satisfiable = false;
				break;
			}
		}
		else
		{
			formulae.assigned = false;
			break;
		}
		if (count == formulae.Formulae.size())
		{
			formulae.assigned = true;
			formulae.satisfiable = true;
		}
	}
}

bool logic_OR(char a, bool b)
{
	if (a == 'T' || b == true)
		return true;
	else {
        return false;
    }
}

bool find_negative_clause(formulae formulae) 
{
	for (int i = 0; i < formulae.Formulae.size(); i++) {
		if (formulae.Formulae[i].value == 'F') {
            return true;
        }
	}

    return false;
}

bool DPLL(formulae formul, vector<symbol> Model) 
{
	if (formul.assigned = true)
		return formul.satisfiable;

	else {
		if (check_empty_clause(formul) == true) { return false; }

		if (check_unit_clause(formul) == true) {
			DPLL(unit_check_update(formul, Model), Model);
		}
		return DPLL(formul, selection_symbol(formul, Model));

	}
}

int main() 
{
	formulae input = FormulaeInitial();
	/*delete pure symbols at first*/
	for (int j = 0; j < input.Formulae.size(); j++) {
		for (int k = 0; k < input.Formulae[j].Clause.size(); k++) {
			if (check_pure_symbol(input, input.Formulae[j].Clause[k]) == true) {
				input = Delete_pure_symbol(input, input.Formulae[j].Clause[k]);
			}
		}
	}

	vector<symbol> model;

	if (DPLL(input, model) == true) {
        cout << "Model Found!";
    }
	else {
        cout << "Inconsistency!";
    }

    return 0;
}