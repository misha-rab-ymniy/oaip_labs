#include "ass.h"

Ass::Ass()
{

}

void Ass::Sort()
{
    for (int i = 0; i < technique.size(); ++i){
        for (int j = i + 1; j < technique.size(); ++j){
            if (technique[i].getPrice() < technique[j].getPrice()){
                Technique tech = technique[j];
                technique[j] = technique[i];
                technique[i] = tech;
            }
        }
    }
}

void Ass::AddTech(QString type = 0, QString firm = 0, QString model = 0, int price = 0, bool isAval = 0)
{
    Technique tech;
    tech.setFirm(firm);
    tech.setIsAval(isAval);
    tech.setModel(model);
    tech.setPrice(price);
    tech.setType(type);
    technique.push_back(tech);
}

QString Ass::ChooseTech(int minPrice, int maxPrice)
{
    if (!technique.size()){
        return "русский военный корабль иди нахуй";
    }
    QString result;
    for (int i = 0; i < technique.size(); ++i){
        if (technique[i].getPrice() > minPrice && technique[i].getPrice() < maxPrice){
            result += technique[i].toString();
        }
    }
    return result;
}

QString Ass::FindType(QString type)
{
    if (!technique.size()){
        return "русский военный корабль иди нахуй";
    }
    QString result;
    for(int i = 0; i < technique.size(); ++i){
        if (technique[i].getType() == type){
            result += technique[i].toString();
        }
    }
    return result;
}

QString Ass::FindFirm(QString firm)
{
    if (!technique.size()){
        return "русский военный корабль иди нахуй";
    }
    QString result;
    for(int i = 0; i < technique.size(); ++i){
        if (technique[i].getFirm() == firm){
            result += technique[i].toString();
        }
    }
    return result;
}

QString Ass::FindModel(QString model)
{
    if (!technique.size()){
        return "русский военный корабль иди нахуй";
    }
    QString result;
    for(int i = 0; i < technique.size(); ++i){
        if (technique[i].getModel() == model){
            result += technique[i].toString();
        }
    }
    return result;
}

QString Ass::showAll()
{
    QString result;
    for (auto a : technique) {
        result += a.toString();
    }
    return result;
}
bool Ass::ReadFile(QString file){
    technique.clear();
    int i = 0, k = 0;
    QString str;
    for(int j = 0; j < file.size(); ++j){
        if(file[j] != ' ' && file[j] != '\n' && k != 4){
            str += file[j];
            if (k == 3 && (file[j] > '9' || file[j] < '0')){
                technique.clear();
                return false;
            }
        }
        else if (k == 4 && file[j] != '\n'){
            str += file[j];
        }
        else {
            switch(k){
            case 0:
                this->AddTech();
                technique[i].setType(str);
                ++k;
                break;
            case 1:
                technique[i].setFirm(str);
                ++k;
                break;
            case 2:
                technique[i].setModel(str);
                ++k;
                break;
            case 3:
                if (str.toInt() > 1000000){
                    return false;
                }
                technique[i].setPrice(str.toInt());
                ++k;
                break;
            case 4:
                bool isAval;
                if (str == "доступен"){
                    isAval = true;
                }
                else if (str == "не доступен"){
                    isAval = false;
                }
                else{
                    technique.clear();
                    return false;
                }
                technique[i].setIsAval(isAval);
                ++i;
                k = 0;
                break;
            }
            str.clear();
        }
    }
    return true;
}

void Ass::DelElem(QString model)
{
    for (int i = 0; i < technique.size(); ++i){
        if (technique[i].getModel() == model){
            technique.erase(technique.begin() + i);
        }
    }

}




