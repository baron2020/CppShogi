#include<iostream>
#include<string>

//�r���h�ŏo����exe�t�@�C���͏������ɃG���W���o�^�ł��܂��B
//���ԂȂ珉��26����Ԃ��܂��B
//quit�̓��͂��󂯎��ƏI�����܂��B
//���̑��̃R�}���h�Fusi,isready,usinewgame,position,go,quit

int main() {
	std::string cmd;
	std::cout << "�R�}���h����͂��Ă��������B\n";
	std::cout << "quit�ŏI�����܂��B\n";
	while (true) {
		std::cin >> cmd;
		//std::cout << "�󂯎�����R�}���h�F" << cmd << "\n";
		if (cmd == "usi") {
			//�\�t�g��
			std::cout << "id name CppShogi1\n";
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
		else if (cmd == "position") {
			//�ǖʂ̎󂯎��
			//�����startpos
			//��Fposition startpos moves 7g7f 3c3d 2g2f
			std::cout << "PositionCmd:" << "\n";
		}
		else if (cmd == "go") {
			//�v�l�J�n
			//���26�����w���B
			std::cout << "CmdGo\n";
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