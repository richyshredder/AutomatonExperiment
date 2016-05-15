#pragma once

#include <queue>

#include "../../base/constants.hpp"
#include "./sync_graph.hpp"
#include "./sync_search_cell.hpp"

class SyncSearch {
private:
	SyncSearchCell a[2][1 << constants::max_automaton_size];

	// queue for search; first - player; second - position
	queue <pair<bool, int>> q;

	SyncGraph g;

	void search_check(bool first_player, int position) {
		for (int i = 0; i < (int)g.prev(position).size(); i++) {
			pair<int, int> p = g.prev(position)[i];
			int pr_position = p.first;
			int pr_letter = p.second;

			if (a[!first_player][pr_position].calculated)
				continue;
			if (first_player) {
				int old_length = a[0][pr_position].length;
				int new_length = a[1][position].length + 1;
				if (old_length == -1 || new_length > old_length)
					a[0][pr_position].set_move(new_length, pr_letter, position);
				a[0][pr_position].count++;
				if (a[0][pr_position].count == g.next(pr_position).size()) {
					a[0][pr_position].set_result(false);
					q.push(make_pair(0, pr_position));
				}
			}
			else {
				a[1][pr_position].set_result(true);
				a[1][pr_position].set_move(a[0][position].length + 1, pr_letter, position);
				q.push(make_pair(1, pr_position));
			}
		}
	}

public:
	SyncSearch(SyncGraph g) : g(g) {
		for (int k = 0; k < 2; k++)
			for (int i = 0; i < g.size(); i++)
				a[k][i].prepare();
		for (int i = 0; i < g.automaton().size(); i++) {
			int current = 1 << i;
			a[0][current].set_result(false);
			a[0][current].length = 0;
			a[1][current].set_result(true);
			a[1][current].length = 0;
			q.push(make_pair(0, current));
			q.push(make_pair(1, current));
		}
	}

	bool search() {
		while (!q.empty()) {
			pair<bool, int> current = q.front();
			q.pop();
			search_check(current.first, current.second);
		}
		int start_position = g.size() - 1;
		return a[1][start_position].result;
	}

	string find_answer() {
		int start_position = g.size() - 1;
		string answer = "";
		if (a[1][start_position].calculated && a[1][start_position].result) {
			pair<bool, int> current = make_pair(true, start_position);
			while (a[current.first][current.second].length > 0) {
				answer += ('a' + a[current.first][current.second].letter);
				current = make_pair(!current.first, a[current.first][current.second].next_position);
			}
		}
		return answer;
	}

};