#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <random>

//���݂̋ǖʃf�[�^now_position_str��^���A���̈����擾����R�[�h
//std::string  now_position_str��ς��邱�ƂŊm�F�ł���B
//��菟����24000�����A��菟����17635����
//�R�����g�������폜

std::vector<std::string> split(std::string str, std::string sep) {
    std::string separator = sep;
    std::vector<std::string> result;
    std::string tstr = str + separator;
    long l = tstr.length(), sl = separator.length();
    std::string::size_type pos = 0, prev = 0;

    for (; pos < l && (pos = tstr.find(separator, pos)) != std::string::npos; prev = (pos += sl)) {
        result.emplace_back(tstr, prev, pos - prev);
    }
    //std::cout << "result�T�C�Y�F" << result.size() << '\n';
    return result;
}

int main() {
    std::vector<std::vector<std::string>> sente_vector;
    std::vector<std::vector<std::string>> gote_vector;
    std::ifstream sente_file("win_sente.txt"); // �ǂݍ��ރt�@�C���̃p�X���w��
    std::ifstream gote_file("win_gote.txt");
    std::string sente_line;
    std::string gote_line;

    if (!sente_file) {
        //�G���[����
        std::cout << "file not found win_sente.txt" << std::endl;
    }
    else {
        sente_vector.clear();
        //1�s���ǂݍ���
        while (std::getline(sente_file, sente_line)) {
            std::vector<std::string> temp_v = split(sente_line,",");
            //�x�N�^�[�ɒǉ�
            sente_vector.push_back(temp_v);
        }
        std::cout << "sente vector size:" << sente_vector.size() << std::endl;
    }

    if (!gote_file) {
        std::cout << "file not found win_gote.txt" << std::endl;
    }
    else {
        gote_vector.clear();
        while (std::getline(gote_file, gote_line)) {
            std::vector<std::string> temp_v = split(gote_line,",");
            gote_vector.push_back(temp_v);
        }
        std::cout << "gote vector size:" << gote_vector.size() << std::endl;
    }

    //std::string position_str = ("");
    std::string  now_position_str = ("position startpos moves 2g2f 8c8d 2f2e");
    //std::string now_position_str = ("position startpos moves 7g7f 3c3d");
    //std::string now_position_str = ("position startpos moves 2g2f 8c8d 2f2e");
    //std::string now_position_str = ("position startpos moves 7g7f");
    
    std::cout << "position_str:" << now_position_str << std::endl;
    std::vector< std::string > now_position_vector = split(now_position_str, " ");
    //����݂̂ɂ���B
    //position,startpos,moves�͍폜����B
    for (int i = 0; i < now_position_vector.size(); i++) {
        if (now_position_vector[i]=="position" || now_position_vector[i] == "startpos" || now_position_vector[i] == "moves") {
            std::cout << "delete str:" << now_position_vector[i] << std::endl;
            //�폜����B
            now_position_vector.erase(now_position_vector.begin()+i);
            i--;
        }
    }
    std::cout << "position_vector�T�C�Y�F" << now_position_vector.size() << std::endl;

    //��Ղ��玟�̈���Ԃ�����
    std::vector<std::string> joseki_vector;//������i�[���Ă����x�N�^�[

    if (now_position_vector.size() % 2 == 0) {
        std::cout << "�萔:" << now_position_vector.size() << " ���ł��B" << std::endl;
        std::cout << "sente_vector size:" << sente_vector.size() << std::endl;
        joseki_vector.clear();//��Ճx�N�^�[�̏�����

        for (int i = 0; i < sente_vector.size(); i++) {
            if (now_position_vector.size() == 0) {
                //����̏���
                joseki_vector.push_back(sente_vector[i][0]);
            }else {
                //����ȊO�̏���
                if (now_position_vector.size() >= sente_vector[i].size()) {
                    //���݂̎萔���Z�������̏ꍇ�͔�����
                    //std::cout << "���A���������F" << sente_vector[i].size() << std::endl;
                    std::cout << "�����܂��B�F" << now_position_vector.size() << "�F" << sente_vector[i].size() << std::endl;
                    continue;
                }
                //���݂̋ǖʂ̎��̈������x�N�^�[�Ɋi�[����B
                for (int j = 0; j < now_position_vector.size(); j++) {
                    if (now_position_vector[j] != sente_vector[i][j]) {
                        break;
                    }
                    if (j == now_position_vector.size()-1) {
                        joseki_vector.push_back(sente_vector[i][now_position_vector.size()]);
                    }
                }
            }
        }
    }else {
        std::cout << "�萔:" << now_position_vector.size() << " ���ł��B" << std::endl;
        std::cout << "gote_vector size:" << gote_vector.size() << std::endl;
        joseki_vector.clear();//��Ճx�N�^�[�̏�����

        for (int i = 0; i < gote_vector.size(); i++) {
            if (now_position_vector.size() >= gote_vector[i].size()) {
                //���݂̎萔���Z�������̏ꍇ�͔�����
                continue;
            }
            for (int j = 0; j < now_position_vector.size(); j++) {
                if (now_position_vector[j] != gote_vector[i][j]) {
                    break;
                }
                if (j == now_position_vector.size() - 1) {
                    joseki_vector.push_back(gote_vector[i][now_position_vector.size()]);
                }
            }
        }
    }
    std::cout << "��Ռ��T�C�Y�F" << joseki_vector.size() << std::endl;
    //std::cout << "��Ռ��[0]�F" << joseki_vector[0] << std::endl;
    //std::cout << "��Ռ��[1]�F" << joseki_vector[1] << std::endl;
    //std::cout << "��Ռ��[2]�F" << joseki_vector[2] << std::endl;
    //std::cout << "��Ռ��[3]�F" << joseki_vector[3] << std::endl;
    //std::cout << "��Ռ��[4]�F" << joseki_vector[4] << std::endl;

    std::cout << "��Ղ��烉���_���Ȍ����Ԃ��܂��B" << std::endl;
    if (joseki_vector.size() >= 1){
        std::cout << "��Ղ�����܂��B" << std::endl;
        std::mt19937 engine{ std::random_device{}() };
        std::uniform_int_distribution<int> dist(0, joseki_vector.size());
        //�\��
        int index = dist(engine);
        std::cout << "��Ռ��萔:" << joseki_vector.size() << std::endl;
        std::cout << "index:" << index << std::endl;
        std::cout << "��Ռ���:" << joseki_vector[index] << std::endl;
    }else {
        std::cout << "��Ղ�����܂���B" << std::endl;
    }
    
    return (0);
}