#pragma once

class SyncSearchCell {
public:
	//    shows if the vertex has been calculated
	bool calculated;
	//    if caluclated, shows the result of user playing from this position
	bool result;
	//    length of optimal playing
	int length;
	//    if calculated and result is positive, shows which letter is chosen by user
	int letter;
	//    for second player: shows how many possible previous vertices have been calculated
	int count;
	//    next position in the optimal game
	int next_position;

	void set_move(int length, int letter, int next_position) {
		this->length = length;
		this->letter = letter;
		this->next_position = next_position;
	}

	void set_result(bool result) {
		this->calculated = true;
		this->result = result;
	}

	void prepare() {
		this->length = -1;
		this->calculated = false;
	}
};