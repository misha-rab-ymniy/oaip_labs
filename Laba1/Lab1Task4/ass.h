#ifndef ASS_H
#define ASS_H

#include "technique.h"
#include <QVector>

class Ass
{
private:
    QVector<Technique> technique;
public:
    Ass();
    void Sort();
    void AddTech(QString type, QString firm, QString model, int price, bool isAval);
    //void PopTech();
    QString ChooseTech(int minPrice, int maxPrice);
    QString FindType(QString type);
    QString FindFirm(QString firm);
    QString FindModel(QString model);
    QString showAll();
    bool ReadFile(QString file);
    void DelElem(QString str);
};

#endif // ASS_H
