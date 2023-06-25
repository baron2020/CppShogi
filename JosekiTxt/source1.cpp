#include <fstream>
#include <iostream>
#include <string>
#include <vector>

//�s���������Ă����Ȃ��ǂݍ��݂��o���邩�m�F����B
//win_sente.txt:24000�s
//win_gote.txt :17635�s
//�J���}�ŋ�؂�A�x�N�^�[�ɒǉ�����B

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
    //sente_vector.clear();
    //gote_vector.clear();

    std::ifstream sente_file("win_sente.txt"); // �ǂݍ��ރt�@�C���̃p�X���w��
    std::ifstream gote_file("win_gote.txt");
    std::string sente_line;
    std::string gote_line;

    if (!sente_file) {
        //�G���[����
        std::cout << "�t�@�C�������݂��܂���B1" << std::endl;
    }
    else {
        //1�s���ǂݍ���
        while (std::getline(sente_file, sente_line)) {
            //std::cout << sente_line << std::endl;
            std::vector<std::string> temp_v = split(sente_line,",");
            //�x�N�^�[�ɒǉ�
            sente_vector.push_back(temp_v);
        }
        std::cout << "�x�N�^�[�T�C�Y1�F" << sente_vector.size() << std::endl;
    }

    if (!gote_file) {
        //�G���[����
        std::cout << "�t�@�C�������݂��܂���B2" << std::endl;
    }
    else {
        while (std::getline(gote_file, gote_line)) {
            //std::cout << gote_line << std::endl;
            std::vector<std::string> temp_v = split(gote_line,",");
            //�x�N�^�[�ɒǉ�
            gote_vector.push_back(temp_v);
        }
        std::cout << "�x�N�^�[�T�C�Y2�F" << gote_vector.size() << std::endl;
    }

    //std::string position_str = ("");
    // std::string position_str = ("position startpos moves");
    std::string position_str = ("position startpos moves 7g7f 3c3d 2g2f");

    std::cout << "position_str:" << position_str << std::endl;
    std::vector< std::string > position_vector = split(position_str, " ");
    //����݂̂ɂ���B
    //position,startpos,moves�͍폜����B
    for (int i = 0; i < position_vector.size(); i++) {
        if (position_vector[i]=="position" || position_vector[i] == "startpos" || position_vector[i] == "moves") {            
            std::string target_str = position_vector[i];
            //�폜����B
            position_vector.erase(position_vector.begin()+i);
            std::cout <<"�폜���܂�:" << target_str << std::endl;
            i--;
        }
    }
    std::cout << "position_vector�T�C�Y�F" << position_vector.size() << std::endl;
    std::cout << "position_vector[0]�F" << position_vector[0] << std::endl;
    std::cout << "position_vector[1]�F" << position_vector[1] << std::endl;
    //std::cout << "position_vector[2]�F" << position_vector[2] << std::endl;
    //std::cout << "position_vector[3]�F" << position_vector[3] << std::endl;

    position_vector.clear();
    std::cout << "position_vector�T�C�Y�F" << position_vector.size() << std::endl;

    return (0);
}