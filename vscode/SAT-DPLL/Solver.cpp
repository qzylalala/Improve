#include "header.h"

vector<symbol> final_model;

// 初始化model
void initModel(vector<symbol>& model) {
	for (int i = 0; i < symbol_num; i++) {
		symbol T_symbol;
		T_symbol.assigned = false;
		T_symbol.name = i + 1;
		T_symbol.sign = true;   // model 默认为正
		model.push_back(T_symbol);
	}
}


//判断clause 是否为单子句
inline bool isUnitClause(clause T_clause) {
	if (T_clause.Clause.size() == 1) {
		return true;
	}
	else {
		return false;
	}
}


// 单子句规则，返回处理后得到的formulae，同时更新了model
vector<symbol> deleteUnitClause(formulae& T_formulae, vector<symbol> model) {
	vector<symbol> delete_symbol; // 存储由单子句原则确定下来的 symbol
	T_formulae.satisfiable = true;
	int counter = 0;

	// 第一个循环， 删除掉单子句，并记录该 symbol  令其assigned = true, value = true
	for (int i = 0; i < T_formulae.Formulae.size(); i++) {
		if (isUnitClause(T_formulae.Formulae[i])) {
			counter++;
			int name = T_formulae.Formulae[i].Clause[0].name;

			for (int j = 0; j < delete_symbol.size(); j++) {
				if (delete_symbol[j].name == name) {
					if (T_formulae.Formulae[i].Clause[0].sign != delete_symbol[j].sign) {
						T_formulae.result = false;
					}
				}
			}


			model[name - 1].sign = T_formulae.Formulae[i].Clause[0].sign;
			model[name - 1].assigned = true;
			delete_symbol.push_back(model[name - 1]);
			T_formulae.Formulae.erase(T_formulae.Formulae.begin() + i);
			i--;
		}
	}

	if (counter == 0) {
		T_formulae.satisfiable = false;
		return model;
	}

	// 第二个循环， 将第一个循环记录的确定value的symbol从剩余子句中删除, 简化原formula
	int i, j, k;
	for (i = 0; i < T_formulae.Formulae.size(); i++) {
		bool flag = false;
		for (j = 0; j < T_formulae.Formulae[i].Clause.size(); j++) {
			flag = false;
			for (k = 0; k < delete_symbol.size(); k++) {
				if (T_formulae.Formulae[i].Clause[j].name == delete_symbol[k].name) {
					flag = true;
					break;
				}
			} // 若 flag 为 true 则表明该子句中含有已被 assigned 的 symbol

			if (flag) {
				if (T_formulae.Formulae[i].Clause[j].sign == delete_symbol[k].sign) {
					T_formulae.Formulae.erase(T_formulae.Formulae.begin() + i);
					i--;
					break;
				}
				else {
					if (T_formulae.Formulae[i].Clause.size() == 1) {
						T_formulae.result = false;;
					}

					T_formulae.Formulae[i].Clause.erase(T_formulae.Formulae[i].Clause.begin() + j);
					j--;
					if (T_formulae.Formulae[i].Clause.empty()) {
						T_formulae.Formulae.erase(T_formulae.Formulae.begin() + i);
						i--;
						break;
					}
				}
			}
		}
	}

	return model;
}



/*  对 纯symbol 的处理
inline bool isPureSymbol(symbol T_symbol, symbolCounter* symbol_times) {
	if (symbol_times[T_symbol.name - 1].falseTimes && symbol_times[T_symbol.name - 1].trueTimes)
		return false;
	else if (symbol_times[T_symbol.name - 1].falseTimes == 0 && symbol_times[T_symbol.name - 1].trueTimes == 0)
		return false;
	else {
		return true;
	}
}

formulae deletePureSymbol(formulae T_formulae, vector<symbol> &model) {
	for (int i = 0; i < T_formulae.Formulae.size(); i++) {
		for (int j = 0; j < T_formulae.Formulae[i].Clause.size(); j++) {
			if (isPureSymbol(T_formulae.Formulae[i].Clause[j])) {
				T_formulae.Formulae[i].Clause[j].assigned = true;
				T_formulae.Formulae[i].Clause[j].value = true;
				auto iter = find(model.begin(), model.end(), T_formulae.Formulae[i].Clause[j]);
				if (iter != model.end()) {
					model.push_back(T_formulae.Formulae[i].Clause[j]);
				}
				T_formulae.Formulae.erase(T_formulae.Formulae.begin() + i);
				i--;
				break;
			}
		}
	}

	return T_formulae;
}
*/


// 记录各 symbol 出现的次数
void countSymbolTimes(formulae T_formulae) {
	for (int i = 0; i < symbol_num; i++) { // init
		symbol_times[i].falseTimes = 0;
		symbol_times[i].trueTimes = 0;
		symbol_times[i].times = 0;
	}

	for (int i = 0; i < T_formulae.Formulae.size(); i++) {
		for (int j = 0; j < T_formulae.Formulae[i].Clause.size(); j++) {
			int index = T_formulae.Formulae[i].Clause[j].name;
			if (T_formulae.Formulae[i].Clause[j].sign > 0) {
				symbol_times[index - 1].trueTimes++;
			}
			else {
				symbol_times[index - 1].falseTimes++;
			}
			symbol_times[index - 1].times++;
		}
	}
}


int sortPreferSymbol() {
	int max = 0;
	int tmp = 0;
	int i;

	for (i = 0; i < symbol_num; i++) {
		if (symbol_times[i].times > max) {
			max = symbol_times[i].times;
			tmp = i;
		}
	}

	if (max = 0) {
		return -1;
	}

	return tmp;
}



void update(formulae& T_formulae, symbol T_symbol) {
	int i, j;
	for (i = 0; i < T_formulae.Formulae.size(); i++) {
		for (j = 0; j < T_formulae.Formulae[i].Clause.size(); j++) {
			if (T_formulae.Formulae[i].Clause[j].name == T_symbol.name) {
				if (T_formulae.Formulae[i].Clause[j].sign == T_symbol.sign) {
					T_formulae.Formulae.erase(T_formulae.Formulae.begin() + i);
					i--;
					break;
				}
				else {
					if (T_formulae.Formulae[i].Clause.size() == 1) {
						T_formulae.result = false;;
					}
					T_formulae.Formulae[i].Clause.erase(T_formulae.Formulae[i].Clause.begin() + j);
					j--;
				}
			}
		}
	}
}



//   prefer_symbol 按照优先级存储了symbol


bool checkClause(clause T_clause, vector<symbol> model) {
	for (int i = 0; i < T_clause.Clause.size(); ++i) {
		int name = T_clause.Clause[i].name;
		if (model[name - 1].sign == T_clause.Clause[i].sign) {
			return true;
		}
	}

	return false;
}


bool checkFormula(formulae T_formulae, vector<symbol> model) {
	for (int i = 0; i < T_formulae.Formulae.size(); ++i) {
		if (!checkClause(T_formulae.Formulae[i], model)) {
			return false;
		}
	}

	return true;
}


bool Dpll(formulae T_formulae, vector<symbol> model) {
	T_formulae.satisfiable = true;

	//cout << "当前formula size： " << T_formulae.Formulae.size() << endl;
	if (T_formulae.Formulae.empty()) {
		final_model = model;
		return true;
	}

	else {
		while (T_formulae.satisfiable) {
			model = deleteUnitClause(T_formulae, model);

			if (!T_formulae.result) {
				return false;
			}

			if (T_formulae.Formulae.empty()) {
				final_model = model;
				return true;
			}
		}

		formulae temp_formuale = T_formulae;	
		
		int index;
		countSymbolTimes(T_formulae);
		index = sortPreferSymbol();

		if (index == -1) {
			return true;
		}

		bool flag = symbol_times[index].falseTimes < symbol_times[index].trueTimes;
		model[index].assigned = true;
		model[index].sign = flag;
		update(T_formulae, model[index]);
		if (!T_formulae.result) {
			return false;
		}

		if (Dpll(T_formulae, model)) {
			return true;
		}

		else {
			model[index].sign = (!flag);
			update(temp_formuale, model[index]);

			if (!T_formulae.result) {
				return false;
			}

			return Dpll(temp_formuale, model);
		}
	}
}
