#include<iostream>
#include<string>

//�r���h�ŏo����exe�t�@�C���͏������ɃG���W���o�^�ł��܂��B
//���ԂȂ珉��26����Ԃ��܂��B
//quit�̓��͂��󂯎��ƏI�����܂��B
//���̑��̃R�}���h�Fusi,isready,usinewgame,go,quit

int main() {
	while (true) {
		std::string cmd;
		std::cout << "�R�}���h����͂��Ă��������B\n";
		std::cout << "quit�ŏI�����܂��B\n";

		std::cin >> cmd;
		if (cmd == "usi") {
			//�\�t�g��
			std::cout << "id name yukawa shogi1\n";
			//�J���Җ�
			std::cout << "id author yukawa\n";
			std::cout << "usiok\n";
		}else if (cmd == "isready") {
			//�΋Ǐ���
			//�ǂݍ��݂��K�v�Ȃ炱���ŏ�������B
			std::cout << "readyok\n";
		}
		else if (cmd == "usinewgame") {
			//�΋ǊJ�n�̍��}
			//�������Ȃ�
		}
		else if (cmd == "go") {
			//�v�l�J�n
			//���26�����w���B
			std::cout << "bestmove 2g2f\n";
		}else if (cmd == "quit") {
			//�G���W����~
			break;
		}
	}
	//�G���W�����I��������B
	std::cout << "�I�����܂��B\n";
	exit(1);
	return 0;
}