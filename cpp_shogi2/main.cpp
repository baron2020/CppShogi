#include<iostream>
#include<string>

//CppShogi2�FCppShogi1����̕ύX�_�Ƃ��āA�v�l�ǖʂ��󂯎��@�\��ǉ��B
//�v�l�ǖʁF46�s�ڂ�position�Ŋm�F�ł���B

int main() {
	std::string cmd;
	std::string position;
	bool positionFlg = false;
	std::cout << "�R�}���h����͂��Ă��������B\n";
	std::cout << "quit�ŏI�����܂��B\n";

	while (true) {
		std::cin >> cmd;
		//std::cout << "�󂯎�����R�}���h�F" << cmd << "\n";
		
		if(positionFlg && cmd!="go") {
			//�ǖʏ��̎󂯎��
			//�����startpos����n�܂�
			//��Fposition startpos moves 7g7f 3c3d 2g2f
			position += " ";
			position += cmd;
			std::cout << "�󂯎�����ǖʏ��F" << cmd << "\n";
		}
		if (cmd == "usi") {
			//�\�t�g��
			std::cout << "id name CppShogi2\n";
			//�J���Җ�
			std::cout << "id author yukawa\n";
			std::cout << "usiok\n";
		}
		else if (cmd == "isready") {
			//�΋Ǐ���
			//�ǂݍ��݂��K�v�Ȃ炱���ŏ�������B
			std::cout << "readyok\n";
		}
		else if (cmd == "usinewgame") {
			//�΋ǊJ�n�̍��}
			//�������Ȃ�
		}
		else if (cmd == "position") {
			//position�R�}���h�̌�ɋǖʂ������Ă��邽�߁A�ǖʎ󂯎��̂���������B
			std::cout << "position�R�}���h\n";
			position.clear();
			position="position";
			positionFlg = true;
		}
		else if (cmd == "go") {
			//�v�l�J�n
			//���26�����w���B
			positionFlg = false;
			std::cout << "�v�l�ǖʁF" << position << "\n";
			std::cout << "go�R�}���h\n";
			std::cout << "bestmove 2g2f\n";
		}
		else if (cmd == "quit") {
			//�G���W����~
			break;
		}
	}
	//�G���W�����I��������B
	std::cout << "�I�����܂��B\n";
	exit(1);
	return 0;
}