#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<cmath>
#include<ctgmath>
using namespace std;


struct symbol
{
	char value;     //T for true or F for false or N for null (temporary)
	bool sign;      //T for true or F for false
	bool pure;      //Is it a pure symbol or not?
	int name;       //which variable?
	bool assigned;  // flag to know if it is assigned or not this meanes this symbol was added to model or not
};

struct clause
{
	char value;        //T for true or F for false or N for null (temporary)
	bool assigned;     //a flag to know if it is assigned or not
	vector<symbol> S;  //A set of symbols that have created the clause
};

struct formulae
{
	vector <clause> f;
	bool satisfiable;   //satisfiability of the formulae
	bool assigned;      //a flag to know if it is assigned or not
};
/*Explanation: create the formulae by reading from file
input: void
output:formulae(set of clauses in CNF form*/
formulae read_initial() 
{
	int dummyint;
	formulae T_f;
	fstream inputfile("file.txt");
	if (inputfile.is_open()) {
		string dummyLine;
		getline(inputfile, dummyLine);
		for (int i = 0; i < 10; i++) {
			clause T_c;
			for (int j = 0; j < 3; j++) {
				symbol T_s;
				inputfile >> dummyint; //skip file's first line 
				T_s.name = abs(dummyint);
				T_s.assigned = false;
				T_s.value = 'N';
				T_s.pure = false;
				if (T_s.name > 0) 
				{
					T_s.sign = true;
				}
				else
				{
					T_s.sign = false;
				}
				

				T_c.S.push_back(T_s);
			}

			T_c.assigned = false;
			T_c.value = 'N';

			T_f.f.push_back(T_c);
			T_f.satisfiable = false;
			T_f.assigned = false;
		}
		return T_f;
	}
	else
	{
		cout << "\tCouldn't read file!\n\tPlease enter correct path \n";
		exit(0);
	}
}
/*Explanation: a clause which has exactly one symbol which is still unassigned
and the other symbols are all assigned to false
input: a specific clause
output:true or false*/
bool check_unit_clause(formulae formulae)
{
	for (int i = 0; i < formulae.f.size(); i++) {
		for (int j = 0; j < formulae.f[i].S.size(); j++)
		{
			if (formulae.f[i].S[j].assigned == false) {
				if (i == 0) {
					if (formulae.f[i].S[j + 1].assigned == true && formulae.f[i].S[j + 2].assigned == true && formulae.f[i].S[j + 1].value == 'F' && formulae.f[i].S[j + 2].value == 'F') {
						return true;
					}
				}
				if (i == 1) {
					if (formulae.f[i].S[j - 1].assigned == true && formulae.f[i].S[j + 1].assigned == true && formulae.f[i].S[j - 1].value == 'F' && formulae.f[i].S[j + 1].value == 'F') {
						return true;
					}
				}
				if (i == 2) {
					if (formulae.f[i].S[j - 1].assigned == true && formulae.f[i].S[j - 2].assigned == true && formulae.f[i].S[j - 1].value == 'F' && formulae.f[i].S[j - 2].value == 'F') {
						return true;
					}
				}
			}
		}
	}
	return false;
}
/*Explanation: updat model and formula after unit clause cheking
and the other symbols are all assigned to false
input: formulae and model
output:new formulae and new model(call by reference) */
formulae unit_check_update(formulae formulae, vector<symbol>& model) {
	for (int i = 0; i < formulae.f.size(); i++) {
		if (check_unit_clause(formulae) == true) {
			for (int j = 0; j < formulae.f[i].S.size(); j++) {
				if (formulae.f[i].S[j].assigned == false) {
					formulae.f[i].S[j].value = 'T';
					formulae.f[i].value = 'T';
					model.push_back(formulae.f[i].S[j]);
				}
			}
		}
	}
}
/*Explanation: pure symbols are occur whit only one polarity in the formulae so can be deleted
and the other symbols are all assigned to false
input : formulae and model
output : true or false */
bool check_pure_symbol(formulae formulae, symbol symbol)
{
	for (int i = 0; i < formulae.f.size(); i++) // number of clauses
	{
		for (int j = 0; j < formulae.f[i].S.size(); j++) // number of variables of each clause
		{
			if (formulae.f[i].S[j].name == symbol.name && formulae.f[i].S[j].sign == symbol.sign) { return true; }
			else { return false; }
		}
	}
}
/*Explanation: After defining a pure symbol, it should be deleted from the formula
input : formulae and a symbol
output : new formulae */
formulae Delete_pure_symbol(formulae formulae, symbol symbol) 
{
	for (int i = 0; i < formulae.f.size(); i++){
		for (int j = 0; j < formulae.f[i].S.size(); j++) {
			if (formulae.f[i].S[j].name == symbol.name && formulae.f[i].S[j].sign == symbol.sign) {
				formulae.f[i].S.erase(formulae.f[i].S.begin() + j); //Deletes the jth element 
			}
		}
	}
	return formulae;
}
/*Explanation: Determines whether the clause is empty or notAfter defining a pure symbol, it should be deleted from the formula
input : formulae 
output : true or false */
bool check_empty_clause(formulae formulae) 
{
	for (int i = 0; i < formulae.f.size(); i++) // number of clauses
	{
		//If the set of clauses is empty, it returns true
		if (formulae.f[i].S.empty()) { return true; }
	}
}
/*Explanation: Choose one of the symbols from the formula that are not assigned; assigned it true and add that symbol to model
input : formulae and model
output : new model */
vector<symbol> selectionsymbol(formulae formulae, vector<symbol>& model)
{
	for (int i = 0; i < formulae.f.size(); i++) {
		for (int j = 0; j < formulae.f[i].S.size(); j++) {
			if (formulae.f[i].S[j].assigned == false) {
				model.push_back(formulae.f[i].S[j]);
				model.back().value = 'T';
				model.back().assigned = true;
			}
		}
	}
	return model;
}
/*Explanation: Choose one of the symbols from the formula that are not assigned; assigned the opposit symbol true and add that symbol to model
input : formulae and model
output : new model */
vector<symbol> selectionoppositesimbol(formulae formulae, vector<symbol>& model)
{
	for (int i = 0; i < formulae.f.size(); i++) {
		for (int j = 0; j < formulae.f[i].S.size(); j++) {
			if (formulae.f[i].S[j].assigned == false) {
				model.push_back(formulae.f[i].S[j]);
				model.back().value = 'F';
				model.back().assigned = true;
			}
		}
	}
	return model;
}
/*Explanation: update formulae with model
input : formulae and model
output : new formula */
formulae updateformulae(formulae formulae, vector<symbol>& model)
{
	for (int i = 0; i < model.size(); i++) {
		for (int j = 0; j < formulae.f.size(); j++) {
			for (int k = 0; k < formulae.f[i].S.size(); k++) {
				if (formulae.f[j].S[k].name == model[i].name && formulae.f[j].S[k].sign == model[i].sign ) {
					formulae.f[j].S[k].value = model[i].value;
					formulae.f[j].S[k].assigned = true;
					return formulae;
				}
				if (formulae.f[j].S[k].name == model[i].name && formulae.f[j].S[k].sign != model[i].sign) {
					formulae.f[j].S[k].value = !(model[i].value);
					formulae.f[j].S[k].assigned = true;
					return formulae;
				}
			}
		}
	}
}

/*Explanation: check if the formulae is satisfiab or not
input : formulae
output : void */
void check_satisfiability_formulae(formulae formulae)
{
	formulae.assigned = false;
	int count = 0;
	for (int i = 0; i < formulae.f.size(); i++)
	{
		if (formulae.f[i].assigned)
		{
			count++;
			if (formulae.f[i].value == false)
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
		if (count == formulae.f.size())
		{
			formulae.assigned = true;
			formulae.satisfiable = true;
		}
	}
}
/*Explanation: implement logic OR
input : tow symbol's value or clause's value
output : true or false */
bool logicOR(char a, bool b)
{
	if (a == 'T' || b == true)
		return true;
	if (a == 'F' && b == false)
		return true;
}

/*void update(formulae formul, symbol symbol)
{
	for (int i = 0; i < formul.f.size(); i++)
	{
		int count = 0;
		bool clause_value = false;
		for (int j = 0; j < formul.f[i].S.size(); j++)
		{
			if (formul.f[i].S[j].assigned)
			{
				count++;
				clause_value = logicOR(clause_value, formul.f[i].S[j].sign);
			}
			if (formul.f[i].S[j].name == symbol.name)
			{
				if (formul.f[i].S[j].sign == symbol.sign)
					formul.f[i].S[j].value = symbol.value;
				else
					formul.f[i].S[j].value = !symbol.value;
				formul.f[i].S[j].assigned = true;
				count++;
				clause_value = logicOR(clause_value, formul.f[i].S[j].sign);
			}
			if (count == formul.f[i].S.size())
			{
				formul.f[i].value = clause_value;
				formul.f[i].assigned = true;
			}
		}
	}
}
*/
/*Explanation: if there is a false clause in formulae, formulae become false anyway
input : formulae
output : true or false */
bool findNegativeclause(formulae formulae) 
{
	for (int i = 0; i < formulae.f.size(); i++) {
		if (formulae.f[i].value == 'F') { return true; }
		else { return false; }
	}
}

/*Explanation: main part af Algorithm if there is a satisfying truth assignment model for a CNF formula formulae
input : formulae and model
output : true or false */
bool DPLL(formulae formul, vector<symbol>& Model) 
{
	if (formul.assigned = true)
		return formul.satisfiable;

	else {
		if (check_empty_clause(formul) == true) { return false; }

		if (check_unit_clause(formul) == true) {
			DPLL(unit_check_update(formul, Model), Model);
		}
		return DPLL(formul, selectionsymbol(formul, Model));

	}
}
int main() 
{
	formulae input = read_initial();
	/*delete pure symbols at first*/
	for (int j = 0; j < input.f.size(); j++) {
		for (int k = 0; k < input.f[j].S.size(); k++) {
			if (check_pure_symbol(input, input.f[j].S[k]) == true) {
				input = Delete_pure_symbol(input, input.f[j].S[k]);
			}
		}
	}

	vector<symbol> model;

	if (DPLL(input, model) == true) { cout << "Model Found!"; }
	else { cout << "Inconsistency!"; }
	
}